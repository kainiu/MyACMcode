#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int treesize=300000;
const long long fuinf=(long long)(-10000000)*100000;
int a[200000],n,m;
struct treenode
{
	long long oe,ee,oo,eo;
} t[treesize];
treenode operator+(treenode a,treenode b)
{
	treenode c;
	c.oe=max(max(a.oo+b.ee,a.oe+b.oe),max(a.oe,b.oe));
	c.oo=max(max(a.oo+b.eo,a.oe+b.oo),max(a.oo,b.oo));
	c.ee=max(max(a.ee+b.oe,a.eo+b.ee),max(a.ee,b.ee));
	c.eo=max(max(a.ee+b.oo,a.eo+b.eo),max(a.eo,b.eo));
	return c;
}
void init(int l,int r,int k)
{
	if (l==r)
	{
		if (l%2==0)
		{
			t[k].ee=a[l];
			t[k].eo=t[k].oe=t[k].oo=fuinf;
		}
		else
		{
			t[k].oo=a[l];
			t[k].eo=t[k].oe=t[k].ee=fuinf;
		}
	}
	else
	{
		int m=(l+r)>>1;
		init(l,m,k+k);
		init(m+1,r,k+k+1);
		t[k]=t[k+k]+t[k+k+1];
	}
}
void change(int l,int r,int k,int x,int y)
{
	if (l==r && l==x)
	{
		if (l%2==0)
		{
			t[k].ee=y;
			t[k].eo=t[k].oe=t[k].oo=fuinf;
		}
		else
		{
			t[k].oo=y;
			t[k].eo=t[k].oe=t[k].ee=fuinf;
		}	
	}
	else
	{
		int m=(l+r)>>1;
		if (x<=m) change(l,m,k+k,x,y);
		if (x>m) change(m+1,r,k+k+1,x,y);
		t[k]=t[k+k]+t[k+k+1];
	}
}
treenode cha(int l,int r,int ll,int rr,int k)
{
	if (l==ll && r==rr)
		return t[k];
	int m=(l+r)>>1;
	if (rr<=m) return cha(l,m,ll,rr,k+k);
	else if (ll>m) return cha(m+1,r,ll,rr,k+k+1);
	else
	{
		return cha(l,m,ll,m,k+k)+cha(m+1,r,m+1,rr,k+k+1);
	}
}

int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		memset(t,0,sizeof(t));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i) scanf("%d",a+i);
		init(1,n,1);
		for (int i=1;i<=m;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if (x==0)
			{
				treenode c=cha(1,n,y,z,1);
				printf("%I64d\n",max(max(c.oo,c.eo),max(c.oe,c.ee)));
			}
			else
			{
				change(1,n,1,y,z);
			}
		}
	}
	return 0;
}