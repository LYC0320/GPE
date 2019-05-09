#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string input;
	int num = 1;

	while(cin >> input)
	{
		stringstream ss;
		ss << num;

		cout << "Case " + ss.str() + ":" << endl;

		num++;

		int queryNum;
		cin >> queryNum;

		for(int i = 0; i < queryNum; i++)
		{
			int start, end, tmp;
			cin >> start;
			cin >> end;
			tmp = max(start, end);
			start = min(start, end);
			end = tmp;

			int len = end - start + 1;
			if(len == 1)
			{
				cout << "Yes" << endl;
				continue;
			}

			string token = input.substr(start, len);

			for(int j = 1; j < len; j++)
			{
				if(token[j] != token[j - 1])
				{
					cout << "No" << endl;
					break;
				}

				if(j == len - 1)
				{
					cout << "Yes" << endl;
				}
			}
		}
	}
}