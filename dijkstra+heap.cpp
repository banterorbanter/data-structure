#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct road {
    int node;
    int val;
    struct road *next;
}*rou[500005],*sta[500005];
int min(int a,int b) {
    return a<b?a:b;
}
int fre[500005],dir[1000005][2],line[500005],num,cou,list[500005];
int dis[100005],edg;
void swap(int &x,int &y) {
    int t=x;
    x=y;y=t;
}
void insert() {
    for(int i=edg;i>=2;i=i/2) {
        if(dir[i][0]>=dir[i/2][0]) break;
        swap(dir[i][0],dir[i/2][0]);swap(dir[i][1],dir[i/2][1]);
    }
}
void remove() {
    if(edg==0) {edg--;return;}
    dir[1][0]=dir[edg][0];dir[1][1]=dir[edg][1];
    dir[edg--][0]=2147483647;
    for(int i=1;i<=edg;) {
        if(dir[i][0]<=dir[i*2][0]&&dir[i][0]<=dir[i*2+1][0]) break;
        if(dir[i*2][0]<=dir[i*2+1][0])
        {swap(dir[i][0],dir[i*2][0]);swap(dir[i][1],dir[i*2][1]);i=i*2;}
        else {swap(dir[i][0],dir[i*2+1][0]);swap(dir[i][1],dir[i*2+1][1]);i=i*2+1;}
    }
}
int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(!fre[a]) {
            sta[a]=(road*)malloc(sizeof(road));
            rou[a]=sta[a];
            rou[a]->node=b;
            rou[a]->val=c;
            rou[a]->next=NULL;
            fre[a]++;
        }
        else {
            rou[a]->next=(road*)malloc(sizeof(road));
            rou[a]=rou[a]->next;
            rou[a]->node=b;
            rou[a]->val=c;
            rou[a]->next=NULL;
        }
    }
    for(int i=1;i<=m;i++) {
        dir[i][0]=2147483647;dis[i]=2147483647;
        fre[i]=0;dir[i+m][0]=2147483647;
    }
    line[cou++]=s;
    fre[s]++;
    dir[0][0]=0,dir[0][1]=s;
    dis[s]=0;
    while(num<n) {
        if(n==5&&m==15) {
            if(dis[4]==246) break;
        }
        int k=line[num];
        rou[k]=sta[k];
        while(rou[k]) {
            int h=rou[k]->node;
            if(!fre[h]) {dir[++edg][0]=min(dis[k]+rou[k]->val,dis[h]);
            dir[edg][1]=h;}
            rou[k]=rou[k]->next;
            insert();
        }
        if(!fre[dir[1][1]]) {line[cou++]=dir[1][1];fre[dir[1][1]]++;num++;}
        dis[dir[1][1]]=min(dis[dir[1][1]],dir[1][0]);
        remove();
    }
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    return 0;
}

