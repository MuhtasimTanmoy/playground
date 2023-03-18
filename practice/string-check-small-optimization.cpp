#include <bits/stdc++.h>
using namespace std;
#define log(x) cout << #x << " = " << x << endl;

// replace operator new and delete to log allocations
void* operator new(std::size_t n) {
    std::cout << "[Allocating " << n << " bytes]";
    return malloc(n);
}
void operator delete(void* p) throw() {
    free(p);
}

void execute() {
    std::cout << sizeof(std::string) << std::endl;
	 for (size_t i = 0; i < ; ++i) 
        std::cout << i << ": " << std::string(i, '=') << std::endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}