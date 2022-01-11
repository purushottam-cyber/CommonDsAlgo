
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

const int sz = 1e5 + 1;
std::vector<int> G[sz];
bool vis[sz];

void BFS(int source , std::vector<int> &dis)
{
	queue<int>qq;

	qq.push(source);
	vis[source] = true;

	while (qq.size() > 0)
	{
		int par = qq.front();
		qq.pop();

		for (auto child : G[par])
		{
			if (vis[child] == false)
			{
				dis[child] = dis[par] + 1;
				qq.push(child);
				vis[child] = true;
			}
		}
	}
}

void solveTestCases()
{
	memset(vis, 0, sz);

	for (int i = 0; i < sz; i++)
		G[i].clear();

	int n;
	cin >> n;
	int m;
	cin >> m;

	fr(i, 0, m)
	{
		int a , b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	std::vector<int>dis(n + 1, 0);

	BFS(1, dis);

	cout << dis[n] << endl;

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



