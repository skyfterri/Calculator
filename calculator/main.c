#include <stdio.h>
#include <math.h>

int readnr(int a)
{
    scanf("%d", &a);
    return a;
}
int calculator_sum (int a, int b)
{
    int c;
    c=a+b;
    printf("= %d",c);
    return c;
}
int calculator_sub(int a, int b)
{
    int c;
    c=a-b;
    printf("= %d",c);
    return c;
}
int calculator_product(int a, int b)
{
    int c;
    c=a*b;
    printf("= %d",c);
    return c;
}
double calculator_division (int a, int b)
{
    double c;
    c=(double)a/b;
    printf("= %.2lf", (double)a/b);
    return c;
}
double calculator_squareroot (int a)
{
    double c;
    c=(double)sqrt(a);
    printf("= %.2lf", c);
    return c;
}
int calculator_power (int a, int b)
{
    int c;
    c=pow(a,b);
    printf("= %d", c);
    return c;
}
double calculator_average ()
{
    double sum=0,n=0;
    double z;
    double a;
    while (1)
    {
        scanf("%lf",&a);
        if (a==0)
        {
            break;
        }
        sum+=a;
        n++;
    }
    z=sum/n;
    printf ("%.2lf",z);
    return z;
}


int main()
{
    int nr1,nr2,sum,sub,prod,y;
    double divi,x,avg;
    char average;
    scanf("%c",&average);
    if (average=='a')
    {
        avg=calculator_average();
    }
    else
    {
    nr1=readnr(nr1);
    char op;
    scanf ("%c",&op);
    if (op=='!')
    {
        x=calculator_squareroot(nr1);
    }
    nr2=readnr(nr2);
    if (op=='+')
    {
        sum=calculator_sum(nr1,nr2);
    }
    if (op=='-')
    {
        sub=calculator_sub(nr1,nr2);
    }
    if (op=='*')
    {
         prod=calculator_product(nr1,nr2);
    }
    if (op=='/')
    {
        divi=calculator_division(nr1,nr2);
    }

    if (op=='^')
    {
        y=calculator_power(nr1,nr2);
    }
    }
    return 0;
}
