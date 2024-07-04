/* nevobiton0@gmail.com
A simple Tile class which describes an element of the catan board
*/
#ifndef TILE_HPP
#define TILE_HPP
#include <string>
class Tile
{
    private:
        int num; // resources receving value
        std::string type; // tile type: Pasture, Mountains, Hills, Agricultural, Forest, Desert
        
    public:    
        // Tile Constructor
        Tile(int n, std::string s) : num(n), type(s) {}

        // Destructor
        ~Tile() = default;

        int getValue() const; // returns the value of the tile
        std::string getType() const; // returns the type of the tile
};
#endif
