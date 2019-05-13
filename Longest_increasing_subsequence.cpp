#include <iostream>
#include <vector>

using namespace std;

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

		int ans = 1;

		for(int i = 1; i < arrayNum; i++)
		{
			for(int j = i - 1; j >= 0; j--)
			{
				if(nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}

		cout << ans << endl;
	}
}