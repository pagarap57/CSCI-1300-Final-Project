# CSCI-1300-Final-Project

Hello!

The main function is in gameDriver.cpp, this is where the game is actually run.

Assuming that the path is correct, you compile and run the game using the command "g++ Board.cpp Player.cpp gameDriver.cpp; ./a.out" (./a.exe on windows)

**How to Play**

Each player selects a character from a predefined list with unique stats.

Players take turns spinning a virtual spinner (rolling a number from 1 to 6).

The player moves forward based on the roll result.

Depending on the tile landed on, different events may occur:

Regular Tile: No special effects.

Special Tile: May trigger random events, riddles, or stat changes.

Players accumulate Pride Points through strategic decisions and encounters.

The game ends when all players reach Pride Rock, and the player with the most Pride Points wins.

Features

Character Selection: Unique characters with different starting attributes.

Random Events: Unexpected events that alter the gameplay.

Riddles: Players may be asked riddles to gain extra Pride Points.

Board Mechanics: A dynamic two-lane board with different tile types.

Turn-Based Gameplay: Players take sequential turns to move across the board.
