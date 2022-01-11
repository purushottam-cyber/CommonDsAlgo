
#include <bits/stdc++.h>
using namespace std;

#define LETSGO int TESTCASES;cin>>TESTCASES;while(TESTCASES--)
#define fr(a,b,c) for(int a=b;a<c;a++)
#define setbit(x) __builtin_popcount(x)
#define all(el) el.begin(),el.end()
#define BOOM ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pinf LLONG_MAX
#define ninf LLONG_MIN

void printans(std::vector<int>&a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n - 1];
	return;
}


void ShellSort(std::vector<int> &a)
{
	int i , j , gap , temp , n = a.size();

	for (gap = n / 2 ; gap >= 1; gap /= 2)
	{
		for ( i = gap; i < n; i++)
		{
			temp = a[i]; // we are shifting that , remeber like insertion sort
			j = i - gap;

			while (j >= 0 && a[j] > temp)
			{
				a[j + gap] = a[j];  // dhifting right
				j -= gap;
			}

			a[j + gap] = temp; // beacuse it would minused up one extra time
		}
	}
}

void solveTestCases()
{
	int n;
	cin >> n;

	std::vector<int> a(n);

	for (auto & it : a)
		cin >> it;

	ShellSort(a);

	printans(a);

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



