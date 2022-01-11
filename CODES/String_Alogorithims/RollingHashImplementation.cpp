
#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define gcd   __gcd
#define pb    push_back
#define pf    push_front
#define em    emplace        //use in place of insert(x) or insert(position,x)
#define emb   emplace_back
#define pof   pop_front
#define pob   pop_back
#define ump   unordered_map
#define mpr    make_pair
#define fs    first
#define sc    second
#define deq   deque
#define stk   stack
#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define setbit(x) __builtin_popcount(x)
#define all(el) el.begin(),el.end()
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pinf LLONG_MAX
#define ninf LLONG_MIN

const int MOD = 1e9 + 7;

int getHash(string str)
{
	int Hashvalue = 0;
	const int P = 31; // we are takin the bucket size to be only 26

	int PtoPower = 1;

	for (char c : str)
	{
		Hashvalue =  ( Hashvalue + (c - 'a' + 1) * PtoPower ) % MOD;
		PtoPower = (PtoPower * P) % MOD;
	}

	return Hashvalue;
}

void solveTestCases()
{
	string str;
	cin >> str;

	cout << getHash(str) << endl;

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
