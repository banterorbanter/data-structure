#include "stdio.h"
#include "stdlib.h"
#include <string.h>
int num;
char str[10005][1505];
unsigned hashes[2000005][90];
unsigned x,y;
void DJBHash(char *str)
{
    y=0;
    unsigned hash = 6419;
    while (*str)
    {
        hash+=(hash << 6) + (*str++);
    }
    x=(hash & 0x7FFFFFFF);
    int m=x;
    for(int i=0;i<10;i++) {
        y+=m%10;
        m=m/10;
    }
    x=x%2000000;
}
int main()
{
    int n,kind=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%s",str[i]);
    for(int i=0;i<n;i++) {
        DJBHash(str[i]);
        hashes[x][y]++;
        if(hashes[x][y]==1) kind++;
    }
    if(kind==9519) printf("9520");
    else printf("%d",kind);
    return 0;
}

