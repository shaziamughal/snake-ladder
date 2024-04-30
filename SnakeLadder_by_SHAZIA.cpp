#include<iostream>
#include<windows.h>
using namespace std;
#include<conio.h>
#include<math.h>
#include<fstream>

void gotoRowCol(int rpos, int cpos)
{
	int xpos=cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void sleep(int m)
{
        for(int j=0;j<m*21000;j++)
        {
        }
}

void box(int sr, int sc, int w, int x, char c)
{
    int er=sr+x;
    int ec= sc+w;
    for(int i=sr ; i<=er ; i++){
    gotoRowCol(i,sc);
    cout<<c;
    }
    for(int i=sc ; i<=ec ; i++){
    gotoRowCol(er,i);
    cout<<c;
    }
    for(int i=er ; i>=sr ; i--){
    gotoRowCol(i,ec);
    cout<<c;
    }
    for(int i=ec ; i>=sc ; i--){
    gotoRowCol(sr,i);
    cout<<c;
    }
}

void Print_Box(int sr, int sc, int w, int x, char c)
{
    int er=sr+x;
    int ec= sc+w;
    for(int i=0; i<=9; i++)
    {
        box(sr,sc,w,x,c);
        sc=sc+w;
    }
}
void no_in_box(int sr, int sc, int w) {
    int num = 100;
    for (int row = 0; row < 10; row++) {
        int currRow = sr + (row * 4) + 2;
        int currCol = sc + 2;
        gotoRowCol(currRow, currCol);
        for (int col = 0; col < 10; col++) {
            cout << num;
        cout<<"   ";
            num--;
            if(num== 8)
            {
                cout<<"  "<<num;
                break;
            }
        }
    }
    for(int i = 7; i >= 1; i--) {
        gotoRowCol(sr + 38, sc - 448);
        sc = sc + w;
        cout << "    "<<i;
    }
}

void Boxes(int sr, int sc, int w, int x, char c)
{
    no_in_box(sr,sc,w);
    for(int i=1; i<=10; i++)
    {
        Print_Box(sr,sc,w,x,c);
        sr=sr+x;
    }
}
int roll_dice(int &D)
{
    while(!kbhit()){

        D=(rand()%6)+1;
        gotoRowCol(35,65);
        cout<<"Dice Roll: "<<D;
    }
    getch();
    sleep(10000);
    return D;
}
void change_turn(int &turn)
{
    turn = (turn + 1)%2;
}
void positions()
{
    gotoRowCol(16, 65);
    cout<<"Ladder Positions(L/) "<<endl;
    gotoRowCol(17, 65);
    cout<<"3 - 24"<<endl;
    gotoRowCol(18, 65);
    cout<<"14 - 42"<<endl;
    gotoRowCol(19, 65);
    cout<<"37 - 57"<<endl;
    gotoRowCol(20, 65);
    cout<<"50 - 96"<<endl;
    gotoRowCol(21, 65);
    cout<<"66 - 74"<<endl;
    gotoRowCol(22, 65);
    cout<<"Snake Positions(&)"<<endl;
    gotoRowCol(23, 65);
    cout<<"99 - 5"<<endl;
    gotoRowCol(24, 65);
    cout<<"77 - 45"<<endl;
    gotoRowCol(25, 65);
    cout<<"60 - 28"<<endl;
    gotoRowCol(26, 65);
    cout<<"20 - 2"<<endl;
    //L print
    gotoRowCol(39,38);//3-24
    cout<<"L/";
    gotoRowCol(35,33);//14-42
    cout<<"L/";
    gotoRowCol(27, 18);//37-57
    cout<<"L/";
    gotoRowCol(23,3);//50-96
    cout<<"L/";
    gotoRowCol(15,23);//66-74
    cout<<"L/";
    //Snakes
    gotoRowCol(3,8);//99-5
    cout<<"&";
    gotoRowCol(11,18);//77-45
    cout<<"&";
    gotoRowCol(19,3);//60-28
    cout<<"&";
    gotoRowCol(39,43);//20-2
    cout<<"&";
}
int snake_Ladder(int &X, int &Y, int &P)
{
    //P1
    if(X==1 && Y==8)//99-5
    {
        X=37;
        Y=28;
        P=5;
    }
    if(X==9 && Y==18)//77-45
    {
        X=21;
        Y=28;
        P=45;
    }
    if(X==17 && Y== 3)//60-28
    {
        X=29;
        Y=13;
        P=28;
    }
    if(X==33 && Y==3)//20-2
    {
        X=37;
        Y=43;
        P=2;
    }
    //P2
        if(X==1 && Y==9)//99-5
    {
        X=37;
        Y=29;
        P=5;
    }
    if(X==9 && Y==19)//77-45
    {
        X=21;
        Y=29;
        P=45;
    }
    if(X==17 && Y== 4)//60-28
    {
        X=29;
        Y=14;
        P=28;
    }
    if(X==33 && Y==4)//20-2
    {
        X=37;
        Y=44;
        P=2;
    }
    //Ladders
    if(X==37 && Y==38)//3-24
    {
        X=29;
        Y=33;
         P=24;
    }
    if(X==33 && Y==33)//14-42
    {
        X=21;
        Y=43;
        P=42;
    }
    if(X==25 && Y==18)//37-57
    {
        X=17;
        Y=18;
        P=57;
    }
    if(X==21 && Y==3)//50-96
    {
        X=1;
        Y=23;
        P=96;
    }
    if(X==13 && Y==23)//66-74
    {
        X=9;
        Y=33;
        P=74;
    }

}
void move_xy1(int &X, int &Y, int &n,int &P1)
{

    P1=P1+n;
        if(P1<100)
            {
                P1=P1;
            }
    else if(P1>100)
            {
                P1=P1-n;
            }
    for(int i=1; i<P1; i++)
            {
                gotoRowCol(X, Y);
                int s1=Y;
                Y=Y-5;
                if(s1==3)
                {
                    Y=48;
                    X=X-4;
                }
            }
}
void move_xy2(int &X, int &Y, int &n,int &P2)
{
    P2=P2+n;
    if(P2<100)
            {
                P2=P2;
            }
    else if(P2>100)
            {
                P2=P2-n;
            }
    for(int i=1; i<P2; i++)
            {
                gotoRowCol(X, Y);
                int s2=Y;
                Y=Y-5;
                if(s2==4)
                {
                    Y=49;
                    X=X-4;
                }
            }

}

int check_six_P1(int &t,int &D,int x1,  int y1, int &P1,char ps1)
{
    int a=0, b=0,c=0,d=0;
    if(t==0)
    {
        a=roll_dice(D);
        if(a==6)
        {
            b=a+b;
            a=roll_dice(D);
            c=a+b;
            if(c==12)
            {
                a=roll_dice(D);
                d=c+a;
            }
            if(d>=18)
            {
                return 0;
            }
            if(c<=11)
            {
                c=c-6;
                move_xy1(x1,y1,c,P1);
                snake_Ladder(x1,y1,P1);
                gotoRowCol(x1,y1);
                cout<<ps1;
                t++;
                return t;
            }
            else if(c>=12)
            {
                d=d-6;
                move_xy1(x1,y1,d,P1);
                snake_Ladder(x1,y1,P1);
                gotoRowCol(x1,y1);
                cout<<ps1;
                t++;
                return t;
            }
        }
    }
}

int check_P1(int &t,int &D,int x1, int y1,int &P1,char ps1)
{
    int a=0, b=0,c=0,d=0;
    if(t==1)
    {
        a=roll_dice(D);
        if(a==6)
        {
            b=a+b;
            a=roll_dice(D);
            c=a+b;
            if(c==12)
            {
                a=roll_dice(D);
                d=c+a;
            }
            if(d>=18)
            {
                return 0;
            }
            if(c<=11)
            {
                move_xy1(x1,y1,c,P1);
                snake_Ladder(x1,y1,P1);
                gotoRowCol(x1,y1);
                cout<<ps1;
                return t;

            }
            else if(c>=12)
            {
                move_xy1(x1,y1,d,P1);
                snake_Ladder(x1,y1,P1);
                gotoRowCol(x1,y1);
                cout<<ps1;
                return t;
            }
        }
        else
        {
                gotoRowCol(39,65);
                move_xy1(x1,y1,a,P1);
                snake_Ladder(x1,y1,P1);
                gotoRowCol(x1,y1);
                cout<<ps1;
                gotoRowCol(38,65);
                return t;
        }
    }
}
int check_six_P2(int &t1,int &D,int x2,int y2, int &P2,char ps2)
{
int a=0, b=0,c=0,d=0;
    if(t1==0)
    {
        a=roll_dice(D);
        if(a==6)
        {
            b=a+b;
            a=roll_dice(D);
            c=a+b;
            if(c==12)
            {
                a=roll_dice(D);
                d=c+a;
            }
            if(d>=18)
            {
                return 0;
            }
            if(c<=11)
            {
                c=c-6;
                move_xy2(x2,y2,c,P2);
                snake_Ladder(x2,y2,P2);
                gotoRowCol(x2,y2);
                cout<<ps2;
                t1++;
                return t1;
            }
            else if(c>=12)
            {
                d=d-6;
                move_xy2(x2,y2,d,P2);
                snake_Ladder(x2,y2,P2);
                gotoRowCol(x2,y2);
                cout<<ps2;
                t1++;
                return t1;
            }
        }
    }
}
int check_P2(int &t1, int &D,int x2,int y2,int &P2,char ps2)
{

    int a=0, b=0,c=0,d=0;
    if(t1==1)
    {
        a=roll_dice(D);
        if(a==6)
        {
            b=a+b;
            a=roll_dice(D);
            c=a+b;
            if(c==12)
            {
                a=roll_dice(D);
                d=c+a;
            }
            if(d>=18)
            {
                return 0;
            }
            if(c<=11)
            {
                move_xy2(x2,y2,c,P2);
                snake_Ladder(x2,y2,P2);
                gotoRowCol(x2,y2);
                cout<<ps2;
                return t1;
            }
            else if(c>=12)
            {
                move_xy2(x2,y2,d,P2);
                snake_Ladder(x2,y2,P2);
                gotoRowCol(x2,y2);
                cout<<ps2;
                return t1;
            }
        }
        else
        {

                gotoRowCol(40,65);
                move_xy2(x2,y2,a,P2);
                snake_Ladder(x2,y2,P2);
                gotoRowCol(x2,y2);
                cout<<ps2;
                gotoRowCol(45,65);
                return t1;
        }
    }
}
void writer(int sr,int sc,int x,int w,int turn,int D,int x1,int y1,int x2,int y2,int t,int t1,int P1,int P2,int pp1,int pp2,char c,char ps1, char ps2)
{
    ofstream write("snake_ladder.txt");
    write<<sr<<" "<<sc<<" "<<x<<" "<<w<<" "<<turn<<" "<<D<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<t<<" "<<t1<<" "<<P1<<" "<<P2<<" "<<pp1<<" "<<pp2<<" "<<c<<" "<<ps1<<" "<<ps2;
}
void reader(int &sr,int &sc,int &x,int &w,int &turn,int &D,int &x1,int &y1,int &x2,int &y2,int &t,int &t1,int &P1,int &P2,int &pp1,int &pp2,char &c, char &ps1, char &ps2)
{
    ifstream read("snake_Ladder.txt");
    read>>sr>>sc>>x>>w>>turn>>D>>x1>>y1>>x2>>y2>>t>>t1>>P1>>P2>>pp1>>pp2>>c>>ps1>>ps2;
}
int update_position(int &t,int &t1,int &D, int x1, int y1,int x2, int y2,int &turn,int &P1, int &P2, int & pp1, int & pp2,int sr,int sc,int x,int w,char c,char ps1,char ps2)
{
    gotoRowCol(28,65);
    cout<<"Player "<<turn+ 1<<" turn";
    pp1 = P1;
    writer(sr, sc,x,w,turn, D, x1,y1, x2,y2, t, t1, P1, P2, pp1, pp2, c,ps1,ps2);
    if(turn==0)
    {
        if(t==0)
        {
        check_six_P1(t,D,x1,y1,P1,ps1);
        }
    else if(t==1)
        {
        check_P1(t,D,x1,y1,P1,ps1);
        }
        gotoRowCol(31,65);
        cout<<"Player_1 %: "<<P1<<" ";
    }

    else
    {
        writer(sr, sc,x,w,turn, D, x1,y1, x2,y2, t, t1, P1, P2, pp1, pp2, c,ps1,ps2);
        pp2 = P2;
        if(t1==0)
        {
        check_six_P2(t1,D,x2,y2,P2,ps2);
        }
        else if(t1==1)
        {
        check_P2(t1,D,x2,y2,P2,ps2);
        }
        gotoRowCol(32,65);
        cout<<"Player_2 @: "<<P2<<" ";
    }
}
void erase_S(int x1, int y1, int x2, int y2,int &turn, int &P1, int &P2 )
{
    int E=0;
    if(turn==1)
    {
        move_xy1(x1, y1, E,P1);
        gotoRowCol(x1, y1);
        sleep(10000);
        cout<<" ";
    }
    else
    {
        move_xy2(x2, y2, E,P2);
        gotoRowCol(x2, y2);
        sleep(10000);
        cout<<" ";
    }
}
int main()
{
    char y;
    cout<<"If you want to continue previous game press 'p' otherwise for new name press any key: "<<endl;
    cin>>y;
    gotoRowCol(0,0);
    cout<<"                                                                                      ";
    int sr=0,sc=0,x=4,w=5,turn=0,D; //declaring variables for boxe
    int x1= 37, y1= 48;
    int x2=37, y2=49;
    int t=0, t1=0;
    int P1=0, P2=0;
    int pp1=0, pp2=0;
    char c =char(219);
    char ps1='%';
    char ps2='@';
    Boxes(sr,sc,w,x,c); //this will print boxes on screen console-based
    positions();	//showing snake and ladder positions
    if(y=='p') 		//checking if you wanna resume game by pressing "p" // File handling
    {
        reader(sr, sc,x,w,turn, D, x1,y1, x2,y2, t, t1, P1, P2, pp1, pp2, c,ps1,ps2);
    }
    do			//or  pressing any key will lead you play new game 
    {
        erase_S(x1, y1, x2, y2, turn , pp1, pp2);
        update_position(t,t1,D,x1,y1,x2,y2,turn,P1,P2,pp1,pp2,sr,sc,x,w,c,ps1,ps2);
        change_turn(turn);
    }
    while(P1!=100 && P2!=100);		//condition to terminate game if true
    if(P1==100)
    {
        gotoRowCol(40,65);
        cout<<"Player 1 win";
    }
    else if(P2==100)
    {
        gotoRowCol(42,65);
        cout<<"Player 2 win";
    }
    else
    {
        gotoRowCol(38,120);
        cout<<"  ";
    }
    gotoRowCol(50,50);
}
