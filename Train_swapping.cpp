#include <iostream>
#include <vector>
#include <utility>

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

		for (int l = 0; l < arrNum; l++)
		{
			for (int m = l + 1; m < arrNum; m++)
			{
				if (data[l] > data[m])
				{
					swap(data[l], data[m]);
					ans++;
				}
			}
		}

		cout << "Optimal train swapping takes " << ans << " swaps." << endl;
	}
}