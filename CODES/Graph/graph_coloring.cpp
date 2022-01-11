// INPUT
/*
5 7
0 1
1 3
2 3
0 2
2 4
1 4
0 4
*/
// Output
/*
3
0 1 1 0 2
*/


#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define lld   long double
#define gcd   __gcd
#define pb    push_back
#define pf    push_front
#define em    emplace        //use in place of insert(x) or insert(position,x)
#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)

void solveTestCases()
{

	int v, e;
	cin >> v >> e;
	vector<vector<int> > g(v);
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int res[v]; // shows which color is used to color current node
	bool available[v]; // which color is available for current node
	res[0] = 0; // the first node is colored with 0th color

	for (int i = 1; i < v; i++) res[i] = -1; // -1 => not colored
	for (int i = 0; i < v; i++) available[i] = false; // all available color are marked false

	int cn = 0; // the no of color used (chromatic number)
	for (int i = 1; i < v; i++) {

		for (auto x : g[i]) {  // true means we can't used these color
			if (res[x] != -1) {
				available[res[x]] = true;
			}
		}

		int cr; // the first Non Used color
		for (cr = 0; cr < v; cr++) {
			if (available[cr] == false) {
				break;
			}
		}

		res[i] = cr; // fill that first non used color to this node
		cn = max(cn, cr + 1);  // to count what is the overall no of colors used
		// (+1 as 0 based indexing was used)


// just reversing what we did earlier , bcz we will check it again at the start
		for (auto x : g[i]) {
			if (res[x] != -1) {
				available[res[x]] = false;
			}
		}
	}

	cout << cn << endl;
	for (int i = 0; i < v; i++) cout << res[i] << " ";

	return;
}

int32_t main() {
	BOOM
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// LETSGO
	solveTestCases ();

	return 0;
}





