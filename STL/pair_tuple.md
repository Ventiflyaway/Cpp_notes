# C++ pair / tuple 完全使用指南

`pair` 和 `tuple` 常用于表示二元组、多元组和结构化返回值。

---

## 一、头文件和声明

```cpp
#include <utility>
#include <tuple>

pair<int, int> p1;
pair<string, int> p2 = {"apple", 5};
tuple<int, string, double> t1 = {1, "abc", 3.14};
```

---

## 二、pair 的常见用法

```cpp
pair<int, int> p = {1, 2};

cout << p.first << ' ' << p.second << endl;

auto p2 = make_pair(3, 4);
auto [x, y] = p;
```

---

## 三、tuple 的常见用法

```cpp
tuple<int, string, double> t = {1, "abc", 3.14};

cout << get<0>(t) << endl;
cout << get<1>(t) << endl;
cout << get<2>(t) << endl;

auto [a, b, c] = t;
```

---

## 四、创建和返回

```cpp
pair<int, int> get_range() {
    return {1, 10};
}

tuple<int, int, int> get_three() {
    return {1, 2, 3};
}
```

---

## 五、比较和排序

```cpp
vector<pair<int, int>> v = {{2, 3}, {1, 5}, {2, 1}};
sort(v.begin(), v.end());
```

默认比较规则是先比 `first`，再比 `second`。

---

## 六、常用函数速查

| 函数 | 说明 |
|---|---|
| `make_pair(a, b)` | 构造 pair |
| `get<i>(t)` | 访问 tuple 第 i 个元素 |
| `tie(a, b)` | 绑定多个变量 |
| `std::ignore` | 忽略 tie 中某个位置 |

---

## 七、特殊用法

```cpp
int a, b;
tie(a, b) = make_pair(1, 2);
```

常见场景：二元返回值、图中边 `(u, v)`、记录坐标和状态、多字段排序和打包信息。