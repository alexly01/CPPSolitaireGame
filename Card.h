#ifndef CARD_H
#define CARD_H

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
#endif 