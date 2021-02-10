#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<iomanip>
#include<vector>
using namespace std;

class Card { // creating the class of Card
 public:
    char suit, card;
    Card(char s, char c){
        suit = s;
        card = c;
    }
    friend ostream& operator<<(ostream& os, const Card& dt){
    os<<dt.suit<<dt.card;
    return os;
    }
};
// Global Variables
vector<Card> deck;
vector<Card> player_0;
vector<Card> player_1;
vector<Card> player_2;
vector<Card> player_3;
vector<Card> player_4;

void Deck () { // Creating the deck of cards
    srand(time(0));
    char suit[] = {'H','D','C','S'};
    char card[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
                deck.push_back(Card (suit[i],card[j]));
        }
    }
}

void player_assign() {
    random_shuffle(deck.begin(), deck.end() ); // Passes cards to each player..
    for(int i=0;i<7;i++){
        player_0.push_back(deck[i]);
        player_1.push_back(deck[i+7]);
        player_2.push_back(deck[i+14]);
        player_3.push_back(deck[i+21]);
        player_4.push_back(deck[i+28]);
    }
}

int card_to_move(vector<Card> input) { // Function to figure out which card to be picked based on the suits at hand
    int h=0,d=0,c=0,s=0;
    for(int i=0; i< input.size(); i++){
        char suit= input[i].suit;
        if(suit== 'H'){h++;}
        if(suit== 'D'){d++;}
        if(suit== 'C'){c++;}
        if(suit== 'S'){s++;}
    }
    for(int x=0; x< input.size(); x++){
        if (h>=d && h>=c && h>=s){
            if(input[x].suit =='H'){
                continue;
            }else return x;
        }
        else if (d>=h && d>=c && d>=s){
            if(input[x].suit =='D'){
                continue;
            }else return x;
        }
        else if (c>=h && c>=d && c>=s){
            if(input[x].suit =='C'){
                continue;
            }else return x;
        }
        else if (s>=h && s>=d && s>=c){
            if(input[x].suit =='S'){
                continue;
            }else return x;
        }
    }
}

bool are_all_same_suit(vector<Card> input)// function to compare suits
    {
    char suit = input[0].suit;
    for (int i = 0; i < input.size(); i ++){
        if (input[i].suit != suit) return false;
        }
    return true;
    }
void players_cards(){ // Outputs the cards in the hands of each player...
    cout<<"player 0 (a)"<<player_0[0]<<setw(5)<<"(b)"<<player_0[1]<<setw(5)<<"(c)"<<player_0[2]<<setw(5)<<"(d)"<<player_0[3]<<setw(5)<<"(e)"<<player_0[4]<<setw(5)<<"(f)"<<player_0[5]<<setw(5)<<"(g)"<<player_0[6]<<endl;
    cout<<"player 1 (a)"<<player_1[0]<<setw(5)<<"(b)"<<player_1[1]<<setw(5)<<"(c)"<<player_1[2]<<setw(5)<<"(d)"<<player_1[3]<<setw(5)<<"(e)"<<player_1[4]<<setw(5)<<"(f)"<<player_1[5]<<setw(5)<<"(g)"<<player_1[6]<<endl;
    cout<<"player 2 (a)"<<player_2[0]<<setw(5)<<"(b)"<<player_2[1]<<setw(5)<<"(c)"<<player_2[2]<<setw(5)<<"(d)"<<player_2[3]<<setw(5)<<"(e)"<<player_2[4]<<setw(5)<<"(f)"<<player_2[5]<<setw(5)<<"(g)"<<player_2[6]<<endl;
    cout<<"player 3 (a)"<<player_3[0]<<setw(5)<<"(b)"<<player_3[1]<<setw(5)<<"(c)"<<player_3[2]<<setw(5)<<"(d)"<<player_3[3]<<setw(5)<<"(e)"<<player_3[4]<<setw(5)<<"(f)"<<player_3[5]<<setw(5)<<"(g)"<<player_3[6]<<endl;
    cout<<"player 4 (a)"<<player_4[0]<<setw(5)<<"(b)"<<player_4[1]<<setw(5)<<"(c)"<<player_4[2]<<setw(5)<<"(d)"<<player_4[3]<<setw(5)<<"(e)"<<player_4[4]<<setw(5)<<"(f)"<<player_4[5]<<setw(5)<<"(g)"<<player_4[6]<<endl;
}

