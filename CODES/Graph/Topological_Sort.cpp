
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

std::vector<int> G[100];
int indegree[100];
bool vis[100];
std::vector<int> ans;

void KAHN(int n)
{
	queue<int>q;

	for (int i = 1; i <= n; i++) // The starring points of where indegree is = 0;
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		ans.push_back(curr);

		for (auto child : G[curr])
		{
			indegree[child]--; // decreasing the indegree because the parent node is already taken
			if (indegree[child] == 0)
				q.push(child);
		}
	}

	if (ans.size() != n) // that means we didn't get the chance to visit all nodes beacuse of some cycle
		cout << "CYLCE PRESENT , CAN'T SORT IT OUT \n";
	else
		for (auto nodes : ans)
			cout << nodes << ", ";
}

void solveTestCases()
{
	int n , m;
	cin >> n >> m;

	while (m--)
	{
		int u , v;
		cin >> u >> v;
		G[u].push_back(v); // it is a directed edge
		indegree[v]++;
	}

	KAHN(n); // total number of nodes
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



