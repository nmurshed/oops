#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std; 

class Card{
private:
	string suite; 
	string face;
public:
	Card();
	Card(string message);
	Card(string cardFace, string cardSuite);
	string print();
};
Card::Card(){}
Card::Card(string message){
	cout<<message<<endl;
}
Card::Card(string cardFace,string cardSuite){
	face = cardFace;
	suite = cardSuite;
}
string Card::print(){
	return face + " of " + suite;
}

const int CARDS_PER_DECK=52;

class DeckofCards{
private:
	Card *deck; 
	int currentCard; 
public:
	DeckofCards();
	void shuffle();
	Card dealCard();
	void print();
};
DeckofCards::DeckofCards(){
	string FACES[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
	string SUITES[]={"Hearts","Diamonds","Clubs","Spades"};
	deck = new Card[CARDS_PER_DECK];
	currentCard = 0;
	for(int i=0; i<CARDS_PER_DECK;i++)
		deck[i]=Card(FACES[i%13],SUITES[i/13]);
}

void DeckofCards::shuffle(){
	currentCard =0; 
	for(int first = 0; first<CARDS_PER_DECK;first++){
		int second = (rand()+time(0))% CARDS_PER_DECK;
		Card temp = deck[first];
		deck[first]=deck[second];
		deck[second]=deck[first];
	}
}
Card DeckofCards::dealCard(){
	if(currentCard>CARDS_PER_DECK)
		shuffle();
	if(currentCard<CARDS_PER_DECK)
		return deck[currentCard++];
}
void DeckofCards::print(){
	for (int i =0; i<CARDS_PER_DECK;i++){
		cout<<setw(19)<<deck[i].print();
		if((i+1)%4==0)
			cout<<endl;
	}
}

class BlackJack : public Card{
public:
	BlackJack(string message);
};
BlackJack::BlackJack(string message):Card(message){

}

int main(){
	DeckofCards deck; 
	Card currentCard; 
	deck.print();
	deck.shuffle();
	cout<<endl;
	deck.shuffle();
	deck.print();

	cout<<endl<<endl;
	for(int i =0; i<CARDS_PER_DECK;i++){
		currentCard = deck.dealCard();
		cout<<currentCard.print()<<endl;
	}
	BlackJack *bl = new BlackJack("I am called ");
	return 0; 
}



