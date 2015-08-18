#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,nn,t;
int wx[1000000],wy[1000000],wd[1000000],f,r;
int a[200][200],c[220][200];
int drx[1000],dry[1000],si[1000],an[1000],any[1000];
int main()
{
	while (~scanf("%d%d%d%d",&n,&m,&nn,&t))
	{
		memset(wx,0,sizeof(wx));
		memset(wy,0,sizeof(wy));
		memset(wd,0,sizeof(wd));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		memset(drx,0,sizeof(drx));
		memset(dry,0,sizeof(dry));
		memset(si,0,sizeof(si));
		memset(an,0,sizeof(an));
		memset(any,0,sizeof(any));
		for (int i=1;i<=nn;++i)
		{
			scanf("%d%d%d",&drx[i],&dry[i],&si[i]);
			a[drx[i]][dry[i]]=si[i];
			an[i]=1;
		}
		int x,y;
		scanf("%d%d",&x,&y);
		wx[1]=wx[2]=wx[3]=wx[4]=x;
		wy[1]=wy[2]=wy[3]=wy[4]=y;
		wd[1]=0;wd[2]=1;wd[3]=2;wd[4]=3;
		f=1;r=4;int tt=0;
		while (f<=r)
		{
			tt++;
			for (int i=f;i<=r;++i)
				if (wd[i]!=-1)
				{
					wx[i]+=dx[wd[i]];
					wy[i]+=dy[wd[i]];
					if (wx[i]<=0 || wx[i]>n || wy[i]<=0 ||wy[i]>m)
						wd[i]=-1;
					else
					{
						if (a[wx[i]][wy[i]]>0)
						{
							a[wx[i]][wy[i]]++;
							wd[i]=-1;
						}
					}
				}
			while (wd[f]==-1 && f<=r) f++;
			int ok=1;
			for (int i=1;i<=nn;++i)
			{
				if (an[i]==1) ok=0;
				while (a[drx[i]][dry[i]]>4)
				{
					if (an[i]==1)
					{
						an[i]=0;
						any[i]=tt;
					}
					a[drx[i]][dry[i]]=0;
					r++;wx[r]=drx[i];wy[r]=dry[i];wd[r]=0;
					r++;wx[r]=drx[i];wy[r]=dry[i];wd[r]=1;
					r++;wx[r]=drx[i];wy[r]=dry[i];wd[r]=2;
					r++;wx[r]=drx[i];wy[r]=dry[i];wd[r]=3;
				}
			}
			if (ok) break;
			if (tt==t) break;
		}
		for (int i=1;i<=nn;++i)
			if (an[i]==1) any[i]=a[drx[i]][dry[i]];
		for (int i=1;i<=nn;++i)
			printf("%d %d\n",an[i],any[i]);
	}
	return 0;
}