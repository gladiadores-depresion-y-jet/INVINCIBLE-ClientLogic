#include <iostream>
#include <string>
#include <sstream>

#include <curl/curl.h>

void postSomething() {
    CURL *curl;
    CURLcode res;

    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if(curl) {
        /* First set the URL that is about to receive our POST. This URL can
           just as well be a https:// URL if that is what should receive the
           data. */
        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:9080/repetir?1");
        /* Now specify the POST data */
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "hilera=algo");

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}


int main()
{
    std::string answer;
    bool finish = false;
    while (!finish) {
       std::cout << "Que desea hacer?" << "\n 1: hacer post\n 2: salir" << std::endl;
       std::cin >> answer;
       if (answer == "1")
           postSomething();
       else
           finish = true;
   }
    return 0;
}

