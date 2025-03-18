#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <fstream>

#include "Board.h"
#include "Tile.h"
#include "Player.h"


using namespace std;

void seperator()
{
    cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
}


void delete_line(const char *file_name, int n) 
{  
	ifstream is(file_name); 
	ofstream ofs; 

	ofs.open("temp.txt", ofstream::out); 
 
	char c; 
	int line_number = 1; 
	while (is.get(c)) 
	{ 
		if (c == '\n') 
        {
            line_number++; 
        }
		if (line_number != n)
        {
            ofs << c; 
        }
	} 
	ofs.close(); 
	is.close(); 
	remove(file_name); 
	rename("temp.txt", file_name); 
} 

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int length = input_string.length();
    string temp = "";
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(input_string[i] == separator)
        {
            if(count < ARR_SIZE)
            {
                arr[count] = temp;
                count++;
                temp = "";
            }else{
                return -1;
            }
        }else{
            temp += input_string[i];
        }
    }
    if(temp != "" && count < ARR_SIZE)
    {
        arr[count] = temp;
        count++;
    }
    else if(count >= ARR_SIZE)
    {
        return -1;
    }
    return count;
}

int calculatePridePoints(int stamina, int strength, int wisdom)
{
    int pridePoints;
    pridePoints += (stamina/100) * 1000;
    pridePoints += (strength/100) * 1000;
    pridePoints += (wisdom/100) * 1000;
    return pridePoints;
}

