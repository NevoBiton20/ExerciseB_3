/*  This is an abstarct class that represent an item that can be placed on the game board, such as: Setllement, City, Path.
    The price array contains how many of each resource is required to buy this item.
    The price format is: [ 'Brick' , 'Lumber' , 'Wool' , 'Grain' , 'Iron' ]
    This item belongs to the player appears in the player field: [-1(empty) - white , 0 - red , 1 - green , 2 - blue ]
*/

#include <string>
#include "player.hpp"
class Item
{
    protected:
        int player; // [-1(empty) - white , 0 - red , 1 - green , 2 - blue ]
        std::string kind; // Can be: Setllement, City, Path, MonopolCard, PathBuildCard, AbundanceYear, KnightCard, PointCard.
        int price[5]; // price format: [ 'Brick' , 'Lumber' , 'Wool' , 'Grain' , 'Iron' ]

    public:
        Item()
        {
            player=-1;
            kind = "empty";
            price[0] = 0;
            price[1] = 0;
            price[2] = 0;
            price[3] = 0;
            price[4] = 0;
        }
        std::string getKind()
        {
            return kind;
        } // returns the kind of item.

        int getPlayer()
        {
            return player;
        }// returns the owner number of this Item

        int* getPrice()
        {
            return price;
        } // returns the price of this item
};

/* A Settlement class */
class Settlement : public Item
{
    public:
        Settlement()
        {
            kind = "Settlement";
            price[0] = 1;
            price[1] = 1;
            price[2] = 1;
            price[3] = 1;
            price[4] = 0;
        }  
};

/* A city class */
class City : public Item
{
    public:
        City()
        {
            kind = "City";
            price[0] = 0;
            price[1] = 0;
            price[2] = 0;
            price[3] = 2;
            price[4] = 3;
        }
};

/* A path class */
class Path : public Item
{
    public:
        Path()
        {
            kind = "Path";
            price[0] = 1;
            price[1] = 1;
            price[2] = 0;
            price[3] = 0;
            price[4] = 0;
        }
};