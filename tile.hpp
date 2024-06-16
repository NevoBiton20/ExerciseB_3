/* A simple Tile class which describes an element of the catan board*/

#include <string>
class Tile
{
    private:
        int num; // resources receving value
        std::string type; // tile type: Meadow, Mountains, Hills, Agricultural, Forest, Desert
        
    public:    
        // Tile Constructor
        Tile(int n, std::string s) : num(n), type(s) {}

        // Destructor
        ~Tile() = default; // Default destructor 

        int getValue(); // returns the value of the tile
        std::string getType(); // returns the type of the tile
};
