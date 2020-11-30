//This is a 2 player checker game
//
#include <iostream>

using namespace std;

char board[8][8] =
{
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
};

char turn = 'B';
bool leap;
bool game_running = true;
int row1, row2, column1, column2;

void display_board();// 
void input();//
bool check_move();//where is the 
void move(); // hasta aqui sirve
void do_leap();
void king();
void game_over();

int main()
{
    cout << "***CHECKER GAME***\n";
    cout << "Player 1 [b]\n";
    cout << "Player 2 [r]\n\n";
    cout << "Multiple leaps are supported.\n";
    cout << "A capital letter represents a king piece.\n";
    cout << "NOTE: Rows and columns are counted starting from 0, not 1.\n";
    cout << "<------COLUMNS------>\n";
    cout << "^\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "ROWS\n";
    cout << "|\n";
    cout << "|\n";
    cout << "|\n";
    cout << "v\n\n";
    cout << "NOTE: Resize your console screen so that this line fits on the screen:\n";
    cout << "_____________________________________________________________________________________\n\n";
    cout << "Press enter to begin...";
    cin.get();//This waits for the user to press enter before continuing

    while (game_running)//game_running was initialzed to true so will run
    {
        display_board();//function is called to display board

        if (turn == 'B')//was initialzed to 'B'line 19
        {
            cout << "--Player 1 [B]--\n";//says player 1 turn
        }
        else if (turn == 'R')
        {
            cout << "--Player 2 [R]--\n";
        }
        //funcitons called
        input();
        move();
        //king();
        //game_over();
    }

    if (turn == 'B')
    {
        cout << endl << endl << "Player 2 [Red] wins!!!\n";
    }
    else if (turn == 'R')
    {
        cout << endl << endl << "Player 1 [Black] wins!!!\n";
    }

    cout << "GAME OVER!\n";
}

