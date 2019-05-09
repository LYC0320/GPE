#include <iostream>
#include <sstream>

using namespace std;

long long int kuti = 10000000, lakh = 100000, hajar = 1000, shata = 100;

string convert(long long int n)
{
	long long int q, r;

	if(n / kuti)
	{
		r = n % kuti;
		q = n / kuti;

		if(r)
			return convert(q) + " kuti " + convert(r);
		else
			return convert(q) + " kuti";
	}
	else if(n / lakh)
	{
		r = n % lakh;
		q = n / lakh;

		if(r)
			return convert(q) + " lakh " + convert(r);
		else
			return convert(q) + " lakh";
	}
	else if(n / hajar)
	{
		r = n % hajar;
		q = n / hajar;

		if(r)
			return  convert(q) + " hajar " + convert(r);
		else
			return  convert(q) + " hajar";
	}
	else if(n / shata)
	{
		r = n % shata;
		q = n / shata;

		if(r)
			return  convert(q) + " shata " + convert(r);
		else
			return  convert(q) + " shata";
	}

	stringstream ss;
	ss << n;

	return ss.str();
}


int main()
{
	long long int input;
	int i = 1;

	while(cin >> input)
	{
		stringstream ss;
		ss << i;

		cout << ss.str() + ". " + convert(input) << endl;

		i++;
	}
}