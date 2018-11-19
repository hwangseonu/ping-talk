#include "MessageReceiver.h"

MessageReceiver::MessageReceiver(string &iface, IPv4Address my_addr) {
    this->my_addr = my_addr;
//    SnifferConfiguration config;
    this->sniffer = new Sniffer(iface);
}

void MessageReceiver::receive() {
    while(true) {
        Packet pk = this->sniffer->next_packet();

        if (!pk.pdu()) continue;
        auto eth = pk.pdu()->find_pdu<EthernetII>();
        if (!eth) continue;
        auto ip = eth->find_pdu<IP>();
        if (!ip) continue;
        auto icmp = eth->find_pdu<ICMP>();
        if (!icmp) continue;
        if (icmp->type() != ICMP::ECHO_REQUEST) continue;

        if (ip->src_addr() == this->my_addr) continue;

        cout << endl << ip->src_addr() << " : ";
        for (auto iter : icmp->find_pdu<RawPDU>()->payload())cout << iter;
        cout << endl;

    }
}
