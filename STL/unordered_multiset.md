# C++ unordered_multiset 完全使用指南

`unordered_multiset` 是允许重复的哈希集合，平均 $O(1)$ 查找、插入、删除。

---

## 一、头文件和声明

```cpp
#include <unordered_set>

unordered_multiset<int> ums;
unordered_multiset<string> ums2;
```

---

## 二、插入元素

```cpp
ums.insert(1);
ums.emplace(2);
ums.insert(2);
```

- 允许重复元素。
- 元素不排序，顺序不固定。

---

## 三、查找

```cpp
auto it = ums.find(2);
if (it != ums.end()) {
    cout << *it << endl;
}

size_t cnt = ums.count(2);
auto range = ums.equal_range(2);
```

---

## 四、删除元素

```cpp
ums.erase(2);          // 删除所有值为 2 的元素

auto it = ums.find(3);
if (it != ums.end()) ums.erase(it);

ums.clear();
```

---

## 五、遍历

```cpp
for (int x : ums) cout << x << ' ';
```

---

## 六、常用函数速查

| 函数 | 说明 |
|---|---|
| `ums.size()` | 元素个数 |
| `ums.empty()` | 是否为空 |
| `ums.find(x)` | 找到任意一个 `x` |
| `ums.count(x)` | `x` 的数量 |
| `ums.equal_range(x)` | `x` 的区间 |
| `ums.insert(x)` | 插入 |
| `ums.erase(x)` | 删除所有匹配值 |
| `ums.clear()` | 清空 |

---

## 七、特殊用法

```cpp
unordered_multiset<int> bag;
bag.insert(5);
bag.insert(5);
```

- 适合“多重集合 + 快速查找”。
- 如果既要计数又要删任意一个元素，也可以考虑 `unordered_map<T, int>`。
