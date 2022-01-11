
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

pii src, dst;
const int N = 8;

int dis[N][N];
bool vis[N][N];

int dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool is_valid(int x , int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N) return false;

	if (vis[x][y]) return false;

	return true;
}

int BFS()
{
	queue<pair<int, int>>q;
	q.push(src);
	int par_x = src.first , par_y = src.second;

	vis[par_x][par_y] = true;
	dis[par_x][par_y] = 0;

	while (!q.empty())
	{
		par_x = q.front().first;
		par_y = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int child_x = par_x + dx[i];
			int child_y = par_y + dy[i];

			if (is_valid(child_x, child_y))
			{
				vis[child_x][child_y] = true;
				dis[child_x][child_y] = dis[par_x][par_y] + 1;
				q.push({child_x, child_y});
				if (q.back() == dst)
				{
					return dis[child_x][child_y];
				}
			}

		}
	}
	return -1;
}

void solveTestCases()
{
	char s1 , s2 , d1 , d2;

	cin >> s1 >> s2 >> d1 >> d2;

	src = {s1 - 'a', s2 - '1'};
	dst = {d1 - 'a', d2 - '1'};


	fr(i, 0, N)
	fr(j, 0, N)
	vis[i][j] = false , dis[i][j] = 0;


	cout << BFS() << endl;

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



