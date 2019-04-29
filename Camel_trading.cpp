#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

int myStoi(string s)
{
	int result = 0;

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '-')
			result = -result;
		else
			result += (s[i] - 48)*pow(10, s.size() - 1 - i);
	}

	return result;
}

int main()
{
	int N;

	cin >> N; 

	vector<string> ans(N, "");

	for (int n = 0; n < N; n++)
	{
		string input;
		cin >> input;
		
		vector<int> number, number2;
		vector<char> operators, operators2;
		string token = "";

		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '+')
			{
				number.push_back(myStoi(token));
				operators.push_back('+');

				number2.push_back(myStoi(token));
				operators2.push_back('+');

				token = "";
			}
			else if (input[i] == '*')
			{
				number.push_back(myStoi(token));
				operators.push_back('*');

				number2.push_back(myStoi(token));
				operators2.push_back('*');

				token = "";
			}
			else
				token += input[i];

			if (i == input.size() - 1)
			{
				number.push_back(myStoi(token));
				number2.push_back(myStoi(token));
			}
		}

		long long maximum = 0, minimum = 0;

		for (int i = 0; i < operators.size(); i++)
		{
			if (operators[i] == '+')
			{
				int tmp = number[i] + number[i + 1];
				number.erase(number.begin() + i);
				number.erase(number.begin() + i);

				number.insert(number.begin() + i, tmp);

				operators.erase(operators.begin() + i);

				i--;
			}
		}

		maximum = number[0];

		for (int i = 1; i < number.size(); i++)
		{
			maximum *= number[i];
		}

		stringstream maxSs;
		maxSs << maximum;

		for (int i = 0; i < operators2.size(); i++)
		{
			if (operators2[i] == '*')
			{
				int tmp = number2[i] * number2[i + 1];
				number2.erase(number2.begin() + i);
				number2.erase(number2.begin() + i);

				number2.insert(number2.begin() + i, tmp);

				operators2.erase(operators2.begin() + i);

				i--;
			}
		}

		for (int i = 0; i < number2.size(); i++)
		{
			minimum += number2[i];
		}

		stringstream minSs;
		minSs << minimum;

		ans[n] = "The maximum and minimum are " + maxSs.str() + " and " + minSs.str() + ".";
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}

	//system("pause");
}