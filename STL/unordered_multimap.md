# C++ unordered_multimap 完全使用指南

`unordered_multimap` 是允许重复 key 的哈希键值容器，平均 $O(1)$ 查找和插入。

---

## 一、头文件和声明

```cpp
#include <unordered_map>

unordered_multimap<int, string> umm;
unordered_multimap<string, int> umm2;
```

---

## 二、插入元素

```cpp
umm.insert({1, "one"});
umm.emplace(1, "uno");
umm.insert(make_pair(2, "two"));
```

- key 可以重复。
- 元素不保证任何顺序。

---

## 三、查找

```cpp
auto it = umm.find(1);
if (it != umm.end()) {
    cout << it->first << " " << it->second << endl;
}

size_t cnt = umm.count(1);
auto range = umm.equal_range(1);
```

---

## 四、删除元素

```cpp
umm.erase(1);          // 删除所有 key 为 1 的元素

auto it = umm.find(2);
if (it != umm.end()) umm.erase(it);

umm.clear();
```

---

## 五、遍历

```cpp
for (const auto& [key, value] : umm) {
    cout << key << ": " << value << endl;
}
```

---

## 六、常用函数速查

| 函数 | 说明 |
|---|---|
| `umm.size()` | 元素个数 |
| `umm.empty()` | 是否为空 |
| `umm.find(key)` | 找到任意一个 key |
| `umm.count(key)` | key 的数量 |
| `umm.equal_range(key)` | key 的区间 |
| `umm.insert(...)` | 插入 |
| `umm.erase(key)` | 删除所有同 key 元素 |
| `umm.clear()` | 清空 |

---

## 七、特殊用法

```cpp
unordered_multimap<int, string> mp;
mp.emplace(1, "a");
mp.emplace(1, "b");
```

- 适合“一个 key 对应多个值”的哈希映射。
- 如果你只是想快速统计次数，`unordered_map<T, int>` 往往更简单。
