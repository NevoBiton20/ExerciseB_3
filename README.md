# __**Instructions**__
This project is a remake of the game cattan, its purpose is to create a simpler version of the Settlers of catan,
in addition, the game interacts with the user in order to resemble as much as possible to the real game (With some nuances).
______________________________________________________________________________________________________________________________

## **Game's rules**

### Structure
The game board looks like this:

```
=============Catan Board======================

 Legend :
H - Hills produce brick
F - Forests produce lumber
M - Mountains produce iron
A - Agricultural fields prodeuce grain
P - Pastures produce wool

      +─────+─────+─────+
      | 10M | 2P  | 9F  |
      +─────+─────+─────+
    /  \  /  \  /  \  /  \ 
   +─────+─────+─────+─────+
   | 12A | 6H  | 4P  | 10H |
   +─────+─────+─────+─────+
  /  \  /  \  /  \  /  \  /  \ 
+─────+─────+─────+─────+─────+
| 9A  | 11F | 0D  | 3F  | 8M  |
+─────+─────+─────+─────+─────+
  \  /  \  /  \  /  \  /  \  / 
   +─────+─────+─────+─────+
   | 8F  | 3M  | 4A  | 5P  |
   +─────+─────+─────+─────+
    \  /  \  /  \  /  \  / 
      +─────+─────+─────+
      | 5H  | 6A  | 11P |
      +─────+─────+─────+

Amit Points: 0
Yossi Points: 0
Dana Points: 0

==============================================
```

Instead of hexagons, each tile is represented by a rectangle.

### Basic rules:
In order for the game to start, it requires 3 names of 3 players of the game.
Firstly, when the game starts it randomizes an order of turns to the players and starts to play.
Secondly, each player is asked to place two free settlements and two free roads.
After each player has chose a place to all these structures, he gets resources according to its choices.
A resource producer structure (Settlement or city) is considered part of country if it lies on one of the vertices of its tile rectangle.
On board, ```+``` signs a settlement, every consecutive line such as: ```|``` ```─────``` ```/``` ```\``` signs a road,
``` ` ``` signs a city.
The amount of points needed to win is decided by the user (Default 10).
The first player that gets his turn with the amount of winning points chosen - wins.

### Values:
Road - 1 point
Settlement - 2 points.
City - 3 points.

### Gameplay
After The game first process, at every player's turn, he's asked to make one of 9 actions:
```
1) Place Settlement
2) Place Road
3) Place City
4) Roll Dice
5) BuyCard
6) Use card
7) Trade
8) View your resources
9) Pass turn
```

every action provides all the things it needs (place settlement ask for place, checks if he is valid. trade asks for player and deal, etc...)
A player can roll dice only once a turn (As should be).

## Main components

