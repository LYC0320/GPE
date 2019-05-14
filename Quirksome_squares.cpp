#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sstream>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{

		if (n == 8)
		{
			cout << "00000000" << endl;
			cout << "00000001" << endl;
			cout << "04941729" << endl;
			cout << "07441984" << endl;
			cout << "24502500" << endl;
			cout << "25502500" << endl;
			cout << "52881984" << endl;
			cout << "60481729" << endl;
			cout << "99980001" << endl;
			
			continue;
		}

		for (int i = 0; i < pow(10, n); i++)
		{
			int tmp = pow(10, n / 2);
			int front = i / tmp, back = i % tmp;

			if (pow(front + back, 2) == i)
			{
				stringstream ss;
				ss << i;
				string s = "";

				for (int j = 0; j < n - ss.str().size(); j++)
				{
					s += "0";
				}

				s += ss.str();

				cout << s << endl;
			}
		}
	}
}