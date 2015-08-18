#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[2][1000000],n,a[1000000];
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i) scanf("%d",&a[i]);
		g[0][2]=2;g[0][1]=1;
		for (int i=3;i<=n;++i)
			if (a[i-2]+a[i]==2*a[i-1])
				g[0][i]=g[0][i-1]+1;
			else g[0][i]=2;
		g[1][2]=2;g[1][1]=1;
		for (int i=3;i<=n;++i)
			if ((long long)a[i-2]*a[i]==(long long)a[i-1]*a[i-1])
				g[1][i]=g[1][i-1]+1;
			else g[1][i]=2;
		int maxx=0;
		for (int i=0;i<=1;++i)
			for (int j=1;j<=n;++j)
			{
				if (g[i][j]>maxx) maxx=g[i][j];
				g[i][j]=0;
			}
		printf("%d\n",maxx);
	}
	return 0;
}