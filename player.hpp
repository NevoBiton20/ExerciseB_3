#include "item.hpp"
#ifndef PLAYER_HPP
#define PLAYER_HPP

/*  This class represent a player, here you can find all the resources and cards a player has, all the assets, and current amount of points in the round 
    The resources array format is : [ 'Brick' , 'Lumber' , 'Wool' , 'Grain' , 'Iron' ]
    The cards array format is  [ 'Monopol' , 'Path Build' , 'Year of plenty' , 'Knight' , 'Victory Point' ] */

#include <string>
#include <iostream>
#include <memory>
class Player
{
    private:
        std::string name;
        int num;
        int points;
        int resources[5];
        int cards[5];
        int settlements;
        int cities;
        int pathes;

    public:
        Player(std::string Pname)
        {
            num=-1;
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
            points = 0;
            settlements = 7;
            cities = 4;
            pathes = 17;
        }
        std::string getName();
        int* getCards()
        {
            return cards;
        }
        int* getResources();
        void placeCity();
        void placeSettlement();
        void placePath();
        void setNum(int n);
        void addPoints(int points);
        void losePoints(int points);
        bool canBuyItem(Item item);
        bool hasItem(Item item);
        void buyCard(int card);

        bool canAfford(int set[5])
        {
            return !(set[0] > resources[0]) || (set[1] > resources[1]) || (set[2] > resources[2]) || (set[3] > resources[3]) || (set[4] > resources[4]); 
        }

        int getPoints()
        {
            return points;
        }

        int getNum()
        {
            return num;
        }
        void addResource(int resource, int amount)
        {
            this->resources[resource] += amount;
        }

        void loseResource(int resource, int amount)
        {
            this->resources[resource] -= amount;
        }

        void addCard(int card)
        {
            cards[card]++;
            if(card == 4)
            {
                addPoints(1);
            }
            else if(card==3)
            {
                if(cards[3]==3)
                {
                    std::cout << name << ", You have just gathered all 3 knights cards! You own the biggest army card! (+2 points)"<<std::endl;
                    addPoints(2);
                }
            }
        }

        bool hasCard(int card)
        {
            return (cards[card]>0);
        }
};
#endif