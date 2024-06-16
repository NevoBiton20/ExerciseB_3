#ifndef PLAYER_HPP
#define PLAYER_HPP

/*  This class represent a player, here you can find all the resources and cards a player has, all the assets, and current amount of points in the round 
    The resources array format is : [ 'Brick' , 'Lumber' , 'Wool' , 'Grain' , 'Iron' ]
    The cards array format is  [ 'Monopol' , 'Path Build' , 'Year of plenty' , 'knight' , 'Victory Point' ] */
#include <string>
#include <iostream>
#include <memory>
#include "item.hpp"
class Player
{
    private:
        std::string name;
        int points;
        int resources[5];
        int cards[5];
        int settlements;
        int cities;
        int pathes;

    public:
        Player(std::string Pname)
        {
            name = Pname;
            resources[0] = 0;
            resources[1] = 0;
            resources[2] = 0;
            resources[3] = 0;
            resources[4] = 0;

            cards[0] = 0;
            cards[1] = 0;
            cards[2] = 0;
            cards[3] = 0;
            cards[4] = 0;

            settlements = 5;
            cities = 4;
            pathes = 15;
        }
        std::string getName();
        int* getResources();
        void placeCity();
        void placeSettlement();
        void placePath();
        void addPoints(int points);
        bool canBuyItem(std::unique_ptr<Item> item);
        bool hasItem(std::unique_ptr<Item> item);

        void addResource(int resource, int amount)
        {
            this->resources[resource] += amount;
        }
        void addCard(int card)
        {
            cards[card]++;
        }
};
#endif