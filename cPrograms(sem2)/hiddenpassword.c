// to take take the input of hidden password in the form of star
// and to print the same
#include<conio.h>
#include<dos.h> //delay()
#include<stdio.h>
#include<string.h>
void main()
{
  char pwd[9];
  int i;
  printf("Enter your password : ");
  for(i=0;i<8;i++)
  {
    pwd[i]=getch();
    printf("*");// to indicate a character is pressed by the user
  }
  pwd[i]='\0';
  printf("\n");
  printf("The entered password is: ");
  for(i=0;pwd[i]!='\0';i++)
  {
    printf("%c",pwd[i]);
  }
  getch();// by this getch() the console will wait for a key to be pressed to exit the program
}
