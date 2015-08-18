#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[10][10],b[10][10],n,m,ans;
void search(int u,int v)
{
	if (u==n+1)
	{
		ans++;
		return ;
	}
	if (v==n+1)
	{
		int aa=0,bb=0;
		for (int i=1;i<=n;++i)
			if (a[u][i]==1) aa++;
			else if (a[u][i]==2) bb++;
		if (aa!=bb) return;
		else search(u+1,1);
		return ;
	}
	if (b[u][v]==1 && a[u][v]==0)
	{
		a[u][v]=a[v][u]=1;
		search(u,v+1);
		a[u][v]=a[v][u]=2;
		search(u,v+1);
		a[u][v]=a[v][u]=0;
	}
	else search(u,v+1);
}
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			b[x][y]=b[y][x]=1;
		}
		ans=0;
		search(1,1);
		cout<<ans<<endl;
	}
	return 0;
}