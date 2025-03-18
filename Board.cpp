#include "Board.h"
#include "Tile.h"
#include <iostream>
using namespace std;
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
void Board::initializeTiles(int board_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    // Keep track of green tile positions to ensure we place exactly 20 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } else if (i == 0) {
            // Set the first tile as Grey for "Pride Rock"
            temp.color = 'Y'; //grey
        } else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        } else {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
                case 0:
                    temp.color = 'B'; // Blue
                    break;
                case 1:
                    temp.color = 'P'; // Pink
                    break;
                case 2:
                    temp.color = 'N'; // Brown
                    break;
                case 3:
                    temp.color = 'R'; // Red
                    break;
                case 4:
                    temp.color = 'U'; // Purple
                    break;
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[board_index][i] = temp;
    }
}
Board::Board()
{
    _player_count = 2;
    // Initialize player position
    _player_position[0] = 0;
    _player_position[1] = 0; 
    // Initialize tiles
    initializeTiles(1);
    initializeTiles(0);
}
Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }
    // Initialize tiles
    initializeBoard();
}
bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}
void Board::displayTile(int board_index, int pos)
{
    // string space = " ";

    string color = "";
    char tile_color = _tiles[board_index][pos].color;


    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>
    // Determine color to display
    if (tile_color == 'R')
    {
        color = RED;
    } else if (tile_color == 'G'){
        color = GREEN;
    } else if (tile_color == 'B'){
        color = BLUE;
    } else if (tile_color == 'U'){
        color = PURPLE;
    } else if (tile_color == 'N'){
        color = BROWN;
    } else if (tile_color == 'P'){
        color = PINK;
    } else if (tile_color == 'O'){
        color = ORANGE;
    } else if (tile_color == 'Y'){
        color = GREY;
    }
    

    string on_tile; 

    bool multiple_players = true; 

    for(int i = 0; i < _player_count; i++)
    {
        if(_player_board[i] == board_index && _player_position[i] == pos)
        {
            if(!multiple_players)
            {
                on_tile += "&";
            }

            on_tile += to_string(i + 1);
            multiple_players = false; 
        }
    }

    if(on_tile.empty())
    {
        on_tile = " ";
    }

    cout << color << "|" << on_tile << "|" << RESET; 
    
    
}

void Board::displayTrack(int board_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(board_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) 
        {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int x)
{
    // Increment player position
    int board_index = _player_board[player_index];
    int pos = _player_position[player_index];
    pos += x;


    _player_position[player_index] = pos; 

    if (pos == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

void Board::chooseBoard(int choice, int player_index)
{
    _player_board[player_index] = choice - 1;
    _player_position[player_index] = 0;
}

int Board::getPlayerBoard(int player_index)
{
    return _player_board[player_index];
}

char Board::getTileColor(int board_index, int pos)
{
    return _tiles[board_index][pos].color;
}
