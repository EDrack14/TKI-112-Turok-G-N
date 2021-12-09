#include <iostream>
using namespace std;

void Counting()
{
	//const double epsilon = 0.0001;
	double h;
	cin >> h;
	const double a = 0.1;
	const int b = 1;
	for (double x = a; x <= b; x = x + h)
	{
		int n = 1;
		int factorial2n = 1;
		for (int i = 1; i <= 2*n; i++)
		{
			factorial2n = factorial2n * i;
		}
		double S;
		if (n == 1) S = 1 - (pow(x, 2) / 2);
		else S = S + pow(-1, n) * pow(x, 2 * n) / factorial2n;
		cout << "x = " << x << "; cos(" << x << ") = " << cos(x) << "; S = "<< S<<endl;
		n = n + 1;
	}
}

int main()
{
	const double epsilon = 0.0001;
	cout << "Enter h "<<endl;
	Counting();
}

