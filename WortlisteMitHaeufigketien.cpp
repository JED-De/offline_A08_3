#include <iostream>
#include <string> 
using namespace std;

struct w_haeufigkeit
{
	string wort;
	int haeufigkeit;
};

string naechstes_wort(string zeile, int& pos)
{
	unsigned int anfang= pos;
	string wort = "";
	for (; pos < zeile.size(); pos++)
	{
		if (zeile.at(pos) >= 'a' && zeile.at(pos) <= 'z' || zeile.at(pos) >= 'A' && zeile.at(pos) <= 'Z')
		{
			break;
		}
	}
	for (; pos < zeile.size(); pos++)
	{
		if (!(zeile.at(pos)>= 'a' && zeile.at(pos)<='z' || zeile.at(pos) >= 'A' && zeile.at(pos) <= 'Z')|| zeile.at(pos) == '.')
		{
			break;
		}
	}
	for (int i = anfang; i < pos; i++)
	{
		if (zeile.at(i) >= 'a' && zeile.at(i) <= 'z' || zeile.at(i) >= 'A' && zeile.at(i) <= 'Z')
		{
			wort += zeile.at(i);
		}
	}
	return wort;
}

void zaehle_wort(string wort, w_haeufigkeit haeufigkeiten[], int& w_count)
{
	bool vorkommen = false;
	for (int k = 0; k < w_count; k++)
	{
		if (haeufigkeiten[k].wort == wort)
		{
			vorkommen = true;
			haeufigkeiten[k].haeufigkeit++;
		}
	}

	if (vorkommen == false)
	{
		haeufigkeiten[w_count].wort = wort;
		haeufigkeiten[w_count].haeufigkeit = 1;
		w_count++;
	}
}

int main() {
	int z_count = 0, w_count = 0;
	string wort = "";
	string eingabe[5];

	/* Eingabe hier, setzt auch z_count auf die Anzahl nicht-leerer Zeilen */ 
	for (z_count = 0; z_count < 5; z_count++)
	{
		cout << "Eingabezeile = ? ";
		getline(cin, eingabe[z_count]);
		if (eingabe[z_count] == "")
		{
			break;
		}
	}

		w_haeufigkeit haeufigkeiten[1000];

		for (int k = 0; k < z_count; k++)
		{
			int pos = 0;
			while (true)
			{
				wort = naechstes_wort(eingabe[k], pos);
				if (wort == "")
					break;
				zaehle_wort(wort, haeufigkeiten, w_count);
			}
		}
		for (int k = 0; k < w_count; k++)
			cout << haeufigkeiten[k].wort << ": "
			<< haeufigkeiten[k].haeufigkeit << endl;

		system("PAUSE");
		return 0;
	}