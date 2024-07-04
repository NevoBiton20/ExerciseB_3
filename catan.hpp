/*nevobiton0@gmail.com
This class is the game facade, it means that all the actual logic of the game
   happens here and this class connects all the other class components together */
#ifndef CATAN_HPP
#define CATAN_HPP
#include "player.hpp"
#include "board.hpp"
#include "bank.hpp"
#include <algorithm>
#include <memory>
#include <random>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define UNDERSCORE "\033[4m"
#define BOLDANDUNDERSCORED "\033[1;4m"

class Catan
{
    private:
        Player players[3];
        Board board;
        Bank bank;
        int turn;
        int winAmount;
        int mode;
    public:
        Catan(Player p1, Player p2, Player p3, int state, int winnerPoints=10) : players{Player(p1.getName()), Player(p2.getName()), Player(p3.getName())}, board(), bank()
        {
            turn =0;
            mode = state;
            winAmount = winnerPoints;
            std::cout<<"Starting Catan...\nPlayers order: ";
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(std::begin(players), std::end(players), g);
            std::cout<<players[0].getName()<<", "<<players[1].getName()<<", "<<players[2].getName()<<"\n";

            players[0].setNum(0);
            players[1].setNum(1);
            players[2].setNum(2);
            for(int j=0; j<3;j++)
            {
                players[j].addResource(0,4);
                players[j].addResource(1,4);
                players[j].addResource(2,2);
                players[j].addResource(3,2);
            }
            if(mode!=2)
            {
                printBoard();
            }
            if(mode==1)
            {
                for(int i = 0; i<3; i++)
                {
                    std::cout<<"It's "<<players[i].getName()<<"'s turn! you have 2 free roads and 2 free settlements to place for start on the board! Choose wisely\n";
                    placeSettlement(i);
                    placeSettlement(i);
                    placePath(i);
                    placePath(i);

                    printBoard();
                }
                giveResources(-1);
            }
        }
        void play();

        int getTurn()
        {
            return turn;
        }
        void passTurn()
        {
            turn++;
            if(turn==3)
            {
                turn = 0;
            }
        }
        void placeSettlement(int player);
        void placeCity(int player);
        void placePath(int player);
        void printBoard();
        void giveResources(int mode);
        void rollDice(int p=-1);
        void printWinner();
        void buyCard(int player);
        void trade(int seller, int buyer, int offer[5], int inExchange[5]);
        void makeTrade(int seller, int buyer, int offer[5], int inExchange[5]);
        void useCard(int player, int card);
        int getWinner()
        {
            int winner = -1;
            for(int i=0; i<3;i++)
            {
                if(players[i].getPoints() == winAmount)
                {
                    winner =i;
                }
            }
            return winner;
        }

        Player* getPlayers()
        {
            return players;
        }
};
#endif
