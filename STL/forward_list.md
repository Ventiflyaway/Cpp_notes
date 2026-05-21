# C++ forward_list 完全使用指南

`forward_list` 是单向链表，更省内存，只能向前迭代。

---

## 一、头文件和声明

```cpp
#include <forward_list>

forward_list<int> flst;
forward_list<int> flst2 = {1, 2, 3};
```

---

## 二、插入元素

```cpp
flst.push_front(2);
flst.emplace_front(1);
flst.insert_after(flst.before_begin(), 0);
flst.emplace_after(flst.before_begin(), -1);
```

---

## 三、删除元素

```cpp
flst.pop_front();
flst.erase_after(flst.before_begin());
flst.remove(2);
flst.remove_if([](int x) { return x < 0; });
flst.clear();
```

---

## 四、遍历

```cpp
for (int x : flst) cout << x << ' ';

for (auto it = flst.begin(); it != flst.end(); ++it) {
    cout << *it << ' ';
}
```

---

## 五、常用函数速查

| 函数 | 说明 |
|---|---|
| `flst.empty()` | 是否为空 |
| `flst.front()` | 头元素 |
| `flst.before_begin()` | 头前迭代器 |
| `flst.insert_after(it, x)` | 在 `it` 后插入 |
| `flst.erase_after(it)` | 删除 `it` 后元素 |
| `flst.sort()` | 排序 |
| `flst.unique()` | 去重相邻重复 |
| `flst.merge(other)` | 合并有序链表 |

---

## 六、特殊用法

```cpp
flst.sort();
flst.unique();
flst.merge(other_flist);
```

- `forward_list` 比 `list` 更省内存。
- 只能单向遍历，所以很多操作都围绕 `before_begin()` 和 `*_after()`。
- 适合只需要头插、顺序访问的场景。
