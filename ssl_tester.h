/*
 * Copyright (C) tanserver.org
 * Copyright (C) Daniele Affinita
 * Copyright (C) Chen Daye
 */

#ifndef SSL_TESTER_H
#define SSL_TESTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <openssl/ssl.h>
#include "error.h"

SSL* ssl_connect(int fileDescriptor);

#ifdef __cplusplus
}
#endif
#endif