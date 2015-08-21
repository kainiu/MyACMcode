#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		int n,m,z,l;
		scanf("%d%d%d%d",&n,&m,&z,&l);
		int ans=0,a=0;
		for (int i=1;i<=n;++i)
		{
			ans=ans^(a+a);
			a=((long long)a*m+z)%l;
		}
		printf("%d\n",ans);
	}
	return 0;
}