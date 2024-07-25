//
// Created by lenovo on 21.07.2024.
//

#include "Receiver.h"


/*
 * Function name: flipBit
 * Description: Flips a bit at a specific location
 * Parameters: data[int] = The variable where the bit flip should happen
 *             pos[int] = The position where the bit flip should happen
 * Return Value: data variable with the flipped bit [int]
*/
int Receiver::flipBit(int data, int pos) {
    int out = data ^ (1 << pos);

    return out;
}


/*
 * Function name: recvPackage
 * Description: Checks if the received message was correct by comparing it with the parity bits
 * Parameters: data[int] = The received payload
 * Return Value: Received message [int]
*/
int Receiver::recvPackage(int data) {
    int originalParityBits = data & 0b000000000011111;
    int originalData = (data & 0b111111111100000) >> 5;
    int out = originalData;

    // Calculate Parity Bits with data
    int parityBits = calculateParityBits(originalData);
    int difference = originalParityBits - parityBits;

    if(difference == 0) {
        return originalData;
    }

    // Check for x7
    if(getBit(difference, 0) != 0 && getBit(difference, 4) != 0) {
        // Error within x7
        out = flipBit(out, 0);
    }

    // Check for x6
    if(getBit(difference, 0) != 0 && getBit(difference, 2) != 0) {
        // Error within x6
        out = flipBit(out, 1);
    }

    // Check for x5
    if(getBit(difference, 0) != 0 && getBit(difference, 3) != 0) {
        // Error within x5
        out = flipBit(out, 2);
    }

    // Check for x4
    if(getBit(difference, 1) != 0 && getBit(difference, 2) != 0) {
        // Error within x4
        out = flipBit(out, 3);
    }

    // Check for x3
    if(getBit(difference, 1) != 0 && getBit(difference, 3) != 0) {
        // Error within x3
        out = flipBit(out, 4);
    }

    // Check for x2
    if(getBit(difference, 1) != 0 && getBit(difference, 1) != 0) {
        // Error within x2
        out = flipBit(out, 5);
    }

    // Check for x1
    if(getBit(difference, 3) != 0 && getBit(difference, 4) != 0) {
        // Error within x1
        out = flipBit(out, 6);
    }

    return out;
}