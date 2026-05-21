# pair / tuple

## Common operations

```cpp
pair<int, int> p = {1, 2};
auto [x, y] = p;

tuple<int, string, double> t = {1, "abc", 3.14};
auto [a, b, c] = t;
```

## Special notes

- Use `make_pair` for quick pair creation.
- `get<i>(tuple)` accesses tuple elements by index.
