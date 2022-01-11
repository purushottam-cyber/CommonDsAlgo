
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

std::vector<int>G[101];
bool vis[101];
int in[101] , low[101];
int timer = 0;

void findBridges(int node , int parent)
{
	vis[node] = true;
	in[node] = low[node] = timer;
	++timer;

	for (auto child : G[node])
	{
		if (child == parent)
			continue;

		if (vis[child]) // if already visited and it is not parent then sure backedge
		{
			// its a backedge with ancestor therefor we will have to update the low time here
			low[node] = min(low[node], in[child]);
		} else
		{
			// if it is not already visited then it must be a forward edge

			findBridges(child, node);

			// backtrackibg steps

			if (low[child] > in[node]) // which means child didn't have any other edge then this one
				cout << "THIS EDGE IS A BRIDGE\n" << node << "->" << child << endl;

			// if its childeren can have a smaller low time the it also must
			low[node] = min(low[node], low[child]);

		}
	}
}


void solveTestCases()
{
	int n , m;
	cin >> n >> m;

	while (m--)
	{
		int u , v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}

	findBridges(1, -1);

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



