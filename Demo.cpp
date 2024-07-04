/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;

int main()
{
    Catan catan(Player("Amit"), Player("Yossi"), Player("Dana"),0);
    Player p1 = catan.getPlayers()[0];
    Player p2 = catan.getPlayers()[1];
    Player p3 = catan.getPlayers()[2];

    p1.addResource(0,4);
    p1.addResource(1,4);
    p1.addResource(2,2);
    p1.addResource(3,2);

    p2.addResource(0,4);
    p2.addResource(1,4);
    p2.addResource(2,2);
    p2.addResource(3,2);

    p3.addResource(0,4);
    p3.addResource(1,4);
    p3.addResource(2,2);
    p3.addResource(3,2);
 
    // Starting of the game. Every player places two settlements and two roads.
    catan.placeSettlement(p1.getNum());
    catan.placePath(p1.getNum());
    
    catan.placeSettlement(p1.getNum());
    catan.placePath(p1.getNum()); 

    catan.printBoard();
    catan.placeSettlement(p2.getNum()); 
    catan.placeSettlement(p2.getNum());
    catan.placePath(p2.getNum());
    catan.placePath(p2.getNum());
    catan.printBoard();

    catan.placeSettlement(p3.getNum());
    catan.placePath(p3.getNum());
    catan.placeSettlement(p3.getNum());
    catan.placePath(p3.getNum());
    catan.printBoard();
    catan.giveResources(-1);

    catan.rollDice(p1.getNum());

    catan.placePath(p1.getNum());

    catan.rollDice(p2.getNum());

    catan.rollDice(p3.getNum());
    int seller[5] = {0,1,0,0,0};
    int buyer[5] =  {1,0,0,0,0};
    p1 = catan.getPlayers()[0];
    p2 = catan.getPlayers()[1];
    p3 = catan.getPlayers()[2];
    catan.trade(p1.getNum(),p2.getNum(),seller,buyer); // p1 trades 1 wood for 1 brick with p2.
    catan.passTurn();

    catan.rollDice(p2.getNum());
    catan.buyCard(p2.getNum()); // p2 buys a development card. 
    catan.passTurn();            // p2 ends his turn.

    catan.printBoard();
    catan.printWinner(); // Should print None because no player reached 10 points.
}