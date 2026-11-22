# J. HEADLINER · 题解

> 题目：[`题面/J-HEADLINER.md`](../../题面/)

## 思路

把每一段的所有歌手名字读进来，**全部排序**，然后数相邻有多少个不同的名字即可。

排序后相同的名字会挨在一起，只要 `name[i] != name[i-1]` 就说明遇到了一位新歌手，计数器加一。

所有段的 k 之和不超过 10^5，所以总人数 `count` 最多 10^5，`qsort` 完全够快。

## 复杂度

时间 O(N log N)（N 为歌手总人次），空间 O(N)。

## 代码

完整源码见 [`main.c`](./main.c)。

```c
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cmp(const void* a,const void* b)
{
    return strcmp((const char*)a,(const char*)b);
}

char name[100005][11];

int main()
{
    int n;
    scanf("%d",&n);

    int count=0;

    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);

        for(int j=0;j<k;j++)
        {
            scanf("%10s",name[count]);
            count++;
        }
    }

    qsort(name,count,sizeof(name[0]),cmp);

    int ans=0;

    for(int i=0;i<count;i++)
    {
        if(i==0||strcmp(name[i],name[i-1])!=0)
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
```

## 备注

两个细节：
1. `char name[100005][11]`——名字最长 10 个字符，要多留 1 位放 `'\0'`；
2. `scanf("%10s", ...)` 限定最多读 10 个字符，防止越界。

如果名字里可能出现空行/空格，`%s` 会自动跳过空白字符，本题名字只含小写字母，够用。

---

本题解为赛后个人整理，非官方标程。
