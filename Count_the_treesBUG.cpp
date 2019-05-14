#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}

		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 4;

		for (int i = 3; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (i - j - 1 == j)
				{
					dp[i] += 2 * i * dp[i - j - 1] * dp[j];
				}
				else
				{
					dp[i] += i * dp[i - j - 1] * dp[j];
				}

				
			}
		}

		cout << dp[n] << endl;

	}

}