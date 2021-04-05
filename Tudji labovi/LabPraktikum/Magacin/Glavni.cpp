#include"Red.h"
#include"Magacin.h"
#include"MagacinLL.h"
#include"RedLL.h"
void main()
{
	try {
		/*Red r(10);
		r.enqueue(2);
		r.enqueue(12);
		r.enqueue(22);
		r.enqueue(32);
		r.stampam();//uvek dodajes na tail, zato je 2 prvi
		//broj, a 32 poslednji
		cout <<"Red: "<< r.dequeue() << " " << r.dequeue() << endl;
		r.stampam();*/
		Magacin m(10);
		m.push(2);
		m.push(4);
		m.push(1);
		m.push(7);
		m.push(12);
		cout << " Staticki Magacin: ";
		m.stampam();
		/*MagacinLL ml;
		ml.push(2);
		ml.push(12);
		ml.push(22);
		ml.push(23);
		ml.stampaj();
		RedLL rl;
		rl.enqueue(2);
		rl.enqueue(1);
		rl.enqueue(3);
		rl.enqueue(7);
		rl.enqueue(34);
		cout << "RedLL: ";
		rl.stampaj();
		cout << rl.dequeue() << " " << rl.dequeue() << endl;
		rl.stampaj();
		cout << "Unesi izraz u prefix notaciji da mu izracunam vrednost." << endl;
		Magacin racunacePrefixIzraz(20);
		char izraz[100];
		cin >> izraz;
		cout << "Vrednost prefix izraz: "<<racunacePrefixIzraz.calcPrefix(izraz) << endl;

		Magacin zaPostfix(20);
		char txt[100];
		cin >> txt;
		zaPostfix.uPostfix(txt);*/
		
		
	/*	char txt1[10];
		char txt2[10];
		cin >> txt1;
		cin >> txt2;
		cout << m.AddLong(txt1, txt2);*/
		
		
		
		
		cout << endl << "Racunam izraz u racunamPostfix notaciji." << endl;
		Magacin racunamPostfix(50);
		while (true)
		{
			char a;
			cin >> a;
			if (a > '0' && a < '9')
			{
				a = a - '0';
				racunamPostfix.push(a);
			}
			else
				switch (a)
				{
				case('+'): 
				{
					int b = racunamPostfix.pop();
					int c = racunamPostfix.pop();
					racunamPostfix.push(c + b);
					break;
				}
				case('*'):
				{
					int b = racunamPostfix.pop();
					int c = racunamPostfix.pop();
					racunamPostfix.push(c * b);
					break;
				}
				case('/'):
				{
					int b = racunamPostfix.pop();
					int c = racunamPostfix.pop();
					racunamPostfix.push(c / b);
					break;
				}
				case('-'):
				{
					int b = racunamPostfix.pop();
					int c = racunamPostfix.pop();
					racunamPostfix.push(c - b);
					break;
				}
				case('e'):
				{
					cout << "Rezultat: " << racunamPostfix.pop()<<endl;
					throw"Ovo je resenje vaseg izraza.";
				}
				}
		}
		


	}
	catch(char* izuzetak)
	{
		cout << izuzetak << endl;
	}
}