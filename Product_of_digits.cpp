#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int dataNum;
	cin >> dataNum;	

	for(int i = 0; i < dataNum; i++)
	{
		int input;
		cin >> input;
		vector<int> ans;

		while(true)
		{
			if(input % 8 == 0)
			{
				ans.push_back(8);
				input /= 8;
			}
			else if(input % 4 == 0)
			{
				ans.push_back(4);
				input /= 4;
			}
			else if(input % 6 == 0)
			{
				ans.push_back(6);
				input /= 6;
			}
			else if(input % 9 == 0)
			{
				ans.push_back(9);
				input /= 9;
			}
			else if(input % 2 == 0)
			{
				ans.push_back(2);
				input /= 2;
			}
			else if(input % 3 == 0)
			{
				ans.push_back(3);
				input /= 3;
			}
			else if(input % 5 == 0)
			{
				ans.push_back(5);
				input /= 5;
			}
			else if(input % 7 == 0)
			{
				ans.push_back(7);
				input /= 7;
			}
			else
				break;

		}

		if(input != 1)
			cout << -1 << endl;
		else
		{
			if(ans.empty())
			{
				cout << 1 <<endl;
				continue;
			}

			sort(ans.begin(), ans.end());
			for(int j = 0; j < ans.size(); j++)
			{
				cout << ans[j];
			}
			cout << endl;
		}
	}
}
