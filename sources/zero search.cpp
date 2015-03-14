#include <iostream>
#include <string>

using namespace std;

struct binom
{
	int a;
	int b;
	int c;
};

double f_binom(double x,binom f)
{
	return (x*x*f.a + x*f.b + f.c);
}

double find_zero(double bottom, double top, double epsilon_f, double epsilon_x, double (*f)(double,binom))
{
	double x = bottom;
	binom example;
	cin >> example.a >> example.b >> example.c;
	while (x <= top)
	{
		if (abs(f(x,example)) <= epsilon_f)
			return x;
		x += epsilon_x;
	}
	if (x >= top)
		return (x);
}

int main()
{
	double bot, top, e_f, e_x;
	cin >> bot >> top >> e_f >> e_x;
	double local = find_zero(bot,top,e_f,e_x, f_binom);
	if (local <= top)
		cout << local;
	else
		cout << "no zeroes with such epsilons or func has no zeroes\n";
	return 0;

}