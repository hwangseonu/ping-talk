#include <iostream>
#include <vector>
#include <thread>
#include <tins/tins.h>
#include "MessageSender.h"
#include "MessageReceiver.h"

using namespace Tins;

vector<NetworkInterface> ifaces = NetworkInterface::all();

void printIfaces() {
    int i = 1;
    for (auto iter : ifaces) {
        cout << i << ". " << iter.name() << endl;
        i++;
    }
}

int selectIface() {
    int i;
    cout << "select network interface > ";
    cin >> i;
    return i - 1;
}

int main() {
    printIfaces();
    NetworkInterface iface = ifaces[selectIface()];
    string name = iface.name();

    auto receiver = new MessageReceiver(name, iface.addresses().ip_addr);
    auto sender = new MessageSender(name);

    auto th1 = thread(&MessageReceiver::receive, receiver);
    auto th2 = thread(&MessageSender::send, sender);

    th1.join();
    th2.join();

    return 0;
}