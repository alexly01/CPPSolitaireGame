#include "Deck.h"
#include <iostream>
using namespace std;

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
