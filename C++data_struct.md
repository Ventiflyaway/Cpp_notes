# C++ 数据结构 & 技巧笔记

## 0. 常用头文件

```cpp
#include <bits/stdc++.h>
using namespace std;
```

更推荐按需包含：

```cpp
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <array>
#include <algorithm>
```
## 0. 变量
### C++ 不会自动给局部变量赋初值
只是在栈（stack）上给 x 分配了一些字节空间
- 字节里原来是什么就还是什么

自动初始化成 0 会多一次写内存操作
- C++ 的设计理念之一是：You don't pay for what you don't use
### 全局变量、static变量会有初始值0

## 1. 函数 / 类基本框架

```cpp
class XX {
public:
    return_type fun_name(parameters) {
        // inner logic
    }
};
```

常见写法：

struct：自定义数据类型（自己造一个类型），把几个相关的数据打包成一个整体

```cpp
struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
```

## 2. 容器总览

### 2.1 顺序容器

- array：固定大小，连续存储，支持随机访问。
- vector：动态数组，尾部增删快，中间和头部慢。
- deque：双端队列，头尾增删快，支持随机访问。
- list：双向链表，任意位置插删快，不支持随机访问。
- forward_list：单向链表，更省内存，只能向前遍历。

### 2.2 有序关联容器

- set / multiset：唯一 / 可重复元素，自动按键排序，底层通常是红黑树。
- map / multimap：键值对，按键排序，键唯一 / 可重复。

### 2.3 无序关联容器

- unordered_set / unordered_multiset：哈希表，不保证顺序。
- unordered_map / unordered_multimap：哈希表键值对，平均查找 O(1)。

### 2.4 容器适配器

- stack：后进先出 LIFO。
- queue：先进先出 FIFO。
- priority_queue：优先队列，默认大顶堆。

## 3. 选择建议

- 默认优先用 vector。
- 需要头尾高频插入删除，优先 deque。
- 需要频繁在任意位置插入删除，优先 list。
- 需要按键查找且不关心顺序，优先 unordered_map / unordered_set。
- 需要按键有序遍历、区间查询，优先 map / set。
- 需要单调性、二分边界、维护最值，优先 set / multiset / priority_queue。

## 4. vector

### 4.1 声明

```cpp
vector<int> a;
vector<int> b(5);
vector<int> c(5, 10);
vector<int> d = {1, 2, 3};
vector<pair<int, int>> e;
```

### 4.2 插入

```cpp
a.push_back(3);
a.emplace_back(4);
a.insert(a.begin() + 1, 99);
a.insert(a.end(), {7, 8, 9});
```

### 4.3 删除

```cpp
a.pop_back();
a.erase(a.begin() + 2);
a.erase(a.begin(), a.begin() + 3);
a.clear();
```

删除指定值常用 erase-remove：

```cpp
a.erase(remove(a.begin(), a.end(), 5), a.end());
```

### 4.4 查找

```cpp
auto it = find(a.begin(), a.end(), 4);
if (it != a.end()) {
    // found
}

sort(a.begin(), a.end());
bool ok = binary_search(a.begin(), a.end(), 4);
auto pos = lower_bound(a.begin(), a.end(), 4);
auto pos2 = upper_bound(a.begin(), a.end(), 4);
```

### 4.5 特殊用法

```cpp
a.reserve(1000);      // 预留容量，减少扩容
a.resize(20);         // 改变大小
a.resize(20, 7);      // 新元素默认填充 7
a.shrink_to_fit();    // 尝试释放多余容量
```

- `operator[]` 不做边界检查，`at()` 会检查边界。
- 反向遍历可用 `rbegin()` / `rend()`。
- 需要稳定引用时要注意 vector 扩容会使迭代器、指针、引用失效。

## 5. deque

### 5.1 声明

```cpp
deque<int> q;
deque<int> q2 = {1, 2, 3};
```

### 5.2 插入

```cpp
q.push_back(1);
q.push_front(2);
q.emplace_back(3);
q.emplace_front(4);
q.insert(q.begin() + 1, 10);
```

### 5.3 删除

```cpp
q.pop_back();
q.pop_front();
q.erase(q.begin() + 2);
q.clear();
```

### 5.4 查找 / 特殊用法

```cpp
auto it = find(q.begin(), q.end(), 10);
```

- 支持随机访问，但比 vector 稍重。
- 适合滑动窗口、双端队列、BFS 中需要双端操作的场景。

## 6. list / forward_list

### 6.1 声明

```cpp
list<int> lst = {1, 2, 3};
forward_list<int> flst = {1, 2, 3};
```

