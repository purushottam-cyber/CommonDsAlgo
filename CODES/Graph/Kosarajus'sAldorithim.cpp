
#include <bits/stdc++.h>
using namespace std;

/*
	INPUT :-
7 8
1 2
2 3
3 1
4 3
7 4
7 5
5 6
6 7

	Outut :-
DFS1 called frome node 5and printing nodes of current SCC
6 7 5
DFS1 called frome node 4and printing nodes of current SCC
4
DFS1 called frome node 1and printing nodes of current SCC
2 3 1

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


const int sz = 100005;
std::vector<int> G[sz] , TG[sz];  // the graph and the transpose graph
std::vector<int>order;            // the order in which will store nodes according to their outTime
std::vector<int> SCC; 			// strongly connected componenets
bool vis[sz];


// we dont really need to assign the in time and out time of the node because we the order in which they get came out
// is all we need here , all this is taken care with our inbuilt stack , so we just have to insert it in order vector
// at the time of backtracking
void DFS(int node)
{
	vis[node] = true;

	for (auto child : G[node])
		if (vis[child] == false)
			DFS(child);

	order.push_back(node);
}

void DFS1(int node)
{
	vis[node] = true;

	for (auto child : TG[node]) // visiting nodes of a transppose graph
		if (vis[child] == false)
			DFS1(child);

	SCC.pb(node);
}



void solveTestCases()
{
	int m , n;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) vis[i] = false, G[i].clear() , TG[i].clear();

	order.clear();

	while (m--)
	{
		int a , b;
		cin >> a >> b;
		// makin the graph and transpose graph
		G[a].pb(b);
		TG[b].pb(a);
	}

	for (int i = 1; i <= n; i++) // setting in time and out time of nodes
		if (vis[i] == false)
			DFS(i);

	for (int i = 1; i <= n; i++) // beacuse we gave to DFS the nodes again
		vis[i] = false;

	for (int i = 1; i <= n; i++)
	{
		// it is actually visiting condensed nodes with reverse order of outtime beacuse as we have studied
		// the node having highest out time will have 0 outdegree in transpose graph
		if (vis[order[n - i]] == false)
		{
			SCC.clear(); // make this condensed node clear

			DFS1(order[n - i]);

			cout << "DFS1 called frome node " << order[n - i] << "and printing nodes of current SCC \n";

			for (auto it : SCC)
				cout << it << " ";

			cout << endl;
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



