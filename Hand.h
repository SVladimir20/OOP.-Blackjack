#pragma once
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;
class Hand
{
public:
	virtual ~Hand();
	void Add(Card *pCard);
	void Clear();
	int GetTotal() const;

protected:
	vector<Card*> h_Cards;
};