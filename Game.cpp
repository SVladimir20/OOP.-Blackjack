#include "Game.h"
Game::Game(const vector<string> &names)
{
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		g_Players.push_back(Player(*pName));
	}
	srand(static_cast<unsigned int>(time(0)));
	g_Deck.Populate();
	g_Deck.Shuffle();
}
void Game::Play()
{
	vector<Player>::iterator pPlayer;
	for (int i = 0; i < 2; ++i)
	{
		for (pPlayer = g_Players.begin(); pPlayer != g_Players.end(); ++pPlayer)
		{
			g_Deck.Deal(*pPlayer);
		}
		g_Deck.Deal(g_House);
	}
	g_House.FlipFirstCard();
	for (pPlayer = g_Players.begin(); pPlayer != g_Players.end(); ++pPlayer)
	{
		cout << *pPlayer << endl;
	}
	cout << g_House << endl;
	for (pPlayer = g_Players.begin(); pPlayer != g_Players.end(); ++pPlayer)
	{
		g_Deck.AdditionalCards(*pPlayer);
	}
	g_House.FlipFirstCard();
	cout << endl << g_House;
	g_Deck.AdditionalCards(g_House);
	if (g_House.IsBusted())
	{
		for (pPlayer = g_Players.begin(); pPlayer != g_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				pPlayer->Win();
			}
		}
	}
	else
	{
		for (pPlayer = g_Players.begin(); pPlayer != g_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->IsBusted()))
			{
				if (pPlayer->GetTotal() > g_House.GetTotal())
				{
					pPlayer->Win();
				}
				else if (pPlayer->GetTotal() < g_House.GetTotal())
				{
					pPlayer->Lose();
				}
				else
				{
					pPlayer->Push();
				}
			}
		}
	}
	for (pPlayer = g_Players.begin(); pPlayer != g_Players.end(); ++pPlayer)
	{
		pPlayer->Clear();
	}
	g_House.Clear();
}