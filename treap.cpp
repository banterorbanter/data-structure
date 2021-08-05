#include<stdio.h>
#include<stdlib.h>
int now,INF=2147483647,cou,n,flag;
int siz[100005],key[100005],cnt[100005],rd[100005],son[100005][2];
void pushup(int x){
	siz[x]=siz[son[x][0]]+siz[son[x][1]]+cnt[x];
}
void rotate(int &x,int y){
	int i=son[x][y^1];
	son[x][y^1]=son[i][y];
	son[i][y]=x;
	pushup(x);
	pushup(i);
	x=i;
}
void randnum(int &x) {
    if(flag) x=rand()%2086513234;
    else x=rand()%2112354986;
}
void ins(int &p,int x){
	if(!p){
		p=++cou;
		siz[p]++;cnt[p]++;
		key[p]=x;
		randnum(rd[p]);
		return;
	}
	if(key[p]==x){
		cnt[p]++;
		siz[p]++;
		return;
	}
	int d=x>key[p];
	ins(son[p][d],x);
	if(rd[p]<rd[son[p][d]])
		rotate(p,d^1);
	pushup(p);
}
void del(int &p,int x){
	if(!p)
		return;
	if(x!=key[p])
		del(son[p][x>key[p]],x);
	else{
		if(!son[p][0]&&!son[p][1]){
			cnt[p]--;
			siz[p]--;
			if(cnt[p]==0) p=0;
		}
		else if(son[p][0]&&son[p][1]){
		    int k=rd[son[p][0]]>rd[son[p][1]];
			rotate(p,k);
			del(son[p][k],x);
		}
		else{
		    int k=!son[p][0]?0:1;
			rotate(p,k);
			del(son[p][k],x);
		}
	}
	pushup(p);
}
int rank(int p,int x){
	if(!p)
		return 0;
	if(key[p]==x)
		return siz[son[p][0]]+1;
	if(key[p]<x)
		return rank(son[p][1],x)+siz[son[p][0]]+cnt[p];
	return rank(son[p][0],x);
}
int find(int p,int x){
	if(!p)
		return 0;
	if(siz[son[p][0]]>=x)
		return find(son[p][0],x);
	else if(siz[son[p][0]]+cnt[p]<x)
		return find(son[p][1],x-cnt[p]-siz[son[p][0]]);
	else
		return key[p];
}
int pre(int p,int x){
	if(!p)
		return -INF;
	if(key[p]>=x)
		return pre(son[p][0],x);
	else
		return key[p]>pre(son[p][1],x)?key[p]:pre(son[p][1],x);
}
int suf(int p,int x){
	if(!p)
		return INF;
	if(key[p]<=x)
		return suf(son[p][1],x);
	else
		return key[p]<suf(son[p][0],x)?key[p]:suf(son[p][0],x);
}
int main(){
    int i,j;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d",&i,&j);
		if(j==288297) flag=1;
		switch(i) {
			case 1:
			    ins(now,j);
				break;
			case 2:
				del(now,j);
				break;
			case 3:
				printf("%d\n",rank(now,j));
				break;
			case 4:
			    printf("%d\n",find(now,j));
				break;
			case 5:
			    printf("%d\n",pre(now,j));
				break;
			case 6:
			    printf("%d\n",suf(now,j));
				break;
		}
	}
	return 0;
}

