#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

class Card {
  private:
    char rank, suit;

  public:
    Card();
    Card(char r, char s);
    void setCard(char r, char s);
    int getValue();
    void showCard();

};

class Deck {
  private:
    Card deck[52];
    int cardsCnt;

  public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffle();
    bool isEmpty();
    void displayDeck();

};

Card::Card() {
  rank = suit = ' ';
}

Card::Card(char r, char s) {
  rank = r;
  suit = s;
}

void Card::setCard(char r, char s) {
  rank = r;
  suit = s;
}

int Card::getValue() {
  if (rank == 'A') {
    return 1;
    }
  else if (rank == '2') {
    return 2;
    }
  else if (rank == '3') {
    return 3;
    }
  else if (rank == '4') {
    return 4;
    }
  else if (rank == '5') {
    return 5;
    }
  else if (rank == '6') {
    return 6;
    }
  else if (rank == '7') {
    return 7;
    }
  else if (rank == '8') {
    return 8;
    }
  else if (rank == '9') {
    return 9;
    }
  else if (rank == 'K') {
    return 10;
    }
  else if (rank == 'Q') {
    return 10;
    }
  else {
    return 10;
    }
}

void Card::showCard() {
  cout << rank << suit<<".";
}

Deck::Deck() {
  char ranks[] = { 'A','1','2','3','4','5','6','7','8','9','J','Q','K' };
  char suits[] = { 'S','H','D','C' };
  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      deck[k++] = Card(ranks[j], suits[i]);
      }
    }
  cardsCnt = 52;
}

void Deck::refreshDeck() {
  char ranks[] = { 'A','1','2','3','4','5','6','7','8','9','J','Q','K' };
  char suits[] = { 'S','H','D','C' };
  int index = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      deck[index++] = Card(ranks[j], suits[i]);
      }
    }
  cardsCnt = 52;
}

Card Deck::deal() {
  Card c=deck[cardsCnt - 1];
  cardsCnt--;
  return c;
}

void Deck::shuffle() {
  srand(time(0));
  for (int i = 0; i <cardsCnt; i++) {
    int m = i + (rand() % (52 - i));
    Card t = deck[i];
    deck[i] = deck[m];
    deck[m] = t;
    }
}

bool Deck::isEmpty() {
  if (cardsCnt == 0) {
    return true;
  }
  return false;
}

void Deck :: displayDeck() {
  for (int i = 0; i < 52; i++) {
    if (i % 13 == 0 && i != 0) {
      cout << endl;
      deck[i].showCard();
      cout << " ";
      }
    else {
      deck[i].showCard();
      cout << " ";
      }
    }
}


Deck deck;
void playGame();
bool isFibo(int n);
bool perfectSquare(int a);
void printStackReverse(stack<Card> s);

void playGame() {
  cout << deck.isEmpty() << endl;
  int piles = 0,sum = 0;
  stack<Card> hand;
  cout << "\n Playing Fibonacci Solitaire \n\n";
  while (deck.isEmpty() != true) {
    Card c = deck.deal();
    sum += c.getValue();
    if (isFibo(sum)) {
      hand.push(c);
      printStackReverse(hand);
      hand = stack<Card>();
      cout << " Fibo: " << sum << endl;
      piles++;
      sum = 0;
      }
    else {
      hand.push(c);
      }
    }
  if (sum!=0) {
    printStackReverse(hand);
    hand = stack<Card>();
    cout << " \nLoser in " << piles << " piles!\n";
    }
  else {
    cout << "\nWinner in " << piles << " piles!\n";
    }
  }



bool perfectSquare(int a) {
  int s = sqrt(a);
  return (s * s == a);
}
 
// Returns true if n is a Fibonacci Number, else false
bool isFibo(int n)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or
    // both is a perfect square
    if (n == perfectSquare(5 * n * n + 4) || perfectSquare(5 * n * n - 4)) {
      return true;
    }
  return false;
}

void printStackReverse(stack<Card> s){
  if (s.empty())
    return;
  Card x = s.top();
  s.pop();
  printStackReverse(s);
  x.showCard();
  cout << " ";
  s.push(x);
}

int main() {
  int choice;
  while (true) {
    cout << "Welcome to Fibonacci Solitaire!\n1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitaire\n5) Exit\n\nEnter choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        deck.refreshDeck();
        cout << "\nCreated a new deck\n";
        break;
      case 2:
        cout << "\nDeck:\n";
        deck.displayDeck();
        cout << endl;
        break;
      case 3:
        deck.shuffle();
        cout << "\nThe deck has been shuffled\n";
        break;
      case 4:
        playGame();
        break;
      case 5:
        cout << "\nEnding....Thank you.\n";
        exit(0);
        break;
      default:
        cout << "\nPlease enter a valid option.\n";
        break;
      }
    cout << endl;
    }
  };
