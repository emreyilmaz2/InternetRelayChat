#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>

class ACommands{
private:

public:
    virtual void execute(int fd, std::vector<std::string> token) = 0;
};




class JoinCommand : public ACommands{
public:
    void execute(int fd, std::vector<std::string> token){
        // parametre kontrolu, must be equal to 2

        // kanal zaten olusturulmus mu, if not then create

        // bana gelen sifre dogruysa ve maximum client a ulasmadiysa kanala ekle
    }

    
};

#endif