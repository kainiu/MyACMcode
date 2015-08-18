#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;
int myrand()
{
	return rand()*rand();
}
int main()
{
	srand((unsigned int) time(0));
	int n,m,nn=1;
	cout<<nn<<endl;
	for (int j=1;j<=nn;++j)
	{
		n=m=10;
		cout<<n<<" "<<m<<endl;
		for (int i=1;i<=n;++i)
		{
			printf("%d ",rand()%100-50);
		}
		cout<<endl;
		for (int i=1;i<=m;++i)
		{
			int x,y,z;
			x=rand()%2;
			y=rand()%n+1;
			if (x==0)
			{
				z=rand()%n+1;
				if (z<y) swap(y,z);
			}
			else z=rand()%100-50;
			printf("%d %d %d\n",x,y,z);
		}
	}
	return 0;
}