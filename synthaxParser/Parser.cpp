//
// Created by kugelblitz on 6/8/19.
//

#include "Parser.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool Parser::scriptTypeofRequestParser(std::string &script) {
    bool hasType = true;
    try {
        // Divide
        std::vector<std::string> strings;
        std::istringstream f(script);
        std::string s;
        while (getline(f, s, ' ')) {
            strings.push_back(s);
        }

        std::string typeOfRequest = strings[0];
        std::transform(typeOfRequest.begin(), typeOfRequest.end(), typeOfRequest.begin(), ::tolower);

        if (typeOfRequest == "insert") {
            this->insertParser(strings);
        }

        else if (typeOfRequest == "select") {
            this->selectParser(strings);
        }

        else if (typeOfRequest == "update") {
            this->updateParser(strings);
        }

        else if (typeOfRequest == "delete") {
            this->deleteParser(strings);
        }

        else {
            hasType = false;
        }
    }

    catch (const std::exception& e) {
        e.what();
        hasType = false;
    }



    return hasType;

}

bool Parser::insertParser(std::vector<std::string> strings) {
    bool successful = false;
    std::string table;
    std::string cols;
    std::string values;
    if (strings.size() >= 6) {
        std::transform(strings[1].begin(), strings[1].end(), strings[1].begin(), ::tolower);
        if (strings[1] == "into") {
            table = strings[2];
            if (strings[3][0] == '(' && strings[3][strings[3].length()-1] == ')') {
                cols = strings[3].substr(1, strings[3].length()-2);
                std::transform(strings[4].begin(), strings[4].end(), strings[4].begin(), ::tolower);
                if (strings[4] == "values") {
                    if (strings[5][0] == '(' && strings[5][strings[5].length()-1] == ')') {
                        values = strings[5].substr(1, strings[5].length()-2);
                        successful = true;

                        std::cout << "Table : " << table << "\n Columnas : " << cols << "\n Valores : " << values << std::endl;
                    }
                }
            }
        }
    }


    return successful;
}

/*bool Parser::insertParser(std::vector<std::string> strings) {
    // TODO cambiar

    bool succcessful = true;
    int i = 1;
    std::string table;
    std::string cols;
    std::string values;

    json jsonToSend;

    // Vefica que exista la palabra INTO
    std::string hasInto = strings[i];
    std::transform(hasInto.begin(), hasInto.end(), hasInto.begin(), ::tolower);
    if (hasInto == "into") {
        i++;
        // Obtiene el nombre la tabla
        table = strings[i];
        i++;

        if (strings[i][0] == '(') {
            // elimina de la primera columna el simbolo (
            std::string substring = strings[i].substr(1, strings[i].length()-1);
            cols.append(substring);
            while (strings[i][strings[i].length()-1] != ')') {
                // anade cols
                cols.append(strings[i]);
                i++;
            }
            // anade la ultima col sin )
            std::string temp = strings[i].substr(0, strings[i].length()-2);
            cols.append(temp);
            i++;

            std::string hasValues = strings[i];
            std::transform(hasValues.begin(), hasValues.end(), hasValues.begin(), ::tolower);
            if (hasValues == "values") {
                i++;

                if (strings[i][0] == '(') {
                    substring = strings[i].substr(1, strings[i].length());

                    values.append(substring);
                    while (strings[i][strings[i].length()-1] != ')') {
                        // anade cols
                        values.append(strings[i]);
                        i++;
                    }
                    // anade la ultima col sin )
                    temp = strings[i].substr(0, strings[i].length()-2);
                    values.append(temp);

                }
            }
        }
    }

    else
        succcessful = false;

    jsonToSend["cols"] = cols;
    jsonToSend["values"] = values;
    jsonToSend["table"] = table;

    return succcessful;
}*/

bool Parser::selectParser(std::vector<std::string> strings) {

}

bool Parser::updateParser(std::vector<std::string> strings) {

}

bool Parser::deleteParser(std::vector<std::string> strings) {

}
