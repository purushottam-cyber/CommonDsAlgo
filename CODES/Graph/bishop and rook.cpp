

#include <bits/stdc++.h>
using namespace std;

#define int   long long
#define lld   long double
#define gcd   __gcd
#define pb    push_back
#define pf    push_front
#define em    emplace        //use in place of insert(x) or insert(position,x)
#define emb   emplace_back
#define pof   pop_front
#define pob   pop_back
#define ump   unordered_map
#define mpr   make_pair
#define FF    first
#define SS    second

#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define setbit(x) __builtin_popcount(x)
#define all(el) el.begin(),el.end()
#define sumALL(el) accumulate(all(el),0ll)
#define minALL(el) *min_element(all(el))
#define maxALL(el) *max_element(all(el))
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pinf LLONG_MAX
#define ninf LLONG_MIN

/* Debugger section*/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


/* Debugger section  XX */

bool mainDiag[20]; // row + col = constant
bool revDiag[20]; // row - col + N - 1 = constant
bool blockedCol[10];

int CHESS[8][8];

void solve(int row , string sofar)
{
	if (row == 8)
	{
		cout << sofar << endl;
		return;
	}


	for (char colC = 'a' ; colC <= 'h' ; colC++)
	{
		int col = colC - 'a';
		if (blockedCol[col] == false && mainDiag[row + col] == false && revDiag[row - col + 7] == false)
		{

			if ((row & 1) == 0)
			{
				CHESS[row][col] = true;
				mainDiag[row + col] = true;
				revDiag[row - col + 7] = true;

				solve(row + 1, sofar + to_string(8 - row) + "<->" + colC + " ");

				CHESS[row][col] = false;
				mainDiag[row + col] = false;
				revDiag[row - col + 7] = false;

			} else
			{
				CHESS[row][col] = true;
				blockedCol[col] = true;

				solve(row + 1, sofar + to_string(8 - row) + "<->" + colC + " ");

				CHESS[row][col] = false;
				blockedCol[col] = false;
			}

		}
	}
}


void solveTestCases()
{
	memset(mainDiag, false, sizeof(mainDiag));
	memset(revDiag, false, sizeof(revDiag));
	memset(blockedCol, false, sizeof(blockedCol));
	memset(CHESS, false, sizeof(CHESS));

	solve(0, "");

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





