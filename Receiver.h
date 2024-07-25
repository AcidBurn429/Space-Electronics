//
// Created by lenovo on 21.07.2024.
//

#include "Sender.h"

#ifndef HAMMINGCODEASCII_RECEIVER_H
#define HAMMINGCODEASCII_RECEIVER_H


class Receiver: Sender {
private:
    int flipBit(int data, int pos);

public:
    int recvPackage(int data);
};


#endif //HAMMINGCODEASCII_RECEIVER_H
