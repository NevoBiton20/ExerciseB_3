#include "item.hpp"

int Item::getPlayer()
{
    return player;
}

std::string Item::getKind()
{
    return kind;
}

int* Item::getPrice()
{
    return price;
}