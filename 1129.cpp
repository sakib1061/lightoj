#include <bits/stdc++.h>
using namespace std;
struct node
{
	bool endmark;
	node *next[11];
	node()
	{
		endmark=false;
		for(int i=0;i<10;i++) next[i]=NULL;
	}
}*root;

void insert(string str,int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark=true;

}
bool search(string str,int len)
{
	node *curr=root;int id;
	for(int i=0;i<len;i++)
	{
		id=str[i]-'0';
		if(curr->next[id]==NULL) return false;
		curr=curr->next[id];

	}
	for(int i=0;i<10;i++)
    {

        if(curr->next[i])
            return 1;
}
	return 0;
}
void del(node *cur)
{
      for(int i=0;i<10;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;


         delete(cur) ;
}
int main(){
    int test,n;
    string A[100001];
    bool flag;
    cin>>test;
    for(int t=1;t<=test;t++) {
            flag=1;
	root=new node();
	int num_word;
	cin>>num_word;
	for(int i=0;i<num_word;i++)
	{
		cin>>A[i];
		insert(A[i],A[i].size());
	}
	int query=num_word;
	for(int i=0;i<query;i++)
	{

		if(search(A[i],A[i].size()))	{
            flag=0;
            break;
    }

	}

	if(flag)
        printf("Case %d: YES\n",t);
    else
        printf("Case %d: NO\n",t);
	del(root);
    }
	return 0;
}
