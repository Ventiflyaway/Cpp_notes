# C++ map / multimap 完全使用指南

`map` 和 `multimap` 都是有序键值容器，按 key 自动排序，底层通常是红黑树。

---

## 一、头文件和声明

```cpp
#include <map>

map<int, string> mp;
multimap<int, string> mmp;
map<string, int, greater<string>> mp2;
```

---

## 二、插入元素

```cpp
map<int, string> mp;

mp[1] = "one";
mp.insert({2, "two"});
mp.emplace(3, "three");
mp.insert(make_pair(4, "four"));
mp.try_emplace(5, "five");
mp.insert_or_assign(6, "six");
```

---

## 三、访问元素

```cpp
map<int, string> mp = {{1, "one"}, {2, "two"}};

string val = mp[1];

auto it = mp.find(2);
if (it != mp.end()) {
    cout << it->first << " " << it->second << endl;
}

cout << mp.at(1) << endl;
```

---

## 四、删除元素

```cpp
mp.erase(1);

auto it = mp.find(2);
if (it != mp.end()) {
    mp.erase(it);
}

mp.clear();
```

---

## 五、查找和边界

```cpp
auto it = mp.find(3);
bool ok = mp.count(3);
auto lb = mp.lower_bound(3);
auto ub = mp.upper_bound(3);
auto range = mmp.equal_range(3);
```

---

## 六、遍历

```cpp
for (auto& [key, value] : mp) {
    cout << key << ": " << value << endl;
}
```

---

## 七、常用函数速查

| 函数 | 说明 |
|---|---|
| `mp[key]` | 访问或插入 |
| `mp.at(key)` | 访问，不存在抛异常 |
| `mp.insert(...)` | 插入 |
| `mp.erase(key)` | 删除 |
| `mp.find(key)` | 查找 |
| `mp.count(key)` | 统计是否存在 |
| `mp.lower_bound(key)` | 第一个 `>= key` |
| `mp.upper_bound(key)` | 第一个 `> key` |
| `mp.begin()` | 最小 key |
| `mp.rbegin()` | 最大 key |

---

## 八、特殊用法

```cpp
map<int, int, greater<int>> desc_map;
```

常见场景：需要有序 key、前缀统计和区间查询、维护映射关系、按 key 排序遍历。