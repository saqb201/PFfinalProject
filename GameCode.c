#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

void creatematrix(int a[][4])
{
  int i,j=1,k,r,ar[16]={0},arr[15];
  srand(time(0));
  for(k=0;k<15;k++)
  {
     r=1+rand()%15;
     if(!ar[r])
          arr[j++]=r;
     else
          k--;
     ar[r]=1;
  }
  for(i=0;i<4;i++)
  {
       for(j=0;j<4;j++)
          a[i][j]=arr[4*i+j+1];
  }
  a[i-1][j-1]=0;
}

void showmatrix(int a[][4])
{
     int i,j;
     printf("\n\n\n---------------------\n");
     for(i=0;i<4;i++)
     {
          printf("| ");
          for(j=0;j<4;j++){
               if(a[i][j]!=0)
                 printf("%-2d | ",a[i][j]);
               else
                    printf("   | ");
          }
          printf("\n");
     }
     printf("---------------------\n");
}

int winner(int a[][4])
{
     int i,j,k=1;
     for(i=0;i<4;i++)
     {
          for(j=0;j<4;j++)
               if(a[i][j]!=k&&k!=16)
                 break;
          if(j<4)
            break;
     }
     if(j<4)
          return 0;
     else
          return 1;
}

void swap(int *p , int *q)
{
     *p=*p+*q;
     *q=*p-*q;
     *p=*p-*q;
     printf("");
}

int readEnteredkey()
{
     char c;
     c=getch();
     if(c==-32)
          c=getch();
     return c;


return c;
}

int shiftup(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
          for(j=0;j<4;j++)
               if(a[i][j]==0)
                 break;
          if(j<4)
             break;
     }
     if(i==3)
          return 0;
     else{
          swap(&a[i][j],&a[i+1][j]);
          return 1;
     }
}

int shiftdown(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
          for(j=0;j<4;j++)
               if(a[i][j]==0)
                 break;
          if(j<4)
             break;
     }
     if(i==0)
          return 0;
     else{
          swap(&a[i][j],&a[i-1][j]);
          return 1;
     }
}

int shiftleft(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
          for(j=0;j<4;j++)
               if(a[i][j]==0)
                 break;
          if(j<4)
             break;
     }
     if(j==3)
          return 0;
     else{
          swap(&a[i][j],&a[i][j+1]);
          return 1;
     }
}
int shiftright(int a[][4])
{
     int i,j;
     for(i=0;i<4;i++)
     {
          for(j=0;j<4;j++)
               if(a[i][j]==0)
                 break;
          if(j<4)
             break;
     }
     if(j==0)
          return 0;
     else{
          swap(&a[i][j],&a[i][j-1]);
          return 1;
     }
}
void gamerule(int a[][4])
{
     int i,j,x;
     system("cls");

     printf("              RULE OF THIS GAME\n");
     printf("\n1.You can move only 1 step at a time by arrow key\n");
     printf("Move Up    : By Up arrow key\n");
     printf("Move Down  : By Down arrow key\n");
     printf("Move left  : By Left arrow key\n");
     printf("Move Right : By Right arrow key\n");
     printf("\n2.You can move number at empty position only");
     printf("\n3.For each valid move : your total number of move will decreased by 1");
     printf("\n4.Winning situation : number in a 4*4 matrix should be in order from 1 to 15\n\n");
     printf("              Winning situation\n");
     printf("-------------------\n");
     for(i=0;i<4;i++)
     {
          printf("|");
          for(j=0;j<4;j++){
               if(a[i][j]!=0)
                    printf("%2d | ",(4*i+j+1));
               else
                    printf("   |");
          }
          printf("\n");
     }
     printf("--------------------\n");
     printf("\n5.You can exit the game at any time by pressing 'E' or 'e'");
     printf("\nSo Try to win in minimum no. of move\n\n");
     printf("          Happy gaming , Good luck\n\n");
     printf("Enter any key to start......");
     x=readEnteredkey();
}
int main()
{
     system("4");
  int a[4][4],key;
  int maxtry=10000;

  char name[20];
  system("cls");
  printf("Enter Your name:");
  gets(name);
  while(1)
  {
       creatematrix(a);
       gamerule(a);

    while(!winner(a))
    {
         system("cls");
         if(!maxtry)
          break;
         printf("\tWelcome %s , Move Remaining : %d",name,maxtry);
         showmatrix(a);

         key=readEnteredkey();
        switch(key)
        {
        case 69:

        case 101:
          printf("\tThanks for Playing\nHit 'Enter' to exit....");
          key=readEnteredkey();
          exit(0);
        case 72:
          if(shiftup(a))
          maxtry--;
          break;
        case 80:
          if(shiftdown(a))
          maxtry--;
          break;
        case 75:
          if(shiftleft(a))
          maxtry--;
          break;
        case 77:
          if(shiftright(a))
          maxtry--;
          break;
        default:
          printf("\t\tNot allowed");
        }
    }
    if(!maxtry){
     printf("\n\n\n\t\tYOU LOSE");
     break;
    }
    else{
     printf("\n\n\n\t CONGRATULATION YOU WON!!!!!");
     break;
    }


  }
return 0;
}