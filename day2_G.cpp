#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char cint=0;
int getint()
{
	for (;cint<'0' || cint>'9';cint=getchar());
	int num=0;
	for (;cint>='0' && cint<='9';cint=getchar())
		num=(num<<1)+(num<<3)+cint-48;
	return num;
}
int n,m;
const treesize=2000000;
int le[treesize],ri[treesize],ke[treesize],ca[treesize],tag[treesize];
long long su[treesize];
int a[1000000];
void treeinit(int l,int r,int k)
{
	le[k]=l;ri[k]=r;
	int m=(l+r)>>1;
	if (r!=l) 
	{
		treeinit(l,m,k+k);
		treeinit(m+1,r,k+k+1);
		ke[k]=ke[k+k+1]>ke[k+k]?ke[k+k+1]:ke[k+k];
		su[k]=su[k+k]+su[k+k+1];
		ca[k]=0;tag[k]=ke[k];
	}
	else ke[k]=su[k]=tag[k]=a[l],ca[k]=0;
}
void pushdown(int k)
{
	if (tag[k+k+1]>tag[k])
	{
		tag[k+k+1]=tag[k];
		
	if (tag[k+k]>tag[k])
		tag[k+k]=tag[k];
}
void pullup(int k)
{
	su[k]=su[k+k]+su[k+k+1];
	ke[k]=ke[k+k]>ke[k+k+1]?ke[k+k]:ke[k+k+1];
	ca[k]=ca[k+k]+ca[k+k+1];
	if (tag[
}
void dfs(int l,int r,int k,int ta)
{
	if (ta>=ke[k]) return ;
	if (l==r)
	{
		if (ke[k]>ta)
		{
			ca[k]=1;
			ke[k]=ta;su[k]=ta;tag[k]=ta;
		}
		return ;
	}
	else
	{
		int m=(l+r)>>1;
		pushdown(k);
		if (ca[k]==r-l+1)
		{
			tag[k]=ta;su[k]=(long long)ta*(r-l+1);tag[k]=ta;
		}
		else
		{
			dfs(l,m,k+k,ta);
			dfs(m+1,r,k+k+1,ta);
			su[k]=su[k+k]+su[k+k+1];
			ca[k]=ca[k+k]+ca[k+k+1];
			
		}
	}
}
void fugai(int l,int r,int ll,int rr,int ta,int k)
{
	if (l==ll && r==rr)
	{
		if (ta>=ke[k]) return ;
		else
		{
			dfs(l,r,k,ta);
		}
	}
}
int main()
{
	int tt;
	for (cin>>tt;tt>0;--tt)
	{
		memset(le,0,sizeof(le));
		memset(ri,0,sizeof(ri));
		memset(ke,0,sizeof(ke));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%d",a+i);
		for (;m>0;--m)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			
		}
	}
}