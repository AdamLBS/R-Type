/*
** EPITECH PROJECT, 2023
** Instance.cpp
** File description:
** Instance
*/

#include "Instance.hpp"

Instance::Instance(int id) : _threadPool(1), _port((int)(4210 + id)), _udpServer((int)(4210 + id)), _id(id)
{
  _udpServer.setInstance(this);
  // use _serverRef to send the UDP server port to the client
}

Instance::~Instance()
{
}