#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	int dataNum;
	cin >> dataNum;

	for (int i = 0; i < dataNum; i++)
	{
		int arrNum;
		cin >> arrNum;

		vector<int> data(arrNum, 0);

		for (int j = 0; j < arrNum; j++)
		{
			cin >> data[j];
		}

		int ans = 0;
		sort(data.begin(), data.end());

		int vito = data[arrNum / 2];

		for (int j = 0; j < arrNum; j++)
		{
			ans += abs(vito - data[j]);
		}

		cout << ans << endl;
	}
}