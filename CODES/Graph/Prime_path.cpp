
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

/*
Q. Given two 4 digit prime nubers a and b convert a into b in minimum number of steps where in each step
   you can choose only 1 digit and change it in such a way that it is also a prime number;

*/

const int sz = 100005;

vector<int> G[sz];
int dis[sz];
bool vis[sz];


bool isprime(int x)
{
	for (int i = 2 ; i * i <= x ; i++)
		if (x % i == 0) return false;

	return true;
}

// checking if only one digit is different or not
bool validNode(int a , int b)
{
	int count = 0;

	while (a)
	{
		if (a % 10 != b % 10)
			count++;
		a /= 10;
		b /= 10;
	}

	return count == 1;
}

// building graph as according to requirement
void buildGraph()
{
	std::vector<int>prime;

	for (int i = 1000; i <= 9999; i++)
		if (isprime(i))
			prime.pb(i);

	for (int i = 0; i < prime.size(); i++)
	{
		for (int j = i + 1; j < prime.size(); j++)
		{
			int a = prime[i] , b = prime[j];

			if (validNode(a, b))
			{
				G[a].pb(b);
				G[b].pb(a);
			}
		}
	}
}

// calculating distance of each rode from node a

void BFS(int start)
{
	dis[start] = 0;
	vis[start] = true;

	queue<int>dq;
	dq.push(start);

	while (!dq.empty())
	{
		int parent = dq.front();
		dq.pop();

		for (auto child : G[parent])
		{
			if (vis[child] == false)
			{
				dis[child] = dis[parent] + 1;
				vis[child] = true;
				dq.push(child);
			}
		}
	}
}

void solveTestCases()
{
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < sz; i++)
		G[i].clear();

	int a, b;
	cin >> a >> b;

	buildGraph();
	BFS(a);

	dis[b] != -1 ? cout << dis[b] << endl : cout << "Impossible" << endl;

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



