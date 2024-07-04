/* Bank implementation */
#include "bank.hpp"

int Bank::askCard(Player player)
{
    if(cards[0]==0 && cards[1]==0 && cards[2]==0 && cards[3] ==0 && cards[4]==0)
    {
        std::cout <<"The Bank doesn't have amy cards left"<<std::endl;
        return -1;
    }
    int card;
    if(player.canBuyItem(Card()))
    {
        do
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 4);
            card = dis(gen);
        } while (cards[card]==0);
        
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
        cards[card]--;
        return card;
    }
    else
    {
        std::cout<<"Insufficent funds for buying card: Required resources: 1 grain, 1 wool, 1 iron"<<std::endl;
        return -1;
    }
}