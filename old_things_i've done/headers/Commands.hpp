#ifndef COMMANDS_HPP
#define COMMANDS_HPP
//pass
#define ERR_NEEDMOREPARAMS(command)                 command         + " :Not enough parameters"                 + " - 461"
#define ERR_ALREADYREGISTRED(nick)                  nick            + " :You may not reregister"                + " - 462"

//nick
#define ERR_NONICKNAMEGIVEN(nick)                   nick            + " :No nickname given"                     + " - 431"
#define ERR_ERRONEUSNICKNAME(nick)                  nick            + " :Erroneus nickname"                     + " - 432"
#define ERR_NICKNAMEINUSE(nick)                     nick            + " :Nickname is already in use"            + " - 433"

#define ERR_INVITEONLYCHAN(channel)                 channel         + " :Cannot join channel (+i)"              + " - 473"
#define ERR_BANNEDFROMCHAN(channel)                 channel         + " :Cannot join channel (+b)"              + " - 474"
#define ERR_BADCHANNELKEY(channel)                  channel         + " :Cannot join channel (+k)"              + " - 475"
#define ERR_CHANNELISFULL(channel)                  channel         + " :Cannot join channel (+l)"              + " - 471"
#define ERR_BADCHANMASK
#define ERR_NOSUCHCHANNEL(channel)                  channel         + " :No such channel"                       + " - 403"
#define ERR_TOOMANYCHANNELS(channel)                channel         + " :You have joined too many channels"     + " - 405"

// part
#define ERR_NOTONCHANNEL(channel)                   channel         + " :You're not on that channel"            + " - 442"

//mode
#define ERR_CHANOPRIVSNEEDED(channel)               channel         + " :You're not channel operator"           + " - 482"
#define ERR_KEYSET(channel)                         channel         + " :Channel key already set"               + " - 467"
#define ERR_UNKNOWNMODE(character)                  character       + " :is unknown mode char to me"            + " - 472"

// names
#define RPL_NAMREPLY
#define RPL_ENDOFNAMES

// invite
#define ERR_USERONCHANNEL(channel, user)            user + channel  + " :is already on channel"                 + " - 443"
#define RPL_INVITING
#define RPL_AWAY

// message
#define ERR_NORECIPIENT
#define ERR_NOTEXTTOSEND                                              " :No text to send"                       + " - 412"
#define ERR_CANNOTSENDTOCHAN(channel_name)          channel_name    + " :Cannot send to channel"                + " - 404"
#define ERR_TOOMANYTARGETS

//ping
#define ERR_NOORIGIN                                                  ":No origin specified"                    + " - 409"




#define ERR_NOSUCHNICK(str)                         str + " :No such nick/channel"












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