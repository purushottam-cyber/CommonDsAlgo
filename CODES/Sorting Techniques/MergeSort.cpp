
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

void merge(vector<int> &a , int low , int mid , int high)
{
	int i , j , k;

	std::vector<int> B(high + 1);

	i = low , j = mid + 1 , k = low;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
			B[k++] = a[i++];
		else
			B[k++] = a[j++];
	}

	while (i <= mid) B[k++] = a[i++];
	while (j <= high) B[k++] = a[j++];

	for (int i = low; i <= high; i++)
		a[i] = B[i];

}

void mergeSortIterative(vector<int> &a)
{
	int n = a.size();

	int i , low , mid , high , p;

	for ( p = 2; p <= n; p *= 2) // important to determine The Passes
	{
		for ( i = 0 ; i + p - 1 < n; i += p) // Put a limit for High index
		{
			low = i;
			high = i + p - 1;
			mid = (low + high) / 2;

			merge(a, low, mid, high);
		}
	}

	if (p / 2 < n)  // if someElement has left out i.e not give proper int for log2(N)
		merge(a, 0, p / 2 - 1, n - 1);
}

void mergeSortRecursive(std::vector<int> &a , int low , int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		mergeSortRecursive(a, low, mid);
		mergeSortRecursive(a, mid + 1, high);

		merge(a, low, mid, high);
	}
}

void solveTestCases()
{
	int n;
	cin >> n;

	std::vector<int> a(n);

	for (auto & it : a)
		cin >> it;

	mergeSortRecursive(a, 0, n - 1);

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



