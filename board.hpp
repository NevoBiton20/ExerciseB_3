/* This class represents the catan full Board which contains all the possible tiles to get resources from */
#include "tile.hpp"
#include <vector>
#include <iostream>
#include "item.hpp"
#include <memory>
class Board
{
    private:
        Tile tiles[19]; // all the tiles of the board, can be : 'Mountains' , 'Meadow' , 'Forest' , 'Hills' , 'Agricultural' , 'Desert' .
        std::vector<std::vector<std::unique_ptr<Item>>> array; // A representaion of the whole board, contains all the elements of the board execpt of tiles.

    public:
        Board(): tiles{ // Tiles reset to some order and value.
            Tile(10, "Mountains"),
            Tile(2, "Meadow"),
            Tile(9, "Forest"),
            Tile(12, "Agricultural"),
            Tile(6, "Hills"),
            Tile(4, "Meadow"),
            Tile(10, "Hills"),
            Tile(9, "Agricultural"),
            Tile(11, "Forest"),
            Tile(0, "Desert"),
            Tile(3, "Forets"),
            Tile(8, "Mountains"),
            Tile(8, "Forest"),
            Tile(3, "Mountains"),
            Tile(4, "Agricultural"),
            Tile(5, "Meadow"),
            Tile(5, "Hills"),
            Tile(6, "Agricultural"),
            Tile(11, "Meadow")}
        {
            std::vector<int> rowSizes = {7,4,7,8,9,5,9,10,11,6,11,10,9,5,9,8,7,4,7}; // Board reset for every row.
            array.resize(rowSizes.size());
            for (size_t i = 0; i < rowSizes.size(); ++i) {
                array[i].resize(rowSizes[i]);
            }
        }
        void placeItem(std::unique_ptr<Item>, size_t row, size_t index);
        std::vector<std::vector<std::unique_ptr<Item>>> getBoard();
};