#include <client/Requests.h>
#include <synthaxParser/Parser.h>
#include <nlohmann/json.hpp>

using nlohmann::json;

int main() {
    /*std::string ipAdress = "127.0.0.1", port = "9082";
    Requests *requests = new Requests(ipAdress, port);
    std::string answer;


    bool finish = false;
    while (!finish) {
       std::cout << "Que desea hacer?" << "\n 1: hacer insert\n 2: salir" << std::endl;
       std::cin >> answer;
       if (answer == "1") {
           json data;

           data["saludo"] = "hola";
           data["imagen"] = 9048123;

           std::string temp = data.dump(4);

           requests->sendPostRequest(temp, INSERT);
       }
       else {
           finish = true;
       }
   }*/

    Parser *parser = new Parser();
    std::string prueba = "INSERT INTO vacaciones (lugar,tiempo) VALUES (portland,2años)";
    parser->scriptTypeofRequestParser(prueba);



     return 0;
}

