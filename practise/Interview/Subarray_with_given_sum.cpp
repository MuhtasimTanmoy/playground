// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include <iostream>
using namespace std;

long long int li[10000001];
int main()
{
    freopen("input.txt", "r", stdin);

    //code
    int testCase;
    cin >> testCase;

    long long int n;
    long long int sum_target = 0;
    long long int sum = 0;

    bool found = false;
    while (testCase--)
    {
        cin >> n;
        cin >> sum_target;
        found = false;
        long long int left = 0;
        long long int right = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> li[i];
        }

        if (n == 1 && li[0] != sum)
        {
            cout << -1 << endl;
            continue;
        }

        sum = li[0];
        while (right < n)
        {
            if (sum == sum_target)
            {
                cout << left + 1 << " " << right + 1 << endl;
                found = true;
                break;
            }
            else if (sum < sum_target)
            {
                right++;
                if (right < n)
                {
                    sum += li[right];
                }
            }
            else if (sum > sum_target)
            {
                sum -= li[left];
                left++;
            }
        }

        if (!found)
            cout << -1 << endl;
    }
    return 0;
}
