
#include <bits/stdc++.h>
using namespace std;


class Node
{
public:
	int val;
	Node* next;
	Node(int _val = 0, Node *_next = NULL): val{_val}, next{_next} {};
};


class LinkList {

private :

	int size;
	Node* Head;
	Node* current;

public:

	LinkList( Node* _head): size{1}, Head{_head}, current{_head} {}

	void addNode(Node *addThis)
	{
		this->current->next = addThis;
		this->current = this->current->next;
		size++;
	}

	int getSize()
	{
		return this->size;
	}

	void printList()
	{
		Node *p = this->Head;

		cout << "[ ";

		while (p)
		{
			cout << p->val;

			if (p->next)
				cout << "->";
			p = p->next;
		}

		cout << " ]";
	}

	Node *getHead()
	{
		return this->Head;
	}

};

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *node1 = new Node{4, NULL};
	LinkList list(node1);
	node1 = new Node{45, NULL};
	list.addNode(node1);
	cout << list.getSize() << endl;

	list.printList();

	return 0;
}



