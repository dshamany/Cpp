#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
using namespace std;

bool win = false;

enum SUIT   { HEART = 1, CLUB, DIAMOND, SPADE };
enum VALUE  { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

class Card{
  public:
    string description();
    string convertToStringDescription();
    int suit;
    int value;
    int points;
};

bool operator==(Card a, Card b){
  if(a.suit == b.suit && a.value == b.value){
    return true;
  }
  return false;
}

vector<Card> cards;
vector<Card> playerHand;
vector<Card> houseHand;
int playerScore = 0;
int houseScore  = 0;

int assignPointsToCard(Card a){
  if(a.value > 10){
    return 10;
  }

  return a.value;
}

void createDeckOfCards(){
  for (int i = 1; i < 5; i++){
    for (int j = 1; j < 14; j++){
      Card tmp;
      tmp.suit    = i;
      tmp.value   = j;
      tmp.value > 10 ? tmp.points = 10 : tmp.points = tmp.value;
      cards.push_back(tmp);
    }
  }
}

Card getRandomCard(){
  int r = rand() % cards.size();
  return cards[r];
}

bool dealer(){
  char accept;
  cout << "Would you like a card? (y | n): ";
  cin >> accept;
  if(accept == 'y' || accept == 'Y'){
    return true;
  } else if (accept == 'n' || accept == 'N'){
    return false;
  } else {
    cout << "Error! Try again." << endl;
    dealer();
  }
  return false;
}

void checkWinner(){
  if (playerScore == 21){
    cout << "You win!" << endl;
  } else if ((21 - playerScore) < (21 - houseScore)){
    cout << "You win!" << endl;
  } else if (playerScore > 21){
    cout << "You lose!" << endl;
  } else if (houseScore == 21){
    cout << "House wins!" << endl;
  } else if ((21 - houseScore) < (21 - playerScore)){
    cout << "House wins!" << endl;
  } else if (houseScore > 21){
    cout << "You win!" << endl;
  } else if (playerScore < 21){
    return;
  }
}

void dealToPlayer(){
  Card pTmp;
  pTmp = getRandomCard();
  playerHand.push_back(pTmp);
  playerScore += pTmp.points;
}

void dealToHouse(){
  Card hTmp;
  hTmp = getRandomCard();
  houseHand.push_back(hTmp);
  houseScore += hTmp.points;
}

int main(int argc, char* argv[]){
  srand(time(NULL));
  createDeckOfCards();
  while(!win){
    if(dealer()){
      dealToPlayer();
      for(int i = 0; i < playerHand.size(); ++i){
        cout << playerHand[i].description() << endl;
      }
    } else {
      return 0;
    }

    dealToHouse();
    for(int i = 0; i < playerHand.size(); ++i){
      cout << houseHand[i].description() << endl;
    }
    cout << "PLAYER: " << playerScore << endl;
    cout << "HOUSE: " << houseScore << endl;
    checkWinner();
  }
  return 0;
}

string Card::convertToStringDescription(){
  string s, v;
  switch(suit){
    case 1:
    s = "Heart";
    break;
    case 2:
    s = "Club";
    break;
    case 3:
    s = "Diamond";
    break;
    case 4:
    s = "Spade";
    break;
  }
  switch(value){
    case 1:
    v = "Ace";
    break;
    case 2:
    v = "Two";
    break;
    case 3:
    v = "Three";
    break;
    case 4:
    v = "Four";
    break;
    case 5:
    v = "Five";
    break;
    case 6:
    v = "Six";
    break;
    case 7:
    v = "Seven";
    break;
    case 8:
    v = "Eight";
    break;
    case 9:
    v = "Nine";
    break;
    case 10:
    v = "Ten";
    break;
    case 11:
    v = "Jack";
    break;
    case 12:
    v = "Queen";
    break;
    case 13:
    v = "King";
    break;
  }

  return s + ": " + v;
}

string Card::description(){
  stringstream s;
  s << points;
  return convertToStringDescription() + "\n" + s.str() + " point(s)";
}
