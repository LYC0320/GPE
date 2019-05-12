#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;

	cin >> T;

	for(int i = 0; i < T; i++)
	{
		int M, N, Q;
		cin >> M;
		cin >> N;
		cin >> Q;

		vector<vector<char> > grid(M, vector<char>(N, '0'));
		for(int m = 0; m < M; m++)
		{
			for(int n = 0; n < N; n++)
			{
				cin >> grid[m][n];
			}
		}

		cout << M << " " << N << " " << Q << endl;

		for(int q = 0; q < Q; q++)
		{
			int x, y, ans = 1;
			char goal;

			cin >> x;
			cin >> y;

			if(x < 0 || x >= M || y < 0 || y >= N)
			{
				cout << 0 << endl;
				continue;
			}

			goal = grid[x][y];

			int len = 2;
			int dirs[5] = {0, 1, 0, -1, 0};
			bool same = true;

			while(x && y && x != M - 1 && y != N - 1 && same)
			{
				int cornerX = --x, cornerY = --y;

				if(grid[x][y] != goal)
				{
					same = false;
					break;
				}

				for(int k = 0; k < 4; k++)
				{
					for(int l = 0; l < len; l++)
					{
						x += dirs[k];
						y += dirs[k + 1];

						if(x < 0 || x >= M || y < 0 || y >= N)
						{
							same = false;
							break;
						}

						if(grid[x][y] != goal)
						{
							same = false;
							break;
						}

					}
				}

				if(same)
				{
					x = cornerX;
					y = cornerY;
					ans += 2;
					len += 2;
				}
			}

			cout << ans << endl;
		}
	}

}