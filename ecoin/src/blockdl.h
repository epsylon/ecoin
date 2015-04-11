#ifndef BLOCKDL_H
#define BLOCKDL_H

#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <version.h>
#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/asio/ip/tcp.hpp>
#include "ui_interface.h"

#ifdef QT_GUI
#include <QSettings>
#include "optionsmodel.h"
#endif



static const std::string	HTTP_SERVER	=	"speed.myecoin.net";
static const std::string	URL_PATH	=	"/ecoin/";
static const std::string	FILELIST_NAME	=	"filelist.lst";


using namespace std;
using namespace boost;
using namespace boost::asio;
using boost::asio::ip::tcp;

extern void removeBlockchain()
{// basically a copy from txdb-leveldb.cpp init_blockindex

        boost::filesystem::path directory = GetDataDir() / "txleveldb";
        boost::filesystem::remove_all(directory);
        boost::filesystem::path dbdirectory = GetDataDir() / "database";// this for different version of client
        boost::filesystem::remove_all(dbdirectory);

        unsigned int nFile = 1;
        while (true)
        {
                boost::filesystem::path strBlockFile = GetDataDir() / strprintf("blk%04u.dat", nFile);
                if(!boost::filesystem::exists( strBlockFile))
                        break;
                boost::filesystem::remove(strBlockFile);
                nFile++;
        }

        boost::filesystem::create_directory(GetDataDir() / "txleveldb");


}


int downloadFile(	const char * getFilename, //what were going to save the files as
			const std::string& serverName,
			const std::string& getCommand,
			int currentFileNumber,
			int totalFileNumber)
{
	std::string errorOut;
  	boost::asio::io_service io_service;

	// Get a list of endpoints corresponding to the server name.
	tcp::resolver resolver(io_service);
	tcp::resolver::query query(serverName, "http");
	tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	tcp::resolver::iterator end;

  	// Try each endpoint until we successfully establish a connection.
  	tcp::socket socket(io_service);
  	boost::system::error_code error = boost::asio::error::host_not_found;
  	while (error && endpoint_iterator != end)
  	{
		socket.close();
		try {
			socket.connect(*endpoint_iterator++, error);
		}
		catch (boost::system::system_error& e) 
		{
			errorOut = "downloadFile: connection error";
			errorOut +=  e.what();
			errorOut += "\n";
			printf("%s",(char*)errorOut.c_str());
			return 3;
		}
	}

	boost::asio::streambuf request;
	std::ostream request_stream(&request);

	request_stream << "GET " << getCommand << " HTTP/1.0\r\n";
	request_stream << "Host: " << serverName << "\r\n";
	request_stream << "Accept: */*\r\n";
	request_stream << "Cache-Control: no-cache\r\n";
	request_stream << "Connection: close\r\n\r\n";


	// Send the request.
	try {
		boost::asio::write(socket, request);
	}
	catch (boost::system::system_error& e)
	{
			errorOut = "downloadFile: connection error"; 
                        errorOut +=  e.what();
                        errorOut += "\n";
                        printf("%s",(char*)errorOut.c_str());
                        return 3;
	}

	// Read the response status line.
	boost::asio::streambuf response;
	boost::asio::read_until(socket, response, "\r\n");

	// Check that response is OK.
	std::istream response_stream(&response);
	std::string http_version;
	response_stream >> http_version;
	unsigned int status_code;
	response_stream >> status_code;
	if (http_version.substr(0,5)  != "HTTP/")
        {
                printf("Invalid response\n");
                return 2;
        }
        if (status_code != 200)
        {
                printf("Response returned with status code %d\n",status_code);
		return status_code;
        }

	std::string status_message;
	std::getline(response_stream, status_message);


	// Read the response headers, which are terminated by a blank line.
	boost::asio::read_until(socket, response, "\r\n\r\n");

	// Process the response headers.
	std::string header;
        int64 startTime;
	unsigned int fileSize=0;
        unsigned int currentDLSize=1;
	float currentPer;
	char mOut[256];
	unsigned int progress;
        unsigned int dataRate;
	filesystem::path workingDir = GetDataDir();
	std::string workingPath = workingDir.string();
	workingPath += "/";
	workingPath += getFilename;
        startTime = GetTimeMillis();
	printf("Downloading File From: %s%s\n",(char*)serverName.c_str(),(char*)getCommand.c_str());
	printf("Downloading File to: %s (%d of %d)\n",(char*)workingPath.c_str(),currentFileNumber,totalFileNumber);

	std::ofstream outFile((char*)workingPath.c_str(), std::ofstream::out | std::ofstream::binary);
	while (std::getline(response_stream, header) && header != "\r")
	{
		if(header.find("Content-Length") != std::string::npos)
		{
			fileSize = atoi(header.substr(16).c_str());
		}
	}
	// Write whatever content we already have to output.
	if (response.size() > 0)
	{
		outFile << &response;
	}
	// Read until EOF, writing data to output as we go.
	while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), error))
	{
		outFile << &response;
		currentDLSize =  outFile.tellp();
		currentPer = ((float)currentDLSize / fileSize) * 100;
		progress++;
		if (progress >= 128) //rate limit gui update of progress
		{
			progress = 0;
                        dataRate = (int)(currentDLSize / (GetTimeMillis() - startTime ));  
                        sprintf (mOut , "Downloading:%s (%d of %d) %dM of %dM %d%% %dKB/s",getFilename,currentFileNumber,totalFileNumber,(currentDLSize / (1024*1024)),(fileSize / (1024*1024)),(int)currentPer,dataRate);
			#ifdef QT_GUI
			uiInterface.InitMessage(mOut);
			#endif
		}
	}
