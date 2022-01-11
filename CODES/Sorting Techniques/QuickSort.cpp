
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

int partition(vector<int> &a, int low , int high)
{
	int pivot = a[low];

	int i = low , j = high;

	while (i < j) {

		do {i++;} while (a[i] <= pivot);
		do {j--;} while (a[j] > pivot);

		if (i < j)
			swap(a[i], a[j]);
	}


	swap(a[low], a[j]);

	return j;
}

void QuickSort(vector<int> &a , int low , int high)
{
	int j;
	if (low < high)
	{
		j = partition(a , low , high);

		QuickSort(a  , low , j);
		QuickSort(a, j + 1, high);
	}
}

void solveTestCases()
{
	int n;
	cin >> n;

	std::vector<int> a(n);

	for (auto &it : a)
		cin >> it;

	a.push_back(INT_MAX);

	QuickSort(a , 0 , n);

	printans(a);

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



