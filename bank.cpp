/* Bank implementation */
#include "bank.hpp"

int Bank::askCard(Player player)
{
    if(player.canBuyItem(Card()))
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 4);
        int card = dis(gen);
        std::string cardName;
        switch (card)
        {
        case 0:
            cardName = "Monopol";
            break;
        case 1:
            cardName = "Path Build";
            break;
        case 2:
            cardName = "Year-Of-Plenty";
            break;
        case 3:
            cardName = "Knight";
            break;
        case 4:
            cardName = "Victory Point(+1)";
            break;
        }
        std::cout <<player.getName() << ", You just earned "<<cardName <<" card!"<<std::endl;
        return card;
    }
    else
    {
        std::cout<<"Insufficent funds for buying card: Required resources: 1 grain, 1 wool, 1 iron"<<std::endl;
        return -1;
    }
}