# C++ unordered_set 完全使用指南

`unordered_set` 是哈希集合，平均 $O(1)$ 查找、插入、删除，不保证顺序。

---

## 一、头文件和声明

```cpp
#include <unordered_set>

unordered_set<int> us;
unordered_set<string> us2;
```

---

## 二、插入元素

```cpp
us.insert(1);
us.emplace(2);
us.insert({3});
```

- 重复元素只保留一个。
- 插入平均复杂度通常是 $O(1)$。

---

## 三、查找

```cpp
auto it = us.find(2);
if (it != us.end()) {
    cout << *it << endl;
}

bool ok = us.count(2);
if (us.contains(2)) {
    cout << "exists" << endl;
}
```

---

## 四、删除元素

```cpp
us.erase(2);

auto it = us.find(3);
if (it != us.end()) us.erase(it);

us.clear();
```

---

## 五、遍历

```cpp
for (int x : us) cout << x << ' ';
for (const auto& x : us) cout << x << ' ';
```

注意：遍历顺序不固定，不要依赖输出顺序。

---

## 六、常用函数速查

| 函数 | 说明 |
|---|---|
| `us.size()` | 元素个数 |
| `us.empty()` | 是否为空 |
| `us.find(x)` | 查找 |
| `us.count(x)` | 是否存在 |
| `us.insert(x)` | 插入 |
| `us.erase(x)` | 删除 |
| `us.clear()` | 清空 |
| `us.reserve(n)` | 预留桶 |
| `us.rehash(n)` | 调整桶数量 |
| `us.contains(x)` | C++20 判断是否存在 |

---

## 七、特殊用法

```cpp
unordered_set<int> seen;
if (!seen.insert(x).second) {
    // x 已经出现过
}
```

- 适合去重、是否出现过、快速 membership test。
- 若 key 复杂，需自定义 `hash` 和 `==`。
