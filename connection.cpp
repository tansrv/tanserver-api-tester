#include "connection.h"

/*
struct sockaddr_in {
               sa_family_t    sin_family; // address family: AF_INET
               in_port_t      sin_port;   // port in network byte order
               struct in_addr sin_addr;   // internet address
           };

struct in_addr {
               uint32_t       s_addr;     // address in network byte order
           };
*/

int _connect(const char* host, in_port_t port){
    struct sockaddr_in addr;
    int s, connRes;

    //returns file descriptor of socket
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) handleError("unable to create socket\n");

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    connRes = connect(s, (struct sockaddr *) &addr, sizeof(addr));
    if(connRes == -1){
        close(s);
        char buff[48];
        sprintf(buff, "System Call connect() failed with errno code %d: %s \n", errno, strerror(errno));
        handleError(buff);
    }

    return s;
}

static bool check_crlf(std::string s){
    size_t dimension = s.size();
    if(dimension < 2)
        return false;
    
    std::string sb = s.substr(dimension - 2, 2);
    return sb == "\r\n";
}

std::string getAnswer(SSL* ssl){
    std::string out;
    char buffer[2];
    memset(buffer, 0, 2);
    while( !check_crlf(out) ){
        SSL_read(ssl, buffer, 1);
        out.append(buffer);
    }

    if(out == "") 
        handleError("Empty response from the server\n");

    return out;
}