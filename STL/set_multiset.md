# set / multiset

## Common operations

```cpp
set<int> s;
multiset<int> ms;
s.insert(1);
ms.insert(2);
s.erase(1);
```

## Search

```cpp
auto it = s.find(1);
auto lb = s.lower_bound(1);
auto ub = s.upper_bound(1);
```

## Special notes

- `set` keeps unique sorted keys.
- `multiset` allows duplicates.
- `erase(value)` removes by key, not iterator position.
