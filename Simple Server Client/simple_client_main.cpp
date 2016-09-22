#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main ( int argc, int argv[] )
{
  try
    {

      ClientSocket client_socket ( "localhost", 30000 );

      std::string number;
      std::string serverMessage;

      try
	{
	     std::cout << "Please enter a message to send to the server!\n";
	     std:: cin >> serverMessage;
	  client_socket << serverMessage;
	  client_socket >> number;
	}
      catch ( SocketException& ) {}

      std::cout << "Your message was " << number << " characters long!\n";

    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}
