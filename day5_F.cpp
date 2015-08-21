#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[660000],b[660000],c[660000],d[660000],us[660000],st[110000],en[110000];
int n=0,m=0;
int din[110000],dout[110000],di[110000],ans[330000];
void qsort(int l,int r)
{
	int i=l,j=r,m=a[(l+r)>>1],x;
	while (i<j)
	{
		while (a[i]<m) i++;
		while (a[j]>m) j--;
		if (i<=j)
		{
			x=a[i];a[i]=a[j];a[j]=x;
			x=b[i];b[i]=b[j];b[j]=x;
			x=c[i];c[i]=c[j];c[j]=x;
			x=d[i];d[i]=d[j];d[j]=x;
			i++;j--;
		}
	}
	if (i<r)qsort(i,r);
	if (l<j) qsort(l,j);
}
void dfs(int u,int y)
{
	for (int i=st[u];i<=en[u];++i)
	{
		st[u]=i;
		if (us[c[i]]==0)
		{
			us[c[i]]=1;
			if (y==0) dout[a[i]]++,din[b[i]]++,ans[c[i]]=d[i];
			else dout[b[i]]++,din[a[i]]++,ans[c[i]]=1-d[i];
			dfs(b[i],y);
			break;
		}
	}
}
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		for (int i=1;i<=n;++i)
			st[i]=en[i]=di[i]=0;
		for (int i=1;i<=m;++i)
			a[i]=b[i]=c[i]=d[i]=us[i]=0;
		memset(di,0,sizeof(di));
		memset(din,0,sizeof(din));
		memset(dout,0,sizeof(dout));
		memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;++i)
		{
			scanf("%d%d",&a[i+i-1],&b[i+i-1]);
			a[i+i]=b[i+i-1];
			b[i+i]=a[i+i-1];
			c[i+i]=c[i+i-1]=i;
			d[i+i-1]=1;d[i+i]=0;
			di[a[i+i]]++;
			di[b[i+i]]++;
		}
		m=m+m;
		qsort(1,m);
		st[a[1]]=1;
		for (int i=2;i<=m;++i)
		if (a[i]!=a[i-1])
		{
			en[a[i-1]]=i-1;
			st[a[i]]=i;
		}
		en[a[m]]=m;
		for (int i=1;i<=n;++i)
			while (din[i]+dout[i]<di[i])
			{
				if (din[i]>dout[i])
				dfs(i,0);
			    else dfs(i,1);
			}
		for (int i=1;i<=m/2;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}