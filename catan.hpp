/* This class is the game facade, it means that all the actual logic of the game
   happens here and this class connects all the other class components together */
#include "player.hpp"
#include "board.hpp"
#include "bank.hpp"
#include <algorithm>
#include <memory>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class Catan
{
    private:
        Player players[3];
        Board board;
        Bank bank;
    public:
        Catan(Player p1, Player p2, Player p3) : players{Player(p1.getName()), Player(p2.getName()), Player(p3.getName())}, board(), bank()
        {
            std::cout<<"Starting Catan...\nPlayers order: ";
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(std::begin(players), std::end(players), g);
            std::cout<<players[0].getName()<<" , "<<players[1].getName()<<" , "<<players[2].getName()<<"\n";

            for(int i = 0; i<3; i++)
            {
                std::cout<<"It's "<<players[i].getName()<<"'s turn! you have free 2 roads and 2 settlements to place for start on the board! Choose wisely\n";
                std::cout<<players[i].getName()<<", Choose an action to perform!\n1) Place settlement\n2) Place road\n";
                int action;
                std::cin>>action;
                if(action==1)
                {
                    placeSettlement(players[i]);
                }
                else if(action==2)
                {
                    placePath(players[i]);
                }
            }
        }
        void placeSettlement(Player player);
        void placeCity(Player player);
        void placePath(Player player);
        void printBoard();
};