# C++ deque 完全使用指南

`deque` 是双端队列，支持头尾高效插入删除，也支持随机访问。

---

## 一、头文件和声明

```cpp
#include <deque>

deque<int> dq;
deque<int> dq2 = {1, 2, 3};
```

---

## 二、插入元素

```cpp
deque<int> dq;

dq.push_back(1);
dq.push_front(2);
dq.emplace_back(3);
dq.emplace_front(4);
dq.insert(dq.begin() + 1, 10);
```

---

## 三、删除元素

```cpp
dq.pop_back();
dq.pop_front();
dq.erase(dq.begin() + 2);
dq.clear();
```

---

## 四、访问和查找

```cpp
int x = dq[0];
int y = dq.at(1);

auto it = find(dq.begin(), dq.end(), 10);
```

---

## 五、常用函数速查

| 函数 | 说明 |
|---|---|
| `dq.push_back(x)` | 尾部插入 |
| `dq.push_front(x)` | 头部插入 |
| `dq.pop_back()` | 尾部删除 |
| `dq.pop_front()` | 头部删除 |
| `dq.insert(pos, x)` | 指定位置插入 |
| `dq.erase(pos)` | 指定位置删除 |
| `dq.front()` | 头部元素 |
| `dq.back()` | 尾部元素 |
| `dq.size()` | 元素个数 |

---

## 六、特殊用法

常见场景：滑动窗口、单调队列、BFS 的双端扩展、需要同时操作头尾的场景。