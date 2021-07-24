#pragma once
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include "House.h"
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
class Game
{
public:
	Game(const vector<string> &names);
	~Game() {}
	void Play();

private:
	Deck g_Deck;
	House g_House;
	vector<Player> g_Players;
};