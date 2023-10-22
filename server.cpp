#include <stdlib.h>
#include <signal.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>
#include <unistd.h>

typedef struct threadArgs_s{
    int id;
    int fd;
    struct sockaddr_in addressDesc;
}threadArg;

#define Port 6667

void closeSocket(int fd){
    shutdown(fd, SHUT_RDWR);
    close(fd);
}

int startTcpServer(short port, int numToWaitClient){
    int retval;
    struct sockaddr_in serverAddrDesc;
    int fd;
    // int yes = 1;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0){
        std::cerr << "error: starting tcpServer Socket";
        exit(EXIT_FAILURE);
    }

    serverAddrDesc.sin_family = AF_INET;
    serverAddrDesc.sin_port = htons(port);
    serverAddrDesc.sin_addr.s_addr = INADDR_ANY;

    retval = bind(fd, (struct sockaddr *) &serverAddrDesc, sizeof(serverAddrDesc));
    if(retval < 0){
        std::cerr << "error: starting tcpServer bind";
        closeSocket(fd);
        exit(EXIT_FAILURE);
    }

    retval = listen(fd, numToWaitClient);
    if(retval < 0){
        std::cerr << "error: starting tcpServer listen";
        closeSocket(fd);
        exit(EXIT_FAILURE);
    }
    return fd;
}

void signalHandler(int signum){
    std::cout << "olduremen beni" << std::endl;
    (void)signum;
}

void setHandler(int sigNum, void(*signalHandler)(int)){
    (void)sigNum;
    signal(SIGINT, signalHandler);
}
void * startThread(void *arg);
int main( void ){
    setHandler(SIGINT, signalHandler);
    int serverSocket = startTcpServer(Port, 0);


    int clientId = 0;
    int clientfd;
    while(1){
        struct sockaddr_in clientAddrDesc;
        socklen_t clientAddrDescLen = sizeof(clientAddrDesc);

        clientfd = accept(serverSocket, (struct sockaddr *)&clientAddrDesc, &clientAddrDescLen);
        if(clientfd > 0){
            threadArg* arg = (threadArg *)malloc(sizeof(threadArg) * 1);
            if(arg){
                arg->id = clientId++;
                arg->fd = clientfd;
                memcpy(&(arg->addressDesc), &clientAddrDesc, sizeof(struct sockaddr_in));
                pthread_t tid;
                pthread_create(&tid, NULL, startThread, arg);
                pthread_detach(tid);
            }
            else{
                std::cerr << "error: creating arg w/ malloc";
            }
        }
    }
    closeSocket(serverSocket);
    return (0);
}

void * startThread(void * arg){
    threadArg * castedArg = (threadArg*)arg;

    char message[1024] = {0};
    int clientid = castedArg->id;
    std::cout << "Client " << clientid << " file descriptor : " << castedArg->fd << std::endl;
    std::cout << "Client " << clientid << " address : " << ntohl(castedArg->addressDesc.sin_addr.s_addr) << std::endl;
    std::cout << "Client " << clientid << " port : " << ntohs(castedArg->addressDesc.sin_port) << std::endl;

    int messageLength = recv(castedArg->fd, message, 1024, 0);
    if(messageLength <= 0)
        std::cerr << "no message here and : " << strerror(errno)<< std::endl;
    else{
        std::cout << "Client " << clientid << " says : " << message << std::endl;
        send(castedArg->fd, "Bye little client\n", 18, 0);
    }

    closeSocket(castedArg->fd);
    free(castedArg);
    return NULL;
}