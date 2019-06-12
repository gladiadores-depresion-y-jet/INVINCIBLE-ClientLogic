//
// Created by kugelblitz on 6/8/19.
//

#ifndef INVINCIBLE_CLIENTLOGIC_PARSER_H
#define INVINCIBLE_CLIENTLOGIC_PARSER_H

#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <client/Requests.h>

class Parser {

public:
    bool scriptTypeofRequestParser(std::string &script);

    bool insertParser(std::vector<std::string> strings);
    bool selectParser(std::vector<std::string> strings);
    bool updateParser(std::vector<std::string> strings);
    bool deleteParser(std::vector<std::string> strings);

    bool sendInsertPostRequest(std::string json);
    bool sendSelectPostRequest(std::string json);
    bool sendUpdatePostRequest(std::string json);
    bool sendDeletePostRequest(std::string json);
};


#endif //INVINCIBLE_CLIENTLOGIC_PARSER_H
