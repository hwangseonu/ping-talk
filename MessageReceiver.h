#ifndef WIFI_KILLER_PACKETRECIEVER_H
#define WIFI_KILLER_PACKETRECIEVER_H

#include <iostream>
#include <tins/tins.h>

using namespace std;
using namespace Tins;

class MessageReceiver {
private:
    Sniffer *sniffer;
    IPv4Address my_addr;
public:
    explicit MessageReceiver(string& iface, IPv4Address my_addr);
    void receive();
};


#endif //WIFI_KILLER_PACKETRECIEVER_H
