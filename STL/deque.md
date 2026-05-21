# deque

## Common operations

```cpp
deque<int> dq;
dq.push_back(1);
dq.push_front(2);
dq.pop_back();
dq.pop_front();
```

## Search and traversal

```cpp
auto it = find(dq.begin(), dq.end(), 2);
```

## Special notes

- Supports random access.
- Efficient at both ends.
- Useful for monotonic queue patterns.
