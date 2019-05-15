#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

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

string reverseString(string s)
{
	string tmp = "";

	for (int i = s.size() - 1; i >= 0; i--)
	{
		tmp += s[i];
	}

	return tmp;
}
									// tmp call by value (不同步搜索)
void traceBack(vector<vector<int> > &dp, int rowIndex, int colIndex, string tmp, string &s1, string &s2, vector<string> &ans)
{
	if (rowIndex == 0 || colIndex == 0)
	{	
		ans.push_back(reverseString(tmp));
		return;
	}

	if (s1[rowIndex - 1] == s2[colIndex - 1])
	{
		
		if (dp[rowIndex][colIndex] == dp[rowIndex - 1][colIndex])
			traceBack(dp, rowIndex - 1, colIndex, tmp, s1, s2, ans);

		if (dp[rowIndex][colIndex] == dp[rowIndex][colIndex - 1])
			traceBack(dp, rowIndex, colIndex - 1, tmp, s1, s2, ans);


		tmp += s1[rowIndex - 1];
		traceBack(dp, rowIndex - 1, colIndex - 1, tmp, s1, s2, ans);
	}
	else if(dp[rowIndex - 1][colIndex] > dp[rowIndex][colIndex - 1])
		traceBack(dp, rowIndex - 1, colIndex, tmp, s1, s2, ans);
	else if(dp[rowIndex - 1][colIndex] < dp[rowIndex][colIndex - 1])
		traceBack(dp, rowIndex, colIndex - 1, tmp, s1, s2, ans);
	else
	{
		traceBack(dp, rowIndex - 1, colIndex, tmp, s1, s2, ans);
		traceBack(dp, rowIndex, colIndex - 1, tmp, s1, s2, ans);
	}
}

void sortAns(vector<string> &ans, int index, int length)
{
	for (int i = index; i < ans.size(); i++)
	{
		for (int j = i + 1; j < ans.size(); j++)
		{
			for (int l = 0; l < length; l++)
			{
				if (ans[i][l] > ans[j][l])
				{
					ans[i].swap(ans[j]);
					break;
				}
				else if (ans[i][l] < ans[j][l])
					break;
			}
		}
	}
}

int main()
{
	int quesNum;
	cin >> quesNum;
	vector<string> ans;

	int index = 0;

	for(int i = 0; i < quesNum; i++)
	{
		string s1, s2;
		cin >> s1;
		cin >> s2;

		int s1Len = s1.size(), s2Len = s2.size();

		vector<vector<int> > dp(s1Len + 1, vector<int>(s2Len + 1, 0));

		for(int row = 1; row <= s1Len; row++)
		{
			for(int col = 1; col <= s2Len; col++)
			{
				if(s1[row - 1] == s2[col - 1])
					dp[row][col] = dp[row - 1][col - 1] + 1;
				else
					dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]); 
			}
		}

		string tmp = "";
		int rowIndex = s1Len, colIndex = s2Len;

		traceBack(dp, rowIndex, colIndex, tmp, s1, s2, ans);

		sortAns(ans, index, dp[s1Len][s2Len]);

		stringstream ss;
		ss << ans.size() - index;

		ans.insert(ans.begin() + index, ss.str());
		ans.push_back(" ");

		index = ans.size();
	}

	for (int i = 0; i < ans.size() - 1; i++)
	{
		if (i == ans.size() - 2)
		{
			cout << ans[i];
			break;
		}

		if (ans[i] != " ")
			cout << ans[i] << endl;
		else
			cout << endl;
	}

	//while (1);
}
