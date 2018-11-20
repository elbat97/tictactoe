#include <iostream>
#include <string>
#include "grid.h"
#include <vector>
using namespace std;

bool containsChar(string spots){
  for (int i = 0; i < spots.length(); ++i){
    if(spots[i] == 'o'){
      return true;
    }else if(spots[i] == 'x'){
      return true;
    }
  }
  return false;
}

int main(){



    char player1;
    char player2;
    int play1 = 1;
    int play2 = 0;
    bool correctSelection = false;
    bool incorrectSelect = false;
    cout<<"Welcome to tic tac toe!"<<endl;
    cout<<"Please select whether you are o's or x's Player 1"<<endl;

    while(correctSelection == false){
        cin >> player1;
        if(player1 == 'o'){
            player2 = 'x';
            correctSelection = true;
        }else if(player1 == 'x'){
            player2 = 'o';
            correctSelection = true;
        }else{
            cout<<"Sorry, you didn't pick a valid player. Please select whether you are o's or x's Player 1"<<endl;
            correctSelection = false;
        }
    }
    cout<<"Okay player 1 is "<< player1 <<" and player 2 is " << player2<<endl;
    cout<<"To select the position you want to play in, you must first select the row (1,2,3) and then the column (1,2,3)."<<endl;
    Grid * mainGrid = new Grid();
    mainGrid->printGrid(mainGrid->spots);
    int row;
    int col;
    while(mainGrid->checkFull(mainGrid->spots) == false){

        if(play1 == 1){
            cout<<"Okay, Player 1! select your position"<<endl;
            while (incorrectSelect == false) {

                cout<<"which row?"<<endl;
                cin >> row;
                cout<<"which column?"<<endl;
                cin >> col;
                if(row != 1 && row != 2 && row != 3){
                    cout<<"Please select valid input. Try Again."<<endl;
                    incorrectSelect = false;
                }else if(col != 1 && col != 2 && col != 3){
                    cout<<"Please select valid input. Try Again."<<endl;
                    incorrectSelect = false;
                }else{
                    int pos = (row - 1) * 3 + (col - 1);
                    if(containsChar(mainGrid->spots[pos])){
                      cout<<"The spot is taken, pick another"<<endl;
                      incorrectSelect = false;
                    }else{
                    mainGrid->updateGrid(player1, pos, mainGrid->spots);
                    mainGrid->printGrid(mainGrid->spots);
                    if(mainGrid->checkWin(player1, mainGrid->spots)){
                        cout<<"Player 1 Wins!"<<endl;
                        return 1;
                    }
                    incorrectSelect = true;
                  }
                }
            }
            play1 = 0;
            play2 = 1;
            incorrectSelect = false;
        }else{
            cout<<"Okay, Player 2! select your position"<<endl;
            while (incorrectSelect == false) {

                cout<<"which row?"<<endl;
                cin >> row;
                cout<<"which column?"<<endl;
                cin >> col;
                if(row != 1 && row != 2 && row != 3){
                    cout<<"Please select valid input. Try Again."<<endl;
                    incorrectSelect = false;
                }else if(col != 1 && col != 2 && col != 3){
                    cout<<"Please select valid input. Try Again."<<endl;
                    incorrectSelect = false;
                }else{
                    int pos = (row - 1) * 3 + (col - 1);
                    if(containsChar(mainGrid->spots[pos])){
                      cout<<"The spot is taken, pick another"<<endl;
                      incorrectSelect = false;
                    }else{
                    mainGrid->updateGrid(player2, pos, mainGrid->spots);
                    mainGrid->printGrid(mainGrid->spots);
                    if(mainGrid->checkWin(player2, mainGrid->spots)){
                        cout<<"Player 2 Wins!"<<endl;
                        return 1;
                    }
                    incorrectSelect = true;
                  }
                }
            }
            play2 = 0;
            play1 = 1;
            incorrectSelect = false;
        }
    }
    cout<<"Looks like a tie!"<<endl;


    return 1;

}
