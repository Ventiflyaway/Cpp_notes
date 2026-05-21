# vector

## Common operations

```cpp
vector<int> v;
v.push_back(1);
v.emplace_back(2);
v.insert(v.begin() + 1, 3);
v.erase(v.begin() + 2);
v.pop_back();
v.clear();
```

## Search and traversal

```cpp
auto it = find(v.begin(), v.end(), 2);
sort(v.begin(), v.end());
auto pos = lower_bound(v.begin(), v.end(), 2);
```

## Special notes

- `reserve()` reduces reallocation.
- `resize()` changes size, not capacity.
- `at()` checks bounds, `operator[]` does not.
