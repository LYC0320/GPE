#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int myStoi(string s)
{	
	int result = 0;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == '-')
			result = -result;
		else
			result += (s[i] - 48) * pow(10, s.size() - 1 - i);
	}

	return result;
}

int main()
{
	int dataNum;
	cin >> dataNum;

	for(int i = 0; i < dataNum; i++)
	{
		int insNum;
		cin >> insNum;
		cin.ignore();

		int p = 0;

		vector<string> inses;

		for(int j = 0; j < insNum; j++)
		{
			string ins;
			getline(cin, ins);

			if(ins == "LEFT")
			{
				inses.push_back("LEFT");
				p--;
			}
			else if(ins == "RIGHT")
			{
				inses.push_back("RIGHT");
				p++;
			}
			else
			{
				string token = "";
				token = ins.substr(8);
				string tmpIns = inses[myStoi(token) - 1];
				inses.push_back(tmpIns);

				if(tmpIns == "LEFT")
					p--;
				else
					p++;
			}
		}

		cout << p << endl;
	}
}