#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int dataNum;
	cin >> dataNum;

	for(int i = 0; i < dataNum; i++)
	{
		int m, n;
		cin >> m;
		cin >> n;

		vector<vector<int> > data(m, vector<int>(n, 0));
		vector<vector<int> > dp(m, vector<int>(n, 0));

		for(int x = 0; x < m; x++)
		{
			for(int y = 0; y < n; y++)
			{
				int tmp;
				cin >> tmp;
				data[x][y] = tmp;
			}
		}

		for(int x = 0; x < m; x++)
		{
			for(int y = 0; y < n; y++)
			{
				if(x == 0 && y == 0)
					dp[x][y] = data[x][y];
				else if(x == 0)
				{
					dp[x][y] = dp[x][y - 1] + data[x][y];
				}
				else if(y == 0)
				{
					dp[x][y] = dp[x - 1][y] + data[x][y];
				}
				else
				{
					dp[x][y] = min(dp[x - 1][y], dp[x][y - 1]) + data[x][y];
				}
			}
		}

		cout << dp[m - 1][n - 1] << endl;
	}
}