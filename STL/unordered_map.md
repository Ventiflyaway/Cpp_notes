# C++ unordered_map 完全使用指南

`unordered_map` 是 C++ 的哈希表，提供平均 $O(1)$ 的查找、插入和删除。

---

## 一、头文件和声明

```cpp
#include <unordered_map>

unordered_map<string, int> umap;          // 键为 string，值为 int
unordered_map<int, vector<int>> umap2;    // 键为 int，值为 vector
unordered_map<int, int> umap3;            // 最常用：键值都是 int

unordered_map<int, int> umap4(100);       // 预留桶数量，减少 rehash

unordered_map<string, int> umap5 = {
    {"apple", 5},
    {"banana", 3},
    {"orange", 2}
};
```

---

## 二、插入元素（5 种常见方式）

```cpp
unordered_map<string, int> umap;

umap["apple"] = 5;                          // 最常用
umap.insert(pair<string, int>("orange", 2));
umap.insert(make_pair("grape", 4));
umap.insert({"melon", 6});
umap.emplace("peach", 7);
```

补充：

- `insert` 插入已有 key 时不会覆盖原值。
- `operator[]` 如果 key 不存在，会先插入默认值，再返回引用。
- 需要“存在则覆盖”时，优先用 `insert_or_assign()`。

```cpp
umap.insert_or_assign("apple", 10);
```

---

## 三、访问元素

```cpp
unordered_map<string, int> umap = {{"apple", 5}, {"banana", 3}};

int val = umap["apple"];   // 存在：返回 5
int val2 = umap["peach"];  // 不存在：会插入默认值 0

auto it = umap.find("apple");
if (it != umap.end()) {
    cout << it->first << ": " << it->second << endl;
}

try {
    int val3 = umap.at("apple");
    int val4 = umap.at("peach");
} catch (const out_of_range&) {
    cout << "key not found" << endl;
}

if (umap.contains("apple")) {
    cout << "exists" << endl;
}
```

---

## 四、删除元素

```cpp
unordered_map<string, int> umap = {
    {"apple", 5}, {"banana", 3}, {"orange", 2}
};

umap.erase("banana");

auto it = umap.find("orange");
if (it != umap.end()) {
    umap.erase(it);
}

umap.clear();
```

---

## 五、遍历

```cpp
for (auto& p : umap) {
    cout << p.first << ": " << p.second << endl;
}

for (const auto& p : umap) {
    cout << p.first << ": " << p.second << endl;
}

for (auto it = umap.begin(); it != umap.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}

for (auto& [key, value] : umap) {
    cout << key << ": " << value << endl;
}
```

注意：`unordered_map` 的遍历顺序不固定，不要依赖输出顺序。

---

## 六、常用函数速查

| 函数 | 说明 | 时间复杂度 |
|---|---|---|
| `umap.size()` | 返回键值对数量 | $O(1)$ |
| `umap.empty()` | 是否为空 | $O(1)$ |
| `umap.find(key)` | 查找，返回迭代器；不存在返回 `end()` | 平均 $O(1)$ |
| `umap.count(key)` | 返回 key 是否存在（0 或 1） | 平均 $O(1)$ |
| `umap.insert({k, v})` | 插入 | 平均 $O(1)$ |
| `umap.erase(key)` | 删除 | 平均 $O(1)$ |
| `umap.clear()` | 清空整个表 | $O(n)$ |
| `umap.contains(key)` | C++20 判断是否存在 | 平均 $O(1)$ |
| `umap.reserve(n)` | 预留桶数量，减少 rehash | $O(n)$ |
| `umap.rehash(n)` | 直接调整桶数量 | $O(n)$ |

---

## 七、性能和使用注意

- 平均复杂度是 $O(1)$，但最坏情况可能退化。
- key 的哈希分布越均匀，性能越稳定。
- 大数据量场景建议提前 `reserve()`。
- `operator[]` 会修改容器，纯查询别乱用。
- 如果需要按 key 排序、区间查询，应该用 `map`，不是 `unordered_map`。

---

## 八、自定义哈希

如果 key 不是基础类型，通常要自定义哈希函数。

```cpp
struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    size_t operator()(const Point& p) const {
        return hash<long long>()(1LL * p.x * 1000003 + p.y);
    }
};

unordered_map<Point, int, PointHash> mp;
```

---

## 九、常见场景

- 计数：字符频率、数字出现次数。
- 映射：ID 到值、名字到编号。
- 去重辅助：配合 `unordered_set` 或计数表。
- 前缀统计：滑动窗口、子数组、异位词类题目。