
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
	int pivot = a[high]; // making pivot the last element

	int i = low - 1 ; // i hamesha last smallest pe rahega

	for (int j = low ; j < high ; j++) {

		if (a[j] < pivot) // pivot se chhote wala left me le jao
		{
			i++;
			swap(a[i], a[j]);
		}
	}

	swap(a[i + 1], a[high]); // pivot se saare chhote wale jo hai i tk hai so i+1 is the original position of pivot

	return i + 1; // returning the current pivot position
}

void QuickSort(vector<int> &a , int low , int high)
{
	int j;
	if (low < high)
	{
		j = partition(a , low , high);

		QuickSort(a  , low , j - 1);
		QuickSort(a, j + 1, high);
	}
}

void solveTestCases()
{
	int n;
	cin >> n;

	vector<int> a(n);

	for (auto &it : a)
		cin >> it;

	QuickSort(a , 0 , n - 1);

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



