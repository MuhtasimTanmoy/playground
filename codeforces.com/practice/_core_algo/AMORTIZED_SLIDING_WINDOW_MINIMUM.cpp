#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int n, sliding_window;
	cin >> n >> sliding_window;

	int li[n];
	deque<int> stk;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}
	
	for (int i = 0; i < sliding_window; i++)
	{
		if (stk.empty())
		{
			stk.push_back(li[i]);
		}
		else
		{
			while (!stk.empty() && stk.back() >= li[i])
			{
				stk.pop_back();
			}
			stk.push_back(li[i]);
		}
	}

	cout << stk.front() << " ";

	for (int i = sliding_window; i < n; i++)
	{
		// while here

		if (li[i - sliding_window] == stk.front())
		{
			stk.pop_front();
		}

		if (stk.empty())
		{
			stk.push_back(li[i]);
		}
		else
		{
			while (!stk.empty() && stk.back() >= li[i])
			{
				stk.pop_back();
			}
			stk.push_back(li[i]);
		}

		cout << stk.front() << " ";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}


// C++ program to find sum of all minimum and maximum 
// elements Of Sub-array Size k. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Returns sum of min and max element of all subarrays 
// of size k 
int SumOfKsubArray(int arr[] , int n , int k) 
{ 
    int sum = 0;  // Initialize result 
  
    // The queue will store indexes of useful elements 
    // in every window 
    // In deque 'G' we maintain decreasing order of 
    // values from front to rear 
    // In deque 'S' we  maintain increasing order of 
    // values from front to rear 
    deque< int > S(k), G(k); 
  
    // Process first window of size K 
    int i = 0; 
    for (i = 0; i < k; i++) 
    { 
        // Remove all previous greater elements 
        // that are useless. 
        while ( (!S.empty()) && arr[S.back()] >= arr[i]) 
            S.pop_back(); // Remove from rear 
  
        // Remove all previous smaller that are elements 
        // are useless. 
        while ( (!G.empty()) && arr[G.back()] <= arr[i]) 
            G.pop_back(); // Remove from rear 
  
        // Add current element at rear of both deque 
        G.push_back(i); 
        S.push_back(i); 
    } 
  
    // Process rest of the Array elements 
    for (  ; i < n; i++ ) 
    { 
        // Element at the front of the deque 'G' & 'S' 
        // is the largest and smallest 
        // element of previous window respectively 
        sum += arr[S.front()] + arr[G.front()]; 
  
        // Remove all elements which are out of this 
        // window 
        while ( !S.empty() && S.front() <= i - k) 
            S.pop_front(); 
        while ( !G.empty() && G.front() <= i - k) 
            G.pop_front(); 
  
        // remove all previous greater element that are 
        // useless 
        while ( (!S.empty()) && arr[S.back()] >= arr[i]) 
            S.pop_back(); // Remove from rear 
  
        // remove all previous smaller that are elements 
        // are useless 
        while ( (!G.empty()) && arr[G.back()] <= arr[i]) 
            G.pop_back(); // Remove from rear 
  
        // Add current element at rear of both deque 
        G.push_back(i); 
        S.push_back(i); 
    } 
  
    // Sum of minimum and maximum element of last window 
    sum += arr[S.front()] + arr[G.front()]; 
  
    return sum; 
}