#include "House.h"
bool House::IsHitting() const
{
	if (GetTotal() <= 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void House::FlipFirstCard()
{
	if (!(h_Cards.empty()))
	{
		h_Cards[0]->Flip();
	}
	else
	{
		cout << "Переворачивать нечего" << endl;
	}
}