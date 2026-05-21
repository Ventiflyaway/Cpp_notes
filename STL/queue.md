# queue

## Common operations

```cpp
queue<int> q;
q.push(1);
q.emplace(2);
q.pop();
int front = q.front();
int back = q.back();
```

## Special notes

- FIFO structure.
- Good for BFS and task scheduling.
