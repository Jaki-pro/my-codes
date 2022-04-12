#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int item;
    int dis;
    Node *l;
    Node *r;
};
Node *create_node(int item, int dis)
{
    Node *new_node = new Node();
    new_node->item = item;
    new_node->dis = dis;
    new_node->l = NULL;
    new_node->r = NULL;
    return new_node;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++)
    {
        Node *root;
        int m=32768;
        root = create_node(a[i], 0);
        map<int, int> mp;

        queue<Node*> q;
        q.push(root);
        Node *x;
        while(!q.empty())
        {
            x = q.front();
            q.pop();

            if(!mp.count(x->item+1))
            {
                x->l = create_node((x->item+1), x->dis+1);
                if((x->item+1) % m == 0)
                {
                    x=x->l;
                    break;
                }
                q.push(x->l);
                mp[x->item+1];
            }
            if(!mp.count(x->item*2))
            {
                x->r = create_node(x->item*2, x->dis+1);
                if((x->item*2)%m==0)
                {
                    x=x->r;
                    break;
                }
                q.push(x->r);
                mp[x->item*2];
            }
        }
        cout<<x->dis<<" ";
    }
    return 0;
}


