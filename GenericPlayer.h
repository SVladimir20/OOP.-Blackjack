#pragma once
#include "Hand.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class GenericPlayer : public Hand
{
public:
	GenericPlayer(const string &name) : g_Name(name) {}
	virtual ~GenericPlayer() {}
	virtual bool IsHitting() const = 0;
	bool IsBusted() const;
	void Bust() const;
	friend ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer);

protected:
	string g_Name;
};