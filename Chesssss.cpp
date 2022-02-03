#include <iostream>
#include <fstream>
#include <stdint.h>
#include "Header.h"
#include "Piece.cpp"
#include <vector>

void copy(uint8_my to[], uint8_my from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') i++;
}

uint8_my startingPosition[65];
uint8_my Position1[65];
int main()
{

   
    //uint_my board; // получаем значения с поля.

 
    
    /*uint8_my type = startingPosition[15];
    uint8_my blackType = 0b01000000;
    uint8_my whiteType = 0b01100000;
    //проверка Enum'ов
    std::cout << static_cast<int>(type & static_cast<uint8_my>(Color::MASK)) << std::endl;*/

    /*
    uint16_t d = startingPosition[63] & static_cast<uint8_my>(Type::MASK);
    std::cout << d << std::endl;*/
    
    uint8_my ourColor = static_cast<uint8_my>(Color::WHITE); // (~ourColor) & Color::MASK

    uint8_my major[65];
    //uint8_my minor[65];

    copy(major, Position1);

    //major = startingPosition;

    std::cout << major << std::endl;
    
    std::vector <int8_my> hits_king;
    Status status = Status::CONTINUE;
    std::vector <int8_my> allSteps; //числа в нем - номера полей ( i на major); 

    for (int8_my i = 0; i < 64; ++i) // i -  поле на major
    {
        
        if ((major[i] & static_cast<uint8_my>(Type::MASK)) == 0)
            continue;
        if ((major[i] & static_cast<uint8_my>(Color::MASK)) == (~(ourColor & static_cast<uint8_my>(Color::MASK)))
        {
            if ((major[i] & static_cast<uint8_my>(Type::MASK)) == static_cast<uint8_my>(Type::ROOK))
            {
                allSteps.push_back(1);
                allSteps.push_back(2);
                allSteps.push_back(3);
                allSteps.push_back(4);
                allSteps.push_back(5);
                allSteps.push_back(6);
                allSteps.push_back(7);
                allSteps.push_back(8);
                allSteps.push_back(16);
            }
            // generate all moves (нужно обнулить всеХоды)
            //есди ходов нет 
            for (int8_my step = 0; step < 30; ++step)
            {
                int8_my x = allSteps[step]; // отдельная переменная для хода
                if ((major[x] & static_cast<uint8_my>(Type::MASK)) == static_cast<uint8_my>(Type::KING))
                {
                    status = Status::CHECK;
                    hits_king.push_back(i); //поле фигуры, которую рассматриваем
                }

            }
        }

    }
    std::cout << "Status" << static_cast<int>(status) << std::endl;
    std::cout << "hits_king:" << hits_king[0] << std::endl;
    
    return 0;
    
}
