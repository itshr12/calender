#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int year,month;
    printf("Enter year and month:");
    scanf("%d %d",&year,&month);
    calender(year,month);
    return 0;
}

int yearadj(int year,int month)
{
    if(month<3)
    {
        month=month+13;
        year=year-1;
    }
    int k=year%100;
    int j=year/100;
    int day=(1+(13*(month+1)/5)+k+(k/4)+(j/4)-(2*j))%7;
    return day;
}
int days(int month,int year)
{
    int dinmon[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(month==2)
    {
        if(year%100!=0||year%400==0&&year%4==0)
        {
            return 29;
        }
    }
    return dinmon[month-1];
}
int calender(int year,int month)
{
    printf("calender for %d and %d\n",year,month);
    printf("  sa su mo tu we th fr\n");
    int fday=yearadj(year,month);
    int tday=days(month,year);
    for(int i=0;i<fday;i++)
    {
        printf("   ");
    }
    for(int dd=1;dd<=tday;dd++)
    {
        printf("%3d",dd);
        if((dd+fday)%7==0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
