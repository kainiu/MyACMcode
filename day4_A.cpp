#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[220000];
int check(int x)
{
	int b[10];
	memset(b,0,sizeof(b));
	for (;x>0;x/=10)
	{
		b[x%10]++;
		if (b[x%10]>1) return 0;
	}
	return 1;
}
int main()
{
	for (int i=1;i<=100000;++i)
		a[i]=a[i-1]+check(i);
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",a[y]-a[x-1]);
	}
	return 0;
}