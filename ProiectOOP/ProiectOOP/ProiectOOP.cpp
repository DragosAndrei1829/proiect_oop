#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;


class CustomException
{
	
};

class TabelCompanie
{
private:
	
	const string numeFirma;
	string* coloana = NULL;

public:
	
	TabelCompanie(string numeFirma) : numeFirma(numeFirma) { }


	

};




class Angajati
{
private:

	int numarAngajati = 0;
	string* nume = NULL;
	string* prenume = NULL;

public:

	Angajati(int numarAngajati)
	{
		this->numarAngajati = numarAngajati;
	}
	
	Angajati(int numarAngajati, string* nume, string* prenume)
	{
		if (numarAngajati > 0 && nume != NULL && prenume != NULL)
		{
			this->numarAngajati = numarAngajati;
			this->nume = new string[this->numarAngajati];
			this->prenume = new string[this->numarAngajati];
			for (int i = 0; i < this->numarAngajati; i++)
			{
				this->nume[i] = nume[i];
				this->prenume[i] = prenume[i];
			}
		}
	}
		

	friend ostream& operator << (ostream& out, const Angajati& a)
	{
		out << "\nNr Angajati : "<< a.numarAngajati;
		for (int i = 0; i < a.numarAngajati; i++)
		{
			out <<"\nNume si prenume :  " << a.nume[i] << " " << a.prenume[i];
		}

		return out;
	}

	~Angajati()
	{
		delete[] nume;
		delete[] prenume;
	}
	
	friend class TabelCompanie;
	friend class Pozitii;
	friend class Salarii;
	friend class DataAngajare;
};




class Pozitii
{
private:
	
	string* pozitie = NULL;
	int numarAngajati = 0;

public:

	Pozitii(string* pozitie, Angajati& a)
	{
		this->numarAngajati = a.numarAngajati;
		this->pozitie = new string[this->numarAngajati];
		for (int i = 0; i < this->numarAngajati; i++)
		{
			this->pozitie[i] = pozitie[i];
		}
	}
	
	friend ostream& operator << (ostream& out, const Pozitii& p)
	{
		out << "\nPozitie Angajat : " ;
		for (int i = 0; i < p.numarAngajati; i++)
		{
			out << p.pozitie[i]<< " ";
		}
		
		return out;
	}

	
	~Pozitii()
	{
		delete[] pozitie;
	}
	
	friend class TabelCompanie;
};




class Salarii
{
private:
	
	static float salariulMinim;
	float* salariu = NULL;
	int numarAngajati = 0;

public:

	Salarii(float* salariu, Angajati& a)
	{
		this->numarAngajati = a.numarAngajati;
		this->salariu = new float[this->numarAngajati];
		for (int i = 0; i < this->numarAngajati; i++)
		{
			this->salariu[i] = salariu[i];
		}
	}

	friend ostream& operator << (ostream& out, const Salarii& s)
	{
		out << "\nSalariu Angajat : ";
		for (int i = 0; i < s.numarAngajati; i++)
		{
			out << s.salariu[i] << " ";
		}

		return out;
	}
	
	~Salarii()
	{
		delete[] salariu;
	}

	friend class TabelCompanie;
};

float Salarii::salariulMinim = 1300;




class DataAngajare
{
private:
	
	int* ziAngajare = NULL;
	int* lunaAngajare = NULL;
	int* anAngajare = NULL;
	int numarAngajati = 0;

public:

	DataAngajare(int* ziAngajare, int* lunaAngajare, int* anAngajare, Angajati& a)
	{
		this->numarAngajati = a.numarAngajati;
		this->ziAngajare = new int[this->numarAngajati];
		this->lunaAngajare = new int[this->numarAngajati];
		this->anAngajare = new int[this->numarAngajati];
		for (int i = 0; i < this->numarAngajati; i++)
		{
			this->ziAngajare[i] = ziAngajare[i];
			this->lunaAngajare[i] = lunaAngajare[i];
			this->anAngajare[i] = anAngajare[i];
		}
	}
		
	friend ostream& operator << (ostream& out, const  DataAngajare& d)
	{
		out << "\nData Angajarilor (dd/mm/yyyy) : ";
		for (int i = 0; i < d.numarAngajati; i++)
		{
			out <<"\n" << d.ziAngajare[i] << "/" << d.lunaAngajare[i] << "/" << d.anAngajare[i];
		}

		return out;
	}

	~DataAngajare()
	{
		delete[] ziAngajare;
		delete[] lunaAngajare;
		delete[] anAngajare;
	}
	
	friend class TabelCompanie;
	
};


int main()
{
//	TabelCompanie Apple("Apple");
	
	string nume[2] = {"Ion", "Cozmaa"};
	string prenume[2] = {"Miau", "Ham"};
	Angajati a1(2, nume, prenume);
	cout << a1;
	
	cout << endl;
	
	string pozitie[2] = {"Salvamar", "Gamer"};
	Pozitii p1(pozitie, a1);
	cout << p1;

	cout << endl;

	float salariu[2] = { 2900, 3400.50 };
	Salarii s1(salariu, a1);
	cout << s1;

	cout << endl;
	
	int ziua[2] = { 21, 30 };
	int luna[2] = { 04, 11 };
	int an[2] = { 2022, 2009 };
	DataAngajare d1(ziua, luna, an, a1);
	
	cout << d1;
	
    return 0;
}

