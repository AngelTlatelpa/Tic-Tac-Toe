#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>

using namespace std;

class TicTacToe{
private:
    int grid[3][3];
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
           grid[i][b] = 0;
           cout << grid[i][b];
        }
        cout << endl;
    }
}

void TicTacToe::PlayerOneChoose(){
    cout << "Player One: " << endl;
    cout << "X coordinate: ";
    cin >> x;
    cout << "Y coordinate: ";
    cin >> y;
    while(grid[y][x] == 1 || grid[y][x] == 2){
        cout << "Sorry but place already taken." << endl; // ***** Checks if there is a place taken ******
        cout << "Player Two: " << endl;
        cout << "X coordinate: ";
        cin >> g;
        cout << "Y coordinate: ";
        cin >> h;
    }
    for(int i = 0; i < 3; i++){                      // ***** Prints out the X value **********
        for(int b = 0; b<3; b++){
            grid[y][x] = 1;
            cout << grid[i][b];
        }
        cout << endl;
    }
}

void TicTacToe::PlayerTwoChoose() {
    cout << "Player Two: " << endl;
    cout << "X coordinate: ";
    cin >> g;
    cout << "Y coordinate: ";
    cin >> h;

    while(grid[h][g] == 1 || grid[h][g] == 2){                // **** Check if there is a place taken ******
        cout << "Sorry but place already taken." << endl;
        cout << "Player Two: " << endl;
        cout << "X coordinate: ";
        cin >> g;
        cout << "Y coordinate: ";
        cin >> h;
    }
    for (int i = 0; i < 3; i++) {                               // PRINTS OUT "O"
        for (int b = 0; b < 3; b++) {
            grid[h][g] = 2;
            cout << grid[i][b];
        }
        cout << endl;
    }
}



bool TicTacToe::CheckPlayerOne(){
    if(grid[0][0] == 1 && grid[0][1] == 1 && grid[0][2] == 1){
        return true;
    }else if(grid[1][0] == 1 && grid[1][1] == 1 && grid[1][2] == 1){
        return true;
    }

}





bool TicTacToe::CheckPlayerTwo(){
    if( (grid[0][0] == 2 && grid[0][1] == 2 && grid[0][2] == 2) || (grid[1][0] == 2 && grid[1][1] == 2 && grid[1][2] == 2) || (grid[2][0] == 2 && grid[2][1] == 2 && grid[2][2] == 2) ){
        return true;
    }else{
        return false;
    }
}



void TicTacToe::PlayUntilWinner(){
    while(CheckPlayerOne() == false || CheckPlayerTwo() == false){
        PlayerOneChoose();
        PlayerTwoChoose();
    }
    if(CheckPlayerOne() == true){
        cout << "Player One Won!" << endl;
    }else{
        cout << "Player Two Won!" << endl;
    }
}






#endif

