/**
 * @Author: Max
 * @Time: 9/19/21 19:18
 */

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int num[12],solve[12],d[12],ans[12];
char str[12][25];
bool vis[12];
int h,n,t0,minn,minTim;

void Dfs(int cnt,int rTime,int tim)
{
    if(tim > h) return;  //tim为读题时间，h为题目限时
    if(cnt > minn|| (cnt == minn && rTime<minTim))  //minTim为暂时的最优解
    {
        minn = cnt;
        minTim = rTime;
        for(int i=0;i<cnt;++i)
            ans[i] = num[i];
    }
    if(cnt >= n) return;
    for(int i=0;i<n;++i)
        if(!vis[i])
        {
            vis[i] = true;
            num[cnt] = i;
            Dfs(cnt+1,rTime+tim+solve[i]+(tim+solve[i]-1)/60*(d[i]+20),tim+solve[i]+(tim+solve[i]-1)/60*d[i]);
            vis[i] = false;
        }
}

int main()
{
    while(scanf("%d",&h)&&h>=0)  //这里一定是h>=0因为题目中说的小于0终止，不一定是-1,
    {
        scanf("%d%d",&n,&t0);
        minn = 0;
        h = h * 60;  //转化成分钟
        for(int i=0;i<n;++i)
            scanf("%s%d%d",str[i],&solve[i],&d[i]);
        Dfs(0,0,t0);
        printf("Total Time = %d\n",minTim);
        for(int i=0;i<minn;++i)
            printf("%s\n",str[ans[i]]);

    }
    return 0;
}