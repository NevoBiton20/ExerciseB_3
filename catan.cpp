#include "catan.hpp"

const char* getColor(int player)
{
    switch (player)
    {
    case 0:
        return RED;
    case 1:
        return GREEN;
    case 2:
        return BLUE;
    default:
        return RESET;
    }
}

bool cleanArea(std::vector<std::vector<std::unique_ptr<Item>>>& array,size_t row, size_t index)
{
    if(row==0)
    {
        if(index==0)
        {
            if(array[row][index+2]->getPlayer()==-1  && array[row+2][index]->getPlayer()==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(index==array[row].size()-1)
        {
            if(array[row][index-2]->getPlayer()==-1  && array[row+2][index]->getPlayer()==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(array[row][index-2]->getPlayer()==-1  && array[row][index+2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(row==18)
    {
        if(index==0)
        {
            if(array[row][index+2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(index==array[row].size()-1)
        {
            if(array[row][index-2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(array[row][index-2]->getPlayer()==-1  && array[row][index+2]->getPlayer()==-1 && array[row-2][index]->getPlayer()==-1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else{
        if(row>9)
        {
            if(array[row+1].size() > array[row-1].size())
            {
                if(index==0)
                {
                    if(array[row][index+2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1 && array[row+2][0]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index==array[row].size()-1)
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1 && array[row+2][index-2]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row][index+2]->getPlayer()==-1 && array[row-2][index]->getPlayer()==-1 && array[row+2][index-2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(index==0)
                {
                    if(array[row][index+2]->getPlayer()==-1  && array[row-2][0]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1 && array[row-2][index+2]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index==array[row].size()-1)
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1 && array[row-2][index+2]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row][index+2]->getPlayer()==-1 && array[row-2][index]->getPlayer()==-1 && array[row-2][index+2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            if(array[row+1].size() > array[row-1].size())
            {
                if(index==0)
                {
                    if(array[row][index+2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1 && array[row+2][0]->getPlayer()==-1 && array[row+2][index+2]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index==array[row].size()-1)
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row-2][index]->getPlayer()==-1 && array[row+2][index+2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row][index+2]->getPlayer()==-1 && array[row-2][index]->getPlayer()==-1 && array[row+2][index+2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(index==0)
                {
                    if(array[row][index+2]->getPlayer()==-1  && array[row-2][0]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index==array[row].size()-1)
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row-2][index-2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if(array[row][index-2]->getPlayer()==-1  && array[row][index+2]->getPlayer()==-1 && array[row-2][index]->getPlayer()==-1 && array[row-2][index-2]->getPlayer()==-1 && array[row+2][index]->getPlayer()==-1)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
}


void Catan::play()
{
    bool hasRolled = false;
    bool nonStop = true;
    while(nonStop)
    {
        std::cout << "Its "<<getColor(turn)<<players[turn].getName()<<RESET<<"'s turn, choose what to do:"<<std::endl;
        std::string actions = "1) Place Settlement\n2) Place Road\n3) Place City\n4) Roll Dice\n5) BuyCard\n6) Use card\n7) Trade\n8) View your resources\n9) Pass turn";
        std::cout << actions<<"\n"<<std::endl;
        int action;
        std::cin >>action;
        switch (action)
        {
        case 1:
            placeSettlement(turn);
            printBoard();
            break;
        case 2:
            placePath(turn);
            printBoard();
            break;
        case 3:
            placeCity(turn);
            printBoard();
            break;
        case 4:
            if(!hasRolled)
            {
                rollDice();
                hasRolled = true;
            }
            else
            {
                std::cout << "You have already rolled the dice!"<<std::endl;
            }
            break;
        case 5:
            buyCard(turn);
            break;
        case 6:
            std::cout <<"\nChoose a card to use (1-3), Here are your usable cards:"<<std::endl; //'Monopol' , 'Path Build' , 'Year of plenty'
            std::cout<<"1) Monopol: "<<players[turn].getCards()[0]<<std::endl;
            std::cout<<"2) Path Build: "<<players[turn].getCards()[1]<<std::endl;
            std::cout<<"3) Monopol: "<<players[turn].getCards()[2]<<std::endl;
            int card;
            std::cin >>card;
            card--;
            useCard(turn,card);
            break;
        case 7:
        {
            int sellerSide = turn;
            std::cout<<"Trade details:"<<std::endl;
            std::cout << "Choose a player to trade with (Enter player num):"<<std::endl;
            for(int i=0; i<3;i++)
            {
                if(i==sellerSide)continue;
                std::cout<<i+1<<") "<<getColor(i)<<players[i].getName()<<RESET<<std::endl;
            }
            int buyerSide;
            std::cin >> buyerSide;
            buyerSide--;

            int brick;
            int lumber;
            int wool;
            int grain;
            int iron;
            std::cout <<"Enter offer:"<<std::endl;
            std::cout << "How many bricks?"<<std::endl;
            do
            {
                std::cin >> brick;
                if(brick<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (brick<0);
            std::cout << "How many lumbers?"<<std::endl;
            do
            {
                std::cin >> lumber;
                if(lumber<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (lumber<0);
            std::cout << "How many wool?"<<std::endl;
            do
            {
                std::cin >> wool;
                if(wool<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (wool<0);
            std::cout << "How many grains?"<<std::endl;
            do
            {
                std::cin >> grain;
                if(grain<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (grain<0);
            std::cout << "How many iron?"<<std::endl;      
            do
            {
                std::cin >> iron;
                if(iron<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (iron<0);


            std::cout <<"\nIn exchange for:"<<std::endl;
            int offering[5] = {brick,lumber,wool,grain,iron};
            std::cout << "How many bricks?"<<std::endl;
            do
            {
                std::cin >> brick;
                if(brick<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (brick<0);
            std::cout << "How many lumbers?"<<std::endl;
            do
            {
                std::cin >> lumber;
                if(lumber<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (lumber<0);
            std::cout << "How many wool?"<<std::endl;
            do
            {
                std::cin >> wool;
                if(wool<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (wool<0);
            std::cout << "How many grains?"<<std::endl;
            do
            {
                std::cin >> grain;
                if(grain<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (grain<0);
            std::cout << "How many iron?"<<std::endl;      
            do
            {
                std::cin >> iron;
                if(iron<0)
                {
                    std::cout <<"Not a valid amount, enter again:"<<std::endl;
                }
            } while (iron<0);
            int exchanging[5] = {brick,lumber,wool,grain,iron};

            trade(sellerSide,buyerSide,offering,exchanging);
            break;
        }
        case 8:
            std::cout <<"\nYour resources:"<<std::endl;
            std::cout<<"Brick: "<<players[turn].getResources()[0]<<std::endl;
            std::cout<<"Lumber: "<<players[turn].getResources()[1]<<std::endl;
            std::cout<<"Wool: "<<players[turn].getResources()[2]<<std::endl;
            std::cout<<"Grain: "<<players[turn].getResources()[3]<<std::endl;
            std::cout<<"Iron: "<<players[turn].getResources()[4]<<"\n"<<std::endl;
            break;
        case 9:
            passTurn();
            hasRolled= false;
            if(players[turn].getPoints() >= winAmount)
            {
                nonStop = false;
            }
            break;
        default:
            break;
        }

    }
    std::cout <<"The winner is "<<getColor(turn)<<players[turn].getName()<<RESET<<std::endl;
}

void Catan::placeSettlement(int player)
{
    Settlement* s = new Settlement();
    if(players[player].canBuyItem(*s))
    {
        if(players[player].hasItem(*s))
        {
            size_t row;
            size_t index;
            do
            {
                do
                {
                    std::cout <<players[player].getName()<<", Enter a row to place the Settlement (0 - 18 (Settlements are only placed in even value rows))\n";
                    std::cin >> row; 
                    if(row <0 || row>18 || row%2!=0)
                    {
                        std::cout <<"You have entered an invalid row value, Try again!\n"; 
                    } 
                } while (row <0 || row>18 || row%2!=0);

                do
                {
                    std::cout << "Enter an index in the row you chose\n";
                    std::cin>>index;
                    if(index<0 || index >= board.getBoard()[row].size())
                    {
                        std::cout <<"You have entered an invalid index, Try again!\n"; 
                    }
                } while (index<0 || index >= board.getBoard()[row].size());
                if(board.getBoard()[row][index]->getKind() != "Settlement" || !cleanArea(board.getBoard(),row,index) || board.getBoard()[row][index]->getPlayer() != -1)
                {
                    std::cout << "This place is already occupied, Try another one! \nPay attention you can put a settlement only in a minimum of 2 roads between each settlement\n";
                }
            } while (board.getBoard()[row][index]->getKind() != "Settlement" || !cleanArea(board.getBoard(),row,index) || board.getBoard()[row][index]->getPlayer() != -1);
            
            players[player].placeSettlement();
            board.placeItem(std::make_unique<Settlement>(players[player].getNum()),row,index);
            std::cout << "Settlement placed succssesfully at: " << row <<" , " << index<<"\n";
        }
        else
        {
            std::cout<<players[player].getName()<<", you don't have any settlements left!\n";
        }
    }
    else
    {
        std::cout<<players[player].getName()<<", you don't enough resources to place a settlement!\n";
    }
    delete s;
}

void Catan::placeCity(int player)
{
    City* c = new City(players[player].getNum());
    if(players[player].canBuyItem(*c))
    {
        if(players[player].hasItem(*c))
        {
            size_t row;
            size_t index;
            do
            {
                do
                {
                    std::cout <<"Enter a row to place the City (0 - 18 (cities are only placed in even value rows))\n";
                    std::cin >> row; 
                    if(row <0 || row>18 || row%2!=0)
                    {
                        std::cout <<"You have entered an invalid row value, Try again!\n"; 
                    } 
                } while (row <0 || row>18 || row%2!=0);

                do
                {
                    std::cout << "Enter an index in the row you chose\n";
                    std::cin>>index;
                    if(index<0 || index >= board.getBoard()[row].size())
                    {
                        std::cout <<"You have entered an invalid index, Try again!\n"; 
                    }
                } while (index<0 || index >= board.getBoard()[row].size());
                if(board.getBoard()[row][index]->getKind() != "Settlement")
                {
                    std::cout << "You can't place a city if there was not a settlement before, You can only expand an existing settlement to a city! Try again\n";
                }
            } while (board.getBoard()[row][index]->getKind() != "Settlement" || board.getBoard()[row][index]->getPlayer() != players[player].getNum());
            
            players[player].placeCity();
            board.placeItem(std::make_unique<City>(players[player].getNum()),row,index);
            std::cout << "City placed succssesfully at: " << row <<" , " << index<<"\n";
        }
        else
        {
            std::cout<<players[player].getName()<<", you don't have any cities left!\n";
        }
    }
    else
    {
        std::cout<<players[player].getName()<<", you don't enough resources to place a city!\n";
    }
    delete c;
}

bool validRoad(std::vector<std::vector<std::unique_ptr<Item>>>& array, size_t row, size_t index, int player)
{
    if(row%2==0)
    {
        return (array[row][index+1]->getPlayer() == player || array[row][index-1]->getPlayer() == player);
    }
    else if(row%4==3)
    {
        if(index %2==0)
        {
            return (array[row+1][index]->getPlayer() == player || array[row-1][index]->getPlayer() == player);
        }
        else
        {
            if(row <8)
            {
                return (array[row-1][index-1]->getPlayer() == player || array[row+1][index+1]->getPlayer() == player);
            }
            else
            {
                return (array[row+1][index-1]->getPlayer() == player || array[row-1][index+1]->getPlayer() == player);
            }
        }
    }
    else
    {
        return (array[row+1][index*2]->getPlayer() == player || array[row-1][index*2]->getPlayer() == player);
    }
}

void Catan::placePath(int player)
{
    Path* p = new Path(players[player].getNum());
    if(players[player].canBuyItem(*p))
    {
        if(players[player].hasItem(*p))
        {
            size_t row;
            size_t index;
            do
            {
                do
                {
                    std::cout <<players[player].getName()<<", Enter a row to place the Path (0 - 18)\n";
                    std::cin >> row; 
                    if(row <0 || row>18)
                    {
                        std::cout <<"You have entered an invalid row value, Try again!\n"; 
                        std::cout << "\n";
                    } 
                } while (row <0 || row>18);

                do
                {
                    std::cout << "Enter an index in the row you chose\n";
                    std::cin>>index;
                    if((index<0 || index >= board.getBoard()[row].size()) || (row%2==0 && index%2==0))
                    {
                        std::cout <<"You have entered an invalid road placement index, Try again!\n"; 
                        std::cout << "\n";
                    }
                } while ((index<0 || index >= board.getBoard()[row].size()) || (row%2==0 && index%2==0));
                if(board.getBoard()[row][index]->getPlayer() != -1 || board.getBoard()[row][index]->getKind() != "Path" || !validRoad(board.getBoard(), row,index,player))
                {
                    std::cout << "This place is may be occupied or not a valid place for a road!, Try another one!\n";
                    std::cout << "\n";
                }
            } while (board.getBoard()[row][index]->getPlayer() != -1 || board.getBoard()[row][index]->getKind() != "Path" || !validRoad(board.getBoard(), row,index,player));
            
            players[player].placePath();
            board.placeItem(std::make_unique<Path>(players[player].getNum()),row,index);
            std::cout << "Road placed succssesfully at: " << row <<" , " << index<<"\n";
        }
        else
        {
            std::cout<<players[player].getName()<<", you don't have any roads left!\n";
        }
    }
    else
    {
        std::cout<<players[player].getName()<<", you don't enough resources to place a road!\n";
    }
    delete p;
}

void Catan::printWinner()
{
    int winner = -1;
    for(int i=0; i<3;i++)
    {
        if(players[i].getPoints() == winAmount)
        {
            winner =i;
        }
    }
    if(winner==-1)
    {
        std::cout<<"No winner yet!"<<std::endl;
    }
    else
    {
        std::cout <<"Congratulations! "<< getColor(winner)<<players[winner].getName()<<RESET<<" is the winner"<<std::endl;
    }
}

void Catan::buyCard(int player)
{
    int card = bank.askCard(players[player]);
    if(card==-1)
    {
        return;
    }
    players[player].buyCard(card);
}

void Catan::trade(int seller, int buyer, int offer[5], int inExchange[5])
{
    if(!players[seller].canAfford(offer))
    {
        std::cout << players[seller].getName() << ", You can't afford this trade"<<std::endl;
        return;
    }

    if(!players[buyer].canAfford(inExchange))
    {
        std::cout << players[buyer].getName() << ", can't afford this trade"<<std::endl;
        return;
    }
    std::string offers = getColor(seller) + players[seller].getName() + RESET + " Wants to make a deal with "+ getColor(buyer) + players[buyer].getName() + RESET + ":\n";
    std::cout << offers;
    for(int i=0;i<5;i++)
    {
        if(offer[i]>0)
        {
            std::string material;
            switch (i)
            {
                case 0:
                    material = " Brick";
                    break;
                case 1:
                    material = " Lumber";
                    break;
                case 2:
                    material = " Wool";
                    break;
                case 3:
                    material = " Grain";
                    break;
                case 4:
                    material = " Iron";
                    break;
            }
            offers= std::to_string(offer[i]) + material+"\n";
            std::cout << offers;
        }
    }
    std::cout<<"In exchange:"<<std::endl;
    for(int i=0;i<5;i++)
    {
        if(inExchange[i]>0)
        {
            std::string material;
            switch (i)
            {
                case 0:
                    material = " Brick";
                    break;
                case 1:
                    material = " Lumber";
                    break;
                case 2:
                    material = " Wool";
                    break;
                case 3:
                    material = " Grain";
                    break;
                case 4:
                    material = " Iron";
                    break;
            }
            offers= std::to_string(inExchange[i]) + material+"\n";
            std::cout << offers;
        }
    }
    std::cout << getColor(buyer) + players[buyer].getName() + RESET ", do you agree to trade? yes/no\n";
    std::string answer;
    std::cin >> answer;
    if(answer=="yes")
    {
        makeTrade(seller,buyer,offer,inExchange);
    }
    else
    {
        std::cout << "Trade Cancelled"<<std::endl;
    }
}

void Catan::makeTrade(int seller, int buyer, int offer[5], int inExchange[5])
{
    for(int i=0; i<5; i++)
    {
        players[seller].addResource(i,inExchange[i]);
        players[seller].loseResource(i,offer[i]);

        players[buyer].loseResource(i,inExchange[i]);
        players[buyer].addResource(i,offer[i]);
    }
    std::cout << "Trade was made succesfully!\n"<<std::endl;
}

void Catan::useCard(int player, int card)
{
    std::cout << std::endl;
    std::string message;
    if(players[player].hasCard(card))
    {
        switch (card)
        {
        case 0:
            message = getColor(player) + players[player].getName() + " Uses Monopoly card!" + RESET;
            std::cout << message<<std::endl;
            std::cout << "Choose a resource to take from everyone: 0 - Brick, 1 - Lumber, 2 - Wool, 3 - Grain, 4 - Iron"<<std::endl;
            int x;
            std::cin >> x;
            message = "";
            for(int i=0;i<3;i++)
            {
                if(i==player)continue;
                if(players[i].getResources()[x]>0)
                {
                    message += getColor(i) + players[i].getName() + RESET + " Gave 1 resource to " +getColor(player) + players[player].getName() + RESET + "\n";
                    players[i].loseResource(x,1);
                    players[player].addResource(x,1);
                }

            }
            message+="\n";
            std::cout << message;
            break;
        case 1:
            message = getColor(player) + players[player].getName() + " Uses Path Build card!" + RESET;
            std::cout << message << std::endl;
            std::cout << "You have 2 free roads to place!"<<std::endl;
            players[player].addResource(0,2);
            players[player].addResource(1,2);
            placePath(player);
            placePath(player);
            break;
        case 2:
            message = getColor(player) + players[player].getName() + " Uses Year-Of-Plenty card!" + RESET;
            std::cout << message << std::endl;
            std::cout << "You have 2 free resources to ask from the bank!"<<std::endl;
            int res;
            std::cout << "Choose first resource! 0 - Brick, 1 - Lumber, 2 - Wool, 3 - Grain, 4 - Iron "<<std::endl;
            std::cin >> res;
            players[player].addResource(res,1);
            std::cout << "Choose second resource! 0 - Brick, 1 - Lumber, 2 - Wool, 3 - Grain, 4 - Iron "<<std::endl;
            std::cin >> res;
            players[player].addResource(res,1);
            break;
        default:
            std::cout << "Not a usable card"<<std::endl;
            break;
        }
    }
    else
    {
        std::cout << "You don't own this card"<<std::endl;
    }
}
void Catan::printBoard()
{
    std::cout<<"\n=============Catan Board======================\n\n";
    std::string legend = std::string(BOLDANDUNDERSCORED) + " Legend :" + RESET +"\n"
    + BOLD + "H - Hills produce brick\nF - Forests produce lumber\nM - Mountains produce iron\nA - Agricultural fields prodeuce grain\nP - Pastures produce wool\n" + RESET;
    std::cout<<legend << "\n";
    const Tile* tiles = board.getTiles();
    int tilesCounter=0;
    for(size_t i=0;i<board.getBoard().size();i++)
    {
        std::string space="";

        if((i>=0 && i<=2) || board.getBoard().size() - i <= 3)
        {
            space = "      ";
        }
        else if(i == 15 || i == 3)
        {
            space = "   ";
        }
        else if(i == 11 || i == 7)
        {
            space = " ";
        }
        else if(((i>=4 && i<=6 ) || (i>=12 && i<=14)))
        {
            space = "   ";
        }

        std::cout << space;
        for(size_t j = 0;j<board.getBoard()[i].size();j++)
        {
            int color = board.getBoard()[i][j]->getPlayer();
            std::string kind = board.getBoard()[i][j]->getKind();
            std::string unit = "";

            if(kind == "City")
            {
                unit ="~";
            }
            else if(kind == "Path")
            {
                if(i%2==0)
                {
                    unit="─────";
                    
                }
                else if(i%4==3)
                {
                    if(i<9)
                    {
                        if(j%2==0)
                        {
                            unit = " / ";
                        }
                        else
                        {
                            unit = " \\ ";
                        }

                    }
                    else
                    {
                        if(j%2==0)
                        {
                            unit = " \\ ";
                        }
                        else
                        {
                            unit = " / ";
                        }
                    }
                }
                else
                {
                    if(j == board.getBoard()[i].size()-1)
                    {
                        unit = "|";
                    }
                    else
                    {
                        if(tiles[tilesCounter].getValue()>=10)
                        {
                            unit = "| ";
                            unit += RESET + std::to_string(tiles[tilesCounter].getValue()) +tiles[tilesCounter].getType().at(0) +" ";
                        }
                        else
                        {
                            unit = "| ";
                            unit+=RESET +std::to_string(tiles[tilesCounter].getValue()) +tiles[tilesCounter].getType().at(0) +"  ";
                        }
                        tilesCounter++;
                    }
                }
            }
            else
            {
                unit = "+";
            }


            if(color == 0)
            {
                unit = RED + unit + RESET;
            }
            else if(color== 1)
            {
                unit = GREEN + unit + RESET;
            }
            else if(color == 2)
            {
                unit = BLUE + unit + RESET;
            }
            std::cout << unit;
        }
        std::cout<<"\n";
    }

    std::string playersMap;
    playersMap = RED + players[0].getName() + " Points: " + std::to_string(players[0].getPoints()) + RESET +"\n" + GREEN + players[1].getName()
    + " Points: " + std::to_string(players[1].getPoints())  + RESET +"\n" + BLUE + players[2].getName()+ " Points: " + std::to_string(players[2].getPoints())  + RESET;
    std::cout<<"\n" <<  playersMap << "\n";
    std::cout<<"\n==============================================\n";
}

void Catan::giveResources(int mode)
{
    for(size_t i=0; i < 19;i+=2)
    {
        for(size_t j=0; j<board.getBoard()[i].size(); j+=2)
        {
            if(board.getBoard()[i][j]->getPlayer() != -1 && board.isNextToTile(i,j,mode))
            {
                std::vector<int> resources = board.resourcesByPlace(i,j,mode);
                int player =board.getBoard()[i][j]->getPlayer();
                std::string name = players[player].getName();
                std::cout<<"\n";
                std::string message =getColor(player) + name +" has obtained: "+RESET;
                std::string materials[5] = {"Brick", "Lumber", "Wool", "Grain", "Iron"};
                for(size_t k=0;k<5;k++)
                {
                    if(resources[k] > 0)
                    {
                        players[player].addResource(k,resources[k]);
                        message+= std::to_string(resources[k])+" " +materials[k] +", ";
                    }
                }

                message.erase(message.length()-2,2);
                std::cout << message<<"\n\n";
            }
        }
    }
}

void Catan::rollDice(int p)
{
    if(p!=-1 && p!=turn)
    {
        throw std::runtime_error("WRONG TURN");
    }
    std::cout<<"Rolling dice..."<<std::endl;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    int die1 = dis(gen);
    int die2 = dis(gen);
    int tile = die1 + die2;
    std::cout<<"Result: "<< tile << std::endl;
    if(p!=-1)
    {
        passTurn();
    }
    if(tile!=7)
    {
        giveResources(tile);
    }
    else
    {
        for(int i=0; i<3;i++)
        {
            int amount=0;
            for(int j=0; j<5;j++)
            {
                amount+=players[i].getResources()[j];
            }
            if(amount > 7)
            {
                do
                {
                    std::cout << getColor(i) <<players[i].getName()<<RESET<<", you have more then 7 resources and dice rolled 7!\nYou have to choose "<<amount-7<<" resources to give up on."<<std::endl;
                    std::cout << "How many bricks?"<<std::endl;
                    int brick,lumber,wool,grain,iron;
                    do
                    {
                        std::cin >> brick;
                        if(brick<0 || players[i].getResources()[0] < brick)
                        {
                            std::cout <<"Not a valid amount, enter again:"<<std::endl;
                        }
                    } while (brick<0 || players[i].getResources()[0] < brick);
                    std::cout << "How many lumbers?"<<std::endl;
                    do
                    {
                        std::cin >> lumber;
                        if(lumber<0|| players[i].getResources()[1] < lumber)
                        {
                            std::cout <<"Not a valid amount, enter again:"<<std::endl;
                        }
                    } while (lumber<0|| players[i].getResources()[1] < lumber);
                    std::cout << "How many wool?"<<std::endl;
                    do
                    {
                        std::cin >> wool;
                        if(wool<0|| players[i].getResources()[2] < wool)
                        {
                            std::cout <<"Not a valid amount, enter again:"<<std::endl;
                        }
                    } while (wool<0|| players[i].getResources()[2] < wool);
                    std::cout << "How many grains?"<<std::endl;
                    do
                    {
                        std::cin >> grain;
                        if(grain<0|| players[i].getResources()[3] < grain)
                        {
                            std::cout <<"Not a valid amount, enter again:"<<std::endl;
                        }
                    } while (grain<0|| players[i].getResources()[3] < grain);
                    std::cout << "How many iron?"<<std::endl;      
                    do
                    {
                        std::cin >> iron;
                        if(iron<0|| players[i].getResources()[4] < iron)
                        {
                            std::cout <<"Not a valid amount, enter again:"<<std::endl;
                        }
                    } while (iron<0|| players[i].getResources()[4] < iron);
                    amount -= (brick + lumber + wool + grain + iron);
                    players[i].loseResource(0,brick);
                    players[i].loseResource(1,lumber);
                    players[i].loseResource(2,wool);
                    players[i].loseResource(3,grain);
                    players[i].loseResource(4,iron);
                } while (amount >7);
                
            }
        }
    }
}
/*
      +-----+-----+-----+
      |     |     |     |
      +-----+-----+-----+
    /  \   /  \  /   \ /  \
   +-----+-----+-----+-----+
   |     |     |     |     |
   +-----+-----+-----+-----+
  /  \  /  \  /  \  /  \  /  \
+-----+-----+-----+-----+-----+
|     |     |     |     |     |
+-----+-----+-----+-----+-----+
  \  /  \  /  \  /  \  /  \  /
   +-----+-----+-----+-----+
   |     |     |     |     |
   +-----+-----+-----+-----+
    \  /  \  /  \  /  \  /
      +-----+-----+-----+
      |     |     |     |
      +-----+-----+-----+
*/
