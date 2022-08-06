#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fmt/core.h>
#include <sstream>
#include <algorithm>

#include "util.hpp"


int main()
{
    try {
        std::string line;
        std::vector<IpAddress> ip_adresses;

        while (std::getline(std::cin, line)) {
            auto tokens = Split(line, '\t');
            auto address_token = tokens.at(0);

            auto ip_address = ParseIpAddress(address_token);
            ip_adresses.push_back(ip_address);
        }

        std::sort(ip_adresses.begin(), ip_adresses.end());

        for (auto addr : ip_adresses) {
            PrintIpAddress(addr);
        }

        // with first byte = 1
        for (auto addr : ip_adresses) {
            if (std::get<0>(addr) == 1) {
                PrintIpAddress(addr);
            }
        }

        for (auto addr : ip_adresses) {
            if (std::get<0>(addr) == 46 && std::get<1>(addr) == 70) {
                PrintIpAddress(addr);
            }
        }

        for (auto addr : ip_adresses) {
            if (std::get<0>(addr) == 46 ||
                std::get<1>(addr) == 46 ||
                std::get<2>(addr) == 46 ||
                std::get<3>(addr) == 46
            ) {
                PrintIpAddress(addr);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
