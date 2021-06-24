#ifndef CONNECTION_H
#define CONNECTION_H

#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <errno.h>
#include <string>
#include "error.h"

int _connect(const char* host, in_port_t port);
std::string getAnswer(SSL* ssl);

#endif