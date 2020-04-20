#include "Termin.h"
#include <string>
#include <iostream>

using namespace std;

Termin::Termin() {
	this->date = this->time = this->JMBG = "";
}

Termin::Termin(string date, string time, string jmbg) {
	setTime(time);
	setJMBG(jmbg);
	setDate(date);
}
Termin::~Termin(){
}

Termin::Termin(const Termin& ime) {
	this->date = ime.date;
	this->time = ime.time;
	this->JMBG = ime.JMBG;
}

bool Termin::isNull() {
	bool povratna = false;
	if (date == "")
		povratna = true;
	return povratna;
}
void Termin::informacije() {
	cout << this->getDate()<<" ";
	cout << this->getTime()<<" ";
	cout << this->getJMBG()<<endl;
}
bool operator==(const Termin& prvi, const Termin& drugi) {
	bool povratna = false;
	if (prvi.date == drugi.date && prvi.time == drugi.time)
		povratna = true;
	return povratna;
}
Termin& Termin::operator=(const Termin& ime) {
	if(this != &ime)
		{
			this->date = ime.date;
			this->time = ime.time;
			this->JMBG = ime.JMBG;
		}
	return *this;
}
int Termin::VremeUInt(string time)
{
	int vreme = 0;
	int j = 0;
	while (j<5)
	{
		if(j!=2)
			vreme = vreme * 10 + (int)time[j] - 48;
		j++;
	}
	return vreme;
}
void Termin::obrisi() {
	this->date = this->time = this->JMBG = "";
}


