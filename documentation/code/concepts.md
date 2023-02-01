# Concepts

- [Interview Questions C++](https://youtu.be/bFtkHJy9kIU)

- Memory Allocation with new

```c++
// How delete knows how much memory to free jup
// over allocation
class Base{
public:
    int b var;
}

// tmp 0 1 2 3 4 5 - 43;

int n = 10;

int main() {
Base *bp = new Base[n];

// The above line gets converted to

// WORDSIZE varies depending on architecture
// char* tmp = (char•) operator new[] (WORDSIZE + n • sizeof(Base));

// Base• p = (Base*) (tmp + WORDSIZE);
// *(size_t) tmp = n;

// for (int i = 0; i < n; i++ ) {
//   new(p + i) Base(); // placement new
// } 

delete [] bp;
}
```

- Template in c++ for each type gets duplicated
- `this` in c++

```c++
Base b;

b.setValue(10);

// converts to this which modifies the function to have this address
// setvalue(&b,10) 
```

- To prevent any built in function
    - overload the operator to private
    - make a separate class having those functionality
    - use delete on those operators

- vector initialize with `2` capacity when exceeds each time doubles the capacity
    - So better not use `push_back`, reserve, resize at the beginning
- Use godbolt
- `nm obj.o` to see name mangling
- Object slicing is more like upcast
- with `reinterpret_cast` can extract value from struct
- stuctural padding and packing for speeding up cpu optmization
    - As in 64 bit or 32 bit in one cycle similar data
    - We need to devide whole meory into segments, in hard disk pages, in memory segment

- Sorting is good for branch prediction
    - Saturating counter
    - A general rule of thumb is to avoid data-dependent branching in critical loops (such as in this example).

```c++
// Dont
int max1(int a, int b) {
    if (a > b) return a;
    else return b;
}

// Do 
int max2(int a, int b) {
    return a > b ? a : b;
}
```