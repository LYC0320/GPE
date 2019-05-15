#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int dataNum;
	cin >> dataNum;

	for(int i = 0; i < dataNum; i++)
	{
		int dayNum, partyNum;
		cin >> dayNum;
		cin >> partyNum;

		vector<int> hartals(partyNum, 0);

		for(int j = 0; j < partyNum; j++)
		{
			cin >> hartals[j];
		}

		vector<bool> days(dayNum, false);

		for(int j = 0; j < dayNum; j++)
		{
			for(int k = 0; k < partyNum; k++)
			{
				if((j + 1) % hartals[k] == 0)
					days[j] = true;
			}
		}

		int index = 5;
		while(index < dayNum)
		{
			days[index] = false;

			if(index + 1 < dayNum)
			{
				days[index + 1] = false;
			}

			index += 7;
		}

		int count = 0;
		for(int j = 0; j < dayNum; j++)
		{
			if(days[j])
				count++;
		}
		cout << count << endl;
	}
}