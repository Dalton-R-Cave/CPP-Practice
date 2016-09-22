#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <sstream>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, int argv[] )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  int dataLength;
		  std::string toSend;
		  new_sock >> data;
		  std::cout << "received data from client!\n";
		  std::cout << "\n";
		  std::cout << "Client says \"" << data << "\\n"; 
		  dataLength = strlen(data.c_str());
		  std::stringstream stream;
		  stream << dataLength;
		  toSend = stream.str();
		  new_sock << toSend;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
