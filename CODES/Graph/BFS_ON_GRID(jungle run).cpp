
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
#define pii pair<int,int>

const int sz = 31;
char A[sz][sz];
bool vis[sz][sz];
int dis[sz][sz];
int N;
pii src , dst;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool isValid(int x , int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N) return false;

	if (vis[x][y] || A[x][y] == 'T') return false;

	return true;
}

int BFS()
{
	queue<pii>q;
	q.push(src);

	vis[src.first][src.second] = true;
	dis[src.first][src.second] = 0;

	while (!q.empty())
	{
		pii parent = q.front();
		q.pop();
		int x = parent.first;
		int y = parent.second;

		fr(i, 0, 4)
		{
			int childx = x + dx[i] ,  childy = y + dy[i];
			if (isValid(childx, childy))
			{
				vis[childx][childy] = true;
				dis[childx][childy] = dis[x][y] + 1;
				pii child = {childx, childy};
				q.push(child);

				if ( child == dst)
					return dis[childx][childy];
			}
		}
	}

	return 0;

}

void solveTestCases()
{
	cin >> N;


	fr(i, 0, N)
	fr(j, 0, N)
	{
		cin >> A[i][j];
		if (A[i][j] == 'S')
			src = {i, j};
		if (A[i][j] == 'E')
			dst = {i, j};
	}

	cout << BFS();

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



