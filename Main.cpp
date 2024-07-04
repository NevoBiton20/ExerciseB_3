#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;


int main()
{
    Catan catan(Player("Amit"), Player("Yossi"), Player("Dana"),1);
    catan.play();
    return 0;
}