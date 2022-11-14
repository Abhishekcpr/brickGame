#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std ;


const int width = 60 ;
const int height = 20 ;
int score = 0 ;
 int dx = 1 ; 
 int dy = 1 ;
char matrix[height][width] ;
int ballX = 20, ballY = 2 ;


int boardX1 = 26 ;
int boardX2 = 27 ;
int boardX3 = 28 ;
int boardX4 = 29 ;
int boardX5 = 30 ;
int boardX6 = 31 ;
int boardX7 = 32 ;
int boardX8 = 33 ;
int boardX9 = 34 ;
bool endGame = false ;
int change = 5 ;



void createBox()
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j<width; j++ )
        {

            if(i == height - 2 && (j >= boardX1 && j <=boardX9 ))
            {
                    matrix[i][j] = 'T' ;
            }

         else  if(i ==0 || i== height - 1 )
           {
                matrix[i][j] = '_' ;
           }
           else if( j ==0 || j == width - 1)
           {
             matrix[i][j] = '|' ;
           }
           else if(i == ballY && j == ballX)
           {
            matrix[i][j] = 'O' ;
           }
           else
           {
             matrix[i][j] = ' ' ;

           }

        }
    }
    
}

void ENDGAME()
    {
        if(ballY == height )
        {
            endGame = true ;
        }
    }


void ballMotion()
{
   

   
        if(ballX==width - 2 || ballX == 1)
        {
            dx = -dx ;
        }

        if(ballY == 1 )
        {
            dy = - dy ; 
         }

        if(ballY == height-3)
        {
            if( ballX >= boardX1 && ballX <= boardX9)
            {
                dy = -dy ;
              
                score = score + 50 ;
                Beep(300,50);
            }
        }
         ballX = ballX + dx ;
         ballY = ballY + dy ;
    
}
void displayBox()
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j<width; j++ ) 
        {
            cout<<matrix[i][j] ;
        }
        cout<<endl;

    }

    cout<<"\n\n Your Score : "<<score ;
}

void boardMotion()
{
    if(_kbhit())
    {
       switch(_getch())
       {
        case 77 :

            if(boardX5 <= width-2)
        {   
           
            boardX9 = boardX9 + change  ;
            boardX8 = boardX8 + change  ;
            boardX7 = boardX7 + change  ;
            boardX6 = boardX6 + change  ;
             boardX5 = boardX5 + change  ;
            boardX4 = boardX4 + change  ;
           boardX3 = boardX3 + change  ;
           boardX2 = boardX2 + change  ;
           boardX1 = boardX1 + change  ;

         
            
        }

        break ;

        case 75 : 
         if(boardX1 >=1)
        { 
            boardX9 = boardX9 - change  ;
            boardX8 = boardX8 - change  ;
            boardX7 = boardX7 - change  ;
            boardX6 = boardX6 - change  ;  
           boardX5 = boardX5 - change  ;
           boardX4 = boardX4 - change  ;
           boardX3 = boardX3 - change  ;
           boardX2 = boardX2 - change  ;
           boardX1 = boardX1 - change  ;
        }

        break ;

        case 'x' :
        endGame = true ;
        break ;

        default :
        break ;
       }
        

   
    }
   
}
void delayTime()
{
    int i = 10000 ;
   
    while(i--)
    {
         int j = 10000;
       while(j--)
       {
           
       }
    }
}
int main()
{

    // ballX = 10 ;
    // ballY = 10 ;
    char ch ;
  cout<<"START GAME (Y/N) ?" ;
  cin>>ch ;
  if(ch == 'y')
  {
     while(!endGame)
  {
  displayBox();
    createBox();
  ballMotion() ;

   boardMotion() ;
    ENDGAME() ;
   system("cls") ;
    // Sleep(10) ;
   delayTime() ;
  }
    system("cls") ;

  cout<<"Thanks for playing !!!" ;
    cout<<endl<<"Your Score :"<<score ;
   for(int i=0; i<8; i++)
   {
    Beep(i*100, 500) ;
   }
  }
   
  else
  cout<<"Thanks for playing !!!" ;
 
}