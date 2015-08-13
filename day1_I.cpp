#pragma comment(linker, "/STACK:1677721600")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stdio.h>
#include<cstdlib>
using namespace std;
const int mm=1<<19;
int tr[mm*4];
int findleft(int x)
{
	for (x+=mm;x>1;x>>=1)
	{
		if (x%2==1 && tr[x-1]>=1) break;
	}
	if (x==1) return -1;
	for (x--;x<mm;)
	{
		if (tr[x+x+1]>=1) x=x+x+1;
		else x=x+x;
	}
	return x-mm;
}
int findrightmost()
{
	int x=1;
	for (;x<mm;)
	{
		if (tr[x+x+1]==0) x=x+x;else x=x+x+1;
	}
	return x-mm;
}
int findleftmost()
{
	int x=1;
	for (;x<mm;)
		if (tr[x+x]==0) x=x+x+1;else x=x+x;
	return x-mm;
}
int findright(int x)
{
	for (x+=mm;x>1;x>>=1)
	{
		if (x%2==0 && tr[x+1]>=1) break;
	}
	if (x==1) return -1;
	for (x++;x<mm;)
	{
		if (tr[x+x]>=1) x=x+x;
		else x=x+x+1;
	}
	return x-mm;
}
int existinset(int x)
{
	return tr[x+mm];
}
void tradd(int x,int y)
{
	for (x+=mm;x>=1;x>>=1)
		tr[x]+=y;
}
int ti[mm+mm],fu[mm+mm];
void RMQ(int n)
{
	for (int i=mm;i>=1;--i)
		if (ti[i+i]>ti[i+i+1]) ti[i]=ti[i+i+1],fu[i]=fu[i+i+1];
		else ti[i]=ti[i+i],fu[i]=fu[i+i]; 
}
int getmin(int s,int v)
{
    int minn=1000000000,ss;
	for (s+=mm-1,v+=mm+1;s^v^1;s>>=1,v>>=1)
	{
		if ((s&1)==0 && ti[s+1]<minn) minn=ti[s+1],ss=fu[s+1];
		if ((v&1)==1 && ti[v-1]<minn) minn=ti[v-1],ss=fu[v-1];
	}
	return ss;
}
int too[mm],va[mm],nxt[mm],head[mm],cp,n,m;
void makeedge(int x,int y,int z)
{
	nxt[++cp]=head[x];head[x]=cp;too[cp]=y;va[cp]=z;
	nxt[++cp]=head[y];head[y]=cp;too[cp]=x;va[cp]=z;
}
int dfn[mm],po[mm],t,lc[mm],tim,dep;
void dfs(int u,int fa)
{
	dfn[u]=tim;po[++t]=u;ti[t+mm]=dep;fu[t+mm]=u;
	lc[u]=t;
	for (int pp=head[u];pp;pp=nxt[pp])
	if (too[pp]!=fa)
	{
		tim+=va[pp];dep+=1;
		dfs(too[pp],u);
		tim-=va[pp];dep-=1;
		po[++t]=u;ti[t+mm]=dep;fu[t+mm]=u;
	}
}
void lcainit()
{
	memset(dfn,0,sizeof(dfn));
	memset(po,0,sizeof(po));
	memset(lc,0,sizeof(lc));
	memset(ti,0,sizeof(ti));
	memset(fu,0,sizeof(fu));
	memset(tr,0,sizeof(tr));
	dfs(n/2,0);
	RMQ(t);
}
int lca(int x,int y)
{
	if (x>y) {int z=x;x=y;y=z;};
	return getmin(x,y);
}
int calc(int y)
{
	y=lc[y];
	if (tr[1]==2)
	{
		int x=y+mm,z=2*(y+mm);
		for (;tr[x]==1;x>>=1,z>>=1);
		x=z^1;
		for (;x<mm;x=tr[x+x]==1?x+x:x+x+1);
		x=x-mm;
		return dfn[po[x]]+dfn[po[y]]-2*dfn[lca(x,y)];
	}
	else
	{
		int x=findleft(y),z;
		if (x==-1)
		{
			x=findright(y);
			z=findrightmost();
		}
		else
		{
			z=findright(y);
			if (z==-1) z=findleftmost();
		}
		int ans;
		ans = dfn[po[y]]+dfn[lca(x,z)]-dfn[lca(x,y)]-dfn[lca(y,z)];
		return ans;
	}
}
int main()
{
	//freopen("data.in","r",stdin);
	int tt;cin>>tt;
	for (int tl=1;tl<=tt;tl++)
	{
		memset(too,0,sizeof(too));
		memset(nxt,0,sizeof(nxt));
		memset(head,0,sizeof(head));
		memset(va,0,sizeof(va));
		cp=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<n;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			makeedge(x,y,z);
		}
		lcainit();
		printf("Case #%d:\n",tl);
		int ans=0;
		for (;m>0;--m)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (x==1)
			{
				if (existinset(lc[y])) 
				{
					printf("%d\n",ans);
					continue;
				}
				tradd(lc[y],1);
				if (tr[1]==1) ans=0;
				else ans+=calc(y);
			}
			else
			{
				if (!existinset(lc[y]))
				{
					printf("%d\n",ans);
					continue;
				}
				if (tr[1]==1 || tr[1]==2) ans=0;
				else ans-=calc(y);
				tradd(lc[y],-1);
			}
			printf("%d\n",ans);
		}
	}
}