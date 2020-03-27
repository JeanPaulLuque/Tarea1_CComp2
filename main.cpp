#include <iostream>

using namespace std;
bool validar(int, int);
void show(int , int );
int days(int, int);
int cZeller(int, int);
int main()
{
	int month , year ;
	cout << "Month: " << endl;
	cin >> month;
	cout << "Year: " << endl;
	cin >> year;
	bool valido = validar(month,year);
	cout << valido << endl;

	if (valido)
	{
		cout << "Ingreso correcto." << endl;
		system("CLS");
		show(month,year);
	}
	else
	{
		cout << "Entradas Incorrectas" << endl;
	}

	return 0;
}
bool validar(int m, int y)
{
	if (m <= 0 || m > 12)
	{
		return false;
	}
	else if (y <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void show(int m, int y)
{
	int dias =(int) days(m, y);
	int zeller = cZeller(m, y);
	
	cout << "    Calendario" << endl;
	cout << " D  L  M  X  J  V  S " << endl;
	for (int i = 0; i < zeller; i++)
	{
		cout << "   ";
	}
	for (int i = 1; i <= dias; i++)
	{
		zeller++;
		if (i < 10)
		{
			cout << " " << i << " ";
			
		}
		else {
			cout << i << " ";
		}
		
		if (!(zeller % 7))
		{
			cout << endl;
		}
	}
}
int days(int m, int y)
{
	int dias;
	if ((m == 1) || (m == 3 )||( m == 5) || (m == 7 )|| (m == 8 )|| (m == 10 )|| (m == 12))
	{
		dias = 31;
		return dias;
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		dias = 30;
		return dias;
	}
	else if (m==2)
	{
		if ((y % 4))
		{
			dias = 28;
			return dias;
		}
		
		else
		{
			dias = 29;
			return dias;
		}
	}
}
int cZeller(int month, int year)
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d, dia = 1;
	d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	
	return d;
	
}