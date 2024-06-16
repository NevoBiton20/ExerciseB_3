#include "catan.hpp"
bool cleanArea(std::vector<std::vector<std::unique_ptr<Item>>> array,size_t row, size_t index)
{
    if(row==0)
    {
        if(index==0)
        {
            if(array[row][index+2]->getKind()=="empty" && array[row+2][index]->getKind() == "empty")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(index=array[row].size()-1)
        {
            if(array[row][index-2]->getKind()=="empty" && array[row+2][index]->getKind() == "empty")
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
            if(array[row][index-2]->getKind()=="empty" && array[row][index+2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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
            if(array[row][index+2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(index=array[row].size()-1)
        {
            if(array[row][index-2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty")
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
            if(array[row][index-2]->getKind()=="empty" && array[row][index+2]->getKind() == "empty" && array[row-2][index]->getKind() == "empty")
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
                    if(array[row][index+2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty" && array[row+2][0]->getKind() == "empty")
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index=array[row].size()-1)
                {
                    if(array[row][index-2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty" && array[row+2][index-2]->getKind() == "empty")
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
                    if(array[row][index-2]->getKind()=="empty" && array[row][index+2]->getKind() == "empty" && array[row-2][index]->getKind() == "empty" && array[row+2][index-2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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
                    if(array[row][index+2]->getKind()=="empty" && array[row-2][0]->getKind() == "empty" && array[row+2][index]->getKind() == "empty" && array[row-2][index+2]->getKind() == "empty")
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index=array[row].size()-1)
                {
                    if(array[row][index-2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty" && array[row+2][index]->getKind() == "empty" && array[row-2][index+2]->getKind() == "empty")
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
                    if(array[row][index-2]->getKind()=="empty" && array[row][index+2]->getKind() == "empty" && array[row-2][index]->getKind() == "empty" && array[row-2][index+2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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
                    if(array[row][index+2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty" && array[row+2][0]->getKind() == "empty" && array[row+2][index+2]->getKind() == "empty")
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index=array[row].size()-1)
                {
                    if(array[row][index-2]->getKind()=="empty" && array[row-2][index]->getKind() == "empty" && array[row+2][index+2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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
                    if(array[row][index-2]->getKind()=="empty" && array[row][index+2]->getKind() == "empty" && array[row-2][index]->getKind() == "empty" && array[row+2][index+2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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
                    if(array[row][index+2]->getKind()=="empty" && array[row-2][0]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(index=array[row].size()-1)
                {
                    if(array[row][index-2]->getKind()=="empty" && array[row-2][index-2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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
                    if(array[row][index-2]->getKind()=="empty" && array[row][index+2]->getKind() == "empty" && array[row-2][index]->getKind() == "empty" && array[row-2][index-2]->getKind() == "empty" && array[row+2][index]->getKind() == "empty")
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

void Catan::placeSettlement(Player player)
{
    if(player.canBuyItem(std::make_unique<Settlement>()))
    {
        if(player.hasItem(std::make_unique<Settlement>()))
        {
            size_t row;
            size_t index;
            do
            {
                do
                {
                    std::cout <<"Enter a row to place the Settlement (0 - 18 (Settlements are only placed in odd value rows))\n";
                    std::cin >> row; 
                    if(row <0 || row>18 || row%2==0)
                    {
                        std::cout <<"You have entered an invalid row value, Try again!\n"; 
                    } 
                } while (row <0 || row>18 || row%2==0);

                do
                {
                    std::cout << "Enter an index in the row you chose\n";
                    std::cin>>index;
                    if(index<0 || index >= board.getBoard()[row].size())
                    {
                        std::cout <<"You have entered an invalid index, Try again!\n"; 
                    }
                } while (index<0 || index >= board.getBoard()[row].size());
                if(board.getBoard()[row][index]->getKind() != "empty")
                {
                    std::cout << "This place is already occupied, Try another one! Pay attention you can only put settlement in a minimum of 2 roads between each settlement\n";
                }
            } while (!cleanArea(board.getBoard(),row,index) || board.getBoard()[row][index]->getKind() != "empty");
            
            player.placeSettlement();
            board.placeItem(std::make_unique<Settlement>(),row,index);
        }
        else
        {
            std::cout<<player.getName()<<", you don't have any settlements left!\n";
        }
    }
    else
    {
        std::cout<<player.getName()<<", you don't enough resources to place a settlement!\n";
    }
}

void Catan::placeCity(Player player)
{
    if(player.canBuyItem(std::make_unique<City>()))
    {
        if(player.hasItem(std::make_unique<City>()))
        {
            size_t row;
            size_t index;
            do
            {
                do
                {
                    std::cout <<"Enter a row to place the City (0 - 18 (cities are only placed in odd value rows))\n";
                    std::cin >> row; 
                    if(row <0 || row>18 || row%2==0)
                    {
                        std::cout <<"You have entered an invalid row value, Try again!\n"; 
                    } 
                } while (row <0 || row>18 || row%2==0);

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
                    std::cout << "You cant place a city if there was not a settlement before, You can only expand an existing settlement to a city! Try again\n";
                }
            } while (board.getBoard()[row][index]->getKind() != "Settlement");
            
            player.placeCity();
            board.placeItem(std::make_unique<City>(),row,index);
        }
        else
        {
            std::cout<<player.getName()<<", you don't have any cities left!\n";
        }
    }
    else
    {
        std::cout<<player.getName()<<", you don't enough resources to place a city!\n";
    }
}

void Catan::placePath(Player player)
{
    if(player.canBuyItem(std::make_unique<Path>()))
    {
        if(player.hasItem(std::make_unique<Path>()))
        {
            size_t row;
            size_t index;
            do
            {
                do
                {
                    std::cout <<"Enter a row to place the Path (0 - 18)\n";
                    std::cin >> row; 
                    if(row <0 || row>18 || row%2==0)
                    {
                        std::cout <<"You have entered an invalid row value, Try again!\n"; 
                    } 
                } while (row <0 || row>18 || row%2==0);

                do
                {
                    std::cout << "Enter an index in the row you chose\n";
                    std::cin>>index;
                    if(index<0 || index >= board.getBoard()[row].size())
                    {
                        std::cout <<"You have entered an invalid index, Try again!\n"; 
                    }
                } while (index<0 || index >= board.getBoard()[row].size());
                if(board.getBoard()[row][index]->getKind() != "empty")
                {
                    std::cout << "This place is already occupied, Try another one!\n";
                }
            } while (board.getBoard()[row][index]->getKind() != "empty");
            
            player.placePath();
            board.placeItem(std::make_unique<Path>(),row,index);
        }
        else
        {
            std::cout<<player.getName()<<", you don't have any roads left!\n";
        }
    }
    else
    {
        std::cout<<player.getName()<<", you don't enough resources to place a road!\n";
    }
}

void Catan::printBoard()
{
    for(size_t i=0;i<board.getBoard().size();i++)
    {
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
                    unit="-----";
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
                    unit = "|     ";
                }
            }
            else
            {
                unit = "+";
            }


            if(color == 0)
            {
                
            }
            else if(color== 1)
            {

            }
            else if(color == 2)
            {

            }
            else
            {

            }
        }
    }
}
/*
      +-----+-----+-----+
      | 11  |  9  |  3  |
      +-----+-----+-----+
    /  \  /  \  /  \  /  \
   +-----+-----+-----+-----+
   |     |     |     |     |
   +-----+-----+-----+-----+
  /   \ /  \  /  \  /  \  /  \
 +-----+-----+-----+-----+-----+
 |     |     |     |     |     |
 +-----+-----+-----+-----+-----+
  \  /   \  /  \ /   \ /   \  /
    +-----+-----+-----+-----+
    |     |     |     |     |
    +-----+-----+-----+-----+
      \ /  \  /   \  /  \ /
       +-----+-----+-----+
       |     |     |     |
       +-----+-----+-----+
*/