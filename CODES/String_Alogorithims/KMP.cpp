
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
	int n = s.size();

	std::vector<int> pi(n, 0);

	for (int i = 1; i < n; i++)
	{
		int j = pi[i - 1];

		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];

		j += (s[i] == s[j]);

		pi[i] = j;
	}

	return pi;
}

void solveTestCases()
{
	string pattern;
	string text;

	cin >> pattern >> text;

	string serchString = pattern + "#" + text;

	std::vector<int> v = getPi(serchString );

	int ans = 0;

	for (auto it : v)
		ans += (it == pattern.size());

	cout << ans << endl;

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



