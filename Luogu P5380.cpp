#include <bits/stdc++.h>
using namespace std;
const int soldier_dx[9]={0,-1,-1,-1,0,0,1,1,1};
const int soldier_dy[9]={0,-1,0,1,-1,1,-1,0,1};
const int horse_dx[9]={0,-2,-2,-1,-1,1,1,2,2};
const int horse_dy[9]={0,-1,1,-2,2,-2,2,-1,1};
const int horse_dx_bie[9]={0,-1,-1,0,0,0,0,1,1};
const int horse_dy_bie[9]={0,0,0,-1,1,-1,1,0,0};
//(-2,-1):(-1,0)
//(-2,1):(-1,0)
//(-1,-2):(0,-1)
//(-1,2):(0,1)
//(1,-2):(0,-1)
//(1,2):(0,1)
//(2,-1):(1,0)
//(2,1):(1,0)
const int duck_dx[9]={0,-3,-3,-2,-2,2,2,3,3};
const int duck_dy[9]={0,-2,2,-3,3,-3,3,-2,2};
const int duck_dx_bie[17]={0,-1,-2,-1,-2,0,-1,0,-1,0,1,0,1,1,2,1,2};
const int duck_dy_bie[17]={0,0,-1,0,1,-1,-2,1,2,-1,-2,1,2,0,-1,0,1};
//(-3,-2):(-1,0)(-2,-1)
//(-3,2):(-1,0)(-2,1)
//(-2,-3):(0,-1)(-1,-2)
//(-2,3):(0,1)(-1,2)
//(2,-3):(0,-1)(1,-2)
//(2,3):(0,1)(1,2)
//(3,-2):(1,0)(2,-1)
//(3,2):(1,0)(2,1)
const int elephant_dx[5]={0,-2,-2,2,2};
const int elephant_dy[5]={0,-2,2,-2,2};
const int elephant_dx_bie[5]={0,-1,-1,1,1};
const int elephant_dy_bie[5]={0,-1,1,-1,1};
const int guard_dx[5]={0,-1,-1,1,1};
const int guard_dy[5]={0,-1,1,-1,1};
const int captain_dx[5]={0,-1,0,0,1};
const int captain_dy[5]={0,0,-1,1,0};
char mp[11][10];
int q,rnd;
//rnd=0:red move
//rnd=1:blue move
int xs,ys,xt,yt;
void init()
{
	for(int i=1;i<=10;i++)
		for(int j=1;j<=9;j++)
			mp[i][j]=' ';
	mp[1][1]=mp[1][9]='C';
	mp[1][2]=mp[1][8]='H';
	mp[1][3]=mp[1][7]='E';
	mp[1][4]=mp[1][6]='G';
	mp[3][1]=mp[3][9]='D';
	mp[4][1]=mp[4][3]=mp[4][5]=mp[4][7]=mp[4][9]='S';
	mp[1][5]='K';
	mp[10][1]=mp[10][9]='c';
	mp[10][2]=mp[10][8]='h';
	mp[10][3]=mp[10][7]='e';
	mp[10][4]=mp[10][6]='g';
	mp[8][1]=mp[8][9]='d';
	mp[7][1]=mp[7][3]=mp[7][5]=mp[7][7]=mp[7][9]='s';
	mp[10][5]='k';
	//´óÐ´£ºR Ð¡Ð´£ºB 
}
bool game_over()
{
	int flag_r=0,flag_b=0;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=9;j++)
		{
			if(mp[i][j]=='K')
				flag_r=1;
			if(mp[i][j]=='k')
				flag_b=1;
		}
	if(flag_r&&flag_b)
		return 0;
	else
		return 1;
}
bool chk()
{
	if(xs<1||xs>10||ys<1||ys>9||xt<1||xt>10||yt<1||yt>9)
		return 0;
	if(mp[xs][ys]==' ')
		return 0;
	if(rnd==0&&(mp[xs][ys]<65||mp[xs][ys]>90))
		return 0;
	if(rnd==0&&65<=mp[xt][yt]&&mp[xt][yt]<=90)
		return 0;
	if(rnd==1&&(mp[xs][ys]<97||mp[xs][ys]>122))
		return 0;
	if(rnd==1&&97<=mp[xt][yt]&&mp[xt][yt]<=122)
		return 0;
	if(rnd==0)
	{
		if(mp[xs][ys]=='C')
		{
			if(xs!=xt&&ys!=yt)
				return 0;
			if(xs==xt)
			{
				if(ys<yt) 
					for(int i=ys+1;i<yt;i++)
						if(mp[xs][i]!=' ')
							return 0;
				if(ys>yt)
					for(int i=ys-1;i>yt;i--)
						if(mp[xs][i]!=' ')
							return 0;
			}
			if(ys==yt)
			{
				if(xs<xt)
					for(int i=xs+1;i<xt;i++)
						if(mp[i][ys]!=' ')
							return 0;
				if(xs>xt)
					for(int i=xs-1;i>xt;i--)
						if(mp[i][ys]!=' ')
							return 0;
			}
		}
		if(mp[xs][ys]=='H')
		{
			int flag1=0;
			for(int i=1;i<=8;i++)
			{
				int xx=xs+horse_dx[i],yy=ys+horse_dy[i];
				if(xx==xt&&yy==yt)
				{
					flag1=1;
					if(mp[xs+horse_dx_bie[i]][ys+horse_dy_bie[i]]!=' ')
						return 0;
				}
			}
			if(flag1==0)
				return 0;
		}
		if(mp[xs][ys]=='E')
		{
			int flag2=0;
			for(int i=1;i<=4;i++)
			{
				int xx=xs+elephant_dx[i],yy=ys+elephant_dy[i];
				if(xx==xt&&yy==yt)
				{
					flag2=1;
					if(mp[xs+elephant_dx_bie[i]][ys+elephant_dy_bie[i]]!=' ')
						return 0;
				}
			}
			if(flag2==0)
				return 0;
		}
		if(mp[xs][ys]=='G')
		{
			int flag3=0;
			for(int i=1;i<=4;i++)
			{
				int xx=xs+guard_dx[i],yy=ys+guard_dy[i];
				if(xx==xt&&yy==yt)
					flag3=1;
			}
			if(flag3==0)
				return 0;
		}
		if(mp[xs][ys]=='K')
		{
			int flag4=0;
			for(int i=1;i<=4;i++)
			{
				int xx=xs+captain_dx[i],yy=ys+captain_dy[i];
				if(xx==xt&&yy==yt)
					flag4=1;
			}
			if(flag4==0)
				return 0;
		}
		if(mp[xs][ys]=='S')
		{
			int flag5=0;
			for(int i=1;i<=8;i++)
			{
				int xx=xs+soldier_dx[i],yy=ys+soldier_dy[i];
				if(xx==xt&&yy==yt)
					flag5=1;
			}
			if(flag5==0)
				return 0;
		}
		if(mp[xs][ys]=='D')
		{
			int flag6=0;
			for(int i=1;i<=8;i++)
			{
				int xx=xs+duck_dx[i],yy=ys+duck_dy[i];
				if(xx==xt&&yy==yt)
				{
					flag6=1;
					if(mp[xs+duck_dx_bie[2*i]][ys+duck_dy_bie[2*i]]!=' ')
						return 0;
					if(mp[xs+duck_dx_bie[2*i-1]][ys+duck_dy_bie[2*i-1]]!=' ')
						return 0;
				}
			}
			if(flag6==0)
				return 0;
		}
	}
	if(rnd==1)
	{
		if(mp[xs][ys]=='c')
		{
			if(xs!=xt&&ys!=yt)
				return 0;
			if(xs==xt)
			{
				if(ys<yt) 
					for(int i=ys+1;i<yt;i++)
						if(mp[xs][i]!=' ')
							return 0;
				if(ys>yt)
					for(int i=ys-1;i>yt;i--)
						if(mp[xs][i]!=' ')
							return 0;
			}
			if(ys==yt)
			{
				if(xs<xt)
					for(int i=xs+1;i<xt;i++)
						if(mp[i][ys]!=' ')
							return 0;
				if(xs>xt)
					for(int i=xs-1;i>xt;i--)
						if(mp[i][ys]!=' ')
							return 0;
			}
		}
		if(mp[xs][ys]=='h')
		{
			int flag7=0;
			for(int i=1;i<=8;i++)
			{
				int xx=xs+horse_dx[i],yy=ys+horse_dy[i];
				if(xx==xt&&yy==yt)
				{
					flag7=1;
					if(mp[xs+horse_dx_bie[i]][ys+horse_dy_bie[i]]!=' ')
						return 0;
				}
			}
			if(flag7==0)
				return 0;
		}
		if(mp[xs][ys]=='e')
		{
			int flag8=0;
			for(int i=1;i<=4;i++)
			{
				int xx=xs+elephant_dx[i],yy=ys+elephant_dy[i];
				if(xx==xt&&yy==yt)
				{
					flag8=1;
					if(mp[xs+elephant_dx_bie[i]][ys+elephant_dy_bie[i]]!=' ')
						return 0;
				}
			}
			if(flag8==0)
				return 0;
		}
		if(mp[xs][ys]=='g')
		{
			int flag9=0;
			for(int i=1;i<=4;i++)
			{
				int xx=xs+guard_dx[i],yy=ys+guard_dy[i];
				if(xx==xt&&yy==yt)
					flag9=1;
			}
			if(flag9==0)
				return 0;
		}
		if(mp[xs][ys]=='k')
		{
			int flag10=0;
			for(int i=1;i<=4;i++)
			{
				int xx=xs+captain_dx[i],yy=ys+captain_dy[i];
				if(xx==xt&&yy==yt)
					flag10=1;
			}
			if(flag10==0)
				return 0;
		}
		if(mp[xs][ys]=='s')
		{
			int flag11=0;
			for(int i=1;i<=8;i++)
			{
				int xx=xs+soldier_dx[i],yy=ys+soldier_dy[i];
				if(xx==xt&&yy==yt)
					flag11=1;
			}
			if(flag11==0)
				return 0;
		}
		if(mp[xs][ys]=='d')
		{
			int flag12=0;
			for(int i=1;i<=8;i++)
			{
				int xx=xs+duck_dx[i],yy=ys+duck_dy[i];
				if(xx==xt&&yy==yt)
				{
					flag12=1;
					if(mp[xs+duck_dx_bie[2*i]][ys+duck_dy_bie[2*i]]!=' ')
						return 0;
					if(mp[xs+duck_dx_bie[2*i-1]][ys+duck_dy_bie[2*i-1]]!=' ')
						return 0;
				}
			}
			if(flag12==0)
				return 0;
		}
	}
	return 1;
}
bool capture()
{
	for(int i=1;i<=10;i++)
		for(int j=1;j<=9;j++)
		{
			if(mp[i][j]=='G')
				for(int d=1;d<=4;d++)
				{
					int xx=i+guard_dx[d],yy=j+guard_dy[d];
					if(mp[xx][yy]=='k')
						return 1;
				}
			if(mp[i][j]=='E')
				for(int d=1;d<=4;d++)
				{
					int xx=i+elephant_dx[d],yy=j+elephant_dy[d];
					if(mp[xx][yy]=='k')
						return 1;
				}
			if(mp[i][j]=='H')
				for(int d=1;d<=8;d++)
				{
					int xx=i+horse_dx[d],yy=j+horse_dy[d];
					int bx=i+horse_dx_bie[d],by=j+horse_dy_bie[d];
					if(mp[xx][yy]=='k'&&mp[bx][by]==' ')
						return 1;
				}
			if(mp[i][j]=='C')
			{
				int xx=i,yy=j;
				while(xx>=1)
				{
					xx--;
					if(mp[xx][yy]!=' ')
						break;
				}
				if(mp[xx][yy]=='k')
					return 1;
				xx=i,yy=j;
				while(xx<=10)
				{
					xx++;
					if(mp[xx][yy]!=' ')
						break;
				}
				if(mp[xx][yy]=='k')
					return 1;
				xx=i,yy=j;
				while(yy>=1)
				{
					yy--;
					if(mp[xx][yy]!=' ')
						break;
				}
				if(mp[xx][yy]=='k')
					return 1;
				xx=i,yy=j;
				while(yy<=9)
				{
					yy++;
					if(mp[xx][yy]!=' ')
						break; 
				}
				if(mp[xx][yy]=='k')
					return 1;
			}
			if(mp[i][j]=='D')
				for(int d=1;d<=8;d++)
				{
					int xx=i+duck_dx[d],yy=j+duck_dy[d];
					int bx=i+duck_dx_bie[2*d],by=j+duck_dy_bie[2*d];
					int bbx=i+duck_dx_bie[2*d-1],bby=j+duck_dy_bie[2*d-1];
					if(mp[xx][yy]=='k'&&mp[bx][by]==' '&&mp[bbx][bby]==' ')
						return 1;
				}
			if(mp[i][j]=='S')
				for(int d=1;d<=8;d++)
				{
					int xx=i+soldier_dx[d],yy=j+soldier_dy[d];
					if(mp[xx][yy]=='k')
						return 1;
				}
			if(mp[i][j]=='g')
				for(int d=1;d<=4;d++)
				{
					int xx=i+guard_dx[d],yy=j+guard_dy[d];
					if(mp[xx][yy]=='K')
						return 1;
				}
			if(mp[i][j]=='e')
				for(int d=1;d<=4;d++)
				{
					int xx=i+elephant_dx[d],yy=j+elephant_dy[d];
					if(mp[xx][yy]=='K')
						return 1;
				}
			if(mp[i][j]=='h')
				for(int d=1;d<=8;d++)
				{
					int xx=i+horse_dx[d],yy=j+horse_dy[d];
					int bx=i+horse_dx_bie[d],by=j+horse_dy_bie[d];
					if(mp[xx][yy]=='K'&&mp[bx][by]==' ')
						return 1;
				}
			if(mp[i][j]=='c')
			{
				int xx=i,yy=j;
				while(xx>=1)
				{
					xx--;
					if(mp[xx][yy]!=' ')
						break;
				}
				if(mp[xx][yy]=='K')
					return 1;
				xx=i,yy=j;
				while(xx<=10)
				{
					xx++;
					if(mp[xx][yy]!=' ')
						break;
				}
				if(mp[xx][yy]=='K')
					return 1;
				xx=i,yy=j;
				while(yy>=1)
				{
					yy--;
					if(mp[xx][yy]!=' ')
						break;
				}
				if(mp[xx][yy]=='K')
					return 1;
				xx=i,yy=j;
				while(yy<=9)
				{
					yy++;
					if(mp[xx][yy]!=' ')
						break; 
				}
				if(mp[xx][yy]=='K')
					return 1;
			}
			if(mp[i][j]=='d')
				for(int d=1;d<=8;d++)
				{
					int xx=i+duck_dx[d],yy=j+duck_dy[d];
					int bx=i+duck_dx_bie[2*d],by=j+duck_dy_bie[2*d];
					int bbx=i+duck_dx_bie[2*d-1],bby=j+duck_dy_bie[2*d-1];
					if(mp[xx][yy]=='K'&&mp[bx][by]==' '&&mp[bbx][bby]==' ')
						return 1;
				}
			if(mp[i][j]=='s')
				for(int d=1;d<=8;d++)
				{
					int xx=i+soldier_dx[d],yy=j+soldier_dy[d];
					if(mp[xx][yy]=='K')
						return 1;
				}
		}
	return 0;
}
void move()
{
	int checkmate=0;
	if(mp[xs][ys]=='C')
		cout<<"red car;";
	else if(mp[xs][ys]=='H')
		cout<<"red horse;";
	else if(mp[xs][ys]=='E')
		cout<<"red elephant;";
	else if(mp[xs][ys]=='G')
		cout<<"red guard;";
	else if(mp[xs][ys]=='K')
		cout<<"red captain;";
	else if(mp[xs][ys]=='D')
		cout<<"red duck;";
	else if(mp[xs][ys]=='S')
		cout<<"red soldier;";
	else if(mp[xs][ys]=='c')
		cout<<"blue car;";
	else if(mp[xs][ys]=='h')
		cout<<"blue horse;";
	else if(mp[xs][ys]=='e')
		cout<<"blue elephant;";
	else if(mp[xs][ys]=='g')
		cout<<"blue guard;";
	else if(mp[xs][ys]=='k')
		cout<<"blue captain;";
	else if(mp[xs][ys]=='d')
		cout<<"blue duck;";
	else
		cout<<"blue soldier;";
	if(mp[xt][yt]==' ')
		cout<<"NA;";
	else if(mp[xt][yt]=='C')
		cout<<"red car;";
	else if(mp[xt][yt]=='H')
		cout<<"red horse;";
	else if(mp[xt][yt]=='E')
		cout<<"red elephant;";
	else if(mp[xt][yt]=='G')
		cout<<"red guard;";
	else if(mp[xt][yt]=='K')
	{
		checkmate=1;
		cout<<"red captain;";
	}
	else if(mp[xt][yt]=='D')
		cout<<"red duck;";
	else if(mp[xt][yt]=='S')
		cout<<"red soldier;";
	else if(mp[xt][yt]=='c')
		cout<<"blue car;";
	else if(mp[xt][yt]=='h')
		cout<<"blue horse;";
	else if(mp[xt][yt]=='e')
		cout<<"blue elephant;";
	else if(mp[xt][yt]=='g')
		cout<<"blue guard;";
	else if(mp[xt][yt]=='k')
	{
		checkmate=1;
		cout<<"blue captain;";
	}
	else if(mp[xt][yt]=='d')
		cout<<"blue duck;";
	else
		cout<<"blue soldier;";
	if(rnd==0)
		rnd=1;
	else
		rnd=0;
	mp[xt][yt]=mp[xs][ys];
	mp[xs][ys]=' ';
	if(capture())
		cout<<"yes;";
	else
		cout<<"no;";
	if(checkmate==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}
int main()
{
	init();
	cin>>q;
	while(q--)
	{
		cin>>xs>>ys>>xt>>yt;
		xs++,ys++,xt++,yt++;
		if(game_over())
		{
			cout<<"Invalid command"<<endl;
			continue;
		}
		if(chk())
			move();
		else
		{
			cout<<"Invalid command"<<endl;
			continue;
		}
	}
	return 0;
}
