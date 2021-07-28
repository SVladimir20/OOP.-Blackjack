#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
class Card
{
public:
	enum class Card_value
	{
		Ace = 1,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
	};
	enum class Suit
	{
		Spades,
		Hearts,
		Diamonds,
		Clubs
	};
	Card(Card_value v, Suit s, bool p) : c_value(v), c_suit(s), card_position(p) {}
	Card(Card_value v, Suit s) : c_value(v), c_suit(s) {}
	void Flip();
	int GetValue() const;
	friend ostream &operator<<(ostream &os, const Card &card);

private:
	Card_value c_value;
	Suit c_suit;
	bool card_position{ true };
};