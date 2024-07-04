#include "player.hpp"
int* Player::getResources()
{
    return resources;
}
std::string Player::getName()
{
    return name;
}

void Player::placeCity()
{
    cities--;
    settlements++;
    points+=3;
    loseResource(3,2);
    loseResource(4,3);
}

void Player::placeSettlement()
{
    settlements--;
    points+=2;
    loseResource(0,1);
    loseResource(1,1);
    loseResource(2,1);
    loseResource(3,1);
}

void Player::placePath()
{
    pathes--;
    points++;
    loseResource(0,1);
    loseResource(1,1);
}

void Player::buyCard(int card)
{
    loseResource(2,1);
    loseResource(3,1);
    loseResource(4,1);
    addCard(card);
}

void Player::addPoints(int points)
{
    this->points+=points;
}

void Player::losePoints(int points)
{
    this->points-=points;
}

bool Player::canBuyItem(Item item)
{
    int* price = item.getPrice();
    return (resources[0] >= price[0] && resources[1] >= price[1] && resources[2] >= price[2] && resources[3] >= price[3] && resources[4] >= price[4]);
}

bool Player::hasItem(Item item)
{
    if(item.getKind() == "Settlement")
    {
        return (settlements > 0);
    }
    else if(item.getKind() == "City")
    {
        return (cities > 0);
    }
    else
    {
        return (pathes > 0);
    }
} 

void Player::setNum(int n)
{
    this->num = n;
}