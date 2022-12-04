/*
Week 2 Honors Assignment By Rizwan Qureshi
Use a struct to define a card as an enumerated member that is its suit value
and a short that is its pips value. Write a function that randomly shuffles
the deck. Then deal out 7 card hands and evaluate the probability that a hand
has no pair, one pair, two pair, three of a kind, full house and 4 of a kind.
This is a Monte Carlo method to get an approximation to these probabilities.
Use at least 1 million randomly generated hands.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMS 1000000
#define CARDS 52
#define RANK 13
#define HAND 7
#define COUNT 6
#define TYPE 5

typedef enum suits { hearts, spades, diamonds, clubs } suit;

typedef struct cards {
  suit s;
  short pips;
} card;

/*
This functions initializes the deck with ordered cards.
*/
void fill(card deck[]) {
  int i = 0;
  for (i = 0; i < CARDS; ++i) {
    deck[i].pips = (i % RANK) + 1;
    deck[i].s = (suit)(i / RANK);
  }
}

/*
This functions shuffles the deck.
*/
void shuffle(card deck[]) {
  card temp;
  int i = 0, rnd;
  for (i = 0; i < CARDS; ++i) {
    rnd = rand() % CARDS;
    temp = deck[i];
    deck[i] = deck[rnd];
    deck[rnd] = temp;
  }
}

/*
This functions deals the deck into 7 (52 cards/7 cards) hands of 7 cards.
*/
void deal(card deck[], card hands[][HAND]) {
  int i, j, k = 0;
  for (i = 0; i < CARDS / HAND; ++i) {
    for (j = 0; j < HAND; ++j) {
      hands[i][j] = deck[k++];
    }
  }
}

/*
This function sorts the cards in one hand.
*/
void orderOneHand(card hand[HAND]) {
  int i, j;
  card temp;
  for (i = 0; i < HAND; ++i) {
    for (j = 0; j < HAND - 1; ++j) {
      if (hand[j].pips < hand[j + 1].pips) {
        temp = hand[j];
        hand[j] = hand[j + 1];
        hand[j + 1] = temp;
      }
    }
  }
}

/*
This function sorts all the hands.
*/
void orderHands(card hands[][HAND]) {
  int i;
  for (i = 0; i < CARDS / HAND; ++i) {
    orderOneHand(hands[i]);
  }
}

/*
This functions finds the count of the matching cards in one hand.
*/
void getMatchCounts(card hands[], int hand_freq[]) {
  int idx = 0;
  while (idx < HAND) {
    if (hand_freq[hands[idx].pips] == -1) {
      hand_freq[hands[idx].pips] = 0;
    }

    hand_freq[hands[idx].pips]++;
    idx++;
  }
}

/*
This functions finds the count of the matching cards in all hands.
*/
void findMatchCounts(card hands[][HAND], int hand_freq[][RANK + 1]) {
  int i;
  for (i = 0; i < CARDS / HAND; ++i) {
    getMatchCounts(hands[i], hand_freq[i]);
  }
}

/*
This functions finds the frequency of the cards in a hand for all hands.
*/
void findFreq(card hands[][HAND], int hand_freq[][RANK + 1]) {
  int i, j, k;
  for (i = 0; i < CARDS / HAND; ++i) {
    for (j = 0; j < HAND; ++j) {
      for (k = 0; k < HAND; ++k) {
        if ((!(j == k)) && (hands[i][j].pips == hands[i][k].pips)) {
          hand_freq[i][hands[i][j].pips]++; /* If its not the same card but*/
        } /* the value is the same use it as an index to increment the freq*/
      }
    }
  }
}

/*
This functions finds the total frequency of the cards in a hand for all hands.
It tells us how many pairs, or three of a kind etc were there in a hand.
*/
void findTotalFreq(int hand_freq[][RANK + 1], int total_freq[][TYPE]) {
  int i, j;
  for (i = 0; i < CARDS / HAND; ++i) {
    for (j = 0; j < RANK + 1; ++j) {
      if (hand_freq[i][j] != -1) {        /* If the frequency is not -1 use*/
        total_freq[i][hand_freq[i][j]]++; /* it as an index to increment freq*/
      }
    }
  }
}

int isFullHouse(int a, int b) { return ((a == 1) && (b == 1)); }
int isFourOfKind(int a) { return (a == 1); }
int isThreeOfKind(int a, int b) { return ((a == 1) && (b == 0)); }
int isTwoPair(int a, int b) { return ((a == 0) && (b == 2)); }
int isPair(int a, int b) { return ((a == 0) && (b == 1)); }
int isHighCard(int a) { return (a == 7); }

