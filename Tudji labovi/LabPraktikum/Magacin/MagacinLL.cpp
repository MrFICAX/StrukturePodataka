#include"MagacinLL.h"

MagacinLL::MagacinLL()
{
	vrh = NULL;
}
void MagacinLL::push(int c)
{
	vrh = new Cvor(c,vrh);
}
int MagacinLL::pop()
{
	if (vrh == NULL)
		throw "Potkoracenje";
	int rezultat = getVrh();
	Cvor* samoZaCas = vrh;
	vrh = vrh->getNext();

	delete samoZaCas;
	return rezultat;
}
void MagacinLL::stampaj()
{
	if (vrh == NULL)
		throw "Magacin je prazan.";
	while (vrh != NULL)
		cout << pop() << " ";
	cout << endl;
}