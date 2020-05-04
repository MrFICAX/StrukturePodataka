#include "BST.h"

BST::BST()
{
	koren = NULL;
	broj_el = 0;
}

BST::~BST()
{
	deleteTree(koren);
}

void BST::insert(int el)
{
	Cvor* p = koren;
	Cvor* prev = NULL;
	while(p != NULL)
	{
		prev = p;
		if (p->jeManji(el))
			p = p->getDesni();
		else if (p->jeVeci(el))
			p = p->getLevi();
		else
			return;
	}
	if (koren == NULL)
		koren = new Cvor(el);
	else if (prev->jeManji(el))
		prev->desni = new Cvor(el);
	else
		prev->levi = new Cvor(el);
	broj_el++;
}

Cvor* BST::search(Cvor* tmp, int el)
{
	while (tmp != NULL)
		if (tmp->jeJednak(el))
			return tmp;
		else
			if (tmp->jeVeci(el))
				tmp = tmp->levi;
			else
				tmp = tmp->desni;
	return nullptr;
}

void BST::deleteTree(Cvor* tmp)
{
	if (tmp != NULL)
	{
		deleteTree(tmp->levi);
		deleteTree(tmp->desni);
		delete tmp;
	}
}
void BST::printPostOrder() {
	cout << "Stampanje u PostOrder notaciji: " << endl;
	printPostOrder(koren);
	cout << endl;
}
void BST::printPostOrder(Cvor* tmp)
{
	//postorder
	if (tmp != NULL)
	{
		printPostOrder(tmp->levi);
		printPostOrder(tmp->desni);
		cout << tmp->kljuc << endl;
	}
}
void BST::printLevelOrder() {
	cout << "Stampanje u LevelOrder notaciji: " << endl;
	printLevelOrder(koren);
	cout << endl;
}
void BST::printLevelOrder(Cvor* root)
{
	int h = visina(root);
	int i;
	for (i = 1; i <= h; i++)
		printGivenLevel(root, i);
}
void BST::printGivenLevel(Cvor* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->kljuc << " ";
	else if (level > 1)
	{
		printGivenLevel(root->levi, level - 1);
		printGivenLevel(root->desni, level - 1);
	}
}
int BST::visina(Cvor* cvor)
{
	if (cvor == NULL)
		return 0;
	else
	{
		
		int lheight = visina(cvor->levi);
		int rheight = visina(cvor->desni);
		
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}
void BST::brisanjeListova()
{
	cout << "Brisanje listova: " << endl;
	if (koren != NULL)
	{
		if (koren->levi == NULL && koren->desni == NULL)
		{
			delete koren;
			koren = NULL;
		}
	}
	brisanjeListova(koren);
}
void BST::brisanjeListova(Cvor* cvor)
{
	if (cvor == NULL)
		return;
	if (cvor->levi != NULL)
	{
		if (cvor->levi->levi == NULL && cvor->levi->desni == NULL)
		{
			delete cvor->levi;
			cvor->levi = NULL;
		}
	}
	if (cvor->desni != NULL)
	{
		if (cvor->desni->levi == NULL && cvor->desni->desni == NULL)
		{
			delete cvor->desni;
			cvor->desni = NULL;

		}
	}
	brisanjeListova(cvor->levi);
	brisanjeListova(cvor->desni);
}





