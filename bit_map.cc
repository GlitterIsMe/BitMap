//
// Created by 张艺文 on 2018/12/8.
//

#include <cmath>
#include <cassert>
#include "bit_map.h"

BitMap::BitMap(size_t maplen) : len_(maplen){
    bytes_ = static_cast<size_t >(ceil(len_ / 8));
    assert(bytes_ > 0);
    bitmap_ = new unsigned char[bytes_];
    for(int i = 0; i < bytes_; i++){
        bitmap_[i] = 0;
    }
}

BitMap::~BitMap() {
    delete[] bitmap_;
}

int BitMap::GetBit() {
    for(int i = 0; i < bytes_; i++){
        unsigned char ruler = 0x01;
        for(int j = 1; j <= 8; j++){
            if(!((bitmap_[i] >> (8 - j)) & ruler)){
                return i * 8 + (j - 1);
            }
        }
    }
    return -1;
}

bool BitMap::SetBit(size_t pos, bool flag) {
    if(pos > len_){
        return false;
    }

    unsigned char ruler = 0x80;
    int byte_pos = pos / 8;
    int bit_pos = pos % 8;

    if(flag){
        // 有符号数会补符号位
        ruler >>= bit_pos;
        bitmap_[byte_pos] |= ruler;
    }else{
        ruler >>= bit_pos;
        ruler ^= 0xFF;
        bitmap_[byte_pos] &= ruler;
    }

    return true;
}

bool BitMap::GetAndSet() {
    int get = GetBit();
    return SetBit(get, true);
}

void BitMap::Reset() {
    for(int i = 0; i < bytes_; i++){
        bitmap_[i] = 0;
    }
}

void BitMap::Print() {
    for(int i = 0; i < len_; i++){
        int byte_pos = i / 8;
        int bit_pos = i % 8;

        unsigned char ruler = 0x01;
        printf("%d[%d] ", i, (bitmap_[byte_pos] >> (7 - bit_pos)) & ruler);
    }
    printf("\n");
}
