#include "board.hpp"
void Board::placeItem(std::unique_ptr<Item> item, size_t row, size_t index)
{
    array[row][index] = std::move(item);
}

std::vector<std::vector<std::unique_ptr<Item>>>& Board::getBoard()
{
    return array;
}

std::vector<int> Board::resourcesByPlace(size_t row,size_t index, int tile)
{
    std::vector<int> resource(5,0);
    int amount = 1;
    if(array[row][index]->getKind() == "City")
    {
        amount =2;
    }
    if(tile==-1)
    {
        if(row == 0 || row == 2)
        {
            if(index == 0 || index == 2)
            {
                resource[4]+=amount;
            }
            if(index == 2 || index == 4)
            {
                resource[2]+=amount;
            }
            if(index == 4 || index == 6)
            {
                resource[1]+=amount;
            }
        }
        else if(row == 4 || row == 6)
        {
            if(index == 0 || index == 2)
            {
                resource[3]+=amount;
            }
            if(index == 2 || index == 4)
            {
                resource[0]+=amount;
            }
            if(index == 4 || index == 6)
            {
                resource[2]+=amount;
            }
            if(index == 6 || index == 8)
            {
                resource[0]+=amount;
            }
        }
        else if(row == 8 || row ==10)
        {
            if(index == 0 || index == 2)
            {
                resource[3]+=amount;
            }
            if(index == 2 || index == 4)
            {
                resource[1]+=amount;
            }
            if(index == 6 || index == 8)
            {
                resource[1]+=amount;
            }
            if(index == 8 || index == 10)
            {
                resource[4]+=amount;
            }
        }
        else if(row == 12 || row == 14)
        {
            if(index == 0 || index == 2)
            {
                resource[1]+=amount;
            }
            if(index == 2 || index == 4)
            {
                resource[4]+=amount;
            }
            if(index == 4 || index == 6)
            {
                resource[3]+=amount;
            }
            if(index == 6 || index == 8)
            {
                resource[2]+=amount;
            }
        }
        else if(row == 16 || row == 18)
        {
            if(index == 0 || index == 2)
            {
                resource[0]+=amount;
            }
            if(index == 2 || index == 4)
            {
                resource[3]+=amount;
            }
            if(index == 4 || index == 6)
            {
                resource[2]+=amount;
            }
        }
    }
    else
    {
        switch (tile)
        {
        case 2:
            if((row==0|| row == 2) && (index == 2 || index == 4)) resource[2]+=amount;
            break;
        case 3:
            if((row==8|| row == 10) && (index == 6 || index == 8)) resource[1]+=amount;
            if((row==12|| row == 14) && (index == 2 || index == 4)) resource[4]+=amount;
            break;
        case 4:
            if((row==4|| row == 6) && (index == 4 || index == 6)) resource[2]+=amount;
            if((row==12|| row == 14) && (index == 4 || index == 6)) resource[3]+=amount;
            break;
        case 5:
            if((row==12|| row == 14) && (index == 6 || index == 8)) resource[2]+=amount;
            if((row==16|| row == 18) && (index == 0 || index == 2)) resource[0]+=amount;
            break;
        case 6:
            if((row==4|| row == 6) && (index == 2 || index == 4)) resource[0]+=amount;
            if((row==16|| row == 18) && (index == 2 || index == 4)) resource[3]+=amount;
            break;
        case 8:
            if((row==8|| row == 10) && (index == 8 || index == 10)) resource[4]+=amount;
            if((row==12|| row == 14) && (index == 0 || index == 2)) resource[1]+=amount;
            break;
        case 9:
            if((row==0|| row == 2) && (index == 4 || index == 6)) resource[1]+=amount;
            if((row==8|| row == 10) && (index == 0 || index == 2)) resource[3]+=amount;
            break;
        case 10:
            if((row==0|| row == 2) && (index == 0 || index == 2)) resource[4]+=amount;
            if((row==4|| row == 6) && (index == 6 || index == 8)) resource[0]+=amount;
            break;
        case 11:
            if((row==8|| row == 10) && (index == 2 || index == 4)) resource[1]+=amount;
            if((row==16|| row == 18) && (index == 4 || index == 6)) resource[2]+=amount;
            break;
        case 12:
            if((row==4|| row == 6) && (index == 0 || index == 2)) resource[3]+=amount;
            break;
        default:
            break;
        }
    }
    return resource;
}
bool Board::isNextToTile(size_t row, size_t index, int tile)
{
    switch (tile)
    {
    case -1:
        return true;
    case 2:
        return (row==0|| row == 2) && (index == 2 || index == 4);
    case 3:
        return (row==8|| row == 10) && (index == 6 || index == 8) || (row==12|| row == 14) && (index == 2 || index == 4);
    case 4:
        return (row==4|| row == 6) && (index == 4 || index == 6) || (row==12|| row == 14) && (index == 4 || index == 6);
    case 5:
        return (row==12|| row == 14) && (index == 6 || index == 8) || (row==16|| row == 18) && (index == 0 || index == 2);
    case 6:
        return (row==4|| row == 6) && (index == 2 || index == 4) || (row==16|| row == 18) && (index == 2 || index == 4);
    case 8:
        return (row==8|| row == 10) && (index == 8 || index == 10) || (row==12|| row == 14) && (index == 0 || index == 2);
    case 9:
        return (row==0|| row == 2) && (index == 4 || index == 6) || (row==8|| row == 10) && (index == 0 || index == 2);
    case 10:
        return (row==0|| row == 2) && (index == 0 || index == 2) || (row==4|| row == 6) && (index == 6 || index == 8);
    case 11:
        return (row==8|| row == 10) && (index == 2 || index == 4) || (row==16|| row == 18) && (index == 4 || index == 6);
    case 12:
        return (row==4|| row == 6) && (index == 0 || index == 2);
    default:
        return false;;
    }
}