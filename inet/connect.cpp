#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<errno.h>
#include<string.h>
namespace inet{
    int connect(const char* domain, const char* protocol){
        struct addrinfo hints;
        struct addrinfo* res;
        memset(&hints,0,sizeof(hints)); 
        hints.ai_family=AF_UNSPEC;
        hints.ai_socktype=SOCK_STREAM;
        int status = getaddrinfo(domain,protocol,&hints,&res);
        if(status!=0){
            std::cerr<<gai_strerror(status);
            return -1;
        }
        
        int sock = socket(res->family,res->ai_socktype,res->ai_protocol);
        if(sock==-1){
            std::cerr<<strerror(errno)<<std::endl;
            freeaddrinfo(res);
            return -1;
        }
        status=connect(sock,res->ai_addr,res->ai_addrlen);
        if(status==-1){
            std::cerr<<strerror(errno)<<std::endl;
            freeaddrinfo(res);
            return -1;
        }
        freeaddrinfo(res);
        return sock;
    }

    int bind(const char* protocol){
        struct addrinfo hints;
        struct addrinfo* res;
        memset(&hints,0,sizeof(hints));
        hints.ai_family=AF_UNSPEC;
        hints.ai_socktype=SOCK_STREAM;
        hints.ai_flag=AI_PASSIVE;
        int status = getaddrinfo(NULL,protocol,&hints,&res);
        if(status!=0){
            std::cerr<<gai_strerror(status)<<std::endl;
            return -1;
        }
        int sock = socket(res->family,res->ai_socktype,res->ai_protocol);
        if(sock==-1){
            std::cerr<<strerror(errno)<<std::endl;
            freeaddrinfo(res);
            return -1;
        }
        status = bind(sock,res->ai_addr,res->ai_addrlen;);
        if(status==-1){
            freeaddrinfo(res);
            std::cerr<<strerror(errno)<<std::endl;
            return -1;
        }
        return sock;
    }
};
