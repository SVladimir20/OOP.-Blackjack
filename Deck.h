#pragma once
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include <iostream>
#include <chrono>
#include <random>
using namespace std;
class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck() {}
	void Populate();
	void Shuffle();
	void Deal(Hand &hand);
	void AdditionalCards(GenericPlayer &genericPlayer);
};