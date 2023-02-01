- bitset
    - `bitset<10> s(string("0010011010")`

- Only difference between struct and class is default private, public identifier
- struct for compatibility with c, used for data not inherited value

- vector
    - `std::vector` has a capactiy (the total slots that can be used) and a `size` (the number of slots actually used)
    - `reserve()` will increase the capacity, i.e. make room for more elements, but it will not increase the size
    - That's the job of `resize()`
        - vec.reserve(1); // capacity >= 1, size = 0!
    - Access to a vector is out of bounds if the index is `>=` the vector's size, irrespective of it's capacity, thus
        - `vec[0] = std::make_shared<A>();` is out of bounds and leads to undefined behaviour. (index 0 >= size 0)

- iterrator
    - For iterating over complex data structure like `map, set`
    - `using mapName = unordered_map<string, int>;`
    - `auto [key, value]: map` to 
    - `#if 0, endif` to not execute some portion of code
    - As `const string& name` supports both lvalue, rvalue, it is hugely used for parameter
    - `string& name` supports only lvalue, `string&& name` supports only rvalue
    - `const int* a` or `int const* a` vs `int* const int` is different
    - After function `const` prevents modifying data
    - `mutable` allow const function to mutate, basically creates a new value and apply changes there in lambda like passing value in lambda then change it with mutable
    - `std::move()` basically converts lvalue to rvalue
    - `object.operator=()` is similar to `=`
    -  string less than certan size like 16 is small string which is heap allocated
    - `async` to parrelalize computation, if future not preserved then it waits for the task to finish in its destructor. Extract performance out of all cores.
    - `std::any`, `std:variant` for data. variant lets type checking for storing multiple type of data in same variable.
    - `std:optional`
    - `union` different variable type punned to same representation
    - To avoid copy `Type& t`

- lambda
    - [&epsilon, zeta] captures epsilon by reference and zeta by value
    - [&] captures all variables used in the `lambda by reference`
    - [=] captures all variables used in the `lambda by value`
    - [&, epsilon] captures all variables used in the `lambda by reference` but captures epsilon by value
    - [=, &epsilon] captures all variables used in the `lambda by value` but captures epsilon by reference

- c++ STL
    - `sort` then `binary_search` if present, `lower_bound`, `upper_bound` gives iterator. It's difference gives span.
    - `for_each`
    - Heap
        - `make_heap`, `push_heap` heapify, `pop_heap` remove greatest value, `sort_heap`
        - `partial_sort` to get nth greatest
        - `nth_element`, `inplace_merge`
    - `partition_point`
    - `rotate`, `shuffle`, `next_permutation`, `prev_permutation`, `reverse`
    - To keep relative order `stable_`
    - Query
        - `count`
        - `equal` or `is_permutation` to check if element same or permuted
        - `mismatch` returns pair of first diff
        - `find` or `adjacent_find` to get two values
        - `max_element`, `min_element` or both
    - Set
        - `set_difference`, `set_interaction`
        - `copy_backward`, `generate`
        - `begin(collection)`
        - `remove()`, `erase`, `unique`

- reference vs pointer
    ```c++
        int i = 10;
        int &ref = i;
        int *pointer = &i;
        // &i and &ref same, pointer different
    ```

```c++
// for heap
auto [n, i] = hq.top(); 
```

- `extern C` when writing `c++` code and including library from `c` to avoid name mangling used for function overloading.

For observing the elements, use the following syntax
    - `for (const auto& elem : container)`    // capture by const reference
If the objects are cheap to copy (like ints, doubles, etc.), it's possible to use a slightly simplified form:
    - `for (auto elem : container)`    // capture by value
For modifying the elements in place, use:
    - `for (auto& elem : container)`    // capture by (non-const) reference
If the container uses "proxy iterators" (like std::vector<bool>), use:
    - `for (auto&& elem : container)`    // capture by &&

- [TSAN, ASAN](https://youtu.be/Q2C2lP8_tNE)

- Address Sanitizer
    - Global out of index access
    - Stack out of index access
    - Heap out of index access
    - Use after free

- Thread Sanitizer

- Dont use bits/stdc++
    - https://stackoverflow.com/questions/31816095/why-should-i-not-include-bits-stdc-h

- Dont use namespace std
    - https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

- [Move Semantics](https://youtu.be/vLinb2fgkHk)
    - Vector is just 3 pointers