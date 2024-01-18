#include <algorithm>
#include <socket.hpp>
#include <sockaddress.hpp>
#include <string>

int main() {

    npl::socket<AF_INET, SOCK_DGRAM> sock;
    npl::sockaddress<AF_INET> srv_addr(10000);
    sock.bind(srv_addr);

    auto [buff, client] = sock.recvfrom(80);

    std::cout << "Received request from IP: " << client.host() << " port: " << client.port() << std::endl;


    std::string text(buff.begin(),buff.end());
    std::transform(text.begin(),text.end(),text.begin(),::toupper); //avevo messo begin() invece di end()... 

    npl::buffer result(text.begin(),text.end());

    sock.sendto(result, client);

    sock.close();


    return EXIT_SUCCESS;






}
