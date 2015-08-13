#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int too[1000000],va[10000000],nxt[10000000],head[20000],head1[20000],cp;
int dis[2][20000],b[20000],dd[20000];
int n,m;
void makeedge1(int x,int y,int z)
{
	nxt[++cp]=head[x];head[x]=cp;too[cp]=y;va[cp]=z;
	nxt[++cp]=head[y];head[y]=cp;too[cp]=x;va[cp]=z;
}
void makeedge2(int x,int y,int z)
{
//	printf("%d %d %d\n",x,y,z);
	nxt[++cp]=head1[x];head1[x]=cp;too[cp]=y;va[cp]=z;
	nxt[++cp]=head1[y];head1[y]=cp;too[cp]=x;va[cp]=0;
}
int q[1000000],f,r;
void spfa(int u,int p)
{
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;++i)
		dis[p][i]=100000000;
	dis[p][u]=0;b[u]=1;
	q[1]=u;f=0;r=1;
	while (f<r)
	{
		u=q[++f];
		for (int pp=head[u];pp;pp=nxt[pp])
		if (dis[p][too[pp]]>dis[p][u]+va[pp])
		{
			dis[p][too[pp]]=dis[p][u]+va[pp];
			if (b[too[pp]]==0)
			{
				b[too[pp]]=1;
				q[++r]=too[pp];
			}
		}
		b[u]=0;
	}
}
void spfa2(int u)
{
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;++i)
		dd[i]=100000000;
	dd[u]=0;b[u]=1;
	q[1]=u;f=0;r=1;
	while (f<r)
	{
		u=q[++f];
		for (int pp=head1[u];pp;pp=nxt[pp])
		if (dd[too[pp]]>dd[u]+1)
		{
			dd[too[pp]]=dd[u]+1;
			if (b[too[pp]]==0)
			{
				b[too[pp]]=1;
				q[++r]=too[pp];
			}
		}
		b[u]=0;
	}
}
int gap[20000],cur[20000],aug[20000],path[20000];
int sap(int st,int ed)
{
	int flow;
	int dis[20000];
	for (int i=1;i<=n;++i)
	{
		aug[i]=gap[i]=dis[i]=0;
		cur[i]=head1[i];
	}
	aug[st]=100000000;gap[0]=n;
	flow=0;
	int u=st;
	while (dis[st]<n)
	{
		if (u==ed)
		{
			for (int v=ed;v!=st;v=too[path[v]^1])
			{
				va[path[v]]-=aug[ed];
				va[path[v]^1]+=aug[ed];
			}
			u=st;
			flow+=aug[ed];
		}
		bool flag=1;
		for (int pp=head1[u];pp;pp=nxt[pp])
		{
			int v=too[pp];
			if (va[pp]>0 && dis[u]==dis[v]+1)
			{
				path[v]=pp;cur[u]=pp;
				aug[v]=min(aug[u],va[pp]);
				u=v;
				flag=0;break;
			}
		}
		if (flag)
		{
			if (--gap[dis[u]]==0) return flow;
			dis[u]=n;
			for (int pp=head1[u];pp;pp=nxt[pp])
			{
				int v=too[pp];
				if (va[pp]>0) dis[u]=min(dis[u],dis[v]+1);
			}
			gap[dis[u]]++;
			cur[u]=head1[u];
			if (u!=st) u=too[path[u]^1];
		}
	}
	return flow;
}
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		memset(too,0,sizeof(too));
		memset(va,0,sizeof(va));
		memset(head,0,sizeof(head));
		memset(head1,0,sizeof(head1));
		memset(nxt,0,sizeof(nxt));
		memset(dis,0,sizeof(dis));
		cp=1;
		for (int i=1;i<=m;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			makeedge1(x,y,z);
		}
		spfa(1,0);
		spfa(n,1);
		int minn=dis[0][n];
		for (int i=1;i<=n;++i)
			for (int pp=head[i];pp;pp=nxt[pp])
			{
				if (dis[0][i]+va[pp]+dis[1][too[pp]]==minn)
					makeedge2(i,too[pp],1);
			}
		spfa2(1);
		printf("%d %d\n",sap(1,n),m-dd[n]);
	}
	return 0;
}