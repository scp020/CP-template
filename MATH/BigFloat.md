### 一、模板类别

​	数学：高精度浮点数。

### 二、模板功能

#### 1.构造

1. 数据类型

   模板参数 `uint32_t _B` ，表示进制，默认为 `10` 。

   模板参数 `uint32_t _W` ，表示压位宽度，默认为 `6` 。

   模板参数 `uint32_t _MAXN` ，表示最大有效数字位数，默认为 `1 << 6` 。

   模板参数 `uint64_t _P` ，表示进行蒙哥马利模乘时的模数，默认为 `9223372006790004737` 。

   模板参数 `uint64_t _R` ，表示 `_P` 对应的原根，默认为 `3` 。

2. 时间复杂度

   $O(1)$ 。

3. 备注

   本模板用于高精度浮点数运算。

   进制 `_B` 须为大于 `1` 的整数。在 `10` 进制及以下，每一位默认对应数字字符；在 `11` 进制到 `36` 进制，增加的数字用小写字母对应；在 `37` 进制到 `62` 进制，增加的数字用大写字母对应。当进制更大时，暂无对应的字符规则，此时与字符串相关的操作会受到影响，但是其他操作仍可以进行。

   高精度浮点数由两部分组成，一部分是大数成员属性，表示有效数字；一部分是小数点移动量，表示小数点需要在大数的基础上，移动多少。

   在无参情况下，高精度浮点数默认初始化为零。

   设 `_K = _MAXN / _W` 向上取整，则 `_K` 表示压位之后的宽度。为设计方便，非零的高精度浮点数，保证有效数字位数是压位宽度 `_W` 的整数倍，最大为 `_W` 的 `_K` 倍。也就是最大有效数字位数可能略大于 `_MAXN` 。

   下文中，用 `bfloat` 代指本高精度浮点数类。

   **注意：** 各个模板参数的意义详见 `BigInt` 模板文档。

#### 2.构造

1. 数据类型

   构造参数 `_Tp __number` ，表示从 `_Tp` 转化为高精度浮点数。`_Tp` 可以为 `int` ， `long long` 等有符号数，也可以为 `uint32_t` ， `uint64_t` 等无符号数，也可以为 `__int128_t` 等类型。

   其余同上。

2. 时间复杂度

   $O(\frac{\log_b n}{_W})$ ，此处 `b` 为进制大小， `n` 为数字的绝对值大小， `W` 为压位宽度。

   或者说 $O(\frac n W)$ ，此处 `n` 为 `b` 进制下数字的长度， `W` 为压位宽度。

3. 备注

   **注意：** 如果输入的参数为负数，转化过程中会转化为相反数。所以如果 `_Tp`  为 `int` ，当 `__number==-2147483648` 时，转化为相反数会出错。如果 `_Tp`  为 `long long` ，当 `__number==9223372036854775808` 时，转化为相反数会出错。

#### 3.构造

1. 数据类型

   构造参数 `_Tp __number` ，表示从 `_Tp` 转化为高精度浮点数。`_Tp` 可以为 `float` ， `double` ， `long double` 等浮点数类。

   其余同上。

2. 时间复杂度

   $O(\frac{\log_b n}{_W})$ ，此处 `b` 为进制大小， `n` 为数字的绝对值大小， `W` 为压位宽度。

   或者说 $O(\frac n W)$ ，此处 `n` 为 `b` 进制下数字的长度， `W` 为压位宽度。

3. 备注

   **注意：** 字符串中，允许有前导零，允许首位为 `+` 或者 `-` 表示正负号，除此之外只能为数字字符，不能有空格、回车等字符。

#### 4.构造

1. 数据类型

   构造参数 `const char *__number` ，表示从常量字符串转化为大数类。

   其余同上。

2. 时间复杂度

   同上。

3. 备注

   **注意：** 字符串中，允许有前导零，允许首位为 `+` 或者 `-` 表示正负号，除此之外只能为数字字符，不能有空格、回车等字符。

#### 5.构造

1. 数据类型

   构造参数 `const std::string &__number` ，表示从字符串转化为大数类。

   其余同上。

2. 时间复杂度

   同上。

3. 备注

   **注意：** 字符串中，允许有前导零，允许首位为 `+` 或者 `-` 表示正负号，除此之外只能为数字字符，不能有空格、回车等字符。

#### 6.构造

1. 数据类型

   构造参数 `bint &&__other` ，表示从右值移动构造大数。

   其余同上。

2. 时间复杂度

   $O(1)$ 。

3. 备注

   当移动构造完成后， `__other` 值为零。

#### 7.构造

1. 数据类型

   构造参数 `const bint &__other` ，表示从另一个大数拷贝构造大数。

   其余同上。

2. 时间复杂度

   $O(\frac{\log_b n}{_W})$ ，此处 `b` 为进制大小， `n` 为数字的绝对值大小， `W` 为压位宽度。

   或者说 $O(\frac n W)$ ，此处 `n` 为 `b` 进制下数字的长度， `W` 为压位宽度。

#### 8.生成随机数

