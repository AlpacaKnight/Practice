#include<stdio.h>
int i;
int j;
int k;
void f1()
{
    for(j=1;j<=4-i;j++)
        printf(" ");
}
void f2()
{
    for(k=1;k<=2*i+2;k++)
        printf("X");
}
int main()
{
    printf("    XX        XX \n");
    for(i=2;i<=4;i++)
    {
        f1();
        f2();
        f1();
        f1();
        f2();
        f1();
        printf("\n");
    }
    for(i=5;i<=14;i++)
    {
        for(j=0;j<i-5;j++)
            printf(" ");
        for(k=1;k<=30-2*i;k++)
            printf("X");
        printf("\n");
    }
    getchar();
    return 0;
}
