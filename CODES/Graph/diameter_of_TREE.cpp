
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
const int mod = 1e9 + 7;

int nodex;
int pdis;

std::vector<int> gr[sz];
bool vis[sz];

void dfs(int node , int dis)
{
  vis[node] = 1;

  if (dis > pdis)
  {
    nodex = node;
    pdis = dis;
  }


  for (auto child : gr[node])
  {
    if (vis[child] == 0)
      dfs(child, dis + 1);
  }

}

void solveTestCases()
{
  memset(vis , 0 , sizeof(vis));



  int n , m;
  cin >> n ;
  m = n - 1;

  while (m--)
  {
    int  a , b;
    cin >> a >> b;
    gr[a].pb(b);
    gr[b].pb(a);
  }

  int far = 0 ;

  nodex = -1 , pdis = -1;

  dfs(1, far);

  fr(i, 0, n + 1)
  vis[i] = 0;

  far = 0 ;

  pdis = -1;

  dfs(nodex, far);

  cout << pdis << endl;



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



