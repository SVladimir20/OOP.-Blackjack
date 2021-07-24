#include "Deck.h"
Deck::Deck()
{
	h_Cards.reserve(52);
	Populate();
}
void Deck::Populate()
{
	Clear();
	for (int s = static_cast<int>(Card::Suit::Spades); s <= static_cast<int>(Card::Suit::Clubs); ++s)
	{
		for (int v = static_cast<int>(Card::Card_value::Ace); v <= static_cast<int>(Card::Card_value::King); ++v)
		{
			Add(new Card(static_cast<Card::Card_value>(v), static_cast<Card::Suit>(s)));
		}
	}
}
void Deck::Shuffle()
{
	mt19937 sh
	{
		static_cast<unsigned>(chrono::high_resolution_clock::now().time_since_epoch().count())
	};
	shuffle(h_Cards.begin(), h_Cards.end(), sh);
}
void Deck::Deal(Hand &hand)
{
	if (!h_Cards.empty())
	{
		hand.Add(h_Cards.back());
		h_Cards.pop_back();
	}
	else
	{
		cout << "Недостаточно карт ";
	}
}
void Deck::AdditionalCards(GenericPlayer &genericPlayer)
{
	cout << endl;
	while (!(genericPlayer.IsBusted()) && genericPlayer.IsHitting())
	{
		Deal(genericPlayer);
		cout << genericPlayer << endl;
		if (genericPlayer.IsBusted())
		{
			genericPlayer.Bust();
		}
	}
}