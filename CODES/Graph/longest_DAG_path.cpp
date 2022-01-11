// INPUT
/*
6 7
1
0 1 5
1 5 5
5 3 2
3 2 20
4 2 10
5 2 50
1 4 2
*/
// OUTPUT
/*
-100005 0 55 7 2 5
*/


#include <bits/stdc++.h>
using namespace std;

#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)

void solveTestCases()
{
	int v , e;
	cin >> v >> e;

	vector<pair<int, int>>edges[v];
	int source;
	cin >> source;

	vector<int>in(v, 0);

	for (int i = 0; i < e; i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
		in[v]++;
	}

	vector<int>top;

	// The topological sort

	queue<int>q;

	for (int i = 0; i < v; i++)
		if (in[i] == 0)q.push(i);

	while (!q.empty())
	{
		auto par = q.front();
		q.pop();
		top.push_back(par);

		for (auto ch : edges[par])
		{
			in[ch.first]--;
			if (in[ch.first] == 0)
				q.push(ch.first);
		}
	}

	// Now we will visit the nodes in the same order as topological sort

	const int ngInf = -100005;
	vector<int>dis(v, ngInf);

	dis[source] = 0;

	for (auto it : top)
	{
		if (dis[it] == ngInf) continue;

		for (auto ch : edges[it])
		{
			int v = ch.first;
			int w = ch.second;

			if (w + dis[it] > dis[v])
				dis[v] = w + dis[it];
		}
	}

	for (auto it : dis)
		cout << it << " ";

	return;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// LETSGO
	solveTestCases ();

	return 0;
}
