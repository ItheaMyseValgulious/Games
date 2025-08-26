#include <bits/stdc++.h>
using namespace std;
const int dx[9]={0,-1,-1,-1,0,0,1,1,1};
const int dy[9]={0,-1,0,1,-1,1,-1,0,1};
int size,b,visited;
int mp[1000][1000];
char c[1000][1000];
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		pair<int,int>k=q.front();
		q.pop();
		int xx=k.first,yy=k.second;
		if(mp[xx][yy]!=0)
			continue;
		for(int d=1;d<=8;d++)
		{
			int nx=xx+dx[d],ny=yy+dy[d];
			if(nx>=1&&nx<=size&&ny>=1&&ny<=size&&mp[nx][ny]!=-1&&c[nx][ny]=='?')
			{
				c[nx][ny]=mp[nx][ny]+48;
				q.push(make_pair(nx,ny));
			}
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	cin>>size>>b;
	for(int i=1;i<=size;i++)
		for(int j=1;j<=size;j++)
			c[i][j]='?';
	while(b)
	{
		int x,y;
		x=rand()%size+1,y=rand()%size+1;
		if(mp[x][y]==-1)
			continue;
		mp[x][y]=-1;
		b--;
	}
	for(int i=1;i<=size;i++)
		for(int j=1;j<=size;j++)
		{
			if(mp[i][j]==-1)
				continue;
			for(int a=1;a<=8;a++)
			{
				int xx=i+dx[a],yy=j+dy[a];
				if(mp[xx][yy]==-1)
					mp[i][j]++;
			}
		}
	while(1)
	{
		int inx,iny;
		for(int i=1;i<=size;i++)
		{
			for(int j=1;j<=size;j++)
				cout<<c[i][j]<<" ";
			cout<<endl;	
		}
		cin>>inx>>iny;
		if(mp[inx][iny]==-1)
		{
			cout<<"Game Over!\nYou Lose!"<<endl;
			break;
		}
		system("cls");
		c[inx][iny]=mp[inx][iny]+48;
		if(mp[inx][iny]==0)
			bfs(inx,iny);
	}
	return 0;
}
