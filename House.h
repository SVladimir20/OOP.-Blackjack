#pragma once
#include "GenericPlayer.h"
#include <iostream>
using namespace std;
class House : public GenericPlayer
{
public:
	House(const string &name = "House") : GenericPlayer(name) {}
	virtual ~House() {}
	virtual bool IsHitting() const;
	void FlipFirstCard();
};