void display_board()//board displayed is similar to tic tac toe except its bigger, has empty spaces
{
    cout << "==================================================================================\n\n\n\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
    cout << "  _________________________________________________________________________________\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "0 |    " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    "  << board[0][3] << "    |    " << board[0][4] << "    |    " << board[0][5] << "    |    " << board[0][6] << "    |    " << board[0][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "1 |    " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    "  << board[1][3] << "    |    " << board[1][4] << "    |    " << board[1][5] << "    |    " << board[1][6] << "    |    " << board[1][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "2 |    " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    "  << board[2][3] << "    |    " << board[2][4] << "    |    " << board[2][5] << "    |    " << board[2][6] << "    |    " << board[2][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "3 |    " << board[3][0] << "    |    " << board[3][1] << "    |    " << board[3][2] << "    |    "  << board[3][3] << "    |    " << board[3][4] << "    |    " << board[3][5] << "    |    " << board[3][6] << "    |    " << board[3][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "4 |    " << board[4][0] << "    |    " << board[4][1] << "    |    " << board[4][2] << "    |    "  << board[4][3] << "    |    " << board[4][4] << "    |    " << board[4][5] << "    |    " << board[4][6] << "    |    " << board[4][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "5 |    " << board[5][0] << "    |    " << board[5][1] << "    |    " << board[5][2] << "    |    "  << board[5][3] << "    |    " << board[5][4] << "    |    " << board[5][5] << "    |    " << board[5][6] << "    |    " << board[5][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "6 |    " << board[6][0] << "    |    " << board[6][1] << "    |    " << board[6][2] << "    |    "  << board[6][3] << "    |    " << board[6][4] << "    |    " << board[6][5] << "    |    " << board[6][6] << "    |    " << board[6][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "7 |    " << board[7][0] << "    |    " << board[7][1] << "    |    " << board[7][2] << "    |    "  << board[7][3] << "    |    " << board[7][4] << "    |    " << board[7][5] << "    |    " << board[7][6] << "    |    " << board[7][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}



void input()//asks player first to CHOOSE their piece using row and column # for exact location, then to MOVE using same concept
{
    cout << "Move piece\n";
    cout << "Row: ";
    cin >> row1;//
    cout << "Column: ";
    cin >> column1;

    while (row1 < 0 || row1 > 7 || column1 < 0 || column1 > 7)//CHOOSE PIECE ...makes sure the input(Chosen piece) is within range
    {
        cout << "Incorrect input. Enter numbers between 0 and 7.\n";//runs if input out of range
        cout << "Move piece\n";
        cout << "Row: ";
        cin >> row1;//allows another chance to enter input 
        cout << "Column: ";
        cin >> column1;
    }

    cout << "To box\n";//allows to MOVE to another location based on row and column
    cout << "Row: ";
    cin >> row2;
    cout << "Column: ";
    cin >> column2;

    while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)//MOVE PIECE...makes sure the move is legal
    {
        cout << "Incorrect input. Enter numbers between 0 and 7.\n";
        cout << "To box\n";
        cout << "Row: ";
        cin >> row2;
        cout << "Column: ";
        cin >> column2;
    }

    while (check_move() == false)//check_move is called....and checks if it is false
    {
        cout << "ILLEGAL MOVE!!\n";
        input();//input function starts again at line 133
    }

}

bool check_move()
{
    //it checks if a non-king piece is moving backwards.
    if (board[row1][column1] != 'B' && board[row1][column1] != 'R')
    {
        if ((turn == 'B' && row2 < row1) || (turn == 'R' && row2 > row1))
        {
            leap = false;
            return false;
        }
    }

    //It checks if the location the piece is moving to is already taken.
    if (board[row2][column2] != ' ')
    {
        leap = false;
        return false;
    }

    //It checks if location entered by the user contains a piece to be moved.
    if (board[row1][column1] == ' ')
    {
        leap = false;
        return false;
    }

    //It checks if the piece isn't moving diagonally.
    if (column1 == column2 || row1 == row2)
    {
        leap = false;
        return false;
    }

    //It checks if the piece is moving by more than 1 column and only 1 row
    if ((column2 > column1 + 1 || column2 < column1 - 1) && (row2 == row1 +1 || row2 == row1 - 1))
    {
        leap = false;
        return false;
    }

    //It checks if the piece is leaping.
    if (row2 > row1 + 1 || row2 < row1 - 1)
    {
        //It checks if the piece is leaping too far.
        if (row2 > row1 + 2 || row2 < row1 - 2)
        {
            leap = false;
            return false;
        }

        //It checks if the piece isn't moving by exactly 2 columns
        if (column2 != column1 + 2 && column2 != column1 - 2)
        {
            leap = false;
            return false;
        }

        //It checks if the piece is leaping over another piece.
        if (row2 > row1 && column2 > column1)
        {
            if (board[row2 - 1][column2 - 1] == ' ')
            {
                leap = false;
                return false;
            }
        }
        else if (row2 > row1 && column2 < column1)
        {
            if (board[row2 - 1][column2 + 1] == ' ')
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 > column1)
        {
            if (board[row2 + 1][column2 - 1] == ' ')
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 < column1)
        {
            if (board[row2 + 1][column2 + 1] == ' ')
            {
                leap = false;
                return false;
            }
        }

        leap = true;
        return true;
    }

    leap = false;
    return true;
}

void move()
{
    bool king_piece = false;

    if (board[row1][column1] == 'B' || board[row1][column1] == 'R')
    {
        king_piece = true;
    }

    board[row1][column1] = ' ';

    if (turn == 'B')
    {
        if (king_piece == false)
        {
            board[row2][column2] = 'b';
        }
        else if (king_piece == true)
        {
            board[row2][column2] = 'B';
        }

        turn = 'R';
    }
    else if (turn == 'R')
    {
        if (king_piece == false)
        {
            board[row2][column2] = 'r';
        }
        else if (king_piece == true)
        {
            board[row2][column2] = 'R';
        }

        turn = 'B';
    }

    if (leap == true)
    {
        do_leap();
    }

}

void do_leap()
{
    char answer;

    //It removes the checker piece after leap.
    if (row2 > row1 && column2 > column1)
    {
        board[row2 - 1][column2 - 1] = ' ';
    }
    else if (row2 > row1 && column2 < column1)
    {
        board[row2 - 1][column2 + 1] = ' ';
    }
    else if (row2 < row1 && column2 > column1)
    {
        board[row2 + 1][column2 - 1] = ' ';
    }
    else if (row2 < row1 && column2 < column1)
    {
        board[row2 + 1][column2 + 1] = ' ';
    }

    display_board();//It displays the board after the changes

    //It asks if the user wants to leap again.
    do
    {
        cout << "You just leaped once. Do you want to do a second leap IF YOU CAN? (y/n): ";
        cin >> answer;
    }

    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');

    if (answer == 'y' || answer == 'Y')
    {
        row1 = row2;
        column1 = column2;
        cout << "Leap piece: row: " << row1 << ", column: " << column1 << endl;
        cout << "To box\n";
        cout << "row: ";
        cin >> row2;
        cout << "column: ";
        cin >> column2;

        while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
        {
            cout << "Incorrect input. Enter numbers between 0 and 7.\n";
            cout << "To box\n";
            cout << "Row: ";
            cin >> row2;
            cout << "Column: ";
            cin >> column2;
        }
    }

        if (turn == 'B')
        {
            turn = 'R';
        }
        else if (turn == 'R')
        {
            turn = 'B';
        }

        check_move();

        if (leap == false)
        {
            cout << "INVALID LEAP!!\n";

            if (turn == 'B')
            {
                turn = 'R';
            }
            else if (turn == 'R')
            {
                turn = 'B';
            }
        }
        else if (leap == true)
        {
            move();
        }
}

/*

void king()
{
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == 'r')
        {
            board[0][i] = 'R';
        }

        if (board[7][i] == 'b')
        {
            board[7][i] = 'B';
        }
    }
}

void game_over()
{
    int counter = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != ' ')
            {
                counter++;
            }
        }
    }

    if (counter > 1)
    {
        game_running = true;
    }
    else if (counter == 1)
    {
        game_running = false;
    }
}
}

*/
