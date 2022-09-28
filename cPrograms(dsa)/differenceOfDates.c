/*
*name: Vishwa Shivanand Appaji
*reg no: 21BCI0026
*here we calculate the difference between two dates.We can use this program for finding the age of person in years,months,dates
    from his date of birth.
*We can also use this program to find the difference between two random dates in terms of years,months,dates
*Here one more thing to be noted is that we are not including the last date of second date, if we include that then simply add 1 to final days 
    in difference.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct info
{
    int date;
    int month;
    int year;
}d1,d2,d3;
int isvalid(struct info d)
{
    int valid=0;
    int isleap=0;
    if(d.year>=1400 && d.year<=9999)
    {
        if((d.year%4==0 && d.year%100!=0) || d.year%400==0)
        {
            if(d.month==2)
            {
                if(d.date>29)
                return valid;
            }

        }
        else
        {
            if(d.month==2)
            {
                if(d.date>28)
                return valid;
            }
        }
        if(d.month>=1 && d.month<=12)
        {
            if(d.month==1 || d.month==3 || d.month==4 || d.month==7 ||d.month==8 || d.month==10 || d.month==12)
            {
                if(d.date>31)
                return valid;
            }
            else
            {
                if(d.date>30)
                return valid;
            }
        }
        else
        return valid;
    }
    else
    return valid;
}
int leap(int m)
{
    if((m%4==0 && m%100!=0) || m%400==0)
    {
        return 1;
    }
    return 0;
}
void exchange(struct info * d1,struct info * d2)//if user gives some random date and first is bigger than second then we simply exchange the 
// the dates and treat them as date of birth and present date. by this we can simply make this program look good,simple.
{
    int tempDate,tempMonth,tempYear;
    tempDate=d1->date;tempMonth=d1->month;tempYear=d1->year;
    d1->date=d2->date;d1->month=d2->month;d1->year=d2->year;
    d2->date=tempDate;d2->month=tempMonth;d2->year=tempYear;
    //printf("date1: %d/%d/%d\n",d1->date,d1->month,d1->year);
    //printf("date1: %d/%d/%d\n",d2->date,d2->month,d2->year);

}
int main()
{
    d3.date=0;d3.month=0;d3.year=0;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Enter the date: ");
    scanf("%d/%d/%d",&d1.date,&d1.month,&d1.year);
    printf("Enter the date: ");
    scanf("%d/%d/%d",&d2.date,&d2.month,&d2.year);
    if(d1.year>d2.year)// here we are checking if first date is smaller than second date or not,if not we simply exchange.
    {
        exchange(&d1,&d2);
    }
    if(isvalid(d1)==0 || isvalid(d2)==0)
    {
        printf("The entered dates are not valid\n");
    }
    else
    {
        if(d1.year<d2.year)
        {
            if(d1.month==d2.month)
            {
                if(d1.date<d2.date)
                {
                    d3.year=d2.year-d1.year;
                    d3.date=d2.date-d1.date;
                }
                else{
                    d3.year=d2.year-d1.year-1;
                    d3.month=d2.month-1;
                    d3.date=month[d2.month-1]-(d1.date-d2.date);//-1 as the end date is not included while calculating
                }
            }
            else
            {
                if(d2.month>d1.month)
                {
                    if(d2.date>d1.date)
                    {
                        d3.year=d2.year-d1.year;
                        d3.month=d2.month-d1.month;
                        d3.date=d2.date-d1.date;
                    }
                    else
                    {
                        d3.year=d2.year-d1.year;
                        d3.month=d2.month-d1.month-1;
                        d3.date=month[d1.month]-(d1.date-d2.date);
                    }
                }
                else
                {
                    if(d2.date==d1.date)
                    {
                        d3.month=(12-d1.month)+d2.month;
                    }
                    else if(d2.date>d1.date)
                    {
                        d3.year=d2.year-d1.year-1;
                        d3.month=(12-d1.month)+d2.month;
                        d3.date=d2.date-d1.date;
                    }
                    else
                    {
                        if(leap(d2.year)!=1)
                        {
                            d3.year=d2.year-d1.year-1;
                            d3.month=(12-d1.month)+d2.month-1;
                            d3.date=(month[d2.month-1]-d1.date)+d2.date;
                        }
                        else{
                            month[2]=29;
                            d3.year=d2.year-d1.year-1;
                            d3.month=(12-d1.month)+d2.month-1;
                            d3.date=(month[d2.month-1]-d1.date)+d2.date;
                        }
                        
                    }
                }
            }
            
        }

    }
    printf("%d years, %d months, %d days",d3.year,d3.month,d3.date);
    return 0;
}