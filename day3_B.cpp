#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pr[1100000],p[1100000];
int f[1100000];
int sf[8][1100000];
int main()
{
	for (int i=2;i<=1000000;++i)
	if (pr[i]==0)
	{
		for (int j=2;j<=1000000/i;++j)
		if (pr[i*j]==0)
		{
			p[i*j]=i;
			pr[i*j]=1;
		}
		p[i]=i;
	}
	for (int i=2;i<=1000000;++i)
	{
		if (pr[i]==0) f[i]=1;
		else
		{
			int kk=0,x=i;
			while (x>1)
			{
				int a=p[x];
				while (x%a==0) x=x/a;
				kk++;
			}
			f[i]=kk;
		}
		sf[f[i]][i]=1;
	}
	for (int i=1;i<=7;++i)
		for (int j=2;j<=1000000;++j)
			sf[i][j]=sf[i][j-1]+sf[i][j];
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int u[8],ans=0;
		for (int i=1;i<8;++i)
			u[i]=sf[i][y]-sf[i][x-1];
		for (int i=7;i>=1;--i)
			if (u[i]>1) 
			{
				ans=i;
				break;
			}
		if (u[6]>=1 && u[3]>=1 && ans<3) ans=3;
		if (u[6]>=1 && u[2]>=1 && ans<2) ans=2;
		if (u[4]>=1 && u[2]>=1 && ans<2) ans=2;
		if (ans==0) ans=1;
		printf("%d\n",ans);
	}
	return 0;
}