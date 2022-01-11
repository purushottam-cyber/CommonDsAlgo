
/*
INPUT :-
8 12
1 2
2 3
3 1
2 8
3 4
8 4
4 8
7 8
5 4
5 7
7 6
6 5

OUTPUT:-

SCC :- 1
8 4
SCC :- 2
3 2 1
SCC :- 3
6 7 5

*/

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

const int sz = 1e6 + 1;
std::vector<int> G[sz];
bool vis[sz];
bool onstack[sz];
int low[sz] , in[sz];
int Timer = 1 , SCC = 0;
stack<int>st; // stack will hold the currently active nodes of a condesed NODE


void DFS(int node)
{
	vis[node] = true;
	in[node] = low[node] = Timer; // this is not new had already did it in bridges and attriculation points
	Timer++;
	st.push(node);  // this stack will contain only active list
	onstack[node] = true;  // an array to access stack element quickly


	for (auto child : G[node])
	{
		// here all things are same but we only can minimize the low time if and only from a active node
		if (vis[child] == true && onstack[child] == true)
		{
			low[node] = min(low[node], in[child]);
		} else if (vis[child] == false)
		{
			DFS(child);

			if (onstack[child] == true) // similar here minimize if visited node is active
				low[node] = min(low[node], low[child]);
		}
	}

	if (in[node] == low[node]) // the starting point of a strongly connected component
	{
		SCC++; // increasing the count of strongly connected component
		cout << "SCC :- " << SCC << endl;

		int u;

		while (1) // print all elements which are in this stack (actually all nodes od current SCC)
		{
			u = st.top();
			st.pop();
			onstack[u] = false;

			cout << u << " ";
			if (u == node) break; // this is important we can only pop it up to all elements of curren condensed node only
		}

		cout << endl;
	}
}

void solveTestCases()
{
	int m , n;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) vis[i] = onstack[i] = false , G[i].clear();

	while (m--)
	{
		int u , v;
		cin >> u >> v;
		G[u].pb(v);
	}

	for (int i = 1; i <= n; i++)
		if (vis[i] == false)
			DFS(i);


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



