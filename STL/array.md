# C++ array 完全使用指南

`array` 是固定大小的顺序容器，底层连续存储，支持随机访问。

---

## 一、头文件和声明

```cpp
#include <array>

array<int, 5> a1{};
array<int, 5> a2 = {1, 2, 3, 4, 5};
array<string, 3> a3 = {"a", "b", "c"};
```

---

## 二、初始化方式

```cpp
array<int, 5> a1{};                 // 全部初始化为 0
array<int, 5> a2 = {1, 2, 3, 4, 5};
array<int, 5> a3 = {1, 2};          // 剩余元素补 0
```

---

## 三、访问元素

```cpp
array<int, 5> a = {1, 2, 3, 4, 5};

cout << a[0] << endl;
cout << a.at(1) << endl;
cout << a.front() << endl;
cout << a.back() << endl;
```

---

## 四、遍历

```cpp
for (int x : a) cout << x << ' ';
for (auto& x : a) x += 1;
for (size_t i = 0; i < a.size(); ++i) cout << a[i] << ' ';
```

---

## 五、常用函数速查

| 函数 | 说明 |
|---|---|
| `a.size()` | 元素个数 |
| `a.empty()` | 是否为空 |
| `a.fill(x)` | 全部填充为 `x` |
| `a.swap(b)` | 交换两个数组 |
| `a.front()` | 第一个元素 |
| `a.back()` | 最后一个元素 |

---

## 六、特殊用法

```cpp
sort(a.begin(), a.end());
auto it = find(a.begin(), a.end(), 3);
auto lb = lower_bound(a.begin(), a.end(), 3);
```

- `array` 适合编译期已知长度的场景。
- 相比原生数组，`array` 更安全、接口更统一。
- 适合静态缓冲区、定长状态、模板题常量数组。
