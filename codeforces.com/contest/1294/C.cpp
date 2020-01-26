//https://codeforces.com/contest/1294/problem/C
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
    int n;
    cin >> n;

    int limit = cbrt(n);
    int start = 2;
    bool found = false;

    while ((n % start) != 0)
    {
        start++;
        if(start>limit){
            break;
        }
    }

    int target = n / start ;

    int left = start+1;

    while ((target % left) != 0)
    {
        left++;
        if(left>limit){
            break;
        }
    }
 
    int right = target/left;
    int check; 

    while (left < right)
    {

        check = left * right;

        if(target == check){
            found = true;
            break;
        }

        if(check > target){
            right--;
        }
        else{
            left++;
        }
    }

    if(found){
        cout<<"YES"<<endl;
        cout<<start<<" "<<left<<" "<<right<<endl;
    }
    else{
        cout<<"NO"<<endl;
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
