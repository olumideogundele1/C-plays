#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

const string values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
  "Jack", "Queen", "King"};
const string suits[4] = {"Clubs", "Diamonds","Hearts","Spades"};

string SelectionOfCard(unsigned int card){
       if(card >= 52){
            return  "Invalid Entry!!!!";
        }
        return "The card you picked is " + values[card % 13] + " of " + suits[card/13];
}

int shuffleCard(){
    srand(time(NULL));
    int card = rand() % 52;
    cout  << SelectionOfCard(card) << endl;
    return 0;
}

int main(){
    shuffleCard();
}
