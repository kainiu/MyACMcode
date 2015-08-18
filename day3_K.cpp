#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int too[3000],nxt[3000],head[3000],cp;
void makeedge(int x,int y)
{
	nxt[++cp]=head[x];head[x]=cp;too[cp]=y;
}
int si[3000],n,k,ans;
int dfs(int u)
{
	si[u]=1;
	for (int pp=head[u];pp;pp=nxt[pp])
		si[u]+=dfs(too[pp]);
	if (si[u]==k+1) ans++;
	return si[u];
}
int main()
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		memset(too,0,sizeof(too));
		memset(nxt,0,sizeof(nxt));
		memset(head,0,sizeof(head));
		cp=0;
		memset(si,0,sizeof(si));
		for (int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			makeedge(x,y);
		}
		ans=0;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}