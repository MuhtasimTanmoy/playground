#include <bits/stdc++.h>
using namespace std;

int modulo = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);

    int testCase;
    cin>> testCase;

    while(testCase--) {
        int nums;
        cin>>nums;
        int secondRowNums;
        secondRowNums = nums;

        set<int> firstRow;

        while (nums--)
        {
           int number;
           cin>>number;
           firstRow.insert(number);
        }

        int match
        while (secondRowNums--)
        {
            int number;
            cin>>number;
            if (set.count(number) == )
        }
        
    }
	return 0;
}
