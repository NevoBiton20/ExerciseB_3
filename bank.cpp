/* Bank implementation */
#include "bank.hpp"

int Bank::askCard(Player player)
{
    if(player.getResources()[2]>0 && player.getResources()[3]>0 && player.getResources()[4]>0)
    {
        std::random_device rd; 
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distr(1, 100);
        int random_number = distr(eng);
        return random_number;
    }
    else
    {
        printf("%s Doesn't meet the required resources to but a card! Required resources: 1 wool, 1 iron, 1 grain",player.getName());
        return -1;
    }
}