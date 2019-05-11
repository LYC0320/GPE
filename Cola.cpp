#include <iostream>

using namespace std;

int main()
{
	int bottleNum;
	
	while(cin >> bottleNum)
	{
		int emptyBottleNum, ans = 0;
		ans += bottleNum;
		emptyBottleNum = bottleNum;

		while(emptyBottleNum >= 3)
		{
			bottleNum = emptyBottleNum / 3;
			emptyBottleNum = emptyBottleNum % 3;

			ans += bottleNum;
			emptyBottleNum += bottleNum;
		}

		if(emptyBottleNum == 2)
			ans++;

		cout << ans << endl;
	}
}