#include<iostream>
using namespace std;

//Potencijalna popravka
void mergesort1(int* data,int* temp, int first, int last);//potpisujemo funkcije hehe
void merge(int* data,int* temp, int first, int last);
//Prvo pravis kostur ovog sortiranja:
void mergesort(int* data, int dim)
{
	int* temp;
	temp = new int[dim];
	mergesort1(data,temp, 0, dim - 1);
	delete[] temp;
}
//Funkcija koja nam deli niz:
void mergesort1(int* data,int* temp, int first, int last)//first i last su indeksi!
{
	if (first < last) {
		int mid = (first + last) / 2;
		mergesort1(data,temp, first, mid);//delimo levu polovinu niza
		mergesort1(data,temp, mid + 1, last);//delimo desnu polovinu niza
		merge(data,temp, first, last);//spajamo
	}
}
//Funkcija koja nam spaja niz u odgovarajucem obliku:
void merge(int* data,int* temp, int first, int last)
{
	int mid = (first + last) / 2;//u prvom prolasku je last=1;
	int i1 = 0, i2 = first, i3 = mid + 1;
	//i1 predstavlja prvi indeks u temp nizu,zato je 0
	while (i2 <= mid  && i3 <= last)//i2 je prvi u levoj polovini
		//a i3 je prvi u desnoj polovini
		if (data[i2] < data[i3])
			//ako je i2 manji od i3 njega smestamo
		{
			temp[i1] = data[i2];
			i1++;
			i2++;
		}
		else
			//ako je i3 manji od i2 njega smesstamo
			temp[i1++] = data[i3++];
	/*Sta se sad desava:
	ti si ispao iz gornjeg vajla jer ti jedan od uslova nije ispunjen,
	sto znaci da moras da prepises ostale elemente u temp jer su oni 
	ostali u dobrom redosledu. Zasto su u dobrom redosledu, jer si ti poceo 
	uporedjujuci po 2 elementa, pa po 4... Ne znam lepo da objasnim, ali 
	se nadam da me razumes. Ono sto ti ostane je vec sortirano. Ako ti je 
	jedan element iz leve polovine manji od i-tog u desnoj, to znaci
	da ce biti manji i od svih posle njega, jer oni su vec sortirani. Eto,
	sad sam se lepo izrazio. :) */
	//  Merge the remaining elements in left array
	while (i2 <= mid)
		temp[i1++] = data[i2++];
    // Merge the remaining elements in right array
	while (i3 <= last)
		temp[i1++] = data[i3++];
	// // Move from temp array to master array
	for (i1 = 0, i2 = first;i2 <= last;i1++, i2++)
		//sa ; izdvajas celine u for-u
		data[i2] = temp[i1];
}
void main() {
	int dim = 6;
	int data[6]={ 4,3,6,1,7,2 };	
	for (int i = 0;i < dim;i++)
		cout << data[i]<<" ";
	cout << endl<<"Nakon mrdzovanja:"<<endl;
	mergesort(data, dim);
	for (int i = 0;i < dim;i++)
		cout << data[i] << " ";

}