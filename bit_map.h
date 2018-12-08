//
// Created by 张艺文 on 2018/12/8.
//

#pragma once

#include <cstdio>

class BitMap{
public:
    BitMap(size_t maplen);

    ~BitMap();

    int GetBit();

    bool SetBit(size_t pos, bool flag);

    bool GetAndSet();

    void Reset();

    void Print();

    // Resize;

private:
    size_t len_;
    size_t bytes_;
    unsigned char* bitmap_;
};
