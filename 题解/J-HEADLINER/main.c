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
