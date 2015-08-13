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
		n=m=100000;
		cout<<n<<" "<<m<<endl;
		for (int i=2;i<=n;++i)
		{
			printf("%d %d %d\n",myrand()%(i-1)+1,i,rand()%100+1);
		}
		for (int i=1;i<=m;++i)
		{
			int x,y;
			x=rand()%2+1;
			y=myrand()%n+1;
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}