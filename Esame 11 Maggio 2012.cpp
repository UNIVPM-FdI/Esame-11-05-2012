#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct schedina {
	char teamcasa[21];
	char teamospite[21];
	int risultato;
	schedina *succ;
};

typedef schedina* lista;
void inserimentordinato (lista& inizio,schedina a);
void stampalista(lista p0);
void leggi (lista& inizio,schedina a);
void trova(schedina b);
void cerca(lista p,int n);
int main()
{
	schedina a,b;
	lista p0=0;
	leggi(p0,a);
	stampalista(p0);
	trova(b);
	//cerca(p0,2);
	return 0;
}

void inserimentordinato(lista& inizio, schedina a)
{lista p=0, q, d;
for (q=inizio;q != 0 && q->risultato>a.risultato; q = q->succ)p = q;
d = new schedina;
d->risultato=a.risultato;
strcpy(d->teamcasa,a.teamcasa);
strcpy(d->teamospite,a.teamospite);
d->succ = q;
// controlla se si deve inserire in testa
if (q == inizio) inizio = d;
 else p->succ = d;
} 

void leggi(lista& inizio, schedina a)
{
	fstream input;	
	input.open("schedina.dat",ios::in);
	while (input.good())
	{
		input >> a.teamcasa >> a.teamospite>> a.risultato;
		inserimentordinato(inizio,a);
	}
	input.close();
}
void stampalista(lista p)
{
	while (p!=0)
	{
		cout << p->teamcasa << " " << p->teamospite << " " << p->risultato << endl;
		p=p->succ;
	}
}
void trova(schedina b) //  metodo mio
{
	fstream input1,input2;	
	input1.open("schedina.dat",ios::in);
	input2.open("fuoricasa.dat",ios::out);
	while (input1.good())
	{
		input1 >> b.teamcasa >> b.teamospite>> b.risultato;
		if(b.risultato==2)
		input2 << b.teamospite << endl; 
			}
			input1.close();
			input2.close();
}
void cerca(lista p,int n) // metodo Dragoni
{
	fstream output;
	output.open("fuoricasa.dat",ios::out);
	while (p != 0)
	{
		if (p->risultato==n)
		output << p->teamospite << endl;
		p=p->succ;
	}
output.close();
}
