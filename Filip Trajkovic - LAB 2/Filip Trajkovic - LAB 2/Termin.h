#pragma once
#include <string>

using namespace std;

class Termin {
private:
	string date;
	string time;
	string JMBG;
	inline void setDate(string Date) { this->date =  Date; }
	inline void setTime(string Time) { this->time = Time; }
	inline void setJMBG(string JMBG) { this->JMBG = JMBG; }
	void obrisi();
public:
	Termin();
	Termin(string date, string time, string jmbg);
	~Termin();
	friend bool operator== (const Termin&, const Termin&);
	Termin(const Termin&);
	bool isNull();
	static int VremeUInt(string);
	void informacije();
	Termin& operator=(const Termin&);
	inline string getDate() { return date; }
	inline string getTime() { return time; }
	inline string getJMBG() { return JMBG; }
};
