#include "Hand.h"
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Card *pCard)
{
	h_Cards.push_back(pCard);
}
void Hand::Clear()
{
	vector<Card*>::iterator iter = h_Cards.begin();
	for (iter = h_Cards.begin(); iter != h_Cards.end(); ++iter)
	{
		delete *iter;
		*iter = nullptr;
	}
	h_Cards.clear();
}
int Hand::GetTotal() const
{
	if (h_Cards.empty())
	{
		return 0;
	}
	if (h_Cards[0]->GetValue() == 0)
	{
		return 0;
	}
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = h_Cards.begin(); iter != h_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}
	bool containsAce = false;
	for (iter = h_Cards.begin(); iter != h_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == static_cast<int>(Card::Card_value::Ace))
		{
			containsAce = true;
		}
	}
	if (containsAce && total <= 11)
	{
		total += 10;
	}
	return total;
}