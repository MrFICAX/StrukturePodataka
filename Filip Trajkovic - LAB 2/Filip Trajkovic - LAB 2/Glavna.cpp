#include "Termin.h"
#include "HashTabela.h"
#include <iostream>
#include <string>
#include <time.h> 


using namespace std;

void main()
{
	srand(time(NULL));
	HashTabela* IzdavanjePasosa = new HashTabela(24);	
	string date;
	string time;
	string jmbg;
	bool da_ne;
	string labela;
	unsigned int broj;

	IzdavanjePasosa->Insert(new Termin("12.Mart2020.godine", "10:00h", "0907943027028"));
	IzdavanjePasosa->Insert(new Termin("15.Mart2020.godine", "15:50h", "0907943027028"));
	IzdavanjePasosa->Insert(new Termin("09.Maj2020.godine", "12:30h", "09079435028"));
	IzdavanjePasosa->Insert(new Termin("11.Jun2020.godine", "17:00h", "0456943027028"));
	IzdavanjePasosa->Insert(new Termin("12.Oktobar2020.godine", "11:28h", "0907943020987"));
	IzdavanjePasosa->Insert(new Termin("12.Februar2020.godine", "15:22h", "1201943027028"));
	IzdavanjePasosa->Insert(new Termin("20.Januar2020.godine", "16:00h", "0907943065438"));
	IzdavanjePasosa->Insert(new Termin("25.Avgust2020.godine", "10:55h", "0907943027321"));
	IzdavanjePasosa->stampaj();
	cout << "Da li zelite da unesete nove termine(DA,NE):" << endl;
	cin >> labela;
	if(labela == "DA"){
		cout << "Koliko termina zelite: " << endl;
		cin >> broj;
		for (int i = 0; i < broj; i++) {
			cout << "Uneti datum: " << endl;
			cin >> date;
			cout << "Uneti vreme: " << endl;
			cin >> time;
			cout << "Uneti jmbg: " << endl;
			cin >> jmbg;
		}
		IzdavanjePasosa->Insert(new Termin(date, time, jmbg));
	}
	    IzdavanjePasosa->InformacijeZaTermin("15.Mart2020.godine", "15:50h");
		IzdavanjePasosa->InformacijeZaTermin("20.Septembar2020.godine", "13:40h");
		IzdavanjePasosa->InformacijeZaTermin("13.April2020.godine", "08:10h");

	delete IzdavanjePasosa;
}