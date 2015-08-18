#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1100][1100],a[1100][1100],b[1100][1100],n,m,ma;
void dfs(int x,int y)
{
	if (b[x][y]) return ;
	b[x][y]=1;
	if (a[x][y]) return ;
	f[x][y]=1;
	if (x+y>ma) ma=x+y;
	if (x>1) dfs(x-1,y);
	if (x<n) dfs(x+1,y);
	if (y>1) dfs(x,y-1);
	if (y<m) dfs(x,y+1);
}
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ma=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
		{
			char s[1100];
			scanf("%s",s);
			for (int j=0;j<m;++j)
				a[i][j+1]=s[j]-48;
		}
		dfs(1,1);
		if (ma==n+m)
		{
			printf("0\n");
			continue;
		}
		if (ma==0)
		{
			ma=2;
			f[1][1]=1;
			printf("1");
		}
		for (int i=ma;i<n+m;++i)
		{
			int flag=1;
			for (int j=max(1,i-m);j<=min(n,i-1);++j)
			if (f[j][i-j])
			{
				int x=j<n?a[j+1][i-j]:1;
				int y=i-j<m?a[j][i-j+1]:1;
				flag=min(flag,min(x,y));
			}
			for (int j=max(1,i-m);j<=min(n,i-1);++j)
			if (f[j][i-j])
			{
				int x=j<n?a[j+1][i-j]:1;
				int y=i-j<m?a[j][i-j+1]:1;
				if (flag==x) f[j+1][i-j]=1;
				if (flag==y) f[j][i-j+1]=1;
			}
			printf("%d",flag);
		}
		printf("\n");
	}
	return 0;
}