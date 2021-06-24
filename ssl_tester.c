#include "ssl_tester.h"

static SSL_CTX* SSL_init(){
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    return SSL_CTX_new(SSLv23_method());
}

SSL* ssl_connect(int fileDescriptor){

    SSL_CTX* context;
    SSL* ssl;

    context = SSL_init();

    if(!context)
        handleError("context init failed\n");

    ssl = SSL_new(context);
    if(!ssl)
        handleError("SSL start failed\n");
    
    if(!SSL_set_fd(ssl, fileDescriptor)){
        SSL_free(ssl);
        handleError("SSL_set_fd failed\n");
    }

    if(SSL_connect(ssl) <= 0){
        SSL_free(ssl);
        handleError("SSL handshake failed\n");
    }

    return ssl;
}