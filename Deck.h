//Create a deck of cards
#ifndef DECK_H
#define DECK_H
#include "Card.h"
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
#endif 