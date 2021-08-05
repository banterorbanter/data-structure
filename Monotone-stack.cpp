#include <stdio.h>
#include <stdlib.h>
int num[3000005],out[3000005],nums[3000005];
int main()
{
    int n,i,list=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i]<num[nums[list]]||list==0)
        {
            nums[++list]=i;
        }
        else
        {
            while(num[i]>num[nums[list]]&&list!=0)
            {
                out[nums[list--]]=i;
            }
            nums[++list]=i;
        }
    }
    for(i=1;i<n;i++)
    {
        printf("%d ",out[i]);
    }
    printf("%d",out[i]);
    return 0;
}

