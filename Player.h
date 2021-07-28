#pragma once
#include "GenericPlayer.h"
#include <iostream>
#include <string>
using namespace std;
class Player : public GenericPlayer
{
public:
	Player(const string &name) : GenericPlayer(name) {}
	virtual ~Player() {}
	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};