# stack

## Common operations

```cpp
stack<int> st;
st.push(1);
st.emplace(2);
st.pop();
int x = st.top();
```

## Special notes

- LIFO structure.
- Default underlying container is usually `deque`.
