
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

const int sz = 1e5 + 2;
int PAR[sz];
int RANK[sz];

// this function will be same as path compression
int findParent(int a)
{
	if (PAR[a] < 0)
		return a;

	int X = findParent(PAR[a]);
	PAR[a] = X;
	return X;
}
// this will make parent the set whose rant will be heigher
void Union(int  a , int b)
{
	int par_a = findParent(a);
	int par_b = findParent(b);

	if (par_a == par_b) return;

	if (RANK[par_a] > RANK[par_b]) // make first_set as parent if it's rank is large
	{
		// here we want to take note of element with having highest magnitude
		PAR[par_a] = min(PAR[par_a], PAR[par_b]); // store highest page to a
		PAR[par_b] = par_a;  // assign parent of set B to a
		RANK[par_a] += RANK[par_b]; // inportant to update the rank here
	}
	else { // make second set as parent

		PAR[par_b] = min(PAR[par_a], PAR[par_b]); // store highest page to a
		PAR[par_a] = par_b;  // assign parent of set B to a
		RANK[par_b] += RANK[par_a]; // inportant to update the rank here
	}
}

void solveTestCases()
{
	int  n , m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		PAR[i] = -i;  // -Ve =>means themself are parent and magnitude (i) is highest element here
		RANK[i] = 1; //initially every one has only one element
	}

	while (m--)
	{
		int u , v;
		cin >> u >> v;

		Union(u, v); // unified beacuse both these owls are friends
	}

	int q;
	cin >> q;

	while (q--)
	{
		int u , v;
		cin >> u >> v;

		int parU = findParent(u); // it will not take much time beause of path compression
		int parV = findParent(v);

		if (PAR[parU] == PAR[parV])  // if both have same highest strength
		{
			cout << "TIE" << '\n';
		} else
		{
			if (PAR[parU] < PAR[parV])  // the magnitude was put in -ve
				cout << u << '\n';
			else
				cout << v << '\n';
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

	// LETSGO
	solveTestCases ();


	return 0;
}



