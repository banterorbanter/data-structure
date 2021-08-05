#include <stdio.h>
#include <stdlib.h>
int a[1000005],b[1000005];
int win[1000005],con[1000005][2];
int main()
{
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&win[i]);
    }
    int ta1=1,ta2=1,he1=1,he2=1;
    int len1=0;
    a[he1]=1,b[he2]=1;
    for(i=2;i<=k;i++)
    {
        while(win[i]>win[a[ta1]]&&ta1>0) ta1--;
        a[++ta1]=i;
        while(win[i]<win[b[ta2]]&&ta2>0) ta2--;
        b[++ta2]=i;
    }
    con[len1][0]=win[a[he1]];con[len1][1]=win[b[he2]];len1++;
    for(i=k+1;i<=n;i++)
    {
        while(a[he1]<=i-k&&he1<=ta1) he1++;
        while(b[he2]<=i-k&&he2<=ta2) he2++;
        while(win[i]>win[a[ta1]]&&ta1>=he1) ta1--;
        a[++ta1]=i;
        while(win[i]<win[b[ta2]]&&ta2>=he2) ta2--;
        b[++ta2]=i;
        con[len1][0]=win[a[he1]];con[len1][1]=win[b[he2]];len1++;
    }
    for(i=0;i<len1-1;i++)
    {
        printf("%d ",con[i][1]);
    }
    printf("%d\n",con[i][1]);
    for(i=0;i<len1-1;i++)
    {
        printf("%d ",con[i][0]);
    }
    printf("%d",con[i][0]);
    return 0;
}

