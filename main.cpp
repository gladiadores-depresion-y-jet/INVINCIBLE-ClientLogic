#include <client/Requests.h>
#include <synthaxParser/Parser.h>

using nlohmann::json;

int main() {

    Parser *parser = new Parser();

    std::string ipAdress = "127.0.0.1", port = "9080";
    Requests *requests = new Requests(ipAdress, port);
/*
    //Parser *parser = new Parser();
    //std::string prueba = "INSERT INTO vacaciones (lugar,tiempo) VALUES (portland,2años)";
    //std::string prueba = "SELECT (name,author) FROM Photos WHERE name IN (danielImage)";
    //std::string prueba = "DELETE FROM vacaciones WHERE lugar=portland";
    //std::string prueba = "DELETE FROM vacaciones";
    //std::string prueba = "UPDATE vacaciones SET lugar=portland,author=david,year=2017 WHERE descripcion=hola";
    json respuesta = parser->scriptTypeofRequestParser(prueba);
    if (!respuesta.empty()) {
        std::string enviar = respuesta.dump();
        std::cout << enviar << std::endl;
        //std::cout << requests->sendPostRequest(enviar, SELECT) << std::endl;
    }*/


    std::string junk = "{algo: \"algo\"}";

    json create;
    create["table"] = "semestre";
    std::string galery = create.dump();


    json insert;
    insert["table"] = "semestre";
    insert["cols"] = "name,author,year";
    insert["values"] = "pretil,david,2019";
    insert["imagen"] = "4913278409382hnflasdkjf;alsdkj";
    std::string insertImage = insert.dump();

    json insert2;
    insert2["table"] = "semestre";
    insert2["cols"] = "name,author,year,description";
    insert2["values"] = "comedor,daniel,2014,hola";
    insert2["imagen"] = "4913278409382hnflasdkjf;alsdkj";
    std::string insert2String = insert2.dump();

    json select;
    select["table"] = "semestre";
    select["cols"] = "author,name,year";
    select["WHERE"] = "author=david";
    std::string selectString = select.dump();

    json update;
    update["table"] = "semestre";
    update["cols"] = "name=pretil,year=2018,description=unaimagenchuza";
    update["WHERE"] = "author=david";
    std::string updateString = update.dump();

    /*std::cout <<  "Restore request: "<< requests->sendPostRequest(junk, RESTORE) << std::endl;
    std::cout << "Create request :" << requests->sendPostRequest(galery, CREATE) << std::endl;
    std::cout << "Insert request :" << requests->sendPostRequest(insertImage, INSERT) << std::endl;
    std::cout << "Insert request :" << requests->sendPostRequest(insert2String, INSERT) << std::endl;
    std::cout << "Select request : " << requests->sendPostRequest(selectString, SELECT) << std::endl;*/
    std::cout << "Update request : " << requests->sendPostRequest(updateString, UPDATE) << std::endl;

    return 0;
}

