#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int num1,num2;
    vector<vector<int>>adj(6);
    for(int i=0;i<7;i++)
    {
        cout<<"Input num1 and num2"<<endl;
        cin>>num1>>num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    queue<int>q;
    int start,end,f=0;
    cout<<"Input start and end node"<<endl;
    cin>>start>>end;
    q.push(start);
    vector<int> vis(6,0);
    vis[start]=1;
    while(!q.empty())
    {
        int val=q.front();
        q.pop();
        if(val==end)
        {
            f=1;
            cout<<"Path Exists";
            break;
        }
        for(auto it:adj[val])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    if(f==0)
    {
        cout<<"Path doesn't exist";
    }
}
