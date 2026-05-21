# map

## Common operations

```cpp
map<int, string> mp;
mp[1] = "one";
mp.emplace(2, "two");
mp.insert({3, "three"});
mp.erase(2);
```

## Search

```cpp
auto it = mp.find(1);
if (it != mp.end()) {
    // it->first, it->second
}
```

## Special notes

- Keys are ordered.
- `operator[]` inserts a default value if the key is missing.
- `lower_bound()` and `upper_bound()` work on keys.
