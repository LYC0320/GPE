#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> data;
	while(cin >> n)
	{
		data.push_back(n);
		sort(data.begin(), data.end());
		int len = data.size();

		if(len % 2 == 0)
			cout << (data[len / 2 - 1] + data[len / 2]) / 2 << endl;
		else
			cout << data[len / 2] << endl;
	}
}
