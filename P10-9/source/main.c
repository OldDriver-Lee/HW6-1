#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CARD 52
#define FACE 13

typedef struct card{
	const char *face;
	const char *suit;
}cards;

void filldeck(cards *const wdeck, const char *wface[], const char *wsuit[]);
void shuffle(cards *const wdeck);
void deal(const cards *const wdeck);

int main(void)
{
	cards deck[CARD];

	const  char *face[] = { " Ace", "Deuce", "Three", "four",
		"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	const char *suit[] = { "Heart", "Diamond", "Clubs", "Spades" };

	srand(time(NULL));

	filldeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	system("pause");

}

void filldeck(cards *const wdeck, const char *wface[], const char *wsuit[])
{
	size_t  i;
	for (i = 0; i < CARD; ++i){
		wdeck[i].face = wface[i%FACE];
		wdeck[i].suit = wsuit[i / FACE];
	}
}

void shuffle(cards *const wdeck)
{
	size_t i;
	size_t j;
	cards temp;

	for (i = 0; i < CARD; i++){
		j = rand() % CARD;
		temp = wdeck[i]; 
		wdeck[i] = wdeck[j];
		wdeck[j] = temp;
	}
}

void deal(const cards *const wdeck)
{
	size_t i;

	for (i = 0; i < CARD; ++i){
		printf("%5s of %-8s\n", wdeck[i].face, wdeck[i].suit, (i + 1) % 4 ? " " : "\n");
	}
}