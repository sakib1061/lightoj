#include <bits/stdc++.h>
using namespace std;

int main() {
int t,m,n;
scanf("%d",&t);
for(int i=0;i<t;i++)
{

  scanf("%d %d",&m,&n);
printf("Case %d: ",i+1);
int g=ceil(((m*n)/2.0)+0.0);
if(m==1 || n==1)
printf("%d",m*n);
else if((m==2 && n<=3) || (m<=3 && n==2))
printf("%d",4);
else if((m==2 && n>3) ||(n==2 && m>3))


{
    int r=(m*n)/8;
    r*=4;
    int c=(m*n)%8;
    if(c>=5)
        c=4;
    r+=c;
    printf("%d",r);
}
else
printf("%d",g);
printf("\n");
}
	return 0;
}
