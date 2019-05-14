#include <iostream>
#include<stdio.h>

using namespace std;

long long bigMod(long long B, long long P, long long M)
{
	if (P == 0)
		return 1;
	else if (P == 1)
		return B % M;
	else
	{
		int result = bigMod(B, P / 2, M);
		if (P % 2)
			return  (result * bigMod(B, P / 2 + 1, M)) % M;
		else
			return (result * result) % M;

	}
}
int main()
{
	long long B, P, M;
	while (scanf("%lld %lld %lld", &B, &P, &M) != EOF)
	{

		if (B >= M)
			B %= M;
	
		long long result = bigMod(B, P, M);
		cout << result << endl;
	}

}