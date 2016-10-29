#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cas,i;
    cin>>cas;
    for(i=1;i<=cas;i++) {
            printf("Case %d:\n",i);
    stack<string>Forward,Backward;
    Forward.push("http://www.lightoj.com/");
    string S,U;
    while(1)
    {
        cin>>S;
        if(S=="QUIT")
            break;
        if(S=="VISIT")
        {
            cin>>U;
            cout<<U<<endl;
            Forward.push(U);
            Backward=stack<string>();
        }
        else if(S=="BACK")
        {
            if(Forward.size()==1)
                cout<<"Ignored\n";
                else {
            string s=Forward.top();
            Forward.pop();
            Backward.push(s);
            cout<<Forward.top()<<endl;
                }
//            cout<<Backward.size()<<" "<<Forward.size()<<endl;
        }
        else if(S=="FORWARD")
        {
            if(Backward.size()==0)
                cout<<"Ignored\n";
//                cout<<Backward.size()<<endl;
else {
                string s=Backward.top();
           Backward.pop();
            Forward.push(s);
            cout<<s<<endl;
}

        }
    }
    }
}