### 6.2 插入

```cpp
lst.push_back(4);
lst.push_front(0);
lst.insert(next(lst.begin()), 99);
lst.emplace_back(5);

flst.push_front(0);
flst.insert_after(flst.before_begin(), 1);
flst.emplace_after(flst.before_begin(), 2);
```

### 6.3 删除

```cpp
lst.pop_back();
lst.pop_front();
lst.erase(next(lst.begin()));
lst.remove(2);
lst.remove_if([](int x) { return x % 2 == 0; });
lst.clear();

flst.pop_front();
flst.erase_after(flst.before_begin());
flst.remove(2);
flst.remove_if([](int x) { return x % 2 == 0; });
```

### 6.4 查找 / 特殊用法

```cpp
auto it = find(lst.begin(), lst.end(), 3);
lst.sort();
lst.unique();
lst.merge(other_lst);
lst.splice(lst.begin(), other_lst);
```

- list 适合频繁在已知位置插删，且不需要随机访问。
- `splice` 是 list 的高频特殊接口，可在 O(1) 级别转移节点。

## 7. array

### 7.1 声明

```cpp
array<int, 5> a1{};
array<int, 5> a2 = {1, 2, 3, 4, 5};
```

### 7.2 特点

- 大小固定，开销小。
- 可直接使用 `sort`、`find`、`lower_bound` 等算法。
- 适合编译期已知大小的场景。

## 8. set / multiset

### 8.1 声明

```cpp
set<int> s;
multiset<int> ms;
set<int, greater<int>> s2;
```

### 8.2 插入

```cpp
s.insert(3);
s.emplace(4);
ms.insert(5);
```

### 8.3 删除

```cpp
s.erase(3);          // 删除值为 3 的元素
auto it = s.find(3);
if (it != s.end()) s.erase(it);   // 按迭代器删除

ms.erase(5);         // multiset 会删除所有值为 5 的元素
ms.erase(ms.find(5));
```

### 8.4 查找

```cpp
auto it = s.find(10);
bool ok = s.count(10);
auto it2 = s.lower_bound(10);
auto it3 = s.upper_bound(10);
auto range = ms.equal_range(10);
```

### 8.5 特殊用法

```cpp
auto it = s.begin();      // 最小值
auto rit = s.rbegin();    // 最大值
```

- `set` 自动去重，`multiset` 允许重复。
- 适合维护有序集合、动态区间最值、离线/在线排序查询。
- `erase(value)` 的语义是按值删除，不是按位置删除。

## 9. map / multimap

### 9.1 声明

```cpp
map<int, string> mp;
multimap<int, string> mmp;
map<string, int, greater<string>> mp2;
```

### 9.2 插入

```cpp
mp[1] = "one";                   // 先查再插，键不存在会默认构造
mp.insert({2, "two"});
mp.emplace(3, "three");
mp.insert(make_pair(4, "four"));

mp.try_emplace(5, "five");
mp.insert_or_assign(6, "six");
```

### 9.3 删除

```cpp
mp.erase(1);          // 按键删除
auto it = mp.find(2);
if (it != mp.end()) mp.erase(it);
mp.clear();
```

### 9.4 查找

```cpp
auto it = mp.find(3);
if (it != mp.end()) {
    cout << it->first << " " << it->second;
}

bool ok = mp.count(3);
auto lb = mp.lower_bound(3);
auto ub = mp.upper_bound(3);
```

### 9.5 特殊用法

```cpp
for (auto &[k, v] : mp) {
    // structured binding
}

auto [it2, inserted] = mp.insert({7, "seven"});
```

- `operator[]` 只适用于 `map` / `unordered_map`，`multimap` 没有这个接口。
- `operator[]` 若键不存在，会先插入默认值，再返回引用。
- `multimap` / `multiset` 常配合 `equal_range` 使用。

## 10. unordered_set / unordered_map

### 10.1 声明

```cpp
unordered_set<int> us;
unordered_multiset<int> ums;
unordered_map<int, string> um;
unordered_multimap<int, string> umm;
```

### 10.2 插入

```cpp
us.insert(1);
us.emplace(2);

um[1] = "one";
um.insert({2, "two"});
um.emplace(3, "three");
um.try_emplace(4, "four");
um.insert_or_assign(5, "five");
```

### 10.3 删除

```cpp
us.erase(1);
auto it = us.find(2);
if (it != us.end()) us.erase(it);
um.erase(1);
um.clear();
```

### 10.4 查找

```cpp
auto it = us.find(10);
bool ok = us.count(10);

auto it2 = um.find(10);
if (it2 != um.end()) {
    cout << it2->second;
}
```

