/*   

    VS6.0    

*/
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <cmath>
using namespace std;
void dxxx();
int main()
{
    initgraph(400,400);
    dxxx();
    LOGFONT a={26,0,};
    setfont(&a);
    RECT r = {0, 180, 400, 400};
    TCHAR c[]=TEXT("爱你");
    drawtext(c,&r,DT_CENTER);
    getch();
}
void dxxx()
{
    float m,n,x,y;float i;
    for (i=0;i<=200;i=i+0.01)
    {
        //产生极坐标点
        m=i;
        n=-50*(((sin(i)*sqrt(fabs(cos(i))))/(sin(i)+1.4))-2*sin(i)+2);
        //转换为笛卡尔坐标
        x=n*cos(m)+200;
        y=n*sin(m)+150;
        putpixel(x,y,YELLOW);
    }
}
