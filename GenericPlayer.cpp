#include "GenericPlayer.h"
bool GenericPlayer::IsBusted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	cout << g_Name << " перебор" << endl;
}
ostream &operator<<(ostream &os, const GenericPlayer &genericPlayer)
{
	os << genericPlayer.g_Name << ": ";
	vector<Card*>::const_iterator pCard;
	if (!genericPlayer.h_Cards.empty())
	{
		for (pCard = genericPlayer.h_Cards.begin(); pCard != genericPlayer.h_Cards.end(); ++pCard)
		{
			os << *(*pCard) << "\t";
		}
		if (genericPlayer.GetTotal() != 0)
		{
			cout << "(" << genericPlayer.GetTotal() << ")";
		}
	}
	else
	{
		os << "пусто";
	}
	return os;
}