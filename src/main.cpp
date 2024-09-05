
#include <iostream>
#include <boost/asio.hpp>

int main()
{
	boost::asio::io_context v{};
	std::cout << "Hello server" << std::endl;
	return 0;
}
