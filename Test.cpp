#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "doctest.h"
#include "board.hpp"
using namespace std;


TEST_CASE("game rules")
{
    Catan catan(Player("Amit"), Player("Yossi"), Player("Dana"),2);
    CHECK(catan.getPlayers()[0].canBuyItem(Settlement()));
    CHECK(catan.getPlayers()[1].canBuyItem(Settlement()));
    CHECK(catan.getPlayers()[2].canBuyItem(Settlement()));
    CHECK(catan.getPlayers()[0].canBuyItem(Path()));
    CHECK(catan.getPlayers()[1].canBuyItem(Path()));
    CHECK(catan.getPlayers()[2].canBuyItem(Path()));
    Board board;

    vector<int> temp = board.resourcesByPlace(12,6);
    CHECK(temp[0]==0);
    CHECK(temp[1]==0);
    CHECK(temp[2]==1);
    CHECK(temp[3]==1);
    CHECK(temp[4]==0);

    temp = board.resourcesByPlace(12,6,5);
    CHECK(temp[0]==0);
    CHECK(temp[1]==0);
    CHECK(temp[2]==1);
    CHECK(temp[3]==0);
    CHECK(temp[4]==0);

    CHECK(true == board.isNextToTile(16,4,11));
    CHECK(true == board.isNextToTile(16,4,6));

    CHECK(true == board.isNextToTile(12,4,4));
    CHECK(true == board.isNextToTile(14,4,3));

    CHECK(!catan.getPlayers()[0].canBuyItem(City()));
    CHECK(!catan.getPlayers()[1].canBuyItem(City()));
    CHECK(!catan.getPlayers()[2].canBuyItem(City()));
    int a[5] = {4,4,2,2,0};
    CHECK(catan.getPlayers()[0].canAfford(a));
    int b[5] = {0,4,2,2,0};
    catan.getPlayers()[0].loseResource(0,4);
    catan.getPlayers()[1].loseResource(0,4);
    catan.getPlayers()[2].loseResource(0,4);
    CHECK(catan.getPlayers()[0].canAfford(b));

    CHECK(!catan.getPlayers()[0].canBuyItem(Settlement()));
    CHECK(!catan.getPlayers()[1].canBuyItem(Settlement()));
    CHECK(!catan.getPlayers()[2].canBuyItem(Settlement()));
    CHECK(!catan.getPlayers()[0].canBuyItem(Path()));
    CHECK(!catan.getPlayers()[1].canBuyItem(Path()));
    CHECK(!catan.getPlayers()[2].canBuyItem(Path()));
    CHECK(!catan.getPlayers()[0].canBuyItem(City()));
    CHECK(!catan.getPlayers()[1].canBuyItem(City()));
    CHECK(!catan.getPlayers()[2].canBuyItem(City()));
    catan.getPlayers()[0].addPoints(10);
    CHECK(catan.getWinner() == catan.getPlayers()[0].getNum());
}