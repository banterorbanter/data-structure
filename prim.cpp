#include <stdio.h>
int val[5005][5005],list[5005],len;
struct value{
    int route;
    int dir;
}point[5005];
int min(int a,int b) {
    if(a<b) return a;
    else return b;
}
int minx,minz=999999999,sum,hash[5005];
int main()
{
    int n,m,a,b,c,flag;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d",&a,&b,&c);
        if(a!=b&&((c<val[a][b]&&c<val[b][a])||!(val[a][b]||val[b][a])))
        {val[a][b]=c;
        val[b][a]=c;}
    }
    list[++len]=1;
    while(len<n) {
        minz=999999999,flag=0;
        for(int i=1;i<=n;i++) {
            if(hash[i]) continue;
            if(i!=list[len]) {
                if(val[list[len]][i]&&(point[i].dir>val[list[len]][i]||point[i].dir==0)) {
                    point[i].route=list[len];
                    point[i].dir=val[list[len]][i];
                }
                else if(!val[list[len]][i]&&point[i].dir==0) {
                    point[i].dir=999999999;
                    point[i].route=list[len];
                }
            }
            else point[i].route=i;
        }
        hash[list[len]]++;
        for(int i=1;i<=n;i++) {
            if(hash[i]) continue;
            if(minz>point[i].dir&&i!=list[len]) {
                minz=point[i].dir,minx=i;
                flag=1;
            }
        }
        list[++len]=minx;
        sum+=val[point[minx].route][minx];
        if(flag==0) break;
    }
    if(flag) printf("%d",sum);
    else printf("orz");
    return 0;
}