int main()
{
    srand(time(0));
    
    cout << "Welcome to the Lion King Game Player 1. Enter your name: " << endl;
    string player1Name;
    cin >> player1Name;

    cout << "Hello " << player1Name << " Select a character (enter number):" << endl;

    ifstream characters("characters.txt");

    const int arrSize = 6;
    string arr[arrSize];
    int currentLine = 1;

    if(characters.is_open())
    {
        string line;
        while(getline(characters,line))
        {
            split(line,'|', arr, arrSize);
            cout << currentLine << ")" << endl;
            cout << "Name: " << arr[0] << endl;
            cout << "Age: " << arr[1] << endl;
            cout << "Strength: " << arr[2] << endl;
            cout << "Stamina: " << arr[3] << endl;
            cout << "Wisdom: " << arr[4] << endl;
            cout << "Pride Points: " << arr[5] << endl;
            seperator();
            currentLine++;
        }
        currentLine = 1; //reset currentline to use again later.
        characters.close();
    }
    int character1;
    cin >> character1;


    
    while(character1 < 1 || character1 > 5) //if player enters int out of range, keep asking again
    {
        cout << "Please select a valid character from the list." << endl;
        ifstream characters("characters.txt");
        if(characters.is_open())
        {
            string line;
            while(getline(characters,line))
            {
                split(line,'|', arr, arrSize);
                cout << currentLine << ")" << endl;
                cout << "Name: " << arr[0] << endl;
                cout << "Age: " << arr[1] << endl;
                cout << "Strength: " << arr[2] << endl;
                cout << "Stamina: " << arr[3] << endl;
                cout << "Wisdom: " << arr[4] << endl;
                cout << "Pride Points: " << arr[5] << endl;
                seperator();
                currentLine++;
            }
            currentLine = 1; //reset currentline to use again later.
            characters.close();
        }
        cin >> character1;
    }

    //switch case to populate player object with the selected character's stats.
    Player player1;
    switch(character1)
    {
        case 1:
            player1 = Player("Apollo", 5, 500, 500, 1000);
            break;
        case 2:
            player1 = Player("Mane",8,900,600,1000);
            break;
        case 3:
            player1 = Player("Elsa",12,900,700,500);
            break;
        case 4:
            player1 = Player("Zuri", 7,600,500,900);
            break;
        case 5:
            player1 = Player("Roary",18,1000,500,500);
            break;
    }

    delete_line("characters.txt", character1); //update the characters.txt file
    //DISCLAIMER: YOU MUST MANUALLY REWRITE THE ORIGINAL CHARACTER LIST BEFORE YOU START A NEW GAME

    cout << "Welcome to the Lion King Game Player 2. Enter your name:" << endl;
    string player2Name;
    cin >> player2Name;

    cout << "Hello " << player2Name << " Select a character (enter number):" << endl;

    ifstream updatedCharacters("characters.txt");

    if(updatedCharacters.is_open())
    {
        string line;
        while(getline(updatedCharacters,line))
        {
            split(line,'|', arr, arrSize);
            cout <<"("  << currentLine << ")" << endl;
            cout << "Name: " << arr[0] << endl;
            cout << "Age: " << arr[1] << endl;
            cout << "Strength: " << arr[2] << endl;
            cout << "Stamina: " << arr[3] << endl;
            cout << "Wisdom: " << arr[4] << endl;
            cout << "Pride Points: " << arr[5] << endl;
            seperator();
            currentLine++;
        }
        currentLine = 1; //reset currentline to use again later.
        updatedCharacters.clear();
        updatedCharacters.seekg(0); //no need to close the file yet, we need it for later.
    }
    int character2;
    cin >> character2;

    while(character2 < 1 || character2 > 4) //if player enters int out of range, keep asking again
    {
        cout << "Please select a valid character from the list." << endl;
        ifstream characters("characters.txt");
        if(characters.is_open())
        {
            string line;
            while(getline(characters,line))
            {
                split(line,'|', arr, arrSize);
                cout << currentLine << ")" << endl;
                cout << "Name: " << arr[0] << endl;
                cout << "Age: " << arr[1] << endl;
                cout << "Strength: " << arr[2] << endl;
                cout << "Stamina: " << arr[3] << endl;
                cout << "Wisdom: " << arr[4] << endl;
                cout << "Pride Points: " << arr[5] << endl;
                seperator();
                currentLine++;
            }
            currentLine = 1; //reset currentline to use again later.
            characters.close();
        }
        cin >> character2;
    }

    Player player2;
    if(updatedCharacters.is_open())
    {
        string line;
        for(int i = 1; i <= character2; i++)// i represents the current line, we only need to loop until the selected line's character (int character2).
        {
            getline(updatedCharacters, line);
            if(i == character2) //if the current line is equal to selected character's line, store stats into player2 object using Player constructor.
            {
                split(line, '|', arr, arrSize);
                player2 = Player(arr[0], stoi(arr[1]), stoi(arr[2]), stoi(arr[3]), stoi(arr[4]));
            }else{
                continue; //if current line isnt equal to selected character's line, do nothing.
            }
        }
    }

    Board board(2); //initialize board.

    cout <<"Welcome young cubs. As you embark on your journey to get to the Pride Lands, you will face many obstacles. \nYou must now select a path type to begin your journey" << endl;
    
    cout << player1Name << ", choose carefully:" << endl;
    cout <<"(1) Cub Training \n(2) Pride Lands" << endl;
    int player1Path;
    cin >> player1Path;

    while (player1Path < 1 || player1Path > 2) 
    {
        cout << "Please select a valid path type." << endl;
        cout << "(1) Cub Training \n(2) Pride Lands" << endl;
        cin >> player1Path;
    }

    board.chooseBoard(player1Path, 0);
    
    int player1Advisor; //int represents the line that the advisor chosen is found on in advisors.txt
    bool advisorTracker1; //true if player has an advisor, false if they don't; dependant on path type.
    string advisor1; //stores advisor
    int player1AdvisorLine; // Store the chosen advisor's line number for player 1

    int player2Advisor;
    bool advisorTracker2;
    string advisor2;
    int player2AdvisorLine;

    if(player1Path == 1)
    {
        advisorTracker1 = true;
        player1.setPridePoints(player1.getPridePoints() - 5000);
        player1.setStamina(player1.getStamina() + 500);
        player1.setStrength(player1.getStrength() + 500);
        player1.setWisdom(player1.getWisdom() + 1000);

        cout << "-5000 Strength, +500 Strength, +500 Stamina, +1000 Wisdom" << endl;
        seperator();
        cout << "Now choose your advisor to mentor you along your journey." << endl;

        ifstream advisors("advisors.txt");
        if(advisors.is_open())
        {
            string line;
            while(getline(advisors,line))
            {
                cout <<"(" <<currentLine << ") ";
                cout << line << endl;
                currentLine++;
            }
            currentLine = 1; //reset to use later
            advisors.clear();
            advisors.seekg(0);
        }
        seperator();

        cin >> player1Advisor;

        while(player1Advisor < 1 || player1Advisor > 5)
        {
            if(advisors.is_open())
            {
                string line;
                while(getline(advisors,line))
                {   
                    cout <<"(" <<currentLine << ") ";
                    cout << line << endl;
                    currentLine++;
                }
                currentLine = 1; //reset to use later
                advisors.clear();
                advisors.seekg(0);
            }
            seperator();
            cin >> player1Advisor;
        }
        if(advisors.is_open())
        {
            string line;
            int lineNumber = 1;
            while(getline(advisors, line))
            {
                if(lineNumber == player1Advisor)
                {
                    advisor1 = line;
                    player1AdvisorLine = lineNumber; // Store the chosen advisor's line number
                    break;
                }
                lineNumber++;
            }
        }
        cout << advisor1 << endl;
        advisors.close();
    }
    else
    {
        advisorTracker1 = false;
        player1.setPridePoints(player1.getPridePoints() + 5000);
        player1.setStamina(player1.getStamina() + 200);
        player1.setStrength(player1.getStrength() + 200);
        player1.setWisdom(player1.getWisdom() + 2000);
    }

    cout << player2Name << ", choose carefully:" << endl;
    cout <<"(1) Cub Training \n(2) Pride Lands" << endl;

    int player2Path;
    cin >> player2Path;

    while (player2Path < 1 || player2Path > 2) 
    {
        cout << "Please select a valid path type." << endl;
        cout << "(1) Cub Training \n(2) Pride Lands" << endl;
        cin >> player2Path;
    }

    board.chooseBoard(player2Path, 1);

    if(player2Path == 1)
    {
        advisorTracker2 = true;
        player2.setPridePoints(player2.getPridePoints() - 5000);
        player2.setStamina(player2.getStamina() + 500);
        player2.setStrength(player2.getStrength() + 500);
        player2.setWisdom(player2.getWisdom() + 1000);

        ifstream advisors("advisors.txt");
        if(advisors.is_open())
        {
            string line;
            int currentLine = 1; // Initialize currentLine here
            int lineNumber = 1;
            while(getline(advisors,line))
            {
                if(lineNumber != player1AdvisorLine) // Skip the chosen advisor's line for player 1
                {
                    cout <<"(" <<currentLine << ") ";
                    cout << line << endl;
                    currentLine++;
                }
                lineNumber++;
            }
            advisors.clear();
            advisors.seekg(0);
        }
        seperator();
        cin >> player2Advisor;
        while(player2Advisor < 1 || player2Advisor > 4) // Adjust the range to 4 since one advisor is already chosen
        {
            if(advisors.is_open())
            {
                string line;
                int currentLine = 1; // Initialize currentLine here
                int lineNumber = 1;
                while(getline(advisors,line))
                {   
                    if(lineNumber != player1AdvisorLine) // Skip the chosen advisor's line for player 1
                    {
                        cout <<"(" << currentLine << ") ";
                        cout << line << endl;
                        currentLine++;
                    }
                    lineNumber++;
                }
                advisors.clear();
                advisors.seekg(0);
            }
            seperator();
            cin >> player2Advisor;
        }
        if(advisors.is_open())
        {
            string line;
            int lineNumber = 1;
            int adjustedLineNumber = 1; // Adjusted line number to match the displayed options
            while(getline(advisors, line))
            {
                if(lineNumber != player1AdvisorLine)
                {
                    if(adjustedLineNumber == player2Advisor)
                    {
                        advisor2 = line;
                        player2AdvisorLine = lineNumber; // Store the chosen advisor's line number
                        break;
                    }
                    adjustedLineNumber++;
                }
                lineNumber++;
            }
        }
    }
    else
    {
        advisorTracker2 = false;
        player2.setPridePoints(player2.getPridePoints() + 5000);
        player2.setStamina(player2.getStamina() + 200);
        player2.setStrength(player2.getStrength() + 200);
        player2.setWisdom(player2.getWisdom() + 2000);
    }

    board.displayBoard();
    seperator();
    int currentPlayer = 0;

    while(!board.isPlayerOnTile(0,51) || !board.isPlayerOnTile(1,51))
    {
        
        int chosenChoice;
        int lastRoll;
        bool reroll = false;
        
        do{
            if(currentPlayer == 0)
            {
                cout << player1Name <<", it's your turn. Pick an option from the menu below." << endl;
            }else{
                cout << player2Name <<", it's your turn. Pick an option from the menu below." << endl;
            }
            cout <<"(1) Check Player Stats: Review Info about yourself." << endl;
            cout <<"(2) Check Position: Display board to view current position." << endl;
            cout <<"(3) Review your Advisor: Check who your current advisor is on the game." << endl;
            cout <<"(4) Move Forward: For each player's turn, access this option to spin the virtual spinner." << endl;
            cout <<"(5) Review Character: Check your character name and age." << endl;
            cin >> chosenChoice;
            seperator();

            if(chosenChoice == 4)
            {
                int rollDie = 1 + rand() % 6; 
                lastRoll = rollDie;
                int currentPosition = board.getPlayerPosition(currentPlayer);
                int newPosition = currentPosition + rollDie;

                cout << "You rolled a: " << rollDie << endl;
                if(newPosition > 51)
                {
                    newPosition = 51;
                }

                board.movePlayer(currentPlayer, newPosition - currentPosition);
            }

            if(chosenChoice == 1)
            {
                if(currentPlayer == 0)
                {
                    cout<<"Here are your stats, " << player1Name << endl;
                    player1.printStats();
                    seperator();
                }else{
                    cout<<"Here are your stats, " << player1Name << endl;
                    player2.printStats();
                    seperator();
                }
            }

            if(chosenChoice == 2)
            {
                board.displayBoard();

                seperator();
            }

            if(chosenChoice == 3)
            {
                if(currentPlayer == 0)
                {
                    if(advisorTracker1) // boolean checks if they have an advisor or not
                    {
                        int nestedChoice;
                        cout << player1Name << " 's Advisor: " << advisor1 << endl;
                        seperator();
                    }else{
                        cout << "You do not have an advisor." << endl;
                        seperator();
                    }
                }else{
                    if(advisorTracker2)
                    {
                        cout << player2Name <<"'s Advisor: " << advisor2 << endl;
                        seperator();
                    }else{
                        cout << "You do not have an advisor." << endl;
                        seperator();
                    }
                }
            }
            if(chosenChoice == 5)
            {
                if(currentPlayer == 0)
                {
                    cout << player1.getName() <<", age " << player1.getAge() <<endl;
                    seperator();
                }else{
                    cout << player2.getName() <<", age " << player2.getAge() << endl;
                    seperator();
                }
            }
        }while(chosenChoice != 4);

        
        board.displayBoard(); //display the board here to show player after they moved
        seperator();
        //


        char color = board.getTileColor(board.getPlayerBoard(currentPlayer),board.getPlayerPosition(currentPlayer));

        
        switch(color){
            case 'R':
            {
                //red, move back 10 tiles and lose 100 Stamina, Strength, and Wisdom Points.

                cout << "You landed on the Graveyard tile!! You moved back 10 steps and lose 100 Stamina, Stregnth, and Wisdom Points" << endl;
                int currentPosition = board.getPlayerPosition(currentPlayer);
                int newPosition = currentPosition - 10;
                
                if (newPosition < 0) {
                    newPosition = 0; //makes sure that player doesnt go behind the board.
                }
                
                board.movePlayer(currentPlayer, newPosition - currentPosition); 

                if(currentPlayer == 0)
                {
                    player1.setStamina(player1.getStamina() - 100);

                }else{
                    player2.setStamina(player2.getStamina() - 100);
                }

                if(currentPlayer == 0)
                {
                    player1.setStrength(player1.getStrength() - 100);
                }else{
                    player2.setStrength(player2.getStrength() - 100);
                }

                if(currentPlayer == 0)
                {
                    player1.setWisdom(player1.getWisdom() - 100);
                }else{
                    player2.setWisdom(player2.getWisdom() - 100);
                }
                break;
            }
                
            case 'G':
            {
                if(currentPlayer == 0)
                {
                    if(player1Path == 1)
                    {
                        int x = rand() % 2; 
                        if(x == 0)
                        {
                            int selectedLine = 1 + rand() % 25;

                            ifstream events("random_events_path_1.txt");

                            if(events.is_open())
                            {
                                string randomArr[arrSize];
                                const int arrSize = 4;
                                string line;
                                while (getline(events, line)) {
                                    if (currentLine == selectedLine) {
                                        split(line, '|', randomArr, arrSize);
                                        cout << "Random event: " << randomArr[0] << endl;

                                        int advisor = stoi(randomArr[2]);
                                        int pridePointsChange = stoi(randomArr[3]);

                                        if (advisor != 0) 
                                        {
                                            if (player1AdvisorLine == advisor) {
                                                cout << "Your advisor protected you. (No Pride Points lost)." << endl;
                                            } else {
                                                player1.setPridePoints(player1.getPridePoints() + pridePointsChange);
                                                cout << "Pride points lost: " << pridePointsChange << endl;
                                            }
                                        } else {
                                            player1.setPridePoints(player1.getPridePoints() + pridePointsChange);
                                            cout << "Pride points gained: " << pridePointsChange << endl;
                                        }
                                        break;
                                    }
                                    currentLine++;
                                }
                                currentLine = 1;
                                events.clear();
                                events.seekg(0);
                            }
                        }
                    }else{
                        int x = rand() % 2; 
                        if(x == 0)
                        {
                            int selectedLine = 1 + rand() % 25;

                            ifstream events("random_events_path_2.txt");

                            if(events.is_open())
                            {
                                string randomArr[arrSize];
                                const int arrSize = 4;
                                string line;
                                while(getline(events,line))
                                {
                                    if(currentLine == selectedLine)
                                    {
                                        split(line, '|', randomArr, arrSize);
                                        cout << "Random event: " << randomArr[0] << endl;

                                        int advisor = stoi(randomArr[2]);
                                        int pridePointsChange = stoi(randomArr[3]);

                                        if (advisor != 0) 
                                        {
                                            if (player1AdvisorLine == advisor) 
                                            {
                                                cout << "Your advisor protected you. (No Pride Points lost)." << endl;
                                            }else{
                                                player1.setPridePoints(player1.getPridePoints() + pridePointsChange);
                                                cout << "Pride points lost: " << pridePointsChange << endl;
                                            }
                                        }else{
                                            player1.setPridePoints(player1.getPridePoints() + pridePointsChange);
                                            cout << "Pride points gained: " << pridePointsChange << endl;
                                        }
                                        break;
                                    }
                                    currentLine++;
                                }
                                currentLine = 1;
                                events.clear();
                                events.seekg(0);
                            }
                        }
                    }
                }else{
                    if(player2Path == 1)
                    {
                        int x = rand() % 2; 
                        if(x == 0)
                        {
                            int selectedLine = 1 + rand() % 25;

                            ifstream events("random_events_path_1.txt");

                            if(events.is_open())
                            {
                                string randomArr[arrSize];
                                const int arrSize = 4;
                                string line;
                                while(getline(events,line))
                                {
                                    if(currentLine == selectedLine)
                                    {
                                        split(line, '|', randomArr, arrSize);
                                        cout << "Random event: " << randomArr[0] << endl;

                                        int advisor = stoi(randomArr[2]);
                                        int pridePointsChange = stoi(randomArr[3]);

                                        if (advisor != 0) 
                                        {
                                            if (player2AdvisorLine == advisor) {
                                                cout << "Your advisor protected you. (No Pride Points lost)." << endl;
                                            } else {
                                                cout << player2.getPridePoints() <<endl;
                                                player2.setPridePoints(player2.getPridePoints() + pridePointsChange);
                                                cout << "Pride points lost: " << pridePointsChange << endl;
                                                cout << player2.getPridePoints() <<endl;
                                            }
                                        } else {
                                            cout << player2.getPridePoints() <<endl;
                                            player2.setPridePoints(player2.getPridePoints() + pridePointsChange);
                                            cout << "Pride points gained: " << pridePointsChange << endl;
                                            cout << player2.getPridePoints() <<endl;
                                        }
                                        break;
                                    }
                                    currentLine++;
                                }
                                currentLine = 1;
                                events.clear();
                                events.seekg(0);
                            }
                        }
                    }else{
                        int x = rand() % 2; 
                        if(x == 0)
                        {
                            int selectedLine = 1 + rand() % 25;

                            ifstream events("random_events_path_2.txt");

                            if(events.is_open())
                            {
                                string randomArr[arrSize];
                                const int arrSize = 4;
                                string line;
                                while(getline(events,line))
                                {
                                    if(currentLine == selectedLine)
                                    {
                                        split(line, '|', randomArr, arrSize);
                                        cout << "Random event: " << randomArr[0] << endl;

                                        int advisor = stoi(randomArr[2]);
                                        int pridePointsChange = stoi(randomArr[3]);

                                        if (advisor != 0) 
                                        {
                                            if (player2AdvisorLine == advisor) {
                                                cout << "Your advisor protected you. (No Pride Points lost)." << endl;
                                            } else {
                                                player2.setPridePoints(player2.getPridePoints() + pridePointsChange);
                                                cout << "Pride points lost: " << pridePointsChange << endl;
                                            }
                                        } else {
                                            player2.setPridePoints(player2.getPridePoints() + pridePointsChange);
                                            cout << "Pride points gained: " << pridePointsChange << endl;
                                        }
                                        break;
                                    }
                                    currentLine++;
                                }
                                currentLine = 1;
                                events.clear();
                                events.seekg(0);
                            }
                        }
                    }
                }
                //green
                break;
            }
            case 'B':
                {
                    cout <<"You’ve found a peaceful oasis! You get an extra turn to keep moving forward—take a deep breath and relax; you also gain Stamina, Strength, and Wisdom Points." <<endl;
                    cout <<"Stamina Gained: 200" <<endl;
                    cout <<"Strength Gained: 200" <<endl;
                    cout <<"Wisdom Gained: 200" <<endl;
                    if(currentPlayer == 0)
                    {
                        player1.setStamina(player1.getStamina() + 200);
                        player1.setStrength(player1.getStrength() + 200);
                        player1.setWisdom(player1.getWisdom() + 200);
                    }
                    reroll = true;
                    
                }
            case 'U':
            {
                //purple
                cout << "Time for a test of wits! Answer the following riddle." << endl;
                int x = 1 + rand() % 27;

                ifstream riddles("riddles.txt");

                if(riddles.is_open())
                {
                    string riddlesArr[arrSize];
                    const int arrSize = 2;
                    string line;
                    
                    while(getline(riddles,line))
                    {
                        if(currentLine == x)
                        {
                            split(line,'|',riddlesArr,2);
                            cout << riddlesArr[0] <<endl;

                            string input;
                            string answer = riddlesArr[1];
                            cin >> input;

                            if(input == answer)
                            {
                                cout << "Correct!" <<endl;
                                cout << "Wisdom Gained: 500" <<endl;
                                seperator();

                                if(currentPlayer == 0)
                                {
                                    player1.setWisdom(player1.getWisdom()+500);
                                }else{
                                    player2.setWisdom(player2.getWisdom()+500);
                                }

                            }else{
                                cout << "Incorrect, the answer was "<< answer <<endl;
                                cout<< "No wisdom gained" << endl;
                                seperator();
                            }
                        }
                        currentLine++;
                    }
                }
                currentLine = 1;
                break;
            }
            case 'N':
                //brown
                cout << "The Hyenas are on the prowl! They drag you back to where you were last, and the journey comes at a cost." <<endl;
                cout << "Stamina Lost:  -300" <<endl;
                seperator();
                if(currentPlayer == 0)
                {
                    player1.setStamina(player1.getStamina() - 300);
                }else{
                    player2.setStamina(player2.getStamina() - 300);
                }
                board.movePlayer(currentPlayer, -lastRoll);
                break;
            case 'P':
                {
                    cout << "Welcome to the land of enrichment, you get to choose an advisor from the available list of advisors. If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor. Don’t forget - an advisor can protect you from random events that negatively impact your Pride Points." << endl;
                    
                    if (currentPlayer == 0) {
                        // Increase stamina, strength, and wisdom by 300
                        player1.setStamina(player1.getStamina() + 300);
                        player1.setStrength(player1.getStrength() + 300);
                        player1.setWisdom(player1.getWisdom() + 300);
                    } else {
                        player2.setStamina(player2.getStamina() + 300);
                        player2.setStrength(player2.getStrength() + 300);
                        player2.setWisdom(player2.getWisdom() + 300);
                    }
                    
                    bool showAdvisors = false;
                    if (currentPlayer == 0) {
                        if (advisor1.empty()) {
                            cout << "Do you want to choose an advisor? (y/n): ";
                        } else {
                            cout << "You already have an advisor: " << advisor1 << endl;
                            cout << "Do you want to change your advisor? (y/n): ";
                        }
                    } else {
                        if (advisor2.empty()) {
                            cout << "Do you want to choose an advisor? (y/n): ";
                        } else {
                            cout << "You already have an advisor: " << advisor2 << endl;
                            cout << "Do you want to change your advisor? (y/n): ";
                        }
                    }
                    
                    string response;
                    cin >> response;
                    if (response == "y") {
                        showAdvisors = true;
                    }
                    
                    if (showAdvisors) {
                        ifstream advisors("advisors.txt");
                        if (!advisors.is_open()) {
                            cout << "Failed to open advisors file." << endl;
                            break;
                        }
                    
                        cout << "Available advisors:" << endl;
                        string line;
                        int lineNumber = 1;
                        while (getline(advisors, line)) {
                            // Skip the advisors already taken by the other player
                            if ((currentPlayer == 0 && lineNumber == player2AdvisorLine) || (currentPlayer == 1 && lineNumber == player1AdvisorLine)) {
                                lineNumber++;
                                continue;
                            }
                            cout << "(" << lineNumber << ") " << line << endl;
                            lineNumber++;
                        }
                        seperator();
                        advisors.clear();
                        advisors.seekg(0);
                    
                        int choice;
                        cout << "Choose an advisor (enter the number): ";
                        cin >> choice;
                    
                        while ((currentPlayer == 0 && choice == player2AdvisorLine) || (currentPlayer == 1 && choice == player1AdvisorLine) || choice < 1 || choice >= lineNumber) {
                            cout << "Invalid choice. Please choose a valid advisor number: ";
                            cin >> choice;
                        }
                    
                        lineNumber = 1;
                        while (getline(advisors, line)) {
                            if (lineNumber == choice) {
                                if (currentPlayer == 0) {
                                    advisor1 = line;
                                    player1AdvisorLine = lineNumber; // Store the chosen advisor's line number
                                    cout << "You have chosen: " << line << endl;
                                    seperator();
                                } else {
                                    advisor2 = line;
                                    player2AdvisorLine = lineNumber; // Store the chosen advisor's line number
                                    cout << "You have chosen: " << line << endl;
                                    seperator();
                                }
                                break;
                            }
                            lineNumber++;
                        }
                        advisors.close();
                    }
                    break;
                }
        }

        if(reroll == false)
        {
            if(currentPlayer == 0) //this is where we switch the turns of players
            {
                currentPlayer = 1;
            }else{
                currentPlayer = 0;
            }
        }else{
            reroll = true;
        }
    }
    //at this point both players reach orange

    int player1Score = calculatePridePoints(player1.getStamina(), player1.getStrength(), player1.getWisdom());
    int player2Score = calculatePridePoints(player2.getStamina(), player2.getStrength(), player2.getWisdom());

    ofstream results("gameResults.txt");

    if(player1Score > player2Score)
    {
        results << "Game over! Here are the rankings (based on pride points)" << endl;
        results << endl;
        results << "1) " << player1Name <<", Total Pride Points: " << player1Score << endl;
        results << "2) " << player2Name << ", Total Pride Points: " << player2Score << endl;
    }else{
        results << "Game over! Here are the rankings (based on pride points)" << endl;
        results << endl;
        results << "1) " << player2Name <<", Total Pride Points: " << player2Score << endl;
        results << "2) " << player1Name<< ", Total Pride Points: " << player1Score << endl;
    }

    ifstream resultsPrinted("gameResults.txt");
    if(resultsPrinted.is_open())
    {
        string line;
        while(getline(resultsPrinted,line))
        {
            cout << line << endl;
        }
    }
}
