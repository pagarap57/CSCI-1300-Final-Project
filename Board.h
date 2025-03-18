#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
class Board
{
    private:
        static const int _BOARD_SIZE = 52;
        static const int _NUM_BOARDS = 2; 
        Tile _tiles[2][_BOARD_SIZE];
        static const int _MAX_PLAYERS = 2;
        int _player_count;
        int _player_position[_MAX_PLAYERS]; //integer array
        int _player_board[_MAX_PLAYERS];
        void displayTile(int board_index, int pos);
        void initializeTiles(int board_index);
    public:
        Board();
        Board(int player_count);
        void displayTrack(int board_index);
        void initializeBoard();
        void displayBoard();
        bool movePlayer(int player_index, int x);
        int getPlayerPosition(int player_index) const;
        bool isPlayerOnTile(int player_index, int pos);
        char getTileColor(int board_index, int pos);
        int getPlayerBoard(int player_index);
        void chooseBoard(int choice, int player_index);
};
#endif
