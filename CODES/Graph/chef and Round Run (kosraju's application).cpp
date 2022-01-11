
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

int a[sz];
std::vector<int> G[sz] , TG[sz];
std::vector<int>order , SCC;
bool vis[sz];

void DFS(int node)
{
	vis[node]  =  true;

	for (auto child : G[node])
		if (vis[child] == false)
			DFS(child);

	order.pb(node);
}

void DFS1(int node)
{
	vis[node] = true;

	for (auto child : TG[node])
		if (vis[child] == false)
			DFS1(child);

	SCC.pb(node);

}

void solveTestCases()
{
	int n;
	cin >> n;

	fr(i, 0, n) G[i].clear() , TG[i].clear(), vis[i] = false , cin >> a[i];

	order.clear();

	// make the graph
	for (int i = 0; i < n; i++)
	{
		int child  = (i + a[i] + 1) % n;
		G[i].pb(child);
		TG[child].pb(i);
	}

	// get the order

	for (int i = 0; i < n; i++)
	{
		if (vis[i] == false)
			DFS(i);
	}

	fr(i, 0, n) vis[i] = false;

	int ans = 0;

	reverse(all(order));

	for (int i = 0; i < n; i++)
	{
		if (vis[order[i]] == false)
		{
			SCC.clear();

			DFS1(order[i]);

			if (SCC.size() == 1 && SCC[0] != G[SCC[0]][0] ) continue; // checking if no self cycle then dont count

			ans += SCC.size();
		}
	}

	cout << ans << endl;

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



