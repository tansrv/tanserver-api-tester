/*
 * Copyright (C) tanserver.org
 * Copyright (C) Daniele Affinita
 * Copyright (C) Chen Daye
 */

#include <string>
#include "error.h"
#include "ssl_tester.h"
#include "connection.h"

using namespace std;

int main(int argc, char **argv)
{
    // argv[1]: IP address, argv[2]: port, argv[3]: api, argv[4]: json parameters
    if(argc != 5) handleError("Usage: ./apitester server_ip_address port api_name json_string\n");
    
    int         wr,
                socketDescriptor;

    SSL         *ssl;

    string      packet,
                rcvd;

    cleanable   *cl;

    char        header[2048];

    //cleanup routine on exit 
    cl = (cleanable*) malloc(sizeof(cleanable));
    memset(cl, 0, sizeof(cleanable));
    on_exit(exitCleanup, (void*) cl);

    //create socket
    socketDescriptor = _connect(argv[1], atoi(argv[2]));
    cl->fd = socketDescriptor;

    //add ssl to connection
    ssl = ssl_connect(socketDescriptor);
    cl->ssl = ssl;

    //building package: header {"user_api":"...","json_length":...}\r\n
    snprintf(header, 2048, "{\"user_api\":\"%s\",\"json_length\":%d}\r\n",argv[3], strlen(argv[4]));
    packet = header;
    
    packet += argv[4];

    wr = SSL_write(ssl, packet.c_str(), packet.length());
    if(wr <= 0)
        handleError("SSL write to server failed\n");

    printf("Data packet sent to the server:\n%s\n%d bytes sent\n", packet.c_str(), wr);

    rcvd = getAnswer(ssl);

    printf("Response from the server: %s", rcvd.c_str());

    return 0;
}