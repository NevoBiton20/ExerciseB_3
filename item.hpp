/*nevobiton0@gmail.com
This is an abstarct class that represent an item that can be placed on the game board, such as: Setllement, City, Path.
    The price array contains how many of each resource is required to buy this item.
    The price format is: [ 'Brick' , 'Lumber' , 'Wool' , 'Grain' , 'Iron' ]
    This item belongs to the player appears in the player field: [-1(empty) - white , 0 - red , 1 - green , 2 - blue ]
*/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
class Item
{
    protected:
        int player; // [-1(empty) - white , 0 - red , 1 - green , 2 - blue ]
        std::string kind; // Can be: Setllement, City, Path, Card.
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
        std::string getKind(); // returns the kind of item.

        int getPlayer();// returns the owner number of this Item

        int* getPrice();// returns the price of this item
};

/* A Settlement class */
class Settlement : public Item
{
    public:
        Settlement()
        {
            player=-1;
            kind = "Settlement";
            price[0] = 1;
            price[1] = 1;
            price[2] = 1;
            price[3] = 1;
            price[4] = 0;
        }  
        Settlement(int p)
        {
            player = p;
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
            player=-1;
            kind = "City";
            price[0] = 0;
            price[1] = 0;
            price[2] = 0;
            price[3] = 2;
            price[4] = 3;
        }
        City(int p)
        {
            player = p;
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
            player=-1;
            kind = "Path";
            price[0] = 1;
            price[1] = 1;
            price[2] = 0;
            price[3] = 0;
            price[4] = 0;
        }
        Path(int p)
        {
            player = p;
            kind = "Path";
            price[0] = 1;
            price[1] = 1;
            price[2] = 0;
            price[3] = 0;
            price[4] = 0;
        }
};

class Card : public Item
{
    public:
        Card()
        {
            player=-1;
            kind = "Card";
            price[0] = 0;
            price[1] = 0;
            price[2] = 1;
            price[3] = 1;
            price[4] = 1;
        }
};
#endif
