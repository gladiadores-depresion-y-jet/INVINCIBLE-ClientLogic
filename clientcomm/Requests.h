//
// Created by david on 07/06/19.
//

#ifndef INVINCIBLE_CLIENTLOGIC_REQUESTS_H
#define INVINCIBLE_CLIENTLOGIC_REQUESTS_H

#include <iostream>
#include <string>

class Requests {
public:
    // TODO especificar tipos de return.
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    void insertMetadata(std::string &data);

    void updateMetadata();
    void deleteMetadata();
    void selectMetadata();
};


#endif //INVINCIBLE_CLIENTLOGIC_REQUESTS_H
