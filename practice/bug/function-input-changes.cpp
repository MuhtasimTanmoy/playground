#include <bits/stdc++.h>
using namespace std;
#define log(x) cout << #x << " = " << x << endl;

void execute(vector<int>& aliceSizes, vector<int>& bobSizes) {
	auto aSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        auto bSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        auto delta = ( bSum - aSum ) >> 1;
        if (delta < 0) swap(aSum, bSum);
        sort(aliceSizes.begin(), aliceSizes.end());
        
        function<int(bool)> find = [&](int num) -> bool {
            cout<<num<<endl;
            int left = 0;
            int right = aliceSizes.size() - 1;
            while (left < right) {
                auto mid = left + (right - left) / 2;
                auto now = aliceSizes[mid];
                // cout<<now<<endl;
                if (now == num) return true;
                else if (now > num) right = mid - 1;
                else left = mid + 1;
            }
            return false;
        };
        
        for (auto b: bobSizes) {
            auto target = b - delta;
            cout<<target<<endl;
            if (find(target)) cout<< b - delta<< "-" << b;
        }

		cout<<"No result"<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	vector<int> a = {2};
	vector<int> b = {1, 3};
	while (no_of_test_cases--) execute(a, b);
	return 0;
}
