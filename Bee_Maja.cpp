#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>

using namespace std;

int myStoi(string s)
{
	int tmp = 0;

	for(int i = s.size() - 1; i >= 0; i--)
	{
		tmp += (s[i] - 48)*pow(10, s.size() - 1 - i);
	}

	return tmp;
}

int main()
{
	string s;

	vector<int> ans;

	while(getline(cin, s))
	{
		int circleNum = 1;
		int input = myStoi(s);

		input--;

		while(input > 0)
		{
			input -= 6*circleNum;
			circleNum++;
		}

		int startIndex[2] = {0 + (circleNum - 1)*1, 0};
		
		bool step1 = true, step2 = false, step3 = false, step4 = false, step5 = false, step6 = false;
		int myCount = 0;

		for(int i = input; input < 0; input++)
		{
			if(step1)
			{
				startIndex[1]--; 
				myCount++;

				if(myCount == circleNum - 1)
				{
					step1 = false;
					step2 = true;

					myCount = 0;
				}
			}
			else if(step2)
			{
				startIndex[0]--;
				myCount++;

				if(myCount == circleNum - 1)
				{
					step2 = false;
					step3 = true;

					myCount = 0;
				}
			}
			else if(step3)
			{
				startIndex[0]--;
				startIndex[1]++;
				myCount++;

				if(myCount == circleNum - 1)
				{
					step3 = false;
					step4 = true;

					myCount = 0;
				}
			}
			else if(step4)
			{
				startIndex[1]++;

				myCount++;

				if(myCount == circleNum - 1)
				{
					step4 = false;
					step5 = true;

					myCount = 0;
				}
			}
			else if(step5)
			{
				startIndex[0]++;
				myCount++;

				if(myCount == circleNum - 1)
				{
					step5 = false;
					step6 = true;

					myCount = 0;
				}
			}
			else if(step6)
			{
				startIndex[0]++;
				startIndex[1]--;

				if(myCount == circleNum - 1)
				{
					step6 = false;
				}
			}
		}
		ans.push_back(startIndex[0]);
		ans.push_back(startIndex[1]);
	}

	for(int i = 0; i < ans.size(); i += 2)
	{
		cout << ans[i] << " " << ans[i + 1] << endl;
	}
}