### 10.5 特殊用法

```cpp
um.reserve(100000);   // 降低 rehash 次数
um.max_load_factor(0.7);
```

- 适合大多数哈希查找场景。
- 可能发生哈希冲突，极端情况下性能退化。
- 常在竞赛和工程中用于计数、去重、映射。

## 11. stack / queue / priority_queue

### 11.1 stack

```cpp
stack<int> st;
st.push(1);
st.emplace(2);
st.pop();
int top = st.top();
bool empty = st.empty();
```

### 11.2 queue

```cpp
queue<int> qu;
qu.push(1);
qu.emplace(2);
qu.pop();
int front = qu.front();
int back = qu.back();
```

### 11.3 priority_queue

```cpp
priority_queue<int> pq;   // 大顶堆
pq.push(3);
pq.emplace(5);
pq.pop();
int top = pq.top();
```

小顶堆写法：

```cpp
priority_queue<int, vector<int>, greater<int>> minpq;
```

自定义结构体优先级：

```cpp
struct Node {
    int x, y;
};

struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.x < b.x;   // 返回 true 表示 a 的优先级更低
    }
};

priority_queue<Node, vector<Node>, Cmp> pq2;
```

## 12. 常见查找接口总结

### 12.1 通用算法

```cpp
find(begin, end, value);
count(begin, end, value);
min_element(begin, end);
max_element(begin, end);
sort(begin, end);
```

### 12.2 有序容器

```cpp
lower_bound(key);
upper_bound(key);
equal_range(key);
```

### 12.3 哈希容器 / map

```cpp
find(key);
count(key);
```

## 13. 常见删除技巧

### 13.1 删除 vector 中某个值

```cpp
v.erase(remove(v.begin(), v.end(), x), v.end());
```

### 13.2 删除满足条件的元素

```cpp
v.erase(remove_if(v.begin(), v.end(), [](int x) {
    return x % 2 == 0;
}), v.end());
```

### 13.3 删除关联容器中元素

```cpp
auto it = s.find(x);
if (it != s.end()) s.erase(it);
```

## 14. 特殊用法 / 高频技巧

### 14.1 emplace 系列

- `emplace` / `emplace_back` / `emplace_front`：原地构造，通常比先构造再插入更高效。

### 14.2 structured binding

```cpp
for (auto &[k, v] : mp) {
    cout << k << " " << v << '\n';
}
```

### 14.3 自定义排序

```cpp
sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    return a.second < b.second;
});
```

### 14.4 自定义 set/map 比较器

```cpp
struct Cmp {
    bool operator()(int a, int b) const {
        return a > b;   // 降序
    }
};

set<int, Cmp> sdesc;
```

### 14.5 pair / tuple

```cpp
pair<int, int> p = {1, 2};
auto [x, y] = p;
```

### 14.6 常见初始化

```cpp
vector<int> v(10, 0);
map<int, int> mp;
unordered_map<int, int> um;
```

## 15. 竞赛 / 工程常用套路

- 计数：`unordered_map<T, int>`。
- 去重：`set<T>` 或 `unordered_set<T>`。
- 区间最值维护：`multiset<int>`。
- Top K：`priority_queue`。
- 单调递增/递减序列维护：`deque` 或双端结构。
- 需要频繁删除任意元素：`list` 或 `set`，不要优先选 vector。
- 需要有序 key 范围查询：`map` / `set`。

## 16. 快速对照表

| 容器 | 是否有序 | 是否可重复 | 是否支持随机访问 | 常见用途 |
|---|---|---:|---:|---|
| vector | 否 | 是 | 是 | 最常用动态数组 |
| deque | 否 | 是 | 是 | 双端操作 |
| list | 否 | 是 | 否 | 频繁中间插删 |
| forward_list | 否 | 是 | 否 | 单链表 |
| set | 是 | 否 | 否 | 去重、有序集合 |
| multiset | 是 | 是 | 否 | 有序多重集合 |
| map | 是 | 键唯一 | 否 | 有序映射 |
| multimap | 是 | 是 | 否 | 有序多重映射 |
| unordered_set | 否 | 否 | 否 | 哈希去重 |
| unordered_map | 否 | 键唯一 | 否 | 哈希映射 |
| stack | 否 | - | - | LIFO |
| queue | 否 | - | - | FIFO |
| priority_queue | 否 | - | - | 堆 |

## 17. 一句话记忆

- `vector`：默认首选。
- `deque`：双端操作。
- `list`：节点插删。
- `set/map`：有序、可二分。
- `unordered_set/map`：快查找。
- `priority_queue`：动态最值。





