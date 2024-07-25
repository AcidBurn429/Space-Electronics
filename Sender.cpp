//
// Created by lenovo on 21.07.2024.
//

#include "Sender.h"


/*
 * Function name: getBit
 * Description: Returns the bit at a specific position in a variable
 * Parameters: d[int] = The variable where bit should be extracted.
 *             k[int] = Bit Position
 * Return Value: Bit at the position [int]
*/
int Sender::getBit(int d, int k) {
    return (d & ( 1 << k )) != 0;
}


/*
 * Function name: calculateParityBits
 * Description: Calculates the parity bits
 * Parameters: data[int] = The variable from which the parity bits should be calculated
 * Return Value: Parity Bits [int]
*/
int Sender::calculateParityBits(int data) {
    int binaryString[7];
    int out = 0;

    for (int k = 6; k>=0; k--) {
        binaryString[k] = getBit(data, k);
    }

    int parityBit1 = !((binaryString[6] + binaryString[5] + binaryString[4]) % 2);
    int parityBit2 = !((binaryString[3] + binaryString[2] + binaryString[1]) % 2);
    int parityBit3 = !((binaryString[5] + binaryString[3] + binaryString[1]) % 2);
    int parityBit4 = !((binaryString[0] + binaryString[2] + binaryString[4]) % 2);
    int parityBit5 = !((binaryString[0] + binaryString[6] + binaryString[3]) % 2);

    out = out | parityBit1 << 0;
    out = out | parityBit2 << 1;
    out = out | parityBit3 << 2;
    out = out | parityBit4 << 3;
    out = out | parityBit5 << 4;

    return  out;
}


/*
 * Function name: sendPackage
 * Description: Combines the parity bits with the message
 * Parameters: data[int] = The variable from which the parity bits should be calculated
 * Return Value: payload [int]
*/
int Sender::sendPackage(int data) {
    int sender = calculateParityBits(data);
    int sendPackage = data << 5 | sender;

    return sendPackage;
}