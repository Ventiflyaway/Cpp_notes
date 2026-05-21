解题思路：把查找从 O(n) 降到 O(1)
两层遍历：两两匹配所有组合，数量爆炸
哈希表：边走边记忆已经见过的数字（如果complement存在，直接返回下标，不存在就把value-index放进hashmap）

1.迭代器可以理解为指向容器中元素的指针，通过它可以访问元素的值

```text
unordered_map<int, int> hash = {{2, 0}, {7, 1}};

// 1. 获取迭代器
auto it = hash.find(2);     // it 指向 key=2 的那个元素

// 2. 通过迭代器访问元素
int key = it->first;        // 2
int value = it->second;     // 0

// 3. 判断迭代器是否有效
if (it != hash.end()) {     // end() 返回"尾后迭代器"（表示"没找到"）
    cout << "找到了！" << endl;
}

// 4. 解引用迭代器（获取元素本身）
pair<int, int> element = *it;  // {2, 0}
```

2.namespace = 名字的"容器"，避免命名冲突

- :: = 作用域运算符（读作"的"）
- std = C++ 标准库的 namespace
- using namespace std; = 把 std 里的名字全部拿进来
- 原则：.cpp 文件可以用 using，头文件不要用，协作项目不要用
