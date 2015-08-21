#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
	int x,ma=-1000000000,ys=0,no=0;
	for (int i=1;i<=n;++i)
	{
		int y;
		scanf("%d",&y);
		if (y==1)
		{
			scanf("%d",&x);
			if (x>ma) ma=x;
			no++;
		}
		if (y==2)
		{
			if (ys==no) continue;
			ys++;
			if (ys==no)
			{
				ma=-1000000000;
			}
		}
		if (y==3)
		{
			if (ys==no)
				printf("%d\n",0);
			else
			printf("%d\n",ma);
		}
	}
	}
	return 0;
}