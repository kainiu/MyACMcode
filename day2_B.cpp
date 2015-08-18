#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,x,y;
int calc(int n,int m)
{
	return min(n,m);
}
int main()
{
	while (scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
	{
		if (n>m) swap(n,m),swap(x,y);
		if (x+x>n) x=n-x+1;
		if (y+y>m) y=m-y+1;
		int ans1=max(max(calc(x-1,y),calc(n-x+1,y-1)),max(calc(n-x,m-y+1),calc(x,m-y)));
		int ans2=max(max(calc(x,y-1),calc(n-x,y)),max(calc(n-x+1,m-y),calc(x-1,m-y+1)));
		int ans3=max(x,min((m+1)/2,n-x));
		int ans4=max(y,min((n+1)/2,m-y));
		printf("%d\n",min(min(ans1,ans2),min(ans3,ans4)));
	}
	return 0;
}