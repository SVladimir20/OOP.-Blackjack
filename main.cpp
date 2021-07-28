#include "Game.h"
#include <string>
#include <sstream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << endl << "                            Blackjack" << endl << endl;
	int numPlayers{};
	string tmp;
	cout << "Введите количество игроков (1 - 6): ";
	while (getline(cin, tmp))
	{
		stringstream ss(tmp);
		if (ss >> numPlayers)
		{
			if (numPlayers > 0 && numPlayers < 7)
			{
				if (ss.eof())
				{
					break;
				}
			}
		}
		cout << "Введите количество игроков (1 - 6): ";
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		bool goodName = false;
		cout << "Введите имя игрока " << i+1 << ": ";
		do
		{
			getline(cin, name);
			if (name[0] == ' ')
			{
				name.erase();
			}
			else
			{
				names.push_back(name);
				goodName = true;
			}
			if (!name.empty())
			{
				names.push_back(name);
				goodName = true;
			}
			else
			{
				cout << "Введите имя игрока " << i + 1 << ": ";
			}
		}
		while (!goodName);
	}
	cout << endl;
	Game aGame(names);
	string answer;
	do
	{
		aGame.Play();
		do
		{
			cin.ignore();
			cout << "Хотите сыграть ещё раз? (y/n): ";
			getline(cin, answer);
		}
		while (answer != "y" && answer != "n");
	}
	while (answer == "y");
	return 0;
}