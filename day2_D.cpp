#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long d[2][200000];
int n,m,k,l,a[200000],x[200000],sum;
void qsort(int l,int r)
{
	int i=l,j=r,m=x[(l+r)>>1],z;
	while (i<j)
	{
		while (x[i]<m) i++;
		while (x[j]>m) j--;
		if (i<=j)
		{
			z=x[i];x[i]=x[j];x[j]=z;
			z=a[i];a[i]=a[j];a[j]=z;
			i++;j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		scanf("%d%d%d",&l,&n,&k);
		for (int i=1;i<=n;++i)
			scanf("%d%d",x+i,a+i);
		qsort(1,n);
		memset(d,0,sizeof(d));
		sum=0;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=a[i];++j)
			{
				sum++;
				int pre=sum-k>0?sum-k:0;
				d[0][sum]=d[0][pre]+(2*x[i]>l?l:2*x[i]);
			}
		sum=0;
		for (int i=n;i>=1;--i)
			for (int j=1;j<=a[i];++j)
			{
				sum++;
				int pre=sum-k>0?sum-k:0;
				d[1][sum]=d[1][pre]+((2*l-2*x[i])>l?l:(2*l-2*x[i]));
			}
		long long ans=d[0][0]+d[1][sum];
		for (int i=1;i<=sum;++i)
			if (d[0][i]+d[1][sum-i]<ans)
				ans=d[0][i]+d[1][sum-i];
		cout<<ans<<endl;
	}
	return 0;
}