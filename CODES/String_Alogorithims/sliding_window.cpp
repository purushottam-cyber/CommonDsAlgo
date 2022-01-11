
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

void printans(std::vector<int>&a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n - 1];
	return;
}



void solveTestCases()
{
	string str , match;

	cin.ignore();

	getline(cin, str);
	getline(cin, match);

	int strSize = str.size();
	int matchSize = match.size();


	int leftPointer  , rightPointer = 0 ;

	for (leftPointer = 0 ; leftPointer < strSize; leftPointer++)
	{
		if (str[leftPointer] == match[0])
		{
			int i = 0;
			rightPointer = leftPointer;

			while (str[rightPointer] == match[i] && i < matchSize)
			{
				++i, ++rightPointer;
			}

			if (i == matchSize)
			{
				cout << leftPointer << " - " << rightPointer - 1 << endl;
			}

			leftPointer = rightPointer - 1;
		}
	}

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



