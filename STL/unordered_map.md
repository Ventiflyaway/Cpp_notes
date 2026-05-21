# unordered_map

## Common operations

```cpp
unordered_map<int, int> mp;
mp[1] = 10;
mp.emplace(2, 20);
mp.insert({3, 30});
mp.erase(2);
```

## Search

```cpp
auto it = mp.find(1);
if (it != mp.end()) {
    // use it->first and it->second
}
```

## Special notes

- Average time complexity is O(1).
- Use `reserve()` when the size is known in advance.
- `operator[]` creates a default value if the key does not exist.