void game_check(){
    while(true){ // To check if any player has same suits, then they win...
        int exit_value=0;
        if(are_all_same_suit(player_0)==true){
            cout<<"My Ship Sails! --- Player 0 Won..."<<endl;
            exit_value++;
        }
        if(are_all_same_suit(player_1)==true){
            cout<<"My Ship Sails! --- Player 1 Won..." <<endl;
            exit_value++;
        }
        if(are_all_same_suit(player_2)==true){
            cout<<"My Ship Sails! --- Player 2 Won..." <<endl;
            exit_value++;
        }
        if(are_all_same_suit(player_3)==true){
            cout<<"My Ship Sails! --- Player 3 Won..." <<endl;
            exit_value++;
        }
        if(are_all_same_suit(player_4)==true){
            cout<<"My Ship Sails! --- Player 4 Won..." <<endl;
            exit_value++;
        }
        if(exit_value > 0){
            cout<< "\n[ Final card distributions ]\n";
            players_cards();
            exit(1);
        }
        break;
    }
    // if the player has mismatch cards they choose to obtain different cards
        if(are_all_same_suit(player_1)!=true){
            player_2.push_back(player_1[card_to_move(player_1)]);
            player_1.erase(player_1.begin()+(card_to_move(player_1)));}
        if(are_all_same_suit(player_2)!=true){
            player_3.push_back(player_2[card_to_move(player_2)]);
            player_2.erase(player_2.begin()+(card_to_move(player_2)));

        }
        if(are_all_same_suit(player_3)!=true){
            player_4.push_back(player_3[card_to_move(player_3)]);
            player_3.erase(player_3.begin()+(card_to_move(player_3)));

        }
        if(are_all_same_suit(player_4)!=true){
            player_0.push_back(player_4[card_to_move(player_4)]);
            player_4.erase(player_4.begin()+(card_to_move(player_4)));}

        cout<< "Hint: " <<"player 0 passed " <<player_1[6]<< " to player 1\n";
        cout<< "Hint: " <<"player 1 passed " <<player_2[6]<< " to player 2\n";
        cout<< "Hint: " <<"player 2 passed " <<player_3[6]<< " to player 3\n";
        cout<< "Hint: " <<"player 3 passed " <<player_4[6]<< " to player 4\n";
        cout<< "Hint: " <<"player 4 passed " <<player_0[6]<< " to player 0\n";
        cout<< endl;
}


void init_game() { // Game Initializer
    cout<<"(a)"<<player_0[0]<<setw(5)<<"(b)"<<player_0[1]<<setw(5)<<"(c)"<<player_0[2]<<setw(5)<<"(d)"<<player_0[3]<<setw(5)<<"(e)"<<player_0[4]<<setw(5)<<"(f)"<<player_0[5]<<setw(5)<<"(g)"<<player_0[6]<<"\n"<<endl;
    char choice; // player_0' choice
    cout << "which one to replace ?"<<endl;
    while(cin >> choice)
    {
    char check;//TF?

    if(choice == 'a'){
        player_1.push_back(player_0[0]);
        player_0.erase(player_0.begin());
        break;
    }else
    if(choice == 'b'){
        player_1.push_back(player_0[1]);
        player_0.erase(player_0.begin()+1);
        break;
    }else
    if(choice == 'c'){
        player_1.push_back(player_0[2]);
        player_0.erase(player_0.begin()+2);
        break;
    }else
    if(choice == 'd'){
        player_1.push_back(player_0[3]);
        player_0.erase(player_0.begin()+3);
        break;
    }else
    if(choice == 'e'){
        player_1.push_back(player_0[4]);
        player_0.erase(player_0.begin()+4);
        break;
    }else
    if(choice == 'f'){
        player_1.push_back(player_0[5]);
        player_0.erase(player_0.begin()+5);
        break;
    }else
    if(choice == 'g'){
        player_1.push_back(player_0[6]);
        player_0.erase(player_0.begin()+6);
        break;
    }else
    if(choice == '?'){
        players_cards();
        cout << endl;
        cout << "which one to replace ?"<<endl;
    }else{cout<< "Wrong input! Which one to replace ? ";}
}

}


int main() { // The start of the program
    Deck();
    player_assign();
    while(true){
        init_game();
        game_check();
    }
}
