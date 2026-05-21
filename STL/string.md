# C++ string 完全使用指南

`string` 是 C++ 中最常用的字符串容器，支持拼接、查找、截取、替换等操作。

---

## 一、头文件和声明

```cpp
#include <string>

string s1;
string s2 = "hello";
string s3("world");
string s4 = s2 + " C++";
```

---

## 二、插入和拼接

```cpp
string s = "hello";

s += " world";
s.push_back('!');
s.append("!!!");
s.insert(5, " C++");
s.insert(s.begin(), '#');
```

---

## 三、删除和修改

```cpp
string s = "hello world";

s.erase(5, 1);
s.erase(s.begin());
s.clear();

s.replace(6, 5, "C++");
```

---

## 四、查找和截取

```cpp
string s = "hello world";

auto pos = s.find("world");
auto pos2 = s.find('o');
auto sub = s.substr(0, 5);
```

找不到时返回 `string::npos`。

---

## 五、比较和遍历

```cpp
string a = "abc";
string b = "abd";

bool ok = a == b;
bool less = a < b;

for (char c : s) {
    cout << c << ' ';
}
```

---

## 六、常用函数速查

| 函数 | 说明 |
|---|---|
| `s.size()` / `s.length()` | 字符串长度 |
| `s.empty()` | 是否为空 |
| `s.clear()` | 清空字符串 |
| `s.push_back(c)` | 尾部加字符 |
| `s.pop_back()` | 删除尾部字符 |
| `s.insert(pos, str)` | 插入字符串 |
| `s.erase(pos, len)` | 删除一段字符 |
| `s.find(str)` | 查找子串 |
| `s.substr(pos, len)` | 截取子串 |
| `s.compare(t)` | 字典序比较 |

---

## 七、输入输出和特殊用法

```cpp
string s;
getline(cin, s);
```

- `cin >> s` 只读到空格前。
- `getline()` 常用于整行输入。
- `string::npos` 常用于判断查找失败。