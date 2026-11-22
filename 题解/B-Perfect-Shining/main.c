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
