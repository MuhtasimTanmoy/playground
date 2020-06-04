#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

class Complex
{
	public:
		Complex (double a, double b): r (a), c (b) {}
	private:
		double r; // R	eal Part
		double c; // Complex Part
};

int main()
{
	Complex* array[1000];
  for (int i = 0;i  <  5000; i++) {
    for (int j = 0; j  <  1000; j++) {
      array[j] = new Complex (i, j);
      }
	for (int j = 0; j  < 1000;j++){
    delete array[j];
    }
} return 0;
}
