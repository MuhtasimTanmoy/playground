//https://Codejam/problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int case_count = 1;

typedef struct duration
{
	int start;
	int end;
} duration;

bool compare(duration &a, duration &b)
{
	return a.end < b.end;
}

void solve()
{
	int n;
	cin >> n;
	vector<duration> list;
	vector<duration> copy_list;

	duration holder;

	for (int i = 0; i < n; i++)
	{
		cin >> holder.start >> holder.end;
		list.push_back(holder);
		copy_list.push_back(holder);
	}

	sort(list.begin(), list.end(), compare);
	bool possible = true;

	for (int i = 2; i < n; i++)
	{
		if (
		   (list[i].start < list[i - 1].end) 
		&& (list[i].start < list[i - 2].end) 
		&& (list[i-1].start < list[i-2].end)
		)
		{
			possible = false;
			break;
		}
	}
	
	cout << "Case #" << case_count << ": ";
	case_count++;

	char current = 'C';

	if(possible){
		cout<< current;
		for (int i = 1; i < n; i++){
			if(copy_list[i].start < copy_list[i-1].end){
				current = ((current == 'C')?'J':'C');
			}
			cout<<current;
		}
		cout<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}
