/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main
*/

#include <gtest/gtest.h>
#include "../server/Server.hpp"

int main() {
    ServerClass server;
    std::thread([&server]() { server.loop(); }).detach();
    server.createInstance("rType");
    ::testing::InitGoogleTest();
    int ret = RUN_ALL_TESTS();

    return ret;
}
