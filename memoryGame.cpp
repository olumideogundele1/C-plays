#include <iostream>
#include <cstdlib>
#include <unistd.h>
//#include <windows.h>

using namespace std;

#define ROWS  4
#define COLS  4
#define CARDS (ROWS*COLS/2)
class MemoryGame{
    private:
        int array[ROWS][COLS];
        int hidden[ROWS][COLS];
        int pr, pc;
        int prev_card;
        int cards_revealed;
        int moves;

    public:
        MemoryGame(void){
            resetdeck();
        }
        //For shuffling the cards
        void resetdeck(void){
            int cnt[CARDS], card_no;
            for( int i=0; i< CARDS; i++ )
                cnt[i] = 0;

            for( int i=0; i< ROWS; i++ )
                for( int j=0; j< COLS; j++){
                    do{
                        card_no = rand() % CARDS+1;
                    }while ( cnt[card_no-1] == 2);

                    array[i][j] = card_no;
                    hidden[i][j] = 1;
                    cnt[card_no-1]++;
                }
            cards_revealed = 0;
            pr =0;
            pc =0;
            prev_card =0;
            moves =0;
        }

        int pickCard(int r, int c){
            if( r<0 || r>= ROWS || c<0 || c>=COLS){
                cout << "Index out of bounds"<<endl;
                //Sleep(1000);
                usleep(1000);
                return -1;
            }
            if( hidden[r][c] == 0){
                cout<< "Card already in revealed position"<<endl;
                //Sleep(2000);
                usleep(2000);
                return -2;
            }
            if( prev_card == 0 ){
                hidden[r][c] = 0;
                pr = r;
                pc = c;
                prev_card = array[pr][pc];
            }
            else if( array[r][c] == prev_card ){
                hidden[r][c] = 0;
                hidden[pr][pc] = 0;
                prev_card = 0;
                pr=0;
                pc=0;
                cards_revealed+=2;

                displaycards();
                cout<<"===>Matched";
                //Sleep(2000);
                usleep(2000);

            }
            else{
                hidden[r][c] = 0;
                displaycards();
                cout<<"===>Unmatched";
                //Sleep(2000);
                usleep(2000);
                hidden[r][c] = 1;
                hidden[pr][pc] = 1;
                prev_card =0;
                pr=0;
                pc=0;
            }
            moves++;
            if( cards_revealed == CARDS*2)
                return 1;
            else
                return 0;
        }
        void displaycards(void){
            for( int i=0; i< 50; i++)
                cout<<endl;
            for( int i=0; i<ROWS; i++){
                for( int j=0; j<COLS; j++)
                    if( hidden[i][j])
                        cout<< "*" << "\t";
                    else
                        cout << array[i][j] << "\t";
                cout<<endl;
            }
            cout<< "Cards Matched: "<<cards_revealed << " Moves: "<< moves<<endl;
         }
};

int main()
{
    MemoryGame* m = new MemoryGame();
    int exit = 0;
    int r, c, ret_code;
    while(!exit){
        m->displaycards();
        cout << "Enter row: ";
        cin >> r;
        cout<< "Enter Col:";
        cin >>c;

        ret_code = m->pickCard(r-1, c-1);
        if( ret_code == 1){
            cout<<"GAME_OVER";
            exit = 1;
        }
    };
}
