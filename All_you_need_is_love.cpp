#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

int myStoi(string s)
{
	int result = 0;

	for(int i = s.size() - 1; i >= 0; i--)
	{
		result += (s[i] - 48) * pow(2, s.size() - 1 - i);
	}

	return result;
}

int findMaxHcf(int a, int b)
{
	while(a != 0 && b != 0)
	{
		if(a >= b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}

	return (a == 0) ? b : a;
}

int main()
{
		int dataNum;
		cin >> dataNum;

		for(int i = 0; i < dataNum; i++)
		{
			string s1, s2;
			cin >> s1;
			cin >> s2;

			stringstream ss;
			ss << i + 1;
			if(findMaxHcf(myStoi(s1), myStoi(s2)) > 1)
				cout << "Pair #" + ss.str() + ": All you need is love!" << endl;
			else
				cout << "Pair #"+ ss.str() +": Love is not all you need!" << endl;
		}
}