#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
#include <map>
#include <stdlib.h> // abs

using namespace std;

int myStoi(string s)
{	
	int result = 0;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == '-')
			result = -result;
		else
			result += (s[i] - 48) * pow(10, s.size() - 1 - i);
	}

	return result;
}

int main()
{
	string input;
	while(cin >> input)
	{
		if(input == " ")
			continue;

		int bookNum = myStoi(input);
		map<int, int> m;
		vector<int> prices(bookNum, 0);

		for(int i = 0; i < bookNum; i++)
		{
			cin >> prices[i];
			if(m.count(prices[i]))
				m[prices[i]]++;
			else
				m[prices[i]] = 1;
		}

		int goal;
		cin >> goal;
		int diff = 1000002;
		int ans[2];

		for(int i = 0; i < prices.size(); i++)
		{
			int newGoal = goal - prices[i];

			if(newGoal < 0)
				continue;

			int newDiff = abs(newGoal - prices[i]);
			if(newDiff < diff && m.count(newGoal))
			{
				if(prices[i] == newGoal && m[prices[i]] == 1)
					continue;

				if(prices[i] <= newGoal)
				{
					ans[0] = prices[i];
					ans[1] = newGoal;
				}
				else
				{
						ans[0] = newGoal;
						ans[1] = prices[i];
				}
				diff = newDiff;
			}	
		}
		stringstream ss, ss2;
		ss << ans[0];
		ss2 << ans[1];

		cout << "Peter should buy books whose prices are " + ss.str() + " and " + ss2.str() + "." << endl;
		cout << endl;
	}
}
