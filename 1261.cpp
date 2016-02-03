/****************************************\
   Allah is Almighty
   Coder-Boxtroll
   sakibhossain.nstu@gmail.com
/*****************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define re(x) return x
#define rep(i,j) for(int i=0;i<j;i++)
#define repa(i,j) for(int i=1;i<=j;i++)
#define per(i,j) for(int i=x;i>=0;i--)
#define po(i,j) pow(i+0.0,j)
#define pb(x) push_back(x)
#define pf printf
#define sf scanf
#define all(x) x.begin(), x.end()
#define clr(x) x.erase(all(x))
#define sum(x) accumulate(all(x),0)
#define vi(x) vector<int>x
#define ca(x) pf("Case %d: ",x)
#define ne pf("\n")
#define SET(x) memset(x, 0, sizeof(x))
#define CLR(x) memset(x, -1, sizeof(x))
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
template <class T> T Max(T a, T b) { return a>b?a:b;}
template <class T> T Min(T a, T b) { return a<b?a:b;}
bool less(const string &a,const string &b)
{
    return a.size()<b.size();
}
int main()
{
vector<int>A[31],B;
int t,i,j,k,f=0,n,m,K,p,q,nn,ng,pp,pg;
cin>>t;
repa(i,t)
{
    f=nn=pp=pg=ng=0;
    cin>>n>>m>>K;
    rep(j,n)
    {
        ng=pg=0;
        rep(k,K)
        {
            cin>>p;
            if(p<0)
                ng++;
            else
                pg++;
            A[j].pb(p);
        }
        A[j].pb(ng);
        A[j].pb(pg);
    }
    cin>>q;
    rep(k,q)
    {
        cin>>p;
        B.pb(p);
    }
    rep(k,n)
    {
        int c=0,fl=1,pp=nn=0;
        rep(j,B.size())
        {
            if(!fl)
                break;
p=0;
            rep(p,K)
            {
                if(!fl)
                    break;
                if(B[j]==abs(A[k][p]) && A[k][p]>=0)
                {
                    f++;
//                    cout<<"ok "<<A[k][p]<<endl;
                fl=0;
                A[k].erase(A[k].begin(),A[k].end());
                    break;
                }
                else if(A[k][p]<0 && B[j]==abs(A[k][p]))
                    nn++;
            }
        }
if(fl)
{
    p=A[k][K];
//    cout<<p<<endl;
    if(p>nn)
        f++;
}
            A[k].erase(A[k].begin(),A[k].end());
//            cout<<f<<endl;
    }
    if(f==n)
        printf("Case %d: Yes\n",i);
    else
        printf("Case %d: No\n",i);
        clr(B);
}
return 0;
}


