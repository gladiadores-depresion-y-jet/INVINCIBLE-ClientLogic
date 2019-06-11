#include <clientcomm/Requests.h>
#include <synthaxParser/Parser.h>

int main() {
    std::string ipAdress = "127.0.0.1", port = "9080";
    Requests *requests = new Requests(ipAdress, port);
    std::string answer;


    bool finish = false;
    while (!finish) {
       std::cout << "Que desea hacer?" << "\n 1: hacer insert\n 2: hacer select" << std::endl;
       std::cin >> answer;
       if (answer == "1") {
           std::cout << "Que desea enviar para el insert?" << std::endl;
           std::cin >> answer;
           requests->sendPostRequest(answer, INSERT);
       }
       else if (answer == "2") {
           std::cout << "Que desea enviar para el select?" << std::endl;
            std:: cin >> answer;
            requests->sendPostRequest(answer, SELECT);
       }
       else {
           finish = true;
       }
   }

    /*Parser *parser = new Parser();
    parser->scriptTypeofRequestParser("Hola mi nombre es david");*/



     return 0;
}

