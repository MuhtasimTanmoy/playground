#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

class node
{
	char val;
	node *nextNode;

public:
	node(char _val)
	{
		val = _val;
		nextNode = NULL;
	}

	void setNext(node *next)
	{
		nextNode = next;
	}

	node *getNext()
	{
		return nextNode;
	}

	char getValue()
	{
		return val;
	}
};

void solve()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	node *head;
	head = new node(s[0]);

	node *itr;
	itr = head;

	for (int i = 1; i < s.size(); i++)
	{
		itr->setNext(new node(s[i]));
		itr = itr->getNext();
	}

	itr = head;

	while (itr->getNext())
	{
		cout << itr->getValue() << " ";
		itr = itr->getNext();
	}

	cout << itr->getValue() << endl;

	itr = head;

	node *back_one_step = NULL;
	back_one_step = head;

	while (itr->getNext())
	{
		cout << itr->getValue() << " " << itr->getNext()->getValue() << endl;
		if (itr->getValue() == itr->getNext()->getValue())
		{
			if (back_one_step == NULL)
			{
				head = itr->getNext()->getNext();
				back_one_step = head;
				itr = head;
			}
			else
			{
				cout << endl<< "backing "<< "...." << 1 << "...." << endl;
				itr = back_one_step;
			}
		}
		else
		{
			back_one_step = itr;
			itr = itr->getNext();
		}
	}

	cout << endl;

	itr = head;

	while (itr->getNext())
	{
		cout << itr->getValue() << " ";
		itr = itr->getNext();
	}

	cout << itr->getValue();
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
