#include <stdio.h>
#include <stdlib.h>
int fa[10005];
void init(int n) {
    int i;
    for(i=1;i<=n;i++) fa[i]=i;
}
int find(int x)
{
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
int main() {
    int n,m,i;
    int a,b,c;
    scanf("%d%d",&n,&m);
    init(n);
    for(i=1;i<=m;i++) {
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) merge(b,c);
        if(a==2) {
            if(find(b)==find(c)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}

