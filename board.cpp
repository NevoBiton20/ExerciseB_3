#include "board.hpp"
void Board::placeItem(std::unique_ptr<Item> item, size_t row, size_t index)
{
    array[row][index] = std::move(item);
}

std::vector<std::vector<std::unique_ptr<Item>>> Board::getBoard()
{
    return array;
}