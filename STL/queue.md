# C++ queue 完全使用指南

`queue` 是先进先出（FIFO）的容器适配器，常用于 BFS、任务调度和层序遍历。

---

## 一、头文件和声明

```cpp
#include <queue>

queue<int> q;
queue<string> q2;
```

---

## 二、入队和出队

```cpp
queue<int> q;

q.push(1);
q.emplace(2);
q.pop();
```

---

## 三、访问和判断

```cpp
queue<int> q;
q.push(10);
q.push(20);

int f = q.front();
int b = q.back();
bool empty = q.empty();
int sz = q.size();
```

`queue` 不支持随机访问，也不能直接遍历中间元素。

---

## 四、常用函数速查

| 函数 | 说明 |
|---|---|
| `q.push(x)` | 入队 |
| `q.emplace(...)` | 原地构造入队 |
| `q.pop()` | 出队 |
| `q.front()` | 队头 |
| `q.back()` | 队尾 |
| `q.empty()` | 是否为空 |
| `q.size()` | 元素个数 |

---

## 五、特殊用法

```cpp
queue<int, deque<int>> q1;
```

常见场景：BFS、树的层序遍历、生产者消费者模型、任务调度。