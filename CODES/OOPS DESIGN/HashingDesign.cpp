
#include <bits/stdc++.h>
using namespace std;

class HashMap
{
private:
	int size;
	vector<vector<int>>keyVal;
public:
	HashMap(int size)
	{
		this->size = size;
		keyVal.clear();
		keyVal.resize(size);
	}

	int getKey(int key)
	{
		return key % size;
	}

	void insert(int val)
	{
		int key = this->getKey(val);

		for (auto it : keyVal[key])
			if (it == val)
				return;

		keyVal[key].push_back(val);
	}

	bool isPresent(int val)
	{
		int key = this->getKey(val);

		for (auto it : keyVal[key])
			if (it == val)
				return true;

		return false;
	}

	void remove(int val)
	{
		int key = this->getKey(val);

		auto it = keyVal[key].begin();

		for (; it != keyVal[key].end(); ++it)
		{
			if (*it == val)
			{
				keyVal[key].erase(it);
				return;
			}
		}
	}

};

void solveTestCases()
{
	HashMap mp(10);
	mp.insert(54);
	mp.insert(99);

	cout << mp.isPresent(54) << endl;
	cout << mp.isPresent(100) << endl;

	mp.remove(54);

	cout << mp.isPresent(54) << endl;
}



int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	solveTestCases ();


	return 0;
}



