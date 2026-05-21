# priority_queue

## Common operations

```cpp
priority_queue<int> pq;
pq.push(3);
pq.emplace(5);
pq.pop();
int top = pq.top();
```

## Special notes

- Default is a max heap.
- Min heap:

```cpp
priority_queue<int, vector<int>, greater<int>> minpq;
```