outFile.close();
return 0;
}

void processFilelist()
{
   filesystem::path workingDir = GetDataDir();
   std::string workingPath = workingDir.string();
   std::string fileList = workingPath;
   workingPath += "/";
   fileList += "/filelist.lst";
	std::string remoteFile = URL_PATH;
        string myArray[256];
        int i=0;
        using namespace std;
        ifstream file((char*)fileList.c_str());
        if(file.is_open())
        {
                while(!file.eof())
                {
                        file >> myArray[i];
                        ++i;
                }
        }
	printf("%d Files to download\n",(i-1));
        for(int a=0;a<(i-1);++a)
        {
workingPath += myArray[a];
remoteFile += myArray[a];
downloadFile((char*)myArray[a].c_str(),HTTP_SERVER,(char*)remoteFile.c_str(),(a+1),(i-1));
remoteFile = URL_PATH;
        }

}

int firstRunCheck ()
{
// check to see if online update has been defined if not define it
#ifdef QT_GUI
OptionsModel om;
QSettings settings;
if (!settings.contains("fCheckOnlineUpdate"))
	settings.setValue("fCheckOnlineUpdate",true);

#endif

/* removed this to stop the automatic on first run seemed like a good idea at the time
//check to see if both items exist if not delete them and download it directly
unsigned int nFile = 1;
filesystem::path directory = GetDataDir() / "txleveldb";
filesystem::path strBlockFile = GetDataDir() / strprintf("blk%04u.dat", nFile);
if (!filesystem::exists(directory) || !filesystem::exists(strBlockFile))
{
	printf("Missing or incomplete blockchain files detected, re-download started\n");
	return 0;
	} else {
	return 1;
}
*/

return 1;
}


void downloadAndReplaceBlockchain()
{
        boost::filesystem::path fileList = GetDataDir() / "filelist.lst";
        boost::filesystem::remove(fileList);

       int fileStatus = downloadFile("filelist.lst",HTTP_SERVER,"/cgi-bin/filelist.pl",1,1);
        if(fileStatus == 0)
        {
                int64 sDownload;
                sDownload = GetTimeMillis();
		removeBlockchain();     //this removes all the block chain from .ecoin dir
                                        //blk????.dat and txleveldb dir
                processFilelist();      //reads the filelist and downloads all files in the list
                //        SoftSetBoolArg("-checkblocks", 0);// Once were done check entire chain
                SoftSetBoolArg("-rescan", true);// Once were done rescan entire chain for tx
                printf("Download      %15"PRI64d"ms\n", GetTimeMillis() - sDownload);
        }
        else if(fileStatus == 404)
        {
                printf("Downloading filelist failed\n");
                cout << "Downloading filelist failed\n";
		uiInterface.InitMessage("Remote file not found!");
		Sleep(5000);
        }
        else if(fileStatus == 303)
        {
                printf("Server update in progress try again later\n");
                cout << "Server update in progress try again later" << endl;
        	uiInterface.InitMessage("Server update in progress try again later");
		Sleep(5000);
	}
	else if(fileStatus == 304)
	{
		printf("Number of downloads exceded for day\n");
		cout << "Number of downloads exceded for day" << endl;
		uiInterface.InitMessage("Number of downloads exceded for day");
		Sleep(5000);
	}
}

#endif
