#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Profil
{
public:
	string nume;

	Profil(string nume)
	{
		this->nume = nume;
	}

	virtual void afisare()
	{
		cout << nume << endl;
	}

	virtual float getCard() { return 0;  };
	virtual void setCard(float depunere) {};
	virtual float getDobanda() { return 0; };
	virtual void afisareCard() {};
	virtual float getEconomi() { return 0; };
	virtual void setEconomi(float transfer) {};

};

class Card : public Profil
{
public:
	float card;

	Card(string nume, float card) : Profil(nume)
	{
		this->card = card;
	}

	virtual void afisare()
	{
		Profil::afisare();
		cout << "card_bancar:" << endl;
		cout << card << endl;
	}

	float getCard()
	{
		return card;
	}
	void setCard(float depunere) 
	{
		card += depunere;
	};
	float getDobanda() { return 0; }
	virtual void afisareCard() {};
	virtual float getEconomi() { return 0; };
	virtual void setEconomi(float transfer) {};
};

class Cont_economii : public Card
{
public:
	float economi;
	float dobanda;

	Cont_economii(string nume, float card, float economi, float dobanda) : Card(nume, card)
	{
		this->economi = economi;
		this->dobanda = dobanda;
	}

	void afisare()
	{
		Card::afisare();
		cout << "cont_economii:" << endl;
		cout << economi << endl;
		cout << dobanda * 100;
	}

	float getDobanda() 
	{ 
		return dobanda;
	};

	void afisareCard() 
	{
		cout << "card_bancar:" << endl;
		cout << card << endl;
		cout << "cont_economii:" << endl;
		cout << economi << endl;
		cout << dobanda;
	};

	virtual float getEconomi() 
	{ 
		return economi;
	};
	virtual void setEconomi(float newEconomi) 
	{
		economi = newEconomi;
	};

};

int main()
{
	string nume;
	float card, economi, dobanda;
	int opt;

	float depunere;
	float extragere;
	float transfer;
	float suma;

	getline(cin, nume);
	cin >> card >> economi >> dobanda >> opt;
	dobanda = dobanda / 100;
	Profil *p = new Cont_economii(nume, card, economi, dobanda);

	switch (opt)
	{
	case 1:
		p->afisare();
		break;

	case 2:
		cin >> depunere;
		if (depunere < 0)
			cout << "EROARE: depunere suma negativa";
		else
		{
			p->setCard(depunere);
			cout << "card_bancar:" << endl;
			cout << p->getCard();
		}
		break;

	case 3:
		cin >> extragere;
		if (extragere > p->getCard())
			cout << "EROARE: fonduri insuficiente";
		else
		{
			p->setCard(p->getCard() - extragere);
			cout << "card_bancar:" << endl;
			cout << p->getCard();
		}
		break;

	case 4:
		cin >> transfer;
		if (transfer > p->getCard())
			cout << "EROARE: fonduri insuficiente";
		else
		{
			p->setCard(0 - transfer);
			p->setEconomi((p->getEconomi() + transfer)*p->getDobanda());
			p->afisareCard();

		}
		break;

	case 5:
		cin >> suma;
		int i=0;
		while (p->getEconomi() < suma)
		{
			p->setEconomi(p->getEconomi() + (p->getEconomi()*p->getDobanda()));
			i++;
		}
		cout << i;

	}
	

	return 0;
}
