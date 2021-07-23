/*
 * Copyright (C) tanserver.org
 * Copyright (C) Daniele Affinita
 * Copyright (C) Chen Daye
 */

#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <string.h>
#include <openssl/ssl.h>

typedef struct{
    int fd;
    SSL* ssl;
} cleanable;

void handleError(const char* msg);
void exitCleanup(int status, void* fd);

#ifdef __cplusplus
}
#endif
#endif