#include <iostream>
#include <sstream>
#include <vector>
#include <string> // substr
#include <algorithm> // reverse

using namespace std;

void findNext(string &s, vector<int> &next)
{
	next[0] = 0;
	for(int i = 1; i < s.size(); i++)
	{
		int j = next[i - 1];
		if(s[i] == s[j])
			next[i] = j + 1;
		else
		{
			while(s[i] != s[j] && j > 0)
			{
				j = next[j - 1];
			}

			if(s[i] == s[j])
				next[i] = j + 1;
			else
				next[i] = j;
		}
	}
}

int KMP(string &s, string &rs)
{
	// TODO
	return 1;
}

int main()
{
	string s;
	while(getline(cin, s))
	{
		int l = s.size();

		if(l > 500)
		{
			// TODO
			sring reverseS = S;
			reverse(reverseS.begin(), reverseS.end());

			vector<int> next(l, 0);
			findNext(s, next);
			KMP(s, reverseS);

			for(int i = 0; i < l; i++)
			{
				cout << next[i] << endl;
			}
		}


		vector<vector<bool> > dp(l, vector<bool>(l, false));
		int maxLenE = 1;

		for(int offset = 0; offset < l; offset++)
		{
			for(int index = 0; index < l - offset; index++)
			{
				if(offset == 0)
					dp[index][index + offset] = true;
				else if(offset == 1)
				{
					if(s[index] == s[index + offset])
					{
						dp[index][index + offset] = true;

						if(index == l - offset - 1)
							maxLenE = max(maxLenE, offset + 1);
					}
				}
				else
				{
					if(s[index] == s[index + offset] && dp[index + 1][index + offset - 1])
					{
						dp[index][index + offset] = true;

						if(index == l - offset - 1)
							maxLenE = max(maxLenE, offset + 1);
					}
				}
			}
		}

		string subS = s.substr(0, l - maxLenE);
		reverse(subS.begin(), subS.end());
		s += subS;

		cout << s << endl;
		
	}
}