
#include <bits/stdc++.h>
using namespace std;
/*
** INPUT:-
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5
** OUTPUT:-
0 3 8 14 11 2 
*/

std::vector < pair<int, int> >G[1001]; // a->{b,edgeWeight}
int dist[1001];

void solveTestCases()
{
	int n , m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dist[i] = INT_MAX;

	for (int i = 0; i < m; ++i)
	{
		int a , b , w;
		cin >> a >> b >> w;
		G[a].push_back({b, w});
		G[b].push_back({a, w});
	}

	priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>>Q; // {weight,node}
	Q.push({0, 1});

	dist[1] = 0;

	while (!Q.empty())
	{
		int Par_Wt = Q.top().first; //Parent_weight
		int Par_Nod = Q.top().second; //Parent_Node
		Q.pop();

		for (auto [node , weight] : G[Par_Nod]) // all the neighbouring node just like BFS 
		{
			if (weight + Par_Wt < dist[node])
			{
				dist[node] = weight + Par_Wt;
				Q.push({weight + Par_Wt, node});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	return;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solveTestCases ();


	return 0;
}



