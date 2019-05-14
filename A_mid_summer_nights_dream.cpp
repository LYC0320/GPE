#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{

		vector<int> data(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> data[i];
		}

		sort(data.begin(), data.end());

		int mid = (n % 2 == 0) ? n / 2 - 1 : n / 2;
		int count = 0;

		int C;
		if ((n % 2 == 0))
		{
			C = (data[mid + 1] - data[mid] + 1);
		}
		else
		{
			C = 1;
		}

		if(n%2 == 0)
		{
			if((data[mid] + data[mid + 1])%2 == 0)
			{
				for(int i = 0; i < n; i++)
				{
					if(data[mid] == data[i] || data[mid + 1] == data[i])
						count++;
				}
			}
			else
			{
				
				for(int j = 0; j < C; j++)
				{
					int tmp = 0;
					int myMin = 10000000;
					for(int i = 0; i < n; i++)
					{
						myMin = min(myMin, abs(data[i] - (data[mid] + j)));
					}

					for(int i = 0; i < n; i++)
					{
						if(abs(data[i] - (data[mid] + j)) == myMin)
							tmp++;
					}

					count = max(count, tmp);
				}	
			}
		}
		else
		{
			for(int i = 0; i < n; i++)
			{
				if(data[mid] == data[i])
					count++;
			}
		}

		cout << data[mid] << " " << count << " " << C << endl;
	}
}