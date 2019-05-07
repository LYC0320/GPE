#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string input;
	while(getline(cin, input))
	{
		string s, t, token = "";
		for(int i = 0; i < input.size(); i++)
		{
			if(input[i] == ' ')
			{
				s = token;
				token = "";
			}
			else
			{
				token += input[i];
			}
		}

		t = token;
		
		int i = 0, j = 0;

		while(i < s.size() && j < t.size())
		{
			if(s[i] == t[j])
			{
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}

		if(i == s.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
