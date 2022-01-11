
#include <bits/stdc++.h>
using namespace std;

/*
** INPUT:-
10
1 2
1 3
2 6
2 9
3 4
6 8
9 5
4 10
4 7

5 // queries
1 8
8 7
9 5
5 5
10 7
** OUTPUT:-
3
6
1
0
2
*/
// we dont need a visited array here because it is a tree
std::vector<int>G[1001];
const int MAX_PARENT = 10;  // beacuse 2^10 = 1024
int LCA[1001][MAX_PARENT + 1];
int level[1001];

void DFS(int node , int lev , int par) // for initializing the frist array
{
	level[node] = lev;
	LCA[node][0] = par;  // => 2^0 th parent

	for (auto child : G[node])
		if (child != par)  // no need of visited array it will do the work because it is a tree
			DFS(child, lev + 1, node);
}

void initializeParentArray(int n)
{
	DFS(1, 0, -1); // intializing all the 1st ancestor and then we will use dp to find other parents

	for (int i = 1; i <= MAX_PARENT; i++) // filling the LCA table
	{
		for (int j = 1; j <= n; j++)
		{
			if (LCA[j][i - 1] != -1)
			{
// Remember the concept where we learned 2th parent = 2^0 th parent of its 2^0 parent
				int par = LCA[j][i - 1];
				LCA[j][i] = LCA[par][i - 1];
			}
		}
	}
}

int least_common_ancestor(int a , int b)
{
	if (level[b] < level[a])swap(a, b);

	int d = level[b] - level[a];

	while (d) // binary lifting
	{
		int l = log2(d);
		b = LCA[b][l];
		d -= (1 << l);
	}

	if (a == b) return a;

// now both the a and b are at the same level and we still want to lift the as max as we can
	for (int i = MAX_PARENT; i >= 0; i--)
	{
		// (if parent exist) ans (we should be at a node below the LCA)
		if (LCA[a][i] != -1 && (LCA[a][i] != LCA[b][i]))
			a = LCA[a][i] , b = LCA[b][i];
	}


	return LCA[a][0];
}

int distaceBetweenA_B(int a , int b)
{
	int lcaAB = least_common_ancestor(a, b);

	int distance = level[a] + level[b] - 2 * level[lcaAB];

	return distance;
}

void solveTestCases()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) // n nodes => n-1 edges
	{
		int a , b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= MAX_PARENT; j++)
			LCA[i][j] = -1;


	initializeParentArray(n);

	int q;
	cin >> q;

	while (q--)
	{
		int a , b;
		cin >> a >> b;

		cout << distaceBetweenA_B(a, b) << endl;
	}

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



