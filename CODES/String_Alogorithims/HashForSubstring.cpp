
#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define gcd   __gcd
#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define setbit(x) __builtin_popcount(x)
#define all(el) el.begin(),el.end()
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pinf LLONG_MAX
#define ninf LLONG_MIN


const int MOD = 1e9 + 7;
int dp[200001]; // for storing the prefix sum
int inv[200001]; // for using it as a Modular division by p^L so we will pre calc. the pow (p^l , MOD-2)

int power(int x, int y)
{
	int temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp) % MOD;
	else
	{
		if (y > 0)
			return (((x * temp) % MOD) * temp) % MOD;
		else
			return (temp * temp) / x;
	}
}

int getSubstringHash(int L , int R)
{
	int result = dp[R];

	if (L > 0) result = (result -  dp[L - 1] + MOD) % MOD;

	result = (result * inv[L]) % MOD; // The Ferments Littel Theorme => (1/a)%M = a ^ (M-2)

	return result;
}

void INIT(string &str)
{
	int P = 31;
	int PtoPower = 1;

	inv[0] = 1;
	dp[0] = (str[0] - 'a' + 1);

	for (int i = 1; i < str.size(); i++)
	{
		int ch = str[i] - 'a' + 1;

		PtoPower = (PtoPower * P) % MOD;

		dp[i] = (dp[i - 1] + ch * PtoPower) % MOD;

		inv[i] = power(PtoPower, MOD - 2);
	}
}


void solveTestCases()
{
	string str;
	cin >> str;

	INIT(str);

	int L , R;
	cin >> L >> R;

	cout << getSubstringHash(L, R) << endl;
	return;
}

int32_t main() {
	BOOM
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	LETSGO
	solveTestCases ();


	return 0;
}



