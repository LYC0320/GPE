#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<int> &nums, vector<int> &dp, vector<int> s, int index, int maxLen, int lastNum, vector<vector<int> > &ans)
{
	if(index < 0)
	{
		if(maxLen == 1)
		{
			ans.push_back(s);
			return;
		}
		else
			return;
	}

	DFS(nums, dp, s, index - 1, maxLen, lastNum, ans);

	if(dp[index] == maxLen - 1 && lastNum > nums[index])
	{
		s.push_back(nums[index]);
		DFS(nums, dp, s, index - 1, maxLen - 1, nums[index], ans);
	}
}

int main()
{
	int dataNum;
	cin >> dataNum;

	for(int k = 0; k < dataNum; k++)
	{
		int arrayNum;
		cin >> arrayNum;

		vector<int> nums(arrayNum, 0);
		vector<int> dp(arrayNum, 1);

		for(int l = 0; l < arrayNum; l++)
		{
			cin >>nums[l];
		}

		int maxLen = 1;

		for(int i = 1; i < arrayNum; i++)
		{
			for(int j = i - 1; j >= 0; j--)
			{
				if(nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			maxLen  = max(maxLen , dp[i]);
		}

		vector<vector<int> > ans;

		for(int i = arrayNum - 1; i >= 0; i--)
		{
			vector<int> s;
			
			if(dp[i] == maxLen)
			{
				s.push_back(nums[i]);
				DFS(nums, dp, s, i - 1, maxLen, nums[i], ans);
			}
		}

		for(int i = 0; i < ans.size(); i++)
		{
			sort(ans[i].begin(), ans[i].end());
		}

		sort(ans.begin(), ans.end());

		cout << ans.size() << endl;

		for(int i = ans.size() - 1; i >= 0; i--)
		{
			for(int j = 0; j < ans[i].size(); j++)
			{
				if(j == ans[i].size() - 1)
					cout << ans[i][j] << endl;
				else
					cout << ans[i][j] << " ";
			}
		}	
		
	}
}