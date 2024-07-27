#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define Beginner 1
#define Intermediate 2
#define Advanced 3

int main()
{
   //Casino number guess
  srand((unsigned int)time(NULL));
 char repeat = 'y';
 while(repeat == 'y'){ 
  int AI_guess = 0;
  int player_guess = 0;
  int diff_level;
  
  int chances = 1;

    AI_guess = (rand() % 99) + 1;
  cout<<"Difficulty levels"<<endl;
  cout<<"01) Beginner (12 chance)"<<endl;
  cout<<"02) Intermediate (8 chances)"<<endl;
  cout<<"03) Advanced (5 chances)" <<endl;
  
  cout<<"Enter the difficulty mode: "<<endl;
  cin>>diff_level;
  
  if(diff_level == Beginner) {
      while(chances <= 12){
          cout<<"Remaining chances: "<< 12-chances<<endl;
          cout<<"Take a number guess: "<<endl;
          cin>>player_guess;
          if(player_guess == AI_guess) {
              cout<<" You win ! hurrah"<<endl;
              break;
          }
          else if(player_guess<AI_guess) {
              cout<<"Guess is samller than the original number."<<endl;
          }
          else if(player_guess>AI_guess){
               cout<<"Guess is bigger than the original number."<<endl;
          }
          chances++;
      }
      cout<<"The original number is: "<< AI_guess<<endl;
    }
 else if(diff_level == Intermediate) {
      while(chances <= 8){
          cout<<"Remaining chances: "<< 8-chances<<endl;
          cout<<"Take a number guess: "<<endl;
          cin>>player_guess;
          if(player_guess == AI_guess) {
              cout<<" You win ! hurrah"<<endl;
              break;
          }
          else if(player_guess<AI_guess) {
              cout<<"Guess is samller than the original number."<<endl;
          }
          else if(player_guess>AI_guess){
               cout<<"Guess is bigger than the original number."<<endl;
          }
          chances++;
      }
      cout<<"The original number is: "<< AI_guess<<endl;
    }
 else if(diff_level == Advanced) {
      while(chances <= 5){
          cout<<"Remaining chances: "<< 5-chances<<endl;
          cout<<"Take a number guess: "<<endl;
          cin>>player_guess;
          if(player_guess == AI_guess) {
              cout<<" You win ! hurrah"<<endl;
              break;
          }
          else if(player_guess<AI_guess) {
              cout<<"Guess is samller than the original number."<<endl;
          }
          else if(player_guess>AI_guess){
               cout<<"Guess is bigger than the original number."<<endl;
          }
          chances++;
      }
      cout<<"The original number is: "<< AI_guess<<endl;
    } 
    cout<<"Want to play again: (y/n)"<<endl;
    cin>>repeat;
 } 
  
    return 0;
}
