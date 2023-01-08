#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>

using namespace std;

class TicTacToe{
private:
    char grid[3][3];
    int x;
    int y;
    int g;
    int h;

public:
    TicTacToe();
    void Grid();
    void PlayerOneChoose();
    void PlayerTwoChoose();
    void PlayUntilWinner();
    bool CheckPlayerOne();
    bool CheckPlayerTwo();
    bool CheckifitsaTie();
};


TicTacToe::TicTacToe() {
    x = 4;
    y = 4;
    g = 5;
    h = 5;
}


void TicTacToe::Grid(){

    for(int i = 0; i < 3; i++){
        for(int b = 0; b<3; b++){
            grid[i][b] = '_';
            cout << grid[i][b];
        }
        cout << endl;
    }
}

void TicTacToe::PlayerOneChoose(){
    cout << "Player One: " << endl;
    cout << "X coordinate(0-2): ";
    cin >> x;
    cout << "Y coordinate(0-2): ";
    cin >> y;
    while(grid[y][x] == 'X' || grid[y][x] == 'O'){
        cout << "Sorry but place already taken." << endl; // ***** Checks if there is a place taken ******
        cout << "Player Two: " << endl;
        cout << "X coordinate(0-2): ";
        cin >> g;
        cout << "Y coordinate(0-2): ";
        cin >> h;
    }
    for(int i = 0; i < 3; i++){                      // ***** Prints out the X value **********
        for(int b = 0; b<3; b++){
            grid[y][x] = 'X';
            cout << grid[i][b];
        }
        cout << endl;
    }
}

void TicTacToe::PlayerTwoChoose() {
    cout << "Player Two: " << endl;
    cout << "X coordinate(0-2): ";
    cin >> g;
    cout << "Y coordinate(0-2): ";
    cin >> h;

    while(grid[h][g] == 'X' || grid[h][g] == 'O'){                // **** Check if there is a place taken ******
        cout << "Sorry but place already taken." << endl;
        cout << "Player Two: " << endl;
        cout << "X coordinate(0-2): ";
        cin >> g;
        cout << "Y coordinate(0-2): ";
        cin >> h;
    }
    for (int i = 0; i < 3; i++) {                               // PRINTS OUT "O"
        for (int b = 0; b < 3; b++) {
            grid[h][g] = 'O';
            cout << grid[i][b];
        }
        cout << endl;
    }
}



bool TicTacToe::CheckPlayerOne(){

    if(grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X'){
        return true;
    }else if(grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X'){
        return true;
    }else if(grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X'){
        return true;
    }else if(grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X'){
        return true;
    }else if(grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X'){
        return true;
    }else if(grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X'){
        return true;
    }else if(grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X'){
        return true;
    }else if(grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X'){
        return true;
    }else{
        return false;
    }

}



bool TicTacToe::CheckPlayerTwo() {

    if(grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O'){
        return true;
    }else if(grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O'){
        return true;
    }else if(grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O'){
        return true;
    }else if(grid[2][0] == 'O' && grid[1][1] == 'O' && grid[0][2] == 'O'){
        return true;
    }else if(grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O'){
        return true;
    }else if(grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O'){
        return true;
    }else if(grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O'){
        return true;
    }else if(grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O'){
        return true;
    }else{
        return false;
    }

}



bool TicTacToe::CheckifitsaTie() {
    if(grid[0][0] != '_' && grid[0][1] != '_' && grid[0][2] != '_' && grid[1][0] != '_' && grid[1][1] != '_' && grid[1][2] != '_' && grid[2][0] != '_' && grid[2][1] != '_' && grid[2][2] != '_'){
        return true;
    }else{
        return false;
    }
}




void TicTacToe::PlayUntilWinner() {
    while (CheckPlayerOne() == false || CheckPlayerTwo() == false) {
        PlayerOneChoose();
        if (CheckPlayerOne() == true) {
            cout << "Player One Won! " << endl;
            exit(0);
        }
        if (CheckifitsaTie() == true) {
            cout << "It's a tie" << endl;
            exit(0);
        }
        PlayerTwoChoose();
        if (CheckPlayerTwo() == true) {
            cout << "Player Two Won" << endl;
            exit(0);
        }
    }
}
#endif
