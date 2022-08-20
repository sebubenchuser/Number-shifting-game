
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
int system();
void print_board();
int winner();
void starting_board();
void input_randomnumber();
int right_shift();
int left_shift();
int up_shift();
int down_shift();
int  enter_key();
int board[4][4],move=400;
char name[30];

int main()
{
    int status=1,w=0,key;
    char yes[1];
   starting_board();

    while(move>1)
    {
       input_randomnumber();
        while(status==1)
   {
       printf(".....");
       print_board();
       w=winner();
       if(w==1)
       {
           printf("\nCongratulation  you won the match !!!!!!!!!!");
           printf("\nwant to play again ? \n");
           printf("enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  ");
           scanf("%s",&yes);
           if(yes[0]=='y'||yes[0]=='Y')
           {
             break;
           }
           if(yes[0]=='n'||yes[0]=='N')
           {
               break;
           }
       }
       if(move<1)
       {
           printf("\n\a          YOU LOSE !          \a\a\n");
           printf("\nwant to play again ? \n");
          printf("enter 'y'/'Y' to play again  and enter 'n'/'N' to not play again :  ");
           fflush(stdin);
           scanf("%s",&yes);
           if(yes[0]=='y'||yes[0]=='Y')
           {
              move=400;
               break;
           }
           if(yes[0]=='n'||yes[0]=='N')
           {
               break;
           }
       }
       key=enter_key();
       switch(key)
       {
           case 1:
           {
              exit(0);
           }
           case 2:
           {
             right_shift();
             break;
           }
           case 3:
           {
             left_shift();
             break;
           }
           case 4:
           {
             up_shift();
             break;
           }
           case 5:
           {
             down_shift();
             break;
           }
       }

   }

    }
    return 0;



    }


void starting_board()
{
 int move=0;
    printf(".........................WELLCOME TO OUR!!...............................\n ");
    printf(".......................Number Shifting Game............................\n\n");
    printf("                        :Rules of This Game:\n");
    printf("                         ------------------\n\n\n");
    printf("1.You can move only 1 step at a time by arrow key:\n\n");
    printf("       -> Move up: by 'u'/'U' key.\n");        //printf("       -> Move up: by up arrow key.\n");
    printf("       -> Move Down: by 'd'/'D' key.\n");       //printf("       -> Move up: by down arrow key.\n");
    printf("       -> Move left: by 'l'/'L' key.\n");     // printf("       -> Move left: by left arrow key.\n");
    printf("       -> Move Right: by 'r'/'R' key.\n\n");        //printf("       -> Move Right: by Right arrow key.\n\n");
    printf("2. You can move number at empty position only.\n\n");
    printf("3.For each valid move: your total number of move will decreased by 1.\n\n");
    printf("4. Winning situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf("                        Winning Situation:\n\n");
    printf("                    -------------------------\n");
    printf("                    |  %d  |  %d  |  %d  |  %d  |\n",1,2,3,4);
    printf("                    -------------------------\n");
    printf("                    |  %d  |  %d  |  %d  |  %d  |\n",5,6,7,8);
    printf("                    -------------------------\n");
    printf("                    |  %d  |  %d |  %d |  %d |\n",9,10,11,12);
    printf("                    -------------------------\n");
    printf("                    |  %d |  %d |  %d |     |\n",13,14,15);
    printf("                    -------------------------\n\n");
    printf("5. You can exit the game at any time by pressing 'E' or 'e'.\n\n");
    printf("                     :So Try to win in minimum no. of move:\n");
    printf("                     .....................................\n");
    printf(".........................Happy gaming!! &  Good Luck!!..................\n\n");
    printf("Please enter your Name:");
    fgets(name,30,stdin);
    printf("\n\n\n");
    printf("           ##########################################################\n\n");
    printf("                        your game start from now\n\n\n");

}

int  enter_key()
{
    char k[1];
    printf("Enter key");
    fflush(stdin);
    scanf("%s",k);
    fflush(stdin);
    if(k[0]=='E'||k[0]=='e')
    {
        printf("\n................Thank you................\n");
        printf("           We will see next time              ");
        return 1;
    }
    if(k[0]=='R'||k[0]=='r')
    {
        return 2;
    }
    if(k[0]=='L'||k[0]=='l')
    {
        return 3;
    }
    if(k[0]=='U'||k[0]=='u')
    {
        return 4;
    }
    if(k[0]=='D'||k[0]=='d')
    {
        return 5;
    }

}

void input_randomnumber()
{
 int a[16],number,space;
  int  lower=1,upper=15,i,j,k=1,c,l=0;
    srand(time(0));
    space=rand()%10;
    for(i=0;i<16;i++)
    {

          while(k==1)
        {
           number=(rand()%(upper-lower+1))+lower;
           c=0;
           for(j=0;j<i+1;j++)
           {
              if(a[j]==number)
              {

                c++;
              }
           }
           if(c==0)
           {
               if(i==space)
               {
                   a[i]=0;
               }
               else
               {
                 a[i]=number;
               }
               break;
           }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {

               board[i][j]=a[l];
                l++;

        }
    }

}



void print_board()
{
    int i,j;
    printf("\n");
    system("cls");
    printf("Player name :%s                   Move:%d\n\n",name,move);
    for(i=0;i<4;i++)
    {
      printf("        --------------------\n");
       printf("        | ");
        for(j=0;j<4;j++)
        {
          if(board[i][j]!=0)
           printf(" %2d |",board[i][j]);
           else
           printf(" %2c |",' ');
        }
        printf("\n");
    }

   printf("        ---------------------\n");

}


       //left shifting function

int left_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(j<=2)
    {
    temp=board[i][j];
    board[i][j]=board[i][j+1];
    board[i][j+1]=temp;
    move--;
    }
    else
    printf("Shifting is not possible!!");

}

       //left shifting function.

int right_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(j>=1)
    {
      temp=board[i][j];
    board[i][j]=board[i][j-1];
    board[i][j-1]=temp;
    move--;
    }
    else
    printf("Shifting is not possible!!");

}

     // up Shifting function

