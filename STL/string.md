# string

## Common operations

```cpp
string s = "hello";
s += " world";
s.push_back('!');
s.insert(5, " C++");
s.erase(5, 4);
```

## Search and substring

```cpp
auto pos = s.find("world");
auto sub = s.substr(0, 5);
```

## Special notes

- `getline(cin, s)` reads full line.
- `s.empty()` checks whether string is empty.
- Use `string::npos` to test failed search.
