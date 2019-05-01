#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

int myStoi(string s)
{
	int result = 0;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == '-')
			result = -result;
		else
			result += (s[i] - 48)*pow(10, s.size() - 1 - i);
	}
	
	return result;
}

int main()
{
	string inputNum;
	getline(cin, inputNum);
	vector<string> ans;
	
	for(int i = 0; i < myStoi(inputNum); i++)
	{
		string input;
		getline(cin, input);
		
		vector<int> data;
		string token = "";
		int sum = 0;

		for(int j = 0; j < input.size(); j++)
		{
			int tmp;

			if(input[j] != ' ')
				token += input[j];
			else
			{
				tmp = myStoi(token);
				data.push_back(tmp);
				sum += tmp;
				token = "";
			}

			if(j == input.size() - 1)
			{
				tmp = myStoi(token);
				data.push_back(tmp);
				sum += tmp;
			}
		}

		if(sum % 2 == 1)
		{
			ans.push_back("NO");
			continue;
		}
		else
		{
			vector< vector<bool> > dp(data.size() + 1, vector<bool>(sum / 2 + 1, false));

			for(int k = 0; k < dp.size(); k++)
			{
				for(int l = 0; l < dp[0].size(); l++)
				{
					if(l == 0)
						dp[k][l] = true;
					else if(k == 0)
						;
					else if(l - data[k - 1] >= 0 && dp[k - 1][l - data[k - 1]])
						dp[k][l] = true;
					else if(dp[k - 1][l])
						dp[k][l] = true;
				}
			}

			if(dp[data.size()][sum/2])
				ans.push_back("YES");
			else
				ans.push_back("NO");
		}


	}

	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
