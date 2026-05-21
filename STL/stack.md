# C++ stack 完全使用指南

`stack` 是后进先出（LIFO）的容器适配器，常用于括号匹配、单调栈和撤销操作。

---

## 一、头文件和声明

```cpp
#include <stack>

stack<int> st;
stack<string> st2;
```

---

## 二、入栈和出栈

```cpp
stack<int> st;

st.push(1);
st.emplace(2);
st.pop();
```

---

## 三、访问和判断

```cpp
stack<int> st;
st.push(10);
st.push(20);

int x = st.top();
bool empty = st.empty();
int sz = st.size();
```

`stack` 只能访问栈顶，不能遍历，也不能随机访问。

---

## 四、常用函数速查

| 函数 | 说明 |
|---|---|
| `st.push(x)` | 入栈 |
| `st.emplace(...)` | 原地构造入栈 |
| `st.pop()` | 出栈 |
| `st.top()` | 访问栈顶 |
| `st.empty()` | 是否为空 |
| `st.size()` | 元素个数 |

---

## 五、特殊用法

```cpp
stack<int, vector<int>> st1;
stack<int, deque<int>> st2;
```

常见场景：括号匹配、单调栈、递归改迭代、反转顺序处理。