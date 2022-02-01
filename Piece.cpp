#include <iostream>
#include <fstream>
#include "Header.h"


    enum class Type : uint8_my
    {
        EMPTY = 0b00000,
        PAWN = 0b10000,   //символ в кодировке ASCII p без первых двух цифр
        KNIGHT = 0b01110, //символ n
        BISHOP = 0b00010, //символ b
        ROOK = 0b10010,   //символ r
        QUEEN = 0b10001,  //символ q
        KING = 0b01011,   //символ k
        MASK = 0b00011111
    };

    enum class Color : uint8_my
    {
        BLACK = 0b0,
        WHITE = 0b1,
        MASK = 0b01000000
    };

    enum class Movement : uint8_my
    {
        MOVED = 0b0,
        DIDNOTMOVE = 0b1,
        MASK = 0b10000010
    };

//все что выше работает"