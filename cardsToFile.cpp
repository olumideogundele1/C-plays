
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

void listOfCards(){

     ofstream MyFile("listOfCards.txt");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++) {
            MyFile << values[j] << " of " << suits[i] << " \n\n";
        }
        cout << "\n";
    }
    MyFile.close();
}

int main(){
    listOfCards();
    cout << "File Created!!!";
    return 0;
}
