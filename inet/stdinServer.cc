//Creates a socket, wait for someone to connect, then send
//the Standard Input directly to the socket. No 'http' or 'ssh' protocol.
//Just transmitting raw data. Kinda like netcat.

//Linux System calls requre a stupid ammount of headers.
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include"inet.h" //In your programs, use <inet/inet.h> or <phoenix/inet/inet.h>

int main(int argc, char *argv[]){
    if(argc<2){
        std::cerr<<"Usage: "<<argv[0]<<" <port>"<<std::endl;
        exit(1);
    }
    sock=inet::bind(argv[1]);
    if(sock==-1){
        std::cerr<<"An error has occured."<<std::endl;
        exit(-1);
    }
    if(listen(sock,2)==-1){
        std::cerr<<"Error listening on socket."<<std::endl; //TODO strerror
        close(sock);
        return -1;
    }
    struct sockaddr peeraddr;
    if(accept(sock,peeraddr,sizeof(peeraddr))==-1){
        //replace NULL with a struct sockaddr to store info
        //This my be important later.
        std::cerr<<"Error accepting connection."<<std::endl; //TODO strerror
        close(sock);
        return -1;
    }
    char* peer = inet_ntop(ntohl(peeraddr.sin_addr.s_addr));
    while(true){
        std::string data;
        std::cout<<peer<<" > ";
        std::cin>>data;
        if(data==EOF){ //TODO is it EOF or std::char_traits::eof?
            break;
        }
        while(data.length() > send(sock,data.c_str(),data.length(),0) ){
            //If this loop runs, there was a send error.
            data=data.substr(bytes);
            //I have no clue how to tesst this code.
        }
    }
    close(sock);
    return 0;
}