/*
This function finds out whether a hand was a Full Houe, Four of a kind etc from
the total of frequencies calculated in findTotalFreq function.
*/
void calculateHand(int total_freq[][TYPE], int what_hand[]) {
  int i;
  for (i = 0; i < CARDS / HAND; ++i) {
    if (isFullHouse(total_freq[i][3], total_freq[i][2])) {
      what_hand[i] = 5;
    }
    if (isFourOfKind(total_freq[i][4])) {
      what_hand[i] = 4;
    }
    if (isThreeOfKind(total_freq[i][3], total_freq[i][2])) {
      what_hand[i] = 3;
    }
    if (isTwoPair(total_freq[i][3], total_freq[i][2])) {
      what_hand[i] = 2;
    }
    if (isPair(total_freq[i][3], total_freq[i][2])) {
      what_hand[i] = 1;
    }
    if (isHighCard(total_freq[i][1])) {
      what_hand[i] = 0;
    }
  }
}

/*
This function prints the count of what a hand is.
*/
void printCountWhatHand(int count_what_hand[]) {
  printf("%-32s%d\n", "The count of No Pair is ", count_what_hand[0]);
  printf("%-32s%d\n", "The count of Pair is ", count_what_hand[1]);
  printf("%-32s%d\n", "The count of Two Pair is ", count_what_hand[2]);
  printf("%-32s%d\n", "The count of Three of a kind is ", count_what_hand[3]);
  printf("%-32s%d\n", "The count of Four of a kind is ", count_what_hand[4]);
  printf("%-32s%d\n", "The count of Full House is ", count_what_hand[5]);
  printf("\n");
}

/*
This function prints the probabilirties of what type a hand is.
*/
void printProbabilities(int count_what_hand[]) {
  printf("%-32s%lf\n", "The prob of No Pair is ",
         (double)count_what_hand[0] / (SIMS * CARDS / HAND));
  printf("%-32s%lf\n", "The prob of Pair is ",
         (double)count_what_hand[1] / (SIMS * CARDS / HAND));
  printf("%-32s%lf\n", "The prob of Two Pair is ",
         (double)count_what_hand[2] / (SIMS * CARDS / HAND));
  printf("%-32s%lf\n", "The prob of Three of a kind is ",
         (double)count_what_hand[3] / (SIMS * CARDS / HAND));
  printf("%-32s%lf\n", "The prob of Four of a kind is ",
         (double)count_what_hand[4] / (SIMS * CARDS / HAND));
  printf("%-32s%lf\n", "The prob of Full House is ",
         (double)count_what_hand[5] / (SIMS * CARDS / HAND));
  printf("\n");
}

/*
This function sums up the count of what a hand is.
*/
void whatHandCount(int what_hand[], int count_what_hand[]) {
  int i;
  for (i = 0; i < CARDS / HAND; ++i) {
    count_what_hand[what_hand[i]]++;
  }
}

/*
This function resets the count of the frequencies of the hands.
*/
void resetHandFreq(int hand_freq[][RANK + 1]) {
  int i, j;
  for (i = 0; i < CARDS / HAND; ++i) {
    for (j = 0; j < RANK + 1; ++j) {
      hand_freq[i][j] = -1;
    }
  }
}

/*
This function resets the count of the total frequencies of the hands.
*/
void resetTotalFreq(int total_freq[][TYPE]) {
  int i, j;
  for (i = 0; i < CARDS / HAND; ++i) {
    for (j = 0; j < TYPE; ++j) {
      total_freq[i][j] = 0;
    }
  }
}

/*
This function resets the count of what the hand types are.
*/
void resetWhatHand(int what_hand[]) {
  int i;
  for (i = 0; i < CARDS / HAND; ++i) {
    what_hand[i] = 0;
  }
}

int main() {
  srand(time(NULL));

  card hands[CARDS / HAND][HAND];
  card deck[CARDS];
  int hand_freq[CARDS / HAND][RANK + 1];
  int total_freq[CARDS / HAND][TYPE] = {0};
  int what_hand[CARDS / HAND] = {0};
  int count_what_hand[COUNT] = {0};
  int i;

  resetHandFreq(hand_freq);

  printf("Please wait ... 1,000,000 simulations are running ...\n");

  for (i = 0; i < SIMS; ++i) {
    fill(deck);
    shuffle(deck);
    deal(deck, hands);
    orderHands(hands);
    findMatchCounts(hands, hand_freq);
    findTotalFreq(hand_freq, total_freq);
    calculateHand(total_freq, what_hand);
    whatHandCount(what_hand, count_what_hand);
    resetHandFreq(hand_freq);
    resetTotalFreq(total_freq);
    resetWhatHand(what_hand);
  }

  printCountWhatHand(count_what_hand);
  printProbabilities(count_what_hand);

  return 0;
}
