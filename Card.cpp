#include "Card.h"
void Card::Flip()
{
	card_position = !(card_position);
}
int Card::GetValue() const
{
	int value{};
	if (card_position)
	{

		value = static_cast<int>(c_value);

		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}
ostream &operator<<(ostream &os, const Card &card)
{
	const string Value[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
	const string Suit[] = { "s", "h", "d", "c" };
	if (card.card_position)
	{
		os << Value[static_cast<int>(card.c_value)] << Suit[static_cast<int>(card.c_suit)];
	}
	else
	{
		os << "XX";
	}
	return os;
}