#include "util.hpp"
#include <sstream>
#include <fmt/core.h>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}   

IpAddress ParseIpAddress(const std::string& address) {
    IpAddress result;
    auto bytes = Split(address, '.');

    if (bytes.size() != 4) {
        throw std::runtime_error("Malformed IP address");
    }

    std::get<0>(result) = static_cast<uint8_t>(std::stoi(bytes[0]));
    std::get<1>(result) = static_cast<uint8_t>(std::stoi(bytes[1]));
    std::get<2>(result) = static_cast<uint8_t>(std::stoi(bytes[2]));
    std::get<3>(result) = static_cast<uint8_t>(std::stoi(bytes[3]));

    return result;
}

void PrintIpAddress(const IpAddress& addr) {
    fmt::print("{0}.{1}.{2}.{3}\n", std::get<0>(addr), std::get<1>(addr), std::get<2>(addr), std::get<3>(addr));
}