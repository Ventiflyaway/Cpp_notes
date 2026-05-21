# C++ vector 完全使用指南

`vector` 是最常用的动态数组，支持随机访问，尾部插入删除高效。

---

## 一、头文件和声明

```cpp
#include <vector>

vector<int> v1;
vector<int> v2(5);              // 5 个默认值 0
vector<int> v3(5, 10);          // 5 个 10
vector<int> v4 = {1, 2, 3};
vector<pair<int, int>> v5;
```

---

## 二、插入元素

```cpp
vector<int> v = {1, 2, 3};

v.push_back(4);
v.emplace_back(5);
v.insert(v.begin() + 1, 99);
v.insert(v.end(), {7, 8, 9});
```

说明：

- `push_back` 和 `emplace_back` 常用于尾部追加。
- `emplace_back` 会原地构造，通常更高效。
- 中间插入是 $O(n)$。