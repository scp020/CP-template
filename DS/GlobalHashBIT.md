### 一、模板类别

​	数据结构：哈希树状数组

​	练习题目：

1. [940. 不同的子序列 II](https://leetcode.cn/problems/distinct-subsequences-ii)
2. [#130. 树状数组 1 ：单点修改，区间查询](https://loj.ac/p/130)
3. [#131. 树状数组 2 ：区间修改，单点查询](https://loj.ac/p/131)
4. [#132. 树状数组 3 ：区间修改，区间查询](https://loj.ac/p/132)
5. [P3368 【模板】树状数组 2](https://www.luogu.com.cn/problem/P3368)
6. [P3369 【模板】普通平衡树](https://www.luogu.com.cn/problem/P3369)
7. [P3372 【模板】线段树 1](https://www.luogu.com.cn/problem/P3372)
8. [P3374 【模板】树状数组 1](https://www.luogu.com.cn/problem/P3374)
9. [P3835 【模板】可持久化平衡树](https://www.luogu.com.cn/problem/P3835)
10. [P5057 [CQOI2006] 简单题](https://www.luogu.com.cn/problem/P5057)
11. [U187320 【模板】树状数组 3](https://www.luogu.com.cn/problem/U187320)




### 二、模板功能

#### 1.建立树状数组

1. 数据类型

   模板参数 `typename KeyType` ，表示树状数组的下标类型。

   模板参数 `typename MappedType` ，表示树状数组的值类型。

   模板参数 `bool RangeUpdate`​ ，表示是否要支持区间修改。

   模板参数 `bool MakeRecord` ，表示是否对哈希表里插入过的结点进行记录。

   模板参数 `size_type L`​ ，表示哈希表的结点数为 `1 << L` 。

   构造参数 `size_type length` ，表示树状数组的覆盖范围为 `[0, length)`。

2. 时间复杂度

    $O(n)$ ，此处 `n` 指哈希表的大小 `1<<L` 。

3. 备注

   树状数组处理的问题为单点增值修改，单点/区间和的查询。当 `RangeUpdate` 参数设置为 `true` 时，可以同时兼备区间增值修改的功能，但是时空效率都会下降。

   树状数组通过加和函数求解前缀和，再通过前缀和做差求解任意区间和。

   树状数组通过一些差分运算，实现了区间修改。
   
   本模板完全为普通版的树状数组把占用数组替换为哈希表后的平替，牺牲了效率，换来了表达空间的增大。


#### 2.单点增值(add)

1. 数据类型

   输入参数 `KeyType i​` ，表示单点增值的下标。

   输入参数 `const MappedType &inc​` ，表示增量大小。

2. 时间复杂度

   均摊 $O(\log n)$ 。

3. 备注

   本函数没有进行参数检查，所以请自己确保下标合法。（位于`[0，n)`）


#### 3.区间增值(add)

1. 数据类型

   输入参数 `KeyType left` ，表示区间增值的开头下标。

   输入参数 `KeyType right​` ，表示区间增值的结尾下标。(闭区间)

   输入参数 `const MappedType &inc` ，表示增量大小。

2. 时间复杂度

   均摊 $O(\log n)$ 。

3. 备注

   本方法仅当 `RangeUpdate` 为 `true` 时合法。

   本函数没有进行参数检查，所以请自己确保下标合法。（位于`[0，n)`，且 `left <= right + 1` ）
   
   
#### 4.前缀和查询(presum)

1. 数据类型

   输入参数 `KeyType i`，表示前缀和查询的结尾下标。(闭区间)

2. 时间复杂度

   均摊 $O(\log n)$ 。

3. 备注

   本函数没有进行参数检查，所以请自己确保下标合法。（位于`[0，n)`）


#### 5.单点查询(query)

1. 数据类型

   输入参数 `KeyType i` ，表示单点查询的下标。

2. 时间复杂度

   均摊 $O(\log n)$ 。

3. 备注

   本函数没有进行参数检查，所以请自己确保下标合法。（位于`[0，n)`）


#### 6.区间查询(query)

1. 数据类型

   输入参数 `KeyType left​` ，表示区间查询的开头下标。

   输入参数 `KeyType right​`，表示区间查询的结尾下标。(闭区间)

2. 时间复杂度

   均摊 $O(\log n)$ 。
   
3. 备注

   本函数没有进行参数检查，所以请自己确保下标合法。（位于`[0，n)`，且 `left <= right + 1` ）


#### 7.查询全部和(query_all)

1. 数据类型

2. 时间复杂度

   均摊 $O(1)$ 。

#### 8.查询第 k 个元素(kth)

1. 数据类型

   输入参数 `MappedType k​` ，表示要查询的元素从小到大的顺次。

2. 时间复杂度

   均摊 $O(\log n)$ 。

3. 备注

   可以解释为，本方法在求可令 `presum(i) > k` 成立的最小的 `i` 。

   顺次 `k​` 表示第 `k + 1` 小，顺次 `0` 表示查询最小的元素。

   本函数没有进行参数检查，所以请自己确保 `k` 合法。（位于`[0，query_all())`）
#### 9.清空(clear)

1. 数据类型

2. 时间复杂度

    $O(n)$ ，此处 `n` 指此前树状数组操作涉及的结点数。

3. 备注

   本方法仅当 `MakeRecord` 为 `true` 时使用。


### 三、模板示例

```c++
#include "DS/GlobalHashBIT.h"
#include "IO/FastIO.h"

// 本模板完全等同于普通树状数组
// 注意，对象必须声明在全局
OY::GHashBIT<uint64_t, int64_t, true, true, 10> Gbit(100000000000000);
void test() {
    Gbit.add(100, 9999);
    Gbit.add(101, 200, 1);
    Gbit.add(1000000100, -99999);
    cout << Gbit.query(100, 1000000100) << endl;
    Gbit.clear();
    cout << Gbit.query_all() << endl;
}

int main() {
    test();
}
```

```
#输出如下
-89900
0


```

