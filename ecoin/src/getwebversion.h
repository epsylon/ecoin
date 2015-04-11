#include <iostream>
#include <boost/asio/ip/tcp.hpp>

#include "version.h"

static const std::string	VERSION_HTTP_SERVER	=	"myecoin.net";
static const std::string	VERSION_URL		=	"/downloads/version.html";

int getWebVersion ()
{

        boost::asio::ip::tcp::iostream webStream;
        // add a timeout
        webStream.expires_from_now(boost::posix_time::seconds(15));
        webStream.connect(VERSION_HTTP_SERVER, "http");
        if(!webStream)
        {
                printf("getWebVersion: Unable to connect to %s   Reason %s\n",(char*)VERSION_HTTP_SERVER.c_str(),(char*)webStream.error().message().c_str());
                return 1;
        }
        webStream << "GET " << VERSION_URL <<" HTTP/1.\r\n";
        webStream << "Host: " << VERSION_HTTP_SERVER << "\r\n";
        webStream << "Accept: */*\r\n"; /**/

        webStream << "Connection: close\r\n\r\n";

        std::string http_version;
        webStream >> http_version;
        unsigned int status_code;
        webStream >> status_code;
        std::string status_message;
        std::getline(webStream, status_message);
        if (!webStream || http_version.substr(0,5)  != "HTTP/")
        {
                printf("getWebVersion: Invalid response\n");
                return 2;
        }
        if (status_code != 200)
        {
                printf("getWebVersion: Response returned with status code %d\n",status_code);
                return status_code;
        }

        std::string header;
        while(std::getline(webStream, header) && header != "\r")
        {//grind though the headers I am sure there is a better way
        }

        std::ostringstream clientVersion;
        clientVersion << webStream.rdbuf();

        unsigned int returnVer;
        returnVer = atoi((char*)clientVersion.str().c_str());
        return returnVer;
}