int up_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(i<=2)
    {
      temp=board[i][j];
    board[i][j]=board[i+1][j];
    board[i+1][j]=temp;
    move--;
    }
    else
    printf("Shifting is not possible!!");

}



 // Down Shifting function

int down_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(i>=1)
    {
      temp=board[i][j];
    board[i][j]=board[i-1][j];
    board[i-1][j]=temp;
    move--;
    }
    else
    printf("Shifting is not possible!!");

}

int winner()
{
    int i,j,k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            k++;
            if(board[i][j]!=k)
            break;
        }
    }
    if(k==15)
    return 1;
    else
    return 0;
}



/*#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
void print_board();
void starting_board();
void input_randomnumber();
int right_shift();
int board[4][4];
int main()
{
    int status=1,w=0,key;
   starting_board();
   while(status==1)
   {
       input_randomnumber();
       print_board();
       w=winner();
       if(w==1)
       {
           printf("\nCongratulation  you won the match !!!!!!!!!!");
       }
       key=enter_key();
       if(key==0)
        {
         break;
        }
        if(key==1)
        {
         break;
        }
   }



   print_board();
   down_shift();
    print_board();
    return 0;
}
void starting_board()
{
 char name[30];
 int move=0;
    printf(".........................WELLCOME TO OUR!!...............................\n ");
    printf(".......................Number Shifting Game............................\n\n");
    printf("                        :Rules of This Game:\n");
    printf("                         ------------------\n\n\n");
    printf("1.You can move only 1 step at a time by arrow key:\n\n");
    printf("       -> Move up: by up arrow key.\n");
    printf("       -> Move Down: by Down arrow key.\n");
    printf("       -> Move left: by left arrow key.\n");
    printf("       -> Move Right: by Right arrow key.\n\n");
    printf("2. You can move number at empty position only.\n\n");
    printf("3.For each valid move: your total number of move will decreased by 1.\n\n");
    printf("4. Winning situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    printf("                        Winning Situation:\n\n");
    printf("                    -------------------------\n");
    printf("                    |  %d  |  %d  |  %d  |  %d  |\n",1,2,3,4);
    printf("                    -------------------------\n");
    printf("                    |  %d  |  %d  |  %d  |  %d  |\n",5,6,7,8);
    printf("                    -------------------------\n");
    printf("                    |  %d  |  %d |  %d |  %d |\n",9,10,11,12);
    printf("                    -------------------------\n");
    printf("                    |  %d |  %d |  %d |     |\n",13,14,15);
    printf("                    -------------------------\n\n");
    printf("5. You can exit the game at any time by pressing 'E' or 'e'.\n\n");
    printf("                     :So Try to win in minimum no. of move:\n");
    printf("                     .....................................\n");
    printf(".........................Happy gaming!! &  Good Luck!!..................\n\n");
    printf("Please enter your Name:");
    fgets(name,30,stdin);
    printf("\n\n\n");
    printf("           ##########################################################\n\n");
    printf("                        your game start from now\n\n\n");
    printf("       Player Name: %s",name);
    printf("       Moves Fixe: %d\n",move);


}

int  enter_key()
{
    char k;
    printf("Enter key");
    scanf("%c",&k);
    if(k=='E'||k=='e')
    {
        printf("\n................Thank you................\n");
        printf("           We will see next time              ");
        return 1;
    }
    if(k=='R'||k=='r')
    {
        return 2;
    }
    if(k=='L'||k=='l')
    {
        return 3;
    }
    if(k=='U'||k=='u')
    {
        return 4;
    }
    if(k=='D'||k=='d')
    {
        return 5;
    }

}

void input_randomnumber()
{
 int a[16],number,space;
  int  lower=1,upper=15,i,j,k=1,c,l=0;
    srand(time(0));
    space=rand()%10;
    for(i=0;i<16;i++)
    {

          while(k==1)
        {
           number=(rand()%(upper-lower+1))+lower;
           c=0;
           for(j=0;j<i+1;j++)
           {
              if(a[j]==number)
              {

                c++;
              }
           }
           if(c==0)
           {
               if(i==space)
               {
                   a[i]=0;
               }
               else
               {
                 a[i]=number;
               }
               break;
           }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {

               board[i][j]=a[l];
                l++;

        }
    }

}



void print_board()
{
    int i,j;
    printf("\n");
    for(i=0;i<4;i++)
    {
      printf("        --------------------\n");
       printf("        | ");
        for(j=0;j<4;j++)
        {
          if(board[i][j]!=0)
           printf(" %2d |",board[i][j]);
           else
           printf(" %2c |",' ');
        }
        printf("\n");
    }

   printf("        ---------------------\n");

}


       //left shifting function

int left_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(j<=2)
    {
    temp=board[i][j];
    board[i][j]=board[i][j+1];
    board[i][j+1]=temp;
    }
    else
    printf("Shifting is not possible!!");

}

       //left shifting function.

int right_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(j>=1)
    {
      temp=board[i][j];
    board[i][j]=board[i][j-1];
    board[i][j-1]=temp;
    }
    else
    printf("Shifting is not possible!!");

}

     // up Shifting function

int up_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(i>=1)
    {
      temp=board[i][j];
    board[i][j]=board[i-1][j];
    board[i-1][j]=temp;
    }
    else
    printf("Shifting is not possible!!");

}



 // Down Shifting function

int down_shift()
{
    int i,j,k,temp;
    for(i=0;i<4;i++)
    {
        k=0;
        for(j=0;j<4;j++)
        {
           if(board[i][j]==0)
           {
               k++;
           break;
           }
        }
        if(k==1)
           break;
    }
    if(i<=2)
    {
      temp=board[i][j];
    board[i][j]=board[i+1][j];
    board[i+1][j]=temp;
    }
    else
    printf("Shifting is not possible!!");

}

int winner()
{
    int i,j,k=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            k++;
            if(board[i][j]!=k)
            break;
        }
    }
    if(k==15)
    return 1;
    else
    return 0;
}*/















