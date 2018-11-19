#include "MessageSender.h"

MessageSender::MessageSender(NetworkInterface iface) {
    this->iface = iface;
}

void MessageSender::send() {
    while (true) {
        string target, msg;
        cout << "input target ip address > ";
        cin >> target;
        cout << "input message > ";
        cin.ignore();
        getline(cin, msg);
        IP pk = IP(target) / ICMP() / RawPDU(msg);
        PacketSender sender(this->iface);
        sender.send(pk);
    }
}
