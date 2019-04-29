#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

int myStoi(string s)
{
	int result = 0;

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '-')
			result = -result;
		else
			result += (s[i] - '0')*pow(10, s.size() - 1 - i);
	}

	return result;
}

int main()
{
	string input;
	vector<string> ans;
	bool isBreak = false;

	while (getline(cin, input))
	{
		vector<string> s;

		if (input == ".")
		{
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i] << endl;
			}
			break;
		}

		string token = "";

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ' ')
			{
				if (token != "")
					s.push_back(token);
				token = "";
				continue;
			}

			token += input[i];

			if (i == input.size() - 1)
				s.push_back(token);
		}

		if (s.size() == 0)
		{
			ans.push_back("illegal");
			continue;
		}
		else if (s.size() == 1)
		{
			ans.push_back("illegal");
		}

		for (int i = s.size() - 1; i >= 0; i--)
		{
			int a, b, c;

			if (s[i] == "+")
			{
				if ((i + 1) >= s.size() || (i + 2) >= s.size())
				{
					ans.push_back("illegal");
					isBreak = true;
					break;
				}

				a = myStoi(s[i + 1]);
				b = myStoi(s[i + 2]);

				c = a + b;
			}
			else if (s[i] == "-")
			{
				if ((i + 1) >= s.size() || (i + 2) >= s.size())
				{
					ans.push_back("illegal");
					isBreak = true;
					break;
				}

				a = myStoi(s[i + 1]);
				b = myStoi(s[i + 2]);

				c = a - b;
			}
			else if (s[i] == "*")
			{
				if ((i + 1) >= s.size() || (i + 2) >= s.size())
				{
					ans.push_back("illegal");
					isBreak = true;
					break;
				}

				a = myStoi(s[i + 1]);
				b = myStoi(s[i + 2]);

				c = a * b;
			}
			else if (s[i] == "/")
			{
				if ((i + 1) >= s.size() || (i + 2) >= s.size())
				{
					ans.push_back("illegal");
					isBreak = true;
					break;
				}

				a = myStoi(s[i + 1]);
				b = myStoi(s[i + 2]);

				c = a / b;
			}
			else if (s[i] == "%")
			{
				if ((i + 1) >= s.size() || (i + 2) >= s.size())
				{
					ans.push_back("illegal");
					isBreak = true;
					break;
				}

				a = myStoi(s[i + 1]);
				b = myStoi(s[i + 2]);

				c = a % b;
			}
			else
			{
				continue;
			}

			s.erase(s.begin() + i);
			s.erase(s.begin() + i);
			s.erase(s.begin() + i);

			stringstream ss;
			ss << c;

			s.insert(s.begin() + i, ss.str());

			i = s.size() - 1;
		}

		if (s.size() == 1 && !isBreak)
			ans.push_back(s[0]);
		else if (!isBreak)
		{
			ans.push_back("illegal");
		}

		isBreak = false;
	}

	//system("pause");
}