### Tile
Tile is a class contains of a string and a number, that is the most simple component in the game system, it's purpose is to represent a simple tile on the board:
Example:
```
+─────+
| 10M |
+─────+
```
This tile represents M - Mountaines - which produce iron (This information on other materials is found on the actual board under ```Legend```.
The requested dice roll for this tile to give iron to all its vertices structures is 10.


### Item
Item is a class that should represent every other object on the board (Settlements, Cities, Roads).
this class contains the following fields:
```
int player
std::string kind
int price[]
```
player field holds which player owns this item (Default -1)
kind field holds the name of the item ("Settlement",etc...)
price is an array of 5 integers which should represent how many of each resource in the game is required to buy it. The array format is ```[ 'Brick' , 'Lumber' , 'Wool' , 'Grain' , 'Iron' ]```

in the same file of item, Settlement class, City class and Path class are created and each of them inherit from Item class.
With that implementaion, each item can set its own price.


### Player
Player class should hold the information about each player along his game.
```
std::string name;
int num;
int points;
int resources[5];
int cards[5];
int settlements;
int cities;
int pathes;
```
name - the name of the player
num - the number which represents him (The first player owns the number 0 and so on)
points - hold the amount of points this player currently has
resources - like the same format, holds how much of each resource this player own
cards - owns how much of each card type this player has, cards have unique format like resources: ```[ 'Monopol' , 'Path Build' , 'Year of plenty' , 'Knight' , 'Victory Point' ]```
settlements - Its known that each player is limited with the amount of settltements he can hold, so this number tracks how much he has left
cities, pathes - same as settlements

some of these fields have a getter in order to be able to pull the information from this object.
this class also have some functions like ```buyCard()```, ```buySettltement()``` and so on, so when the player buys something,
the corresponding function is called the the corresponding resources are being taken from the player.


### Board
Board class purpose is to manage all the board related aspects of the game: Place an item on board, hold the board information...
board hold two fields:
```
Tile tiles[19]; 
std::vector<std::vector<std::unique_ptr<Item>>> array; 
```
tiles is a simple array of tile objects, shouid just hold the number and the resource produced from there, nothing is changed along the game, and thus its built in that way.
array is an asymetric vector that should hold the actual game board, the board is composed by roads, settlements and cities, and thus, this is a 2d vector
so each row is a vector of smart pointers of items, each item holds an information that may change along the game, thus, I chose to use smart pointers so there are only one copy of those items and no one of them
is being copied unnecessarily and all the memory will be allocated on the heap and managed smartly and automatically by the pointers.
the most important function of this class is ```void placeItem(std::unique_ptr<Item>, size_t row, size_t index)```, which gets a position and an item and places the item in this place (manages the unique_ptr accordingly)
The board class also own some algorithematic functions such as ```std::vector<int> resourceByPlace(size_t row, size_t index, int tile)``` that receives a position and tile on the board
and returns a formatted resources vector (formatted as descussed earlier) of resources that certain item on the board should receive given a tile that was rolled.


### Bank
The bank class role is a pretty simple one, the bank class holds in a formatted array (like showed earlier) the amount of cards of each type that can be bought in the entire game.
If a player wants to buy a card (assuming he has the required funds for a card), he asks a card from the bank and the bank randomizes and outputs a card to the player.

### **Catan**
The catan class is the most important class in the project and plays the controller role in the project ,The way I chose to implement catan in this project, is by the "Façade" design pattern.
It means that every component composes the game is not accesible by the user, the user just sees the front of the game and makes simple actions. In this way, the user has a minimal API,
which is really desirable when interacting with a game system.

The catan class holds each of the components and manages the interactions between them,
fields:
```
Player players[3];
Board board;
Bank bank;
int turn;
int winAmount;
int mode;
```

players is a 3 players array holding all the users in the game.
board is a board object as shown earlier, through it the class connects between the players and the board.
bank is the bank of the catan, when a player asks for a card, he actually asks from the catan class, and the catan class is the one interacting with the bank and gives it to the player.
turn holds the number of player that its his turn currently, every time the turn is passes, turn number is increased by 1 (returns to the first player when exceeds the players amount)
winAmount is the amount of points required to win the game (given by constructor)
mode is some number created in order to manage different uses of the game (testing, demo, etc..)

**Main functions**
```
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
```
placeSettlement gets a player num and asks it for input, checks the input validation and eventually places it (if met the requirements).
placeCity and placePath works the same
printBoard() just prints the current board to terminal holded by the board object in the current time.
giveResources(int mode) is a dynamic function that makes all the resources giving by rolls thing, (if receives a tile, returns by his value, else (like the first resources give when every player receives resources by his first choices)
rollDice(int p=-1) is a function that rolls the dice (randomizes two numbers, sum them and use the sum) and give resources to the corresponding players, p variable which is default -1 is used to other things related to the game mode.
printWinner, if there is a winner currently, prints him, else , prints that there isn't a winner yet.
buyCard(int player) recives a player (assuming he has the materials for it) and asks from the bank for a random card to give him.
trade function gets a seller, buyer, offer, exchange and ask buyer (in case he can afford it) if he wants to make the deal.
makeTrade is a function that trade function uses, when a buyer wants to make a trade, make trade actually makes it.
useCard gets a player and card (assuming the player has the card) and makes the effect of the card used.

## **Tests and programs**
This project owns a doctest tests file which run some tests to see that the game rules are really being executed correctly.
In addition, there is a demo file which runs a demo run of the game (A quick run of the game to see main functions in action),
this class also has a main file which you can run a full run of the game (until 10 points).
