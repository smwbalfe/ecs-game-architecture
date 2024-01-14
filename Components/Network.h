//
// Created by shriller44 on 10/3/22.
//

#ifndef TEST_NETWORK_H
#define TEST_NETWORK_H

#include <cstdint>
#include <string>

enum class type {LOCAL, REMOTE};

struct Network {
    std::uint32_t port;
    std::string host;
    type networkType;
};

#endif //TEST_NETWORK_H
