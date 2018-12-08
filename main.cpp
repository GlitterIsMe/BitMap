#include <iostream>
#include "bit_map.h"
int main() {
    BitMap bitmap(16);
    for(int i = 0; i < 16; i++){
        bitmap.SetBit(i, i % 2);
    }
    bitmap.Print();
    return 0;
}