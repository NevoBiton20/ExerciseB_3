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
    points++;

}

void Player::placeSettlement()
{
    settlements--;
    points++;
}

void Player::placePath()
{
    pathes--;
}

void Player::addPoints(int points)
{
    this->points+=points;
}

bool Player::canBuyItem(std::unique_ptr<Item> item)
{
    int* price = item->getPrice();
    return (resources[0] >= price[0] && resources[1] >= price[1] && resources[2] >= price[2] && resources[3] >= price[3] && resources[4] >= price[4]);
}

bool Player::hasItem(std::unique_ptr<Item> item)
{
    if(item->getKind() == "Settlement")
    {
        return (settlements > 0);
    }
    else if(item->getKind() == "City")
    {
        return (cities > 0);
    }
    else
    {
        return (pathes > 0);
    }
} 