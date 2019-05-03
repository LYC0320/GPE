#include <iostream>
#include <sstream> 
#include <math.h>

using namespace std;

long long int c = pow(10, 9) + 9;

long long int f(long long int n, long long int c)
{
	if(n == 1)
		return 3;

	long long int result = f(n / 2, c);

	if(n % 2 == 1)
		return (result * result * 3) % c;
	else
		return (result * result) % c;
}

int main()
{
	long long int n;
	
	while(cin >> n)
	{
		long long int ans = f(n, c) - 2;
		if(ans < 0)
			ans += c;

		cout << ans << endl;
	}
}