#include <iostream>
using namespace std;

void Summ()
{
	int n;
	cin >> n;
	double s = 0;
	for (int k = 1; k <= n; k++)
	{
		int kfactorial = 1;
		for (int i = 1; i <= k; i++)
		{
			kfactorial = kfactorial * i;
		}
		
		cout << " kfactorial = " << kfactorial << endl;
		s = s + (pow(-1, k) * (1 / pow(kfactorial, 2)));
	}
	cout << "Summ:" << s;
}

void Summ2()
{
	int e;
	cin >> e;
	double s2 = 0;
	for (int i = 1; i <= e; i++)
	{
		s2 = s2 + (pow(-1, 1) * (1 / pow(1, 2)));
	}
	cout << "Summ2:" << s2;
}

int main()
{
	cout << "Enter n" << endl;
	Summ();
	cout << "Enter e" << endl;
	Summ2();
}

