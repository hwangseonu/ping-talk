#ifndef WIFI_KILLER_PACKETSENDER_H
#define WIFI_KILLER_PACKETSENDER_H

#include <tins/tins.h>
#include <thread>
#include <iostream>

using namespace std;
using namespace Tins;

class MessageSender {
private:
    NetworkInterface iface;
public:
    explicit MessageSender(NetworkInterface iface);
    void send();
};


#endif //WIFI_KILLER_PACKETSENDER_H
