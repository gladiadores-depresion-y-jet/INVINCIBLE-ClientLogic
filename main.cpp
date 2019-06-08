#include <clientcomm/Requests.h>

int main() {
    Requests *requests = new Requests();
    std::string answer;


    bool finish = false;
    while (!finish) {
       std::cout << "Que desea hacer?" << "\n 1: hacer post\n 2: salir" << std::endl;
       std::cin >> answer;
       if (answer == "1") {
           std::cout << "Que desea enviar?" << std::endl;
           std::cin >> answer;
           requests->insertMetadata(answer);
       }
       else
           finish = true;
   }
    return 0;
}

