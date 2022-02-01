#include <iostream>
#include <fstream>
#include "Header.h"


int main()
{
#include "EnumClass.cpp"
   
    uint_my board; // получаем значения с поля.

    char startingMajor[65] =
        "RNBQKBNR"
        "PPPPPPPP"
        "        "
        "        "
        "        "
        "        "
        "pppppppp"
        "rnbqkbnr"
        ;
    
    /*Type type = Type::QUEEN;
    int8_my blackType = 0b1000000;
    int8_my whiteType = 0b1100000;
    //проверка Enum'ов
    std::cout << static_cast<char>(static_cast<int8_t>(type) | blackType) << std::endl; */

    int d = static_cast<uint_my>(startingMajor[63]) & static_cast<uint_my>(Type::MASK);
    std::cout << d << std::endl;
    
    return 0;
    
}
