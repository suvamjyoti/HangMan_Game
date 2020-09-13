#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;



int main() {

  int mode;
  string chosenString;
  int SLength;

  //Welcome Statement
  std::cout << "Welcome to hangman Game...Guess the state of india.\n"
            << "No of star represent the no of Letters.\n"
            << "You can type only one letter at a time.\n"
            << "You have 5 tries to guess the word.\n"
            << "No penalty for Right answers\n"
            <<"```````````````````````````````````````````````````````````````\n"
            <<"Select mode 1 for single player, 2 for multiplayer\n";
  std::cin >> mode;

  //single player implementation
  if(mode==1){

    //Initialize names of state
    string state[]={
      "andhrapradesh", "arunachalpradesh", "assam", "bihar", "chhattisgarh", "goa", 
      "gujrat", "haryana", "himachalpradesh", "jharkhand", "Karnataka", "kerala",
      "madhyapradesh", "maharastra", "manipur", "meghalaya", "mizoram", "nagaland" 
    };
    //random selection part
    srand((unsigned int)time(NULL));
    int r1 = rand() % 18;
    chosenString = state[r1];
    SLength = chosenString.length();
  }

  // multiplayer implimentation
  else{
    std::cout <<"player2 keep eyes closed. \n"
              <<"player1 enter String (with no space or capital letter) to be guessed\n";
    std::cin >> chosenString;
    std::cout<<"player2 open eyes\n\n";
    SLength = chosenString.length();
  }

//guessing part start
//string to **
  string guessString = string(chosenString.length(),'*');
  char Gletter;
  int NoOfGuess = 5;
  std::cout << guessString<<"\n";

  while(NoOfGuess>0){
    if(chosenString != guessString){
      std::cout << "Guess a letter:" << "\n";
      std::cin >> Gletter;

      //serching part
      int flag = 0;
      for(int i=0; i<SLength ; i++){
        if(chosenString[i]==Gletter){
          flag = 1;
          guessString[i] = Gletter;
        }
      }
      if(flag==0){
        NoOfGuess--;
        std::cout << "Opps! Wrong Guess. "<< NoOfGuess << " guess left"<<"\n\n";
        std::cout <<guessString;
      }
      else{
        std::cout <<guessString<<"\n";
        std::cout<<"Right answer.";
        if(NoOfGuess<5 && chosenString!=guessString){
          std::cout<<"one extra guess, ";
          NoOfGuess++;
          std::cout << NoOfGuess << " guess left";
        }
      }
      std::cout << "\n\n";
    }
    else{
      NoOfGuess=0;
    }
  }

  // Final part success or failure
  if(chosenString==guessString){
    std::cout<<
    "``````````````````````````````well played ! You did it````````````````````````````````";
  }
  else{
    std::cout<<
    "`````````````````````````````````````GAME OVER````````````````````````````````````````"
    <<"\n"<<"coreect answer was\n"<<chosenString;
  } 

}