#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	return (a + b) > (b + a);
}

int main()
{
	int dataNum;
	while(cin >> dataNum)
	{
		if(!dataNum)
				break;

		vector<string> data;
		string input;

		for(int i = 0; i < dataNum; i++)
		{
			cin >> input;
			data.push_back(input);
		}

		sort(data.begin(), data.end(), cmp);

		for(int i = 0; i < dataNum; i++)
			cout << data[i];
		cout << endl;
	}
}
