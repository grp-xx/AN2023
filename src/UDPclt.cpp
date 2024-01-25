#include <socket.hpp>
#include <sockaddress.hpp>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <server> <port>" << std::endl;
        return (1);
    }

    npl::sockaddress<AF_INET> srvaddr(argv[1],std::atoi(argv[2]));
    npl::socket<AF_INET,SOCK_DGRAM> sock;

    std::string line;

    std::getline(std::cin, line);

    npl::buffer buff(line.begin(),line.end());
    sock.sendto(buff,srvaddr);

    auto [buf, srv] = sock.recvfrom(80);

    std::cout << std::string(buf.begin(),buf.end()) << std::endl;

    sock.close();    

    return EXIT_SUCCESS;
}