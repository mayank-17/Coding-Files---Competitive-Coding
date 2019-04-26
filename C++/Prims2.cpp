#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int weight[10000][10000],visited[10000],d[10000],p[10000];
int v,e;

void creategraph()
{
int i,j,a,b,w;
cin>>v;
cin>>e;
for(i=1;i<=v;i++)
  for(j=1;j<=v;j++)
    weight[i][j]=0;
for(i=1;i<=v;i++)
{
  p[i]=visited[i]=0;
  d[i]=32767;
}
for(i=1;i<=e;i++)
{
  cin>>a>>b>>w;
  weight[a][b]=weight[b][a]=w;
}
}

long prim()
{
    int current,totalvisited,i;
    long mincost;
    current=1;d[current]=0;
    totalvisited=1;
    visited[current]=1;
    while(totalvisited!=v)
    {
      for(i=1;i<=v;i++)
      {
        if(weight[current][i]!=0)
          if(visited[i]==0)
        if(d[i]>weight[current][i])
        {
          d[i]=weight[current][i];
          p[i]=current;
        }
      }
      mincost=32767;
      for(i=1;i<=v;i++)
      {
        if(visited[i]==0)
          if(d[i]<mincost)
          {
        mincost=d[i];
        current=i;
          }
      }
      visited[current]=1;
      totalvisited++;
    }
    mincost = 0;
    for(i=1;i<=v;i++) {
      mincost+=d[i];
    }
    return mincost;
}
int main()
{
    creategraph();
    int result = prim();
    cout << result << endl;
    return 0;
}