1. 数据类型

   输入参数 `uint32_t __integerLength` ，表示整数部分的位数。

   返回类型 `bfloat` ，表示整数位长度为 `__integerLength` 的大数。

2. 时间复杂度

   或者说 $O(\frac n W)$ ，此处 `n` 为有效数字位数， `W` 为压位宽度。

3. 备注

   本方法产生的随机数，最少保证 `_W` 位的有效数字，

   本方法保证生成的 `__length` 位长度的随机数首位非零。

#### 9.比较绝对值大小

1. 数据类型

   输入参数 `const bfloat &__a` ，表示参与比较的第一个高精度浮点数。

   输入参数 `const bfloat &__b` ，表示参与比较的第二个高精度浮点数。

   返回类型 `int` ，可以为 `-1` ， `0` ， `1` ，分别表示前者绝对值小于、等于、大于后者绝对值。

2. 时间复杂度

   $O(1\sim\frac{n}{_W})$ ，此处 `n` 为有效数字位数， `W` 为压位宽度。

3. 备注

   如果两个高精度浮点数的整数部分长度不同，则可以直接确定二者绝对值的大小。否则需要从高位到低位诸位比较。

#### 10.收缩

1. 数据类型

2. 时间复杂度

   $O(\frac n W)$ ，`n` 表示浮点数的有效数字长度， `W` 表示压位宽度。

3. 备注

   本成员方法用于将有效数字里多余的尾零删除。
   
   注意，本方法并不是将所有尾零删除。为了使有效数字为压位宽度 `_W` 的整数倍，可能会保留少量尾零。

#### 11.变为相反数

1. 数据类型

2. 时间复杂度

   $O(1)$ 。

3. 备注

   本成员方法将高精度浮点数本身置为自己的相反数。

   当高精度浮点数绝对值为零时，无法设置为负。

#### 12.设置是否为负

1. 数据类型

   输入参数 `bool __negative` ，表示是否设置为负数。

2. 时间复杂度

   $O(1)$ 。

3. 备注

   本成员方法根据参数，将高精度浮点数设置为正或负。

   当高精度浮点数绝对值为零时，无法设置为负。

#### 13.取最高位位置

1. 数据类型

2. 时间复杂度

   $O(1)$ 。

3. 备注

   取最高非零位所在位置。对应关系为，个位为 `0` ，十位为 `1` ，百位为 `2` ；十分位为 `-1` ，百分位为 `-2` ，以此类推。

   **注意：** 若高精度浮点数为零，返回 `-1` ，但无实际意义。

#### 14.幂

1. 数据类型

   输入参数 `uint64_t __n` ，表示指数大小。

   返回类型 `bfloat` ，表示幂的值。

2. 时间复杂度

   或者说 $O(\frac n W\cdot\log \frac n W\cdot \log m)$ ，此处 `n` 为有效数字位数， `W` 为压位宽度， `m` 为指数的大小。

3. 备注

   本成员方法使用快速幂的方法进行次方求值。

#### 15.开方

1. 数据类型

   输入参数 `uint32_t __n` ，表示开方次数。

   返回类型 `bfloat` ，表示得到的开方结果。

2. 时间复杂度

   或者说 $O(\frac n W\cdot\log^2 \frac n W\cdot \log m)$ ，此处 `n` 为 `b` 进制下数字的长度， `W` 为压位宽度，`m` 为开方次数。

3. 备注

   本成员方法使用 `std::log` 函数进行预估初值，然后进行牛顿迭代求解。

#### 16.各种运算符

1. 数据类型

2. 时间复杂度

   对于 `+=` ， `-=` ， `+` ， `-` ， `*=(long long)` ， `/=(long long)` ， `<<=` ， `>>=` ， `+`（正号） ， `-` （负号），`==` ， `!=` ， `<` ， `>` ， `<=` ， `>=` ， `*(long long)` ， `/(long long)` ， `<<` ， `>>` ，等运算符，时间复杂度为 $O(n)$  ，此处 `n` 表示有效数字位数。

   对于 `*=(bfloat)` ， `/=(bfloat)` ， `*(bfloat)` ，`/(bfloat)` 等运算符，时间复杂度为 $O(n\cdot \log n)$ ，此处 `n` 表示有效数字位数。

3. 备注

   运算符的效果非常显然，不一一阐述。

   **注意：** 此处 `<<` ， `>>` ， `<<=` ， `>>=` 符号，同样是按位移动，但是并不是按二进制位移动，而是按当前进制进行按位移动。

#### 17.强制类型转换为布尔

1. 数据类型

2. 时间复杂度

   $O(1)$ 。

#### 18.强制类型转换为数字类型

1. 数据类型

   模板参数 `typename _Tp` ，表示要转换为的类型。

   返回类型 `_Tp` ，表示转换结果。

2. 时间复杂度

   或者说 $O(\frac n W)$ ，此处 `n` 为有效数字位数， `W` 为压位宽度。

3. 备注

   在对超过 `int` 上限的大数强制转换为 `int` 时会出错， `long long` 同理。

#### 19.强制类型转换为浮点类型

