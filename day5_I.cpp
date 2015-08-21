#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct bignum
{
	int a[1000];
	bignum()
	{
		memset(a,0,sizeof(a));
	}
	bignum(int x)
	{
		memset(a,0,sizeof(a));
		a[0]=1;a[1]=x;
	}
};
bignum operator+(bignum a,bignum b)
{
	bignum c;
	c.a[0]=max(a.a[0],b.a[0]);
	for (int i=1;i<=c.a[0];++i)
		c.a[i]=a.a[i]+b.a[i];
	for (int i=1;i<c.a[0];++i)
	{
		c.a[i+1]+=c.a[i]/10;
		c.a[i]%=10;
	}
	if (c.a[c.a[0]]>9)
	{
		c.a[++c.a[0]]=1;
		c.a[c.a[0]-1]%=10;
	}
	return c;
}
bignum operator-(bignum a,bignum b)
{
	bignum c;
	for (int i=1;i<=a.a[0];++i)
	{
		if (a.a[i]<b.a[i]) 
		{
			a.a[i]+=10;
			a.a[i+1]-=1;
		}
		c.a[i]=a.a[i]-b.a[i];
	}
	c.a[0]=a.a[0];
	while (c.a[c.a[0]]==0 && c.a[0]>1) c.a[0]--;
	return c;
}
bignum m,f[3];
char ss[1000];
bignum trans()
{
	bignum c;
	c.a[0]=strlen(ss);
	for (int i=c.a[0]-1;i>=0;--i)
		c.a[c.a[0]-i]=ss[i]-48;
	return c;
}
int operator%(bignum a,int b)
{
	long long num=0;
	for (int i=a.a[0];i>=1;--i)
	{
		num=num*10+a.a[i];
		num=num%b;
	}
	return int(num);
}
bool operator<(bignum a,bignum b)
{
	a.a[1]++;
	for (int i=1;i<a.a[0];++i)
	{
		a.a[i+1]+=a.a[i]/10;
		a.a[i]%=10;
	}
	if (a.a[a.a[0]]>9)
	{
		a.a[++a.a[0]]=1;
		a.a[a.a[0]-1]%=10;
	}
	if (a.a[0]<b.a[0]) return true;
	if (a.a[0]>b.a[0]) return false;
	for (int i=a.a[0];i>=1;--i)
	{
		if (a.a[i]<b.a[i]) return true;
		if (a.a[i]>b.a[i]) return false;
	}
	return false;
}
int main()
{
	int tt,n;
	for (cin>>tt;tt>0;--tt)
	{
		
		scanf("%d%s",&n,&ss);
		m=trans();
		if (m.a[0]==1)
		{
			if (m.a[1]==1) 
			{
				printf("0\n");continue;
			}
		}
		int p=2;
		f[0]=bignum(1);
		f[1]=bignum(1);
		while (true)
		{
			f[p]=f[(p+1)%3]+f[(p+2)%3];
			if (m<f[p]) break;
			p=(p+1)%3;
		}
		m=m-f[(p+1)%3];
		printf("%d\n",m%258280327);
	}
	return 0;
}