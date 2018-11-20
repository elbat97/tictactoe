#include <iostream>
#include <string>
#include "grid.h"
#include <vector>
using namespace std;

void Grid::printGrid(vector<string> spots){
    int j = 0;
    while(j < 8){
        cout <<spots[j] << spots[j+1] << spots[j+2]<<endl;
        j = j + 3;
    }
}

void Grid::updateGrid(char val, int pos,vector<string>&spots){
    for (int i = 0; i < spots[pos].length(); ++i){
        if(spots[pos][i] == ' '|| spots[pos][i] == '_'){
            spots[pos][i] = val;
            return;
        }
    }
}

bool containsStr(char val, string pos){
    for(int i = 0; i < pos.length(); ++i){
        if(pos[i] == val){
            return true;
        }
    }
    return false;
}

bool Grid::checkWin(char val,vector<string>&spots){
    if(containsStr(val, spots[0])&& containsStr(val, spots[1])&& containsStr(val, spots[2])){
        return true;
    }else if(containsStr(val, spots[3])&& containsStr(val, spots[4])&& containsStr(val, spots[5])){
        return true;
    }else if(containsStr(val, spots[6])&& containsStr(val, spots[7])&& containsStr(val, spots[8])){
        return true;
    }else if(containsStr(val, spots[0])&& containsStr(val, spots[4])&& containsStr(val, spots[8])){
        return true;
    }else if(containsStr(val, spots[2])&& containsStr(val, spots[4])&& containsStr(val, spots[6])){
        return true;
    }else if(containsStr(val, spots[0])&& containsStr(val, spots[3])&& containsStr(val, spots[6])){
        return true;
    }else if(containsStr(val, spots[1])&& containsStr(val, spots[4])&& containsStr(val, spots[7])){
        return true;
    }else if(containsStr(val, spots[2])&& containsStr(val, spots[5])&& containsStr(val, spots[8])){
        return true;
    }else{
        return false;
    }
}

bool Grid::checkFull(vector<string>&spots){
    for(int i = 0; i < 9; ++i){
        if(containsStr('o', spots[i]) || containsStr('x', spots[i])){
        }else{
            return false;
        }
    }
    return false;
}
