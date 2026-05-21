# C++ set / multiset 完全使用指南

`set` 和 `multiset` 都是有序关联容器，底层通常是红黑树。

---

## 一、头文件和声明

```cpp
#include <set>

set<int> s;
multiset<int> ms;
set<int, greater<int>> s2;   // 降序
```

---

## 二、插入元素

```cpp
s.insert(1);
s.emplace(2);

ms.insert(3);
ms.insert(3);
```

- `set` 自动去重。
- `multiset` 允许重复。
- 插入复杂度通常是 $O(\log n)$。

---

## 三、删除元素

```cpp
s.erase(1);

auto it = s.find(2);
if (it != s.end()) {
    s.erase(it);
}

ms.erase(3);
```

注意：`erase(value)` 是按 key 删除，不是按位置删除。

---

## 四、查找和边界

```cpp
auto it = s.find(1);
bool ok = s.count(1);

auto lb = s.lower_bound(1);
auto ub = s.upper_bound(1);
auto range = ms.equal_range(1);
```

---

## 五、常用函数速查

| 函数 | 说明 |
|---|---|
| `s.insert(x)` | 插入 |
| `s.erase(x)` | 删除 |
| `s.find(x)` | 查找 |
| `s.count(x)` | 统计是否存在 |
| `s.lower_bound(x)` | 第一个 `>= x` |
| `s.upper_bound(x)` | 第一个 `> x` |
| `s.begin()` | 最小值 |
| `s.rbegin()` | 最大值 |

---

## 六、特殊用法

```cpp
set<int, greater<int>> desc_set;
```

常见场景：维护有序集合、动态第 k 小 / 第 k 大、区间边界查询、去重 + 排序。