# C++ list 完全使用指南

`list` 是双向链表，任意位置插入删除快，但不支持随机访问。

---

## 一、头文件和声明

```cpp
#include <list>

list<int> lst;
list<int> lst2 = {1, 2, 3};
list<string> lst3 = {"a", "b"};
```

---

## 二、插入元素

```cpp
lst.push_back(3);
lst.push_front(1);
lst.emplace_back(4);
lst.emplace_front(0);
lst.insert(next(lst.begin()), 2);
```

---

## 三、删除元素

```cpp
lst.pop_back();
lst.pop_front();
lst.erase(next(lst.begin()));
lst.remove(2);
lst.remove_if([](int x) { return x % 2 == 0; });
lst.clear();
```

---

## 四、查找和遍历

```cpp
auto it = find(lst.begin(), lst.end(), 3);

for (int x : lst) cout << x << ' ';
for (auto it = lst.begin(); it != lst.end(); ++it) cout << *it << ' ';
```

---

## 五、常用函数速查

| 函数 | 说明 |
|---|---|
| `lst.size()` | 元素个数 |
| `lst.empty()` | 是否为空 |
| `lst.front()` | 头元素 |
| `lst.back()` | 尾元素 |
| `lst.insert(it, x)` | 在迭代器前插入 |
| `lst.erase(it)` | 删除迭代器位置元素 |
| `lst.sort()` | 链表排序 |
| `lst.unique()` | 去除相邻重复 |
| `lst.merge(other)` | 合并有序链表 |
| `lst.splice(it, other)` | O(1) 转移节点 |

---

## 六、特殊用法

```cpp
lst.sort();
lst.unique();
lst.merge(other_lst);
lst.splice(lst.begin(), other_lst);
```

- `list` 适合频繁中间插删。
- `splice` 是 `list` 的高频特殊接口，能 O(1) 转移节点。
- 不支持随机访问，不能用下标。
