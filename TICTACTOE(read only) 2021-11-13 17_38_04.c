//Program: Tic-Tac Project C Programming by Enoch Abiodun
//Date: 24/11/2020

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <ctype.h>

/* Some list of combinations for background and text colour change 
    0 = Black
    1 = Blue
    2 = Green
    3 = Aqua
    4 = Red
    5 = Purple
    6 = Yellow
    7 = White
    8 = Gray
    9 = Light Blue
    A = Light Green
    B = Light Aqua
    C = Light Red
    D = Light Purple
    E = Light Yellow
    F = Bright White */

int main()

{
    char player,playername[20];
    char player1;
    char grid[9] = {'0','1', '2','3','4','5','6','7','8'}; //Arrary for grid and the numbers displayed on the grid spaces
    int spaceX[9];
    int position = 0;
    int count = 0,count_tie=0;
    int i,countgame = 1;
    int c = 1, u = 1 ,a = 1;
    int turn = 0;
    int finish = 0;
    int go =1;
    int turngo = 0;
    int playergame = 0, playergame1 = 0;
    int letter = 0;

    system("color 90"); //Makes the backgrounf of the console 'Light blue' and the text colour 'black' ( Can be altered with the digits assigned to the listed Colours)
    
    printf("Enter your name to begin: ");
    gets(playername);
    printf("\n");

    if (playername[0] >= 'a' && playername[0] <= 'z')//Converts first letter of name to capital for User
    {
        playername[0] = playername[0] - 32;
    }

    printf("Welome %s, your oppenent for this Tic-Tac game is Computer to play enter numbers displayed on board!!!\n", playername); // Instruction on how to play

    while (turngo != 3) //Loop asking user to type 1 or 2 with if , else if statements nested in it deciding if the user chose 1 or 2 or a different charater 
    {
        printf("\n%s do you want to go first or second (Enter 1 or 2):  ", playername); //User prompeted to enter 1(to go First) or 2(to go Second)
        scanf("%i", &turngo); //User input a value for int turngo

        if (turngo == 1) //Based on what user Entered, if it is a '1' it will make user go first and exit loop
        {
            turn = 2;
            turngo = 3;
        }
        else if (turngo == 2) //Based on what user Entered, if it is a '2' it will make user go second and exit loop
        {
            turn = 3;
            turngo = 3;
        }
        else //Based on what user Entered, if it was anything other '1' or '2' it will make user have to enter a value until they make a rasonable entry
        {
            printf("Error,%s please try again\n\n", playername);
        }
    }

    while (letter != 2) //Loop asking user to type 1 or 2 with if , else if statements nested in it deciding if the user chose 1 or 2 or a different charater
    {
        printf("\n%s please enter what letter you want to be X(1) or O(2)? ",playername); //  User prompeted to enter 1(to be X) or 2(to be O) **** Only prompted one throughout the whole game ****
        scanf("%i", &letter); // User input a value for int letter

        if (letter == 1) //Based on what user Entered, if it is a '1' it will make user go use X when selecting a grid in future turns and Computuer O and exit loop
        {
            player = 'X';
            player1 = 'O';
            letter = 2;
        }
        else if (letter == 2) //Based on what user Entered, if it is a '2' it will make user go use O when selecting a grid in future turns and Computuer X and exit loop
        {
            player = 'O';
            player1 = 'X';
            letter = 2;
        }
        else //Based on what user Entered, if it was anything other '1' or '2' it will make user have to enter a value until they make a rasonable entry
        {
            printf("Error,Please try again\n\n"); //Taunts user to try again
        }
       
    }
   
    while (go == 1)//A loop that has the loop for the main function of the games and the option to change who goes first and the option to play more than one game if user chooses not the whole game will end
    {
        char grid[9] = {'0','1','2','3','4','5','6','7','8'}; //assigns values of grid to the original state to allow user to be able to choose a space in a grid based on the number displayed
        a = 1; //Sets a to its orginal value so it can enter the loop in line 248
        while (finish != 1) //A loop to compete the main functions of the game will be exited once a player or computer wins or if both ties a game 
        {
            turngo = 0; //Resets turngo to its intial value so it can enter the loop at 248 after beinging changed in the first loop at line 61
            printf("\n");
            printf(" %c | %c | %c \n", grid[0], grid[1], grid[2]); //prints the first row of the grid 
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", grid[3], grid[4], grid[5]); //prints the second row of the grid 
            printf("---|---|---\n");
            printf(" %c | %c | %c \n", grid[6], grid[7], grid[8]); //prints the third row of the grid 
            printf("\n");

            if (turn % 2 == 0) //Statement determines who's turn it is based on the variable turn incremented value on line 237
            {
                while (u != 0) //Loop that awaits for Users input on what space they want to enter printing a error and try again if the space is taken or invalid entry until a empty space is chosen
                {
                    printf("\nIt is %s's (%c) turn, enter the position you want to fill: ",playername,player); //Informs that it is the Users turn
                    scanf("%i", &position); //User Input for a value for position

                    if (grid[position] == 'X' || grid[position] == 'O') //This statment checks if the space on the grid is taken by an O or X
                    {
                        printf("\nInvalid Entry, Please try again\n\n"); //If the statement is true it will print the following and prompt the user again
                    }
                    else if (position != (spaceX[count])) //This statment checks that the space on the grid was not previously entered by comparing the number enter to the ones in the array spaceX
                    {
                        spaceX[count] = position; //position is stored in SpaceX to compare the next time its in this loop
                        grid[position] = player; //The string value assigned to player is then filled into the entered position
                        u = 0; //value of u set to 0 so it will exit the loop
                        system("cls"); //clears console 
                    }
                }
                u = 1; //Resets the value of u back to 1 so it can enter loop at line 123 if another game begins

                if (grid[0] == grid[4] && grid[4] == grid[8]) //checks if grid 0,4 and 8 have the same content (diagonal)
                {
                    printf("%s(%c) wins on a diagonal move!\n\n",playername, player); //if it has the same content it will print the charactor asigned to char player
                    playergame++; //adds 1 to the value of playergame
                    finish = 1; // makes finish equal to one to exit the while loop at line 110
                }
                if (grid[2] == grid[4] && grid[4] == grid[6]) //checks if grid 2,4 and 6 have the same content (diagonal)
                {
                    printf("That's it. %s(%c) has won!\n\n",playername , player); //if it has the same content it will print the charactor asigned to char player
                    playergame++; //adds 1 to the value of playergame
                    finish = 1; //makes finish equal to one to exit the while loop at line 110
                }
                for (i = 0; i < 3; i++) { //changes the value of i in order to be able to check all the rows and columns in one loop
                    if (grid[3 * i] == grid[3 * i + 1] && grid[3 * i + 1] == grid[3 * i + 2]) //checks if all horizontal contents from the row starting 0 then to the row starting with 3 and last the row starting with 6
                    {
                        printf("We have a winner! It is %s(%c).\n\n", playername, player); //if it has the same content it will print the charactor asigned to char player
                        playergame++; //adds 1 to the value of playergame
                        finish = 1; //makes finish equal to one to exit the while loop at line 110
                    }
                    if (grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6]) //checks the vertical contents from coloumn begin with 0 and then with 1 and then with 2
                    {
                        printf("Game over! %s(%c) is the winner\n\n",playername, player); //if it has the same content it will print the charactor asigned to char player
                        playergame++; //adds 1 to the value of playergame
                        finish = 1; //makes finish equal to one to exit the while loop at line 110
                    }
                }
                if (count_tie == 8 && finish == 0) //checks if count_tie value has reached 8 due to it beimg added by 1 each time players take their turns and by 8 assumes all the spaces have been filled an if a winner of the game hasn't been found it exit loop at line 110
                {
                    printf("Tie game...\n\n"); //Informs user game eneded in a draw
                    finish = 1; //makes finish equal to one to exit the while loop at line 110
                }
            }
            else if (turn % 2 != 0) //Statement determines who's turn it is based on line 121 and the variable turn incremented value on line 237
            {
                while (c != 0) //Loop that awaits formulates Computers input on what space it will enter using random numbers if it chooses a filled space it will produce a random number with reduced shuffling time to reduce chance further of it choosing the same and also finding a free place faster
                {
                    srand((int)time(0)); //retruns the number of seconds since 00:00 hours , Jan 1, 1970 so a random number is generated so everytime a new set of random number is generated
                    for (i = 0; i < rand(); i++) { //loop goes on until the value of i is one less then the random number produced
                        position = rand() % 9; //Operation used to set the range of random number produced from 0 to 9
                    }

                    if (grid[position] == 'X' || grid[position] == 'O') //This statment checks if the space on the grid is taken by an O or X
                    {

                        for (i = 0; i < 3; i++) {  //loop goes on until the value of i is one less then 3
                            position = rand() % 9; //Operation used to set the range of random number produced from 0 to 9 and stores it in postion instead of a user having to input it this is how the Computer makes its choice
                        }
                    }
                    else if (position != (spaceX[count])) //This statment checks that the space on the grid was not previously entered by comparing the number enter to the ones in the array spaceX
                    {
                        printf("\nIt is Computer's (%c) turn, enter the position you want to fill: ",player1); //Informs the User that it is the Computers turn 
                        printf("%i", position); //Prints out Computer Space on the grid of choice 
                        printf("\n");

                        spaceX[count] = position; //position is stored in SpaceX to compare the next time its in this loop
                        grid[position] = player1; //The string value assigned to player1 is then filled into the entered position
                        c = 0; //value of c set to 0 so it will exit the loop
                        Sleep(1500); //This function allows for the user to see what move the Computer made for 1.5 seconds before clearing
                        system("cls"); //clears console 
                    }
                }
                c = 1; // Resets the value of c back to 1 so it can enter loop at line 176 if another game begins
                if (grid[0] == grid[4] && grid[4] == grid[8]) //checks if grid 0,4 and 8 have the same content (diagonal)
                {
                    printf("Computer(%c) wins on a diagonal move!\n\n", player1); //if it has the same content it will print the charactor asigned to char player1
                    playergame1++; //adds 1 to the value of playergame1
                    finish = 1; //makes finish equal to one to exit the while loop at line 110
                }
                if (grid[2] == grid[4] && grid[4] == grid[6]) //checks if grid 2,4 and 6 have the same content (diagonal)
                {
                    printf("That's it. Computer(%c) has won!\n\n", player1); //if it has the same content it will print the charactor asigned to char player1
                    playergame1++; //adds 1 to the value of playergame1
                    finish = 1; //makes finish equal to one to exit the while loop at line 110
                }
                for (i = 0; i < 3; i++) { //changes the value of i in order to be able to check all the rows and columns in one loop
                    if (grid[3 * i] == grid[3 * i + 1] && grid[3 * i + 1] == grid[3 * i + 2]) //checks if all horizontal contents from the row starting 0 then to the row starting with 3 and last the row starting with 6
                    {
                        printf("We have a winner! It is Computer(%c)\n\n", player1); //if it has the same content it will print the charactor asigned to char player1
                        playergame1++; //adds 1 to the value of playergame1
                        finish = 1; //makes finish equal to one to exit the while loop at line 110
                    }
                    if (grid[i] == grid[i + 3] && grid[i + 3] == grid[i + 6]) //checks the vertical contents from coloumn begin with 0 and then with 1 and then with 2
                    {
                        printf("Game over! Computer(%c) is the winner\n\n", player1); //if it has the same content it will print the charactor asigned to char player1
                        playergame1++; //adds 1 to the value of playergame1
                        finish = 1; //makes finish equal to one to exit the while loop at line 110
                    }
                }
                if (count_tie == 8 && finish == 0) //checks if count_tie value has reached 8 due to it beimg added by 1 each time players take their turns and by 8 assumes all the spaces have been filled an if a winner of the game hasn't been found it exit loop at line 110
                {
                    printf("Tie game...\n\n"); //Informs user game eneded in a draw
                    finish = 1; //makes finish equal to one to exit the while loop at line 110
                }
            }
            count_tie++; //count_tie has a 1 added to it after every cycle of while loop at line 110 to count number of spaces used up each player turn 
            turn++; //turn has a 1 added to it after every cycle of while loop at line 110 to switch the turns from user to pc each time it goes through the loop
        }

        printf("\n");
        printf(" %c | %c | %c \n", grid[0], grid[1], grid[2]); //prints the first row of the grid 
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", grid[3], grid[4], grid[5]); //prints the second row of the grid
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", grid[6], grid[7], grid[8]); //prints the third row of the grid 
        printf("\n");

        while (a != 0 && turngo != 3)
        {
            printf("Having fun %s!? Enter 1 to continue or Enter 0 to end game... ", playername); //User prompeted to enter 1(to continue) or 0(to end game)
            scanf("%i", &go); //User input a value for int go
            if (go == 1) //Statement only performs when 1 is entered in go by User
            {
                printf("\n\n%s do you want to go first or second (Enter 1 or 2)? ", playername); //User prompeted to enter 1(to go First) or 2(to go Second)
                scanf("%i", &turngo); //User input a value for int turngo

                if (turngo == 1) //Based on what user Entered, if it is a '1' it will make user go first and exit loop
                {
                    turn = 2;
                    turngo = 3;  //The value of turngo is changed to 3 as one of the conditions need to be met to exit the loop 
                }
                else if (turngo == 2) //Based on what user Entered, if it is a '2' it will make user go second and exit loop
                {
                    turn = 3;
                    turngo = 3;  //The value of turngo is changed to 3 as one of the conditions need to be met to exit the loop 
                }
                else //Based on what user Entered, if it was anything other '1' or '2' it will make user have to enter a value until they make a rasonable entry
                {
                    printf("Error,%s please try again\n\n",playername);
                }
                countgame++; //adds a 1 to countgame(1) everytime a new game starts
                printf("\n\nGame %i will begin...\n\n",countgame); //Informs User game is starting
                finish = 0; //Reset value
                int spaceX[9] = {0,1,2,3,4,5,6,7,8}; //Initialise values again
                count= 0; //Reset value
                count_tie = 0; //Reset value
                position = 0; //Reset value
                a = 0; //The value of a is changed to 0 as one of the conditions need to be met to exit the loop 
            }
            else if (go == 0) //Statement only performs when 0 is entered in go by User this prints out a chart of the Number of wins and how many games have been played and then ends the game
            {
                printf("\n\nGame will end,Here are the scores after %i games..(wins)\n\n",countgame);
                printf("   \r%s  | COMPUTER\n",playername);
                printf("___%c___|___%c___\n", player, player1);
                printf("       |        \n");
                printf("   %i   |   %i    \n",playergame,playergame1);
                a = 0; //The value of a is changed to 0 as one of the conditions need to be met to exit the loop 
            }
            else //Based on what user Entered, if it was anything other '1' or '0' it will make user have to enter a value until they make a rasonable entry
            {
                printf("Invalid input,%s please try agin!!!",playername); 
            }
        }
        for (i = 0; i <= 10; i++) // This loop resets the content of the grid 
        {
            grid[position] = i;
        }
    }
    return 0;
}