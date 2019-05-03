#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int freshNum;
	while(cin >> freshNum)
	{
		if(!freshNum)
			break;

		vector<string> data_s;

		for(int i = 0; i < freshNum; i++)
		{
			vector<int> data(5, 0);

			for(int j = 0; j < 5; j++)
			{
				cin >> data[j];
			}

			sort(data.begin(), data.end());
			
			string tmp = "";

			for(int j = 0; j < 5; j++)
			{
				stringstream ss;
				ss << data[j];
				tmp += ss.str();
			}

			data_s.push_back(tmp);
		}
		
		int myMax = 1;
		int myMaxCount = 0;

		for(int i = 0; i < freshNum; i++)
		{
			int myCount = 1;
			
			for(int j = i + 1; j < freshNum; j++)
			{
				if(data_s[i] == data_s[j])
					myCount++;
			}
			
			if(myCount > myMax)
			{
				myMax = myCount;
				myMaxCount = 1;
			}
			else if(myCount == myMax)
				myMaxCount++;
		}

		cout << myMax*myMaxCount << endl;
	}
}
