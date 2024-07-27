#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int main()
{
  // ROCK beats SCISSORS
  //PAPER beats SCISSORS
  //SCISSORS beats PAPER
  
  srand ((unsigned int)time(NULL));
  int player_throw = 0;
  int AI_throw = 0;

  char repeat = 'y';
  while(repeat == 'y'){
      bool draw = false;
      while(draw!=true){
          cout<<"Select your throw"<<endl;
          cout<<"01) Rock"<<endl;
          cout<<"02) PAPER"<<endl;
          cout<<"03) Scissor"<<endl;
          cout<<"Selection: "<<endl;
          cin>>player_throw;
          cout<<endl;
          if(player_throw == ROCK) cout<<"player_throw throws ROCK"<<endl;
          if(player_throw == PAPER) cout<<"player_throw throws PAPER"<<endl;
          if(player_throw == SCISSORS) cout<<"player_throw throws SCISSORS"<<endl;
          AI_throw = (rand() % 3) +1;
          if(AI_throw == ROCK) cout<<"AI_throw throws ROCK"<<endl;
          if(AI_throw == PAPER) cout<<"AI_throw throws PAPER"<<endl;
          if(AI_throw == SCISSORS) cout<<"AI_throw throws SCISSORS"<<endl;
          
          if(player_throw == AI_throw) {
              draw = true;
              cout<<"Draw! Play Again"<<endl;
          }
          else if(player_throw == ROCK && AI_throw == PAPER) cout <<"AI Wins!"<<endl;
          else if(player_throw == ROCK && AI_throw == SCISSORS) cout <<"You Wins!"<<endl;
          
          else if(player_throw == PAPER && AI_throw == ROCK) cout <<"You Wins!"<<endl;
          else if(player_throw == PAPER && AI_throw == SCISSORS) cout <<"AI Wins!"<<endl;
      
          else if(player_throw == SCISSORS && AI_throw == PAPER) cout <<"You Wins!"<<endl;
          else if(player_throw == SCISSORS && AI_throw == ROCK) cout <<"AI Wins!"<<endl;
      }
      cout<<"Want to repeat the game? (y/n) "<<endl;
      cin>>repeat;
    }

    return 0;
}
