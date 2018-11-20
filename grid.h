#ifndef GRID
#define GRID
#include <string>
#include <vector>
class Grid{

    public:
      std::vector<std::string> spots;
      Grid (){
        for(int i = 1; i <= 6; ++i){
          if(i%3 == 1){
            spots.push_back("_|");
          }else if(i%3 == 2){
            spots.push_back("_");
          }else{
            spots.push_back("|_");
          }
       }
       for(int i = 7; i <= 9; ++i){
         if(i%3 == 1){
           spots.push_back(" |");
         }else if(i%3 == 2){
           spots.push_back(" ");
         }else{
           spots.push_back("| ");
         }
       }
      }

        void printGrid(std::vector<std::string>spots);
        void updateGrid(char val, int pos, std::vector<std::string> &spots);
        bool checkWin(char player, std::vector<std::string>&spots);
        bool static checkFull(std::vector<std::string>&spots);
};
#endif
