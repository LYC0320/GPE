#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void DFS(vector<int> &nums, vector<int> &s, map<int, vector<int>> &m, int index)
{
	

	if(m.find(index) == m.end())
	{
		s.pop_back();
		DFS(nums, s, m, s.back());
	}

	s.push_back(index);

	for(int i = 0; i < m[index].size(); i++)
	{
		DFS(nums, s, m, m[index][i]);
	}
}

int main()
{
	int arrayNum;
	while(cin >> arrayNum)
	{
		vector<int> nums(arrayNum, 0);
		vector<int> dp(arrayNum, 1);

		for(int i = 0; i < arrayNum; i++)
		{
			cin >> nums[i];
		}

		int maxLen = 1;
		map<int, vector<int>> m;

		for(int i = 1; i < arrayNum; i++)
		{
			for(int j = i - 1; j >= 0; j--)
			{
				if(nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
					m[i].push_back(j);
				}
			}
			maxLen  = max(maxLen , dp[i]);
		}

		vector<int> tmp;
		vector<int> s;

		for(int i = arrayNum - 1; i >= 0; i--)
		{
			
			if(dp[i] == maxLen)
			{
				DFS(nums, s, m, i);
				break;
			}
		}
	}
}