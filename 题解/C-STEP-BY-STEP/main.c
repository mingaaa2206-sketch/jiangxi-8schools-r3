#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        char s[40];
        scanf("%s",s);

        int len=strlen(s);

        int i=len-1;

        while(i>=0&&s[i]=='9')
        {
            i--;
        }

        if(i>=0)
        {
            s[i]++;

            for(int j=i+1;j<len;j++)
            {
                s[j]='1';
            }

            printf("%s\n",s);
        }
        else
        {
            for(int j=0;j<=len;j++)
            {
                s[j]='1';
            }
            s[len+1]='\0';

            printf("%s\n",s);
        }
    }

    return 0;
}
