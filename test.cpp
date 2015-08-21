#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[200];
int main()
{
	int mi=1,ma=1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if (a[i]<=a[mi]) mi=i;
		if (a[i]>a[ma]) ma=i;
	}
	cout<<ma-1+(n-mi)-(ma>mi?1:0)<<endl;
	return 0;
}