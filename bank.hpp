/*nevobiton0@gmail.com
This is the bank class which used to make all the operations that the bank needs to do such as:
    Random card purchase or bank resources ask */
#ifndef BANK_HPP
#define BANK_HPP
#include <random>
#include "player.hpp"
#include <iostream>
class Bank
{
    private:
        int cards[5];
    public:
        Bank()
        {
            cards[0] = 2;
            cards[1] = 2;
            cards[2] = 2;
            cards[3] = 3;
            cards[4] = 4;
        }
        int askCard(Player player);
};
#endif
