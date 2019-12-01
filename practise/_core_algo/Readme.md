- **Number range**

> -2^31 - 2^31 or -2*10^9 - 2*10^9 exact 2147483648

> −2^63...2^63 −1 or −9·10^18...9·10^18 exact 9.223372e+18

> \_\_int128_t −2^127...2^127 −1 or about −10^38...10^38

- **Floating point**

```
if (abs(a-b) < 1e-9) {
// a and b are equal
}
```

- **Formula**

Arithmatic Progression - n* ( a + b ) / 2

Geometric Progression - ( b * k - a ) / ( k - 1 )

- **Factorial**

Binet formula

```
int fib_formula(int n)
{
	float five = sqrt(5);
	return (pow((1 + five), n) + pow((1 - five), n)) / (pow(2, n) * five);
}
```






