//
// Created by lenovo on 21.07.2024.
//

#ifndef HAMMINGCODEASCII_SENDER_H
#define HAMMINGCODEASCII_SENDER_H


class Sender {
protected:
    int getBit(int d, int k);
    int calculateParityBits(int data);

public:
    int sendPackage(int data);
};


#endif //HAMMINGCODEASCII_SENDER_H
