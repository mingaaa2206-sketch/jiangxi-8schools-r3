# B. Perfect Shining! · 题解

> 题目：[`题面/B-Perfect-Shining.md`](../../题面/)

## 思路

两个数 a、b 只有两种拼接方式：`a` 在前或 `b` 在前。分别算出两个结果，输出较大的那个即可。

关键是怎么"拼"：

- 设 a 有 `la` 位，那么把 b 接在 a 后面等于 `a * 10^lb + b`（b 有 `lb` 位）；
- 反过来就是 `b * 10^la + a`。

所以先数位数，再算两个 10 的幂，最后比较。

因为 a、b ≤ 9999，拼接结果最多 8 位，`int` 完全够用。

## 复杂度

时间 O(log a + log b)，空间 O(1)。

## 代码

完整源码见 [`main.c`](./main.c)。

```c
#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int x=a;
    int la=0;
    while(x>0)
    {
        la++;
        x/=10;
    }

    int y=b;
    int lb=0;
    while(y>0)
    {
        lb++;
        y/=10;
    }

    int p1=1,p2=1;
    for(int i=0;i<la;i++)
    {
        p1*=10;
    }
    for(int i=0;i<lb;i++)
    {
        p2*=10;
    }

    int n1=a*p2+b,n2=b*p1+a;

    if(n1>n2)
    {
        printf("%d",n1);
    }
    else
    {
        printf("%d",n2);
    }
    return 0;
}
```

## 备注

也可以用字符串拼接后比较，或者按 `to_string(a)+to_string(b)` 与 `to_string(b)+to_string(a)` 比字典序。这里用整数运算，避免字符串比较长度不一致的麻烦。

---

本题解为赛后个人整理，非官方标程。
