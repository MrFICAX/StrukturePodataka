#include"Magacin.h"

Magacin::Magacin()
{
	niz = NULL;
	velicina = top = 0;
}
Magacin::Magacin(int n)
{
	velicina = n;
	top = -1;
	niz = new int[n];
}
Magacin::~Magacin() { delete[] niz; }

int Magacin::getTop() 
{
	if (top == -1)
		throw "Prazan je magacin.";
	return niz[top];
}
void Magacin::push(int el)
{
	top++;
		if (top == velicina)
			throw " Magacin je prazan.";
		niz[top] = el;
}
int Magacin::pop()
{
	if (top == -1)
		throw "Magacin je prazan.";
	int el = niz[top];
	top--;
	return el;
}
void Magacin::stampam()
{
	if (top == -1)
		throw "Magacin je prazan.";
	while (top != -1)
		cout << pop() << " ";
	cout << endl;
}
int Magacin::prioritet(char c)
{
	int p = 0;
	if (c == '+' || c == '-')
		p = 1;
	if (c == '*' || c == '/')
		p = 2;
	if (c == '^')
		p = 3;
	return p;
}
void Magacin::uPostfix(char* s)
{
	for (int i = 0; i < (int)strlen(s); i++)
	{
		char pom = s[i];
		//Svaku brojku koju uneses odmah je stampas.
		switch (pom)
		{
		case '(':
			//kad naidjes na otvorenu zagradu, samo je stavis
			push(pom);
			break;
		case ')':
			//kad zatvoris zagradu popujes sve sto je bilo unutra
			//dok god ne dodjes na otvorenu zagradu, ili na dno steka
		{
			char c;
			while ((!isEmpty()) && ((c = pop()) != '('))
				cout << c;
		}
		break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		{
			if ((!isEmpty()) && (prioritet(pom) <= prioritet(getTop())))
			{
				//stampaces sve sto je na steku manjeg prioriteta, imaj na umu da
				//su na steku samo operacije
				cout << pop();
			}
			push(pom);
		}
		break;
		default:
			cout << pom;
		}
	}
	while (!isEmpty())
		//na kraju cistis stek
		cout << (char)pop();//nasa pop funkcija vraca intedzer
	//zato moramo da kastujemo
}

double Magacin::calcPrefix(char* inStr)
{
	double d;
	int a;
	int b;
	for (int i = strlen(inStr) - 1;i >= 0;i--)
	{
		char c;
		c = inStr[i];
		if (c >= '0'&&c <= '9')
		{
			c = c - '0';
			push(c);
		}
		
		switch (c)
		{
		case ('+'):
			 a = pop();
			 b = pop();
			 d = b + a;
			 push(d);
			break;
		case('-'):
			 a = pop();
			 b = pop();
			 d = a - b;
			 push(d);
			break;
		case('*'):
			 a = pop();
			 b = pop();
			 d = b * a;
			 push(d);;
			break;
		case('/'):
		{
			 a = pop();
			b = pop();
			 d = a / b;
			 push(d);
			break;
		}

		}
	}
	return pop();
}


//Ideja je ova, sad je problem sto su moji popovi u pushevi int
//Evenutualno neka manja korekcija, nemam sad kad da radim.
char* Magacin::AddLong(char* s1, char*s2)
{
	Magacin stek1(10);
	Magacin stek2(10);
	Magacin stek3(10);//rezultat
	Magacin prenos(10);
	for (int i = 0;i < strlen(s1) - 1;i++)
	{
		char c=s1[i];
		c = c - '0';
		stek1.push(c);
	}
	for (int i = 0;i < strlen(s2) - 1;i++)
	{
		char c = s2[i];
		c = c - '0';
		stek2.push(c);
	}
	while (!stek1.isEmpty() && !stek2.isEmpty())
	{
		int a = stek1.pop() + stek2.pop();
		int b = a % 10;

		if (prenos.top != -1)
			stek3.push(b + prenos.pop());
		else
			stek3.push(b);
		a = a / 10;
		prenos.push(a);
		
	}
		while (!stek1.isEmpty())
		{
			if (prenos.top != -1)
				stek3.push(stek1.pop() + prenos.pop());
			else
			stek3.push(stek1.pop());
		}
		while (!stek2.isEmpty())
		{
			if (prenos.top != -1)
				stek3.push(stek2.pop() + prenos.pop());
			else
			stek3.push(stek2.pop());
		}
	
		static char* rezultat = new char[10];
		int i = 0;
		while (!stek3.isEmpty())
		{
			char karakter= char(stek3.pop());
			 rezultat[i++] = karakter;
		}
		rezultat[i] = '\0';
		return rezultat;

}