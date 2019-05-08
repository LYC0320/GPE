#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int guardNum;

	cin >> guardNum;
	
	vector<string> ans;

	for(int i = 0; i < guardNum; i++)
	{
		vector<vector<int> > data(2, vector<int>(4, 0));

		for(int r = 0; r < 2; r++)
		{
			for(int j = 0; j < 4; j++)
			{
				cin >> data[r][j];
			}
		}

		pair<int, int> p1, p2;
		p1.first = max(data[0][0], data[1][0]);
		p1.second = max(data[0][1], data[1][1]);

		p2.first = min(data[0][2], data[1][2]);
		p2.second = min(data[0][3], data[1][3]);

		int strong, unsecure;
		int weak = (data[0][2] - data[0][0]) * (data[0][3] - data[0][1]) + (data[1][2] - data[1][0]) * (data[1][3] - data[1][1]);

		if(p2.first <= p1.first || p2.second <= p1.second)
		{
			strong = 0;
		}
		else
		{
			strong = (p2.first - p1.first) * (p2.second - p1.second);
			
		}
		weak -= 2 * strong;
		unsecure = 10000 - weak - strong;

		stringstream s1, s2, s3, s4;
		s1 << (i + 1);
		s2 << strong;
		s3 << weak;
		s4 << unsecure;

		ans.push_back("Night " + s1.str() + ":" + " " + s2.str() + " " + s3.str() + " " + s4.str());
	}

	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
