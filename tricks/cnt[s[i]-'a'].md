## C++ 字符编码（ASCII）+ 数组索引的小技巧

cnt[s[i] - 'a']

字符其实本质是整数（ASCII 编码）:'b' - 'a'其实是：98 - 97 = 1

### 统计字符频率
```text
int cnt[26];
cnt[c - 'a']++;
```

### 判断字母出现
```text
bool visited[26];
visited[c - 'a'] = true;
```

### 位运算压缩字符集
```text
mask |= (1 << (c - 'a'));
```

字符先转成数字，再直接定位到内存槽位
连续内存（array）通常比离散结构（hashmap）快很多。因为 cache locality（缓存局部性）更好