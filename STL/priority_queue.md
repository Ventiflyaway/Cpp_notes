# C++ priority_queue 完全使用指南

`priority_queue` 是堆结构，默认是大顶堆，常用于 TopK、动态最值和贪心问题。

---

## 一、头文件和声明

```cpp
#include <queue>

priority_queue<int> pq;
priority_queue<string> pq2;
```

---

## 二、插入和删除

```cpp
priority_queue<int> pq;

pq.push(3);
pq.emplace(5);
pq.pop();
```

---

## 三、访问和判断

```cpp
int top = pq.top();
bool empty = pq.empty();
int sz = pq.size();
```

`priority_queue` 只能访问堆顶，不能随机访问，也不能遍历中间元素。

---

## 四、最小堆写法

```cpp
priority_queue<int, vector<int>, greater<int>> minpq;
```

---

## 五、自定义比较器

```cpp
struct Node {
    int x, y;
};

struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.x < b.x;   // 返回 true 表示 a 的优先级更低
    }
};

priority_queue<Node, vector<Node>, Cmp> pq2;
```

---

## 六、常用函数速查

| 函数 | 说明 |
|---|---|
| `pq.push(x)` | 入堆 |
| `pq.emplace(...)` | 原地构造入堆 |
| `pq.pop()` | 弹出堆顶 |
| `pq.top()` | 访问堆顶 |
| `pq.empty()` | 是否为空 |
| `pq.size()` | 元素个数 |

---

## 七、常见场景

- TopK
- 合并 K 个有序序列
- 数据流中位数
- 动态维护最值
- 贪心和调度类题目