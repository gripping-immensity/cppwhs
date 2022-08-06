#pragma once

#include <tuple>
#include <string>
#include <vector>

using IpAddress = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

std::vector<std::string> Split(const std::string& str, char delimiter);
IpAddress ParseIpAddress(const std::string& address);
void PrintIpAddress(const IpAddress& addr);
