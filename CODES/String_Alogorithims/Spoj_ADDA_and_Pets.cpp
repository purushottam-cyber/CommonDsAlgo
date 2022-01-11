
#include <bits/stdc++.h>
using namespace std;

#define int   long long

#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define setbit(x) __builtin_popcount(x)
#define all(el) el.begin(),el.end()
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pinf LLONG_MAX
#define ninf LLONG_MIN


std::vector<int> getPi(const string &s)
{
	std::vector<int>Pi(s.size(), 0);

	for (int i = 1; i < s.size(); i++)
	{
		int j = Pi[i - 1];

		while (j > 0 && s[i] != s[j])
			j = Pi[j - 1];

		j += (s[i] == s[j]);

		Pi[i] = j;
	}

	return Pi;
}


void solveTestCases()
{
	string s ;
	cin >> s;

	int k;
	cin >> k;

	int ans = s.size();

	std::vector<int> Pi = getPi(s);

	ans += (k - 1) * (s.size() - Pi.back());

	cout << ans << "\n";

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



