#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int mm=1<<18;
int ti[mm][20],ta[mm][20];
int n,a[mm],k;
void RMQ(int num) //预处理->O(nlogn)
{
	for(int j = 1; j < 20; ++j)
		for(int i = 1; i <= n; ++i)
			if(i + (1 << j) - 1 <= n)
			{
				ta[i][j] = max(ta[i][j - 1], ta[i + (1 << (j - 1))][j - 1]);
				ti[i][j] = min(ti[i][j - 1], ti[i + (1 << (j - 1))][j - 1]);
			}
}
int getmin(int s,int v)
{
    int k=(int)(log((v-s+1)*1.0)/log(2.0));
    return min(ti[s][k],ti[v-(1<<k)+1][k]);
}
int getmax(int s,int v)
{
    int k=(int)(log((v-s+1)*1.0)/log(2.0));
    return max(ta[s][k],ta[v-(1<<k)+1][k]);
}
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		long long ans=0;
		memset(ti,0,sizeof(ti));
		memset(ta,0,sizeof(ta));
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			ti[i][0]=ta[i][0]=a[i];
		}
		RMQ(n);
		for (int i=1;i<=n;++i)
		{
			int l=i,r=n;
			while (l<r-3)
			{
				int m=(l+r)>>1;
				if (getmax(i,m)-getmin(i,m)>=k) r=m;
				else l=m;
			}
			for (;(getmax(i,l)-getmin(i,l)<k) && (l<=n);l++);
			ans=ans+l-i;
		}
		cout<<ans<<endl;
	}
	return 0;
}