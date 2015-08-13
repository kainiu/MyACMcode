#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int pp=1000000007;
int n,a[200000];
int nxt[300000],too[300000],head[20000],cp;
int findleft(int x,int w)
{
	while (nxt[head[x]]!=0 && too[nxt[head[x]]]<w)
		head[x]=nxt[head[x]];
	return too[head[x]];
}
int findright(int x,int w)
{
	while (nxt[head[x]]!=0 && too[nxt[head[x]]]<=w)
		head[x]=nxt[head[x]];
	if (nxt[head[x]]==0) return n+1;
	else
		return too[nxt[head[x]]];
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		cp=0;
		memset(nxt,0,sizeof(nxt));
		memset(too,0,sizeof(too));
		memset(head,0,sizeof(head));
		memset(a,0,sizeof(a));
		long long ans=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=10000;++i)
		{
			nxt[++cp]=head[i];head[i]=cp;too[cp]=n+1;
		}
		for (int i=n;i>=1;--i)
		{
			nxt[++cp]=head[a[i]];head[a[i]]=cp;too[cp]=i;
		}
		for (int i=1;i<=10000;++i)
		{
			nxt[++cp]=head[i];head[i]=cp;too[cp]=0;
		}		
		for (int i=1;i<=n;++i)
		{
			int l=0,r=n+1;
			for (int j=1;j<=100;++j)
			if (a[i]%j==0)
			{
				int x=findleft(j,i);
				if (x>l && x!=i) l=x;
				x=findright(j,i);
				if (x<r && x!=i) r=x;
				if (j*j!=a[i])
				{
					x=findleft(a[i]/j,i);
					if (x>l && x!=i) l=x;
					x=findright(a[i]/j,i);
					if (x<r && x!=i) r=x;					
				}
			}
			ans=(ans+(long long)(i-l)*(r-i))%pp;
		}
		cout<<ans<<endl;
	}
	return 0;
}