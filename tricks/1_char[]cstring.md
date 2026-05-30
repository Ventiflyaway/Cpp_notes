## 一、C++ 判断字符串相等有以下几种写法：

### 1.== 运算符（推荐）
```text
std::string s1 = "hello", s2 = "hello";
if (s1 == s2) { /* 相等 */ }
```

#### 注意：=：赋值（assignment）
==：比较是否相等（comparison）

### 2.compare() 方法
```text
if (s1.compare(s2) == 0) { /* 相等 */ }
```

### 3.C 风格字符串使用 strcmp()
```text
cpp
const char* s1 = "hello";
const char* s2 = "hello";
if (strcmp(s1, s2) == 0) { /* 相等 */ }
```
## 二、C字符串和 string

### 1. C 风格字符串
本质：字符数组，以空字符 '\0' 结尾。

类型：char[] 或 char*。

示例
```text
char str1[] = "hello";     // 自动添加 '\0'
char* str2 = "world";      // 字符串字面量（只读）
```
常用操作（需 <cstring）
```text
求长度	strlen(s)
复制	strcpy(dest, src)  
拼接	strcat(dest, src)  
比较	strcmp(s1, s2)（返回 0 表示相等）
```
缺点：
- 不安全（容易缓冲区溢出）
- 操作繁琐（需手动管理内存）
- 不方便（不能直接用 =、+、==）

### 2. C++ string
本质: 类模板 std::basic_string<char> 的实例

需包含 <string

示例
```text
#include <string>
std::string s1 = "hello";
std::string s2 = "world";
```
常用操作（直观、安全）
```text
赋值	s1 = s2
拼接	s1 + s2 或 s1 += s2
比较	s1 == s2、s1 < s2 等
求长度	s1.size() 或 s1.length()
取 C 风格字符串	s1.c_str()
```
优点
- 自动管理内存
- 支持运算符重载（=、+、==、[] 等）
- 更安全、方便

### 3. 相互转换
string → C 风格
```text
std::string s = "hello";
const char* cstr = s.c_str();   // 只读
```
C 风格 → string
```text
const char* cstr = "hello";
std::string s = cstr;           // 自动转换
```