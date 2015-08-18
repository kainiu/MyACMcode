#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long ll,rr,ans;
void search(long long l,long long r)
{
	if (r-l+1>ll) return ;
	if (r>ans) return ;
	if ((r>>1)+1==l)
	{
		ans=r;return ;
	}
	search(l-(r-l)-2,r);
	search(l-(r-l)-1,r);
	if (r!=l)
		search(l,r+(r-l));
	search(l,r+(r-l+1));
}
int main()
{
	while (scanf("%I64d%I64d",&ll,&rr)!=EOF)
	{
		if (ll==0) 
		{
			printf("%I64d\n",rr);
			continue;
		}
		ans=ll*2;
		search(ll,rr);
		if (ans==ll*2)
			printf("-1\n");
		else printf("%I64d\n",ans);
	}
	return 0;
}