#include <iostream>

using namespace std;

int main()
{
	int stepNum;
	while(cin >> stepNum)
	{
		if(!stepNum)
			break;

		int u = 1, d = 6, n = 2, s = 5, w = 3, e = 4;

		for(int i = 0; i < stepNum; i++)
		{
			string step;
			cin >> step;

			if(step == "north")
			{
				int tmp = u;
				u = s;
				s = d;
				d = n;
				n = tmp;

			}
			else if(step == "south")
			{
				int tmp = u;
				u = n;
				n = d;
				d = s;
				s = tmp;
			}
			else if(step == "east")
			{
				int tmp = u;
				u = w;
				w = d;
				d = e;
				e =tmp;
			}
			else
			{
				int tmp = u;
				u = e;
				e = d;
				d = w;
				w =tmp;
			}
		}

		cout << u << endl;
	}
}