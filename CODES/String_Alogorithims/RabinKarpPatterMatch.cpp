
#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define gcd   __gcd
#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)

#define all(el) el.begin(),el.end()
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


const int MOD = 1e9 + 7;
int dp[1000001]; // for storing the prefix sum
int power[1000001]; // for using it as a Modular division by p^L so we will pre calc. the pow (p^l , MOD-2)


int getHash(string str)
{
	int Hashvalue = 0;
	const int P = 31; // we are takin the bucket size to be only 26

	int PtoPower = 1;

	for (char c : str)
	{
		Hashvalue =  ( Hashvalue + ((c - 'a' + 1) * PtoPower) % MOD ) % MOD;
		PtoPower = (PtoPower * P) % MOD;
	}

	return Hashvalue;
}


int getSubstringHash(int L , int R)
{
	int result = dp[R];

	if (L > 0) result = (result -  dp[L - 1] + MOD) % MOD;

	// No need ofFerments Littel Theorme => (1/a)%M = a ^ (M-2)

	return result;
}


void INIT(string &str)
{
	int P = 31;
	int PtoPower = 1;

	power[0] = 1;
	dp[0] = (str[0] - 'a' + 1);

	for (int i = 1; i < str.size(); i++)
	{
		int ch = str[i] - 'a' + 1;

		PtoPower = (PtoPower * P) % MOD;

		dp[i] = (dp[i - 1] + (ch * PtoPower) % MOD) % MOD;

		power[i] = PtoPower;
	}
}


void solveTestCases()
{
	int n;

	string needle;
	cin >> needle;

	string pattern;
	cin >> pattern;

	INIT(pattern);

	int needleHash = getHash(needle);

	for (int i = 0 , j = n - 1 ; j < pattern.size(); i++, j++)
	{
		int subHash = getSubstringHash(i, j);

		int NewneedleHash = (needleHash * power[i]) % MOD;

		if (subHash == NewneedleHash)
		{
			cout << i << endl;
		}
	}
	cout << endl;


	return;
}

int32_t main() {
	BOOM
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// LETSGO
	solveTestCases ();


	return 0;
}



