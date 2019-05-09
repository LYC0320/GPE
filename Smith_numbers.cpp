#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

void buildPrimes(vector<int> &primes, int k, set<int> &hash)
{
	primes.push_back(2);
	hash.insert(2);

	for(int i = 3; i < k; i++)
	{
		int l = primes.size();

		for(int j = 0; j < l; j++)
		{
			if(i % primes[j] == 0)
			{
				break;
			}

			if(j == l - 1)
			{
				primes.push_back(i);
				hash.insert(i);
			}
		}
	}
}

int sumDigit(string s)
{
	int result = 0;

	for(int i = 0; i < s.size(); i++)
	{
		result += (s[i] - 48);
	}

	return result;
}

int main()
{

	vector<int> primes;
	set<int> hash;
	buildPrimes(primes, 100000, hash);

	int dataNum;
	cin >> dataNum;
	
	for(int i = 0; i < dataNum; i++)
	{
		int n;
		cin >> n;
		n++;

		while(true)
		{
			int goal = 0, count = 0;

			stringstream ss;
			ss << n;

			goal += sumDigit(ss.str());

			int tmp = n;

			int pIndex = 0;


			while(tmp != 1 && pIndex < primes.size())
			{
				if(tmp % primes[pIndex] == 0)
				{
					ss.str("");
					ss << primes[pIndex];

					count += sumDigit(ss.str());

					tmp /= primes[pIndex];
				}
				else
					pIndex++;
			}

			if(tmp != 1)
			{
				if(tmp == n)
				{
					n++;
					continue;
				}

				ss.str("");
				ss << tmp;

				count += sumDigit(ss.str());
			}

			if(count == goal && !hash.count(n))
			{
				cout << n << endl;
				break;
			}

			n++;
		}
	}
}