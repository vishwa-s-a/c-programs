#include<stdio.h>
#include<conio.h>
#include<string.h>
// imp note is create a global struct variable so all user defined and main functions can access the template of the structure.
struct records
    {
        char author[30];
        char title[30];
        int price;
        struct
        {
            char publisher[30];
            int year;
            char month[20];
        }info;
        int quantity;
    };
int look_up(struct records table[5],char a[20],char b[20]);// here we are creating new struct variable called table as we are using call by value functions.
void main()
{
    char bookname[30];
    char bookauthor[20];
    int index,quantity;
    char d;
    struct records books[5]={{"vishwa","abcdef",250,"appaji",2000,"july",100},{"sachin","qwert",350,"motor",2010,"june",120},{"aishu","oiuiu",200,"amw",2020,"aug",130},{"soumya","zcvbb",450,"medico",2001,"sep",140}};
    printf("please enter title of the book\n");
    scanf("%s",&bookname);
    printf("please enter the name of the author of the book\n");
    scanf("%s",&bookauthor);
    index=look_up( books,bookname,bookauthor);
    if (index==-1)
    {
        printf("Sorry the requested book is not available, please search for any other book\n");
    }
    else{
        printf("The requested book details are as follows:\n");
        printf(" book name:%s\n book author:%s\n book price:%d\n book publisher:%s\n number of books instocks:%d\n",books[index].title,books[index].author,books[index].price,books[index].info.publisher,books[index].quantity);
    }
    printf("Please check accordingly the number of books in stocks and enter your requirements\n");
    scanf("%d",&quantity);
    printf("Thank you for your response, are you ready to checkout\n");
    printf("To checkout please enter Y or to exit enter N\n");
    fflush(stdin);
    scanf("%c",&d);
    if((d=='Y')||(d=='y'))
    {
        printf("Total amount to be paid is: %d\n",quantity*(books[index].price));
    }
    else if((d=='N')||(d=='n'))
    {
        printf("You can add some more books to cart or cancel all books from your cart Thankyou");
    }
    printf("Thank you for visiting our shop, have a good day\n");


}
int look_up(struct records table[5],char a[20],char b[20])
{
    int i;
    for(i=0;i<5;i++)
    {
        if((strcmp(a,table[i].title)==0) &&(strcmp(b,table[i].author)==0))
        return i;
        else
        return -1;
    }

}