1. 数据类型

   模板参数 `typename _Tp` ，表示要转换为的类型。

   返回类型 `_Tp` ，表示转换结果。

2. 时间复杂度

   或者说 $O(\frac n W)$ ，此处 `n` 为有效数字位数， `W` 为压位宽度。


#### 20.转换为字符串

1. 数据类型

   返回类型 `std::string` ，表示转换结果。

2. 时间复杂度

   或者说 $O(\frac n W)$ ，此处 `n` 为有效数字位数， `W` 为压位宽度。

#### 21.流式输入输出

1. 数据类型

2. 时间复杂度

   或者说 $O(\frac n W)$ ，此处 `n` 为，有效数字位数 `W` 为压位宽度。

### 三、模板示例

```c++
#include "IO/FastIO.h"
#include "MATH/BigFloat.h"

int main() {
    using bfloat = OY::BigFloat<10, 3, 16>;
    // 无参构造为零
    bfloat zero;
    cout << "zero : " << zero << endl;
    // 可以从 int/long long 等构造
    bfloat one(1ll);
    cout << "one : " << one << endl;
    // 可以从 int128 构造
    bfloat a(__int128_t(123456789987654321));
    cout << "a : " << a << endl;
    // 可以从 float/double/long double 等构造
    bfloat pi(3.1415);
    cout << "pi : " << pi << endl;
    // 可以从常量字符串或者 std::string 构造
    bfloat b("112233445566778899998877665544332211");
    cout << "b : " << b << endl;

    // 生成 5 个位长为 7 的高精度浮点数
    std::vector<bfloat> some(5);
    for (int i = 0; i < 5; i++) some[i] = bfloat::rand(7);
    for (int i = 0; i < 5; i++) cout << "some[" << i << "] = " << some[i] << endl;

    // 比较绝对值大小
    bfloat d(123.45);
    bfloat e(-1234.56);
    auto comp_res = bfloat::absCompare(d, e);
    if (comp_res == 1)
        cout << "abs(" << d << ") > abs(" << e << ")" << endl;
    else if (comp_res == 0)
        cout << "abs(" << d << ") = abs(" << e << ")" << endl;
    else
        cout << "abs(" << d << ") < abs(" << e << ")" << endl;

    // 变为相反数
    cout << "d = " << d << endl;
    d.opposite();
    cout << "after opposite, d = " << d << endl;

    // 改变符号
    d.setSign(false);
    cout << "after setSign, d = " << d << endl;

    // 取首位
    auto len = a.length();
    cout << "length of " << a << " is " << len << endl;

    a >>= 20;
    len = a.length();
    cout << "length of " << a << " is " << len << endl;

    // 幂运算
    auto pow = a.pow(3);
    cout << a << "^3 = " << pow << endl;

    // 开根运算
    auto sqrt = pow.sqrt(6);
    cout << pow << "^(1/3) = " << sqrt << endl;

    // 强转为 bool
    if (zero)
        cout << zero << " is true\n";
    else
        cout << zero << " is false\n";
    if (one)
        cout << one << " is true\n";
    else
        cout << one << " is false\n";

    // 强转为 int
    int g(some[0]);
    cout << "g = " << g << endl;

    // 强转为 double
    double h(some[0]);
    cout << "h = " << h << endl;

    // 一段计算
    std::string s(some[0]);
    cout << "s = " << s << endl;

    // 给出一段计算圆周率的代码，检验高精度浮点数的正确性
    {
        // 当设定 N = 1024 时，可以获取 1020 位准确的小数，最后三位有误差
        static constexpr int N = 1024;
        using bfloat = OY::BigFloat<10, 7, N>;
        bfloat res(1), cur(1);
        for (int i = 1; i < N * 3.4; i++) {
            cur *= i;
            cur /= i * 2 + 1;
            res += cur;
        }
        res *= 2;
        cout << res << '\n';
    }
}
```

```
#输出如下
zero : 0
one : 1
a : 123456789987654321
pi : 3.14149999999999436
b : 112233445566778899000000000000000000
some[0] = 2857343.02
some[1] = 5032989.85429391
some[2] = 3405650
some[3] = 3390000
some[4] = 6190000
abs(123.449999999999795) < abs(-1234.55999999999795)
d = 123.449999999999795
after opposite, d = -123.449999999999795
after setSign, d = 123.449999999999795
length of 123456789987654321 is 17
length of 0.00123456789987654321 is -3
0.00123456789987654321^3 = 0.00000000188167641694938855
0.00000000188167641694938855^(1/3) = 0.035136418427
0 is false
1 is true
g = 2857343
h = 2857343.020000
s = 2857343.02
3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912983367336244065664308602139494639522473719070217986094370277053921717629317675238467481846766940513200056812714526356082778577134275778960917363717872146844090122495343014654958537105079227968925892354201995611212902196086403441815981362977477130996051870721134999999837297804995105973173281609631859502445945534690830264252230825334468503526193118817101000313783875288658753320838142061717766914730359825349042875546873115956286388235378759375195778185778053217122680661300192787661119590921642019893809525720106548586327883182

```
