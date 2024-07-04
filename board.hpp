/*nevobiton0@gmail.com
This class represents the catan full Board which contains all the possible tiles to get resources from */
#ifndef BOARD_HPP
#define BOARD_HPP
#include "tile.hpp"
#include <vector>
#include <iostream>
#include "item.hpp"
#include <memory>
class Board
{
    private:
        Tile tiles[19]; // all the tiles of the board, can be : 'Mountains' , 'Pasture' , 'Forest' , 'Hills' , 'Agricultural' , 'Desert' .
        std::vector<std::vector<std::unique_ptr<Item>>> array; // A representaion of the whole board, contains all the elements of the board execpt of tiles.

    public:
        Board(): tiles{ // Tiles reset to some order and value.
            Tile(10, "Mountains"),
            Tile(2, "Pasture"),
            Tile(9, "Forest"),
            Tile(12, "Agricultural"),
            Tile(6, "Hills"),
            Tile(4, "Pasture"),
            Tile(10, "Hills"),
            Tile(9, "Agricultural"),
            Tile(11, "Forest"),
            Tile(0, "Desert"),
            Tile(3, "Forets"),
            Tile(8, "Mountains"),
            Tile(8, "Forest"),
            Tile(3, "Mountains"),
            Tile(4, "Agricultural"),
            Tile(5, "Pasture"),
            Tile(5, "Hills"),
            Tile(6, "Agricultural"),
            Tile(11, "Pasture")}
        {
            std::vector<size_t> rowSizes = {7, 4, 7, 8, 9, 5, 9, 10, 11, 6, 11, 10, 9, 5, 9, 8, 7, 4, 7};
            for (size_t i = 0; i < 19; ++i) {
                std::vector<std::unique_ptr<Item>> row;
                for (size_t j = 0; j < rowSizes[i]; ++j) {
                    if(i%2!=0 || j%2!=0)
                    {
                        row.push_back(std::make_unique<Path>());
                    }
                    else
                    {
                        row.push_back(std::make_unique<Settlement>());
                    }
                }
                array.push_back(std::move(row));  // Move row into array
            }
        }
        void placeItem(std::unique_ptr<Item>, size_t row, size_t index);
        std::vector<std::vector<std::unique_ptr<Item>>>& getBoard();
        std::vector<int> resourcesByPlace(size_t row,size_t index, int mode=-1);
        const Tile* getTiles() const
        {
            return tiles;
        }
        bool isNextToTile(size_t row, size_t index,int tile);
};
#endif
