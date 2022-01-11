
#include <bits/stdc++.h>
using namespace std;
/*
** INPUT:-
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

**OUTPUT:-
19

*/

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

const int sz = 1e4 + 2;
const int Edsz = 1e5 + 2;

struct Edge
{
	int a ;
	int b ;
	int Weight;
};

bool comp(Edge &e1 , Edge &e2)
{
	return e1.Weight < e2.Weight;
}

Edge G[Edsz];
int PAR[sz];

int findPar(int a)
{
	if (PAR[a] < 0)
		return a;

	return PAR[a] = findPar(PAR[a]);
}

void merge(int a , int b)
{
	PAR[a] = b;
}

void solveTestCases()
{
	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 1; i <= n; i++)
		PAR[i] = -1; // ,akingg everyone their own parent

	for (int i = 0; i < m; ++i)
		cin >> G[i].a >> G[i].b >> G[i].Weight;

	sort(G, G + m, comp); // so that edge with min weight come first

	int cost = 0;

	for (int i = 0; i < m; i++)
	{
		int par1 = findPar(G[i].a);
		int par2 = findPar(G[i].b);
		if (par2 != par1)  // means different component
		{
			merge(par1, par2);

			cost += G[i].Weight;
		} // else they are connected no need to do anything
	}

	cout << cost;

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



