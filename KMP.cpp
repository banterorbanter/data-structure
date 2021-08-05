#include <stdio.h>
#include <string.h>
int next[1000005];
char s1[1000005],s2[1000005];
int main()
{
    int i=0,j=0,k=-1;
    scanf("%s",s1);
    scanf("%s",s2);
    next[0]=-1;
    int len2=strlen(s2),len1=strlen(s1);
    while(j<len2)
    {
        if(k==-1||s2[k]==s2[j])
        {
            j++,k++;
            next[j]=k;
        }
        else k=next[k];
    }
    for(i=0;i<len1;)
    {
        for(j=0;j<len2;j++)
        {
            if(j==-1||s1[i]==s2[j])
            {
                i++;continue;
            }
            else {j=next[j];i=i-j;break;}
        }
        if(j>=len2) {printf("%d\n",i-len2+1);i=i-next[j];}
    }
    for(i=1;i<len2;i++)
    {
        printf("%d ",next[i]);
    }
    printf("%d",next[i]);
    return 0;
}

