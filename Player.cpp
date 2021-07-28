#include "Player.h"
bool Player::IsHitting() const
{
	cout << g_Name << ", раздать ещё одну карту? (Y/N): ";
	char answer;
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Player::Win() const
{
	cout << endl << g_Name << " выиграл." << endl;
}
void Player::Lose() const
{
	cout << endl << g_Name << " проиграл." << endl;
}
void Player::Push() const
{
	cout << endl << g_Name << " сыграл вничью." << endl;
}