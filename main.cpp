#include <iostream>
#include "bit_map.h"
int main() {
    BitMap bitmap(16);
    for(int i = 0; i < 16; i++){
        bitmap.SetBit(i, i % 2);
    }
    bitmap.Print();

    for (int i = 0; i < 16; ++i) {
        //printf("%d ", bitmap.GetBit());
        bitmap.GetAndSet();
        bitmap.Print();
    }
    printf("\n");
    return 0;
}