#include "error.h"

void handleError(const char* msg){
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}

void exitCleanup(int status, void* cl){
    cleanable* tmp = (cleanable*) cl;
    if(tmp){
        if(tmp->fd)
            close(tmp->fd);

        if(tmp->ssl)
            SSL_free(tmp->ssl);
    }
    free(tmp);
}