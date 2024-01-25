#include <socket.hpp>
#include <sockaddress.hpp>
#include <string>
#include <sys/socket.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <server> <port>" << std::endl;
        return (1);
    }

    npl::sockaddress<AF_INET> srvaddr(argv[1],std::atoi(argv[2]));
    npl::socket<AF_INET,SOCK_STREAM> sock;

    sock.connect(srvaddr);


    std::string line;

    std::getline(std::cin, line);

    npl::buffer buff(line.begin(),line.end());


    sock.write(buff);

    npl::buffer buf = sock.read(80);

    std::cout << std::string(buf.begin(),buf.end()) << std::endl;

    sock.close();    

    return EXIT_SUCCESS;
}