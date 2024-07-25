#include <iostream>

#include "Sender.h"
#include "Receiver.h"

using namespace std;



int main() {
    int data = 0x41;

    Sender sender = Sender();

    int sent = sender.sendPackage(data);

    Receiver recv = Receiver();

    recv.recvPackage(sent);

    return 0;
}

