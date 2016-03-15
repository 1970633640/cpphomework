
//This is a Test Input File for EraseComments

/*******************************************************************
// Programming problem 2  p672 
// Eight Queens Problem. 
//******************************************************************/
#include <iostream> // for cout
#include <fstream>  // for file operations
#include <iomanip>  // for setw
#include <ctime>    // for run time counting

using namespace std;

const int MAXNUM = 12 ;   //NUM <= 12

int NUM ;   

/****************************************************************/
/*      print layout                                            */
/****************************************************************/
void printBoard(const char [][MAXNUM]); 
/****************************************************************/
/*      recursive function to place each queen                  */
/****************************************************************/
void place(char [][MAXNUM],char,char);
/****************************************************************/
/*      rotate layout by 90 degree                              */
/****************************************************************/
void rotatematrix90(int rrow[MAXNUM],int rrow1[MAXNUM]);
/****************************************************************/
/*      decide if different solutuin "//found//"                */
/****************************************************************/
bool canfound(int rrow[MAXNUM], int rowcol[][MAXNUM],int solution);

int rowcol[14200][MAXNUM];
int solution=0;
int diffrowcol[3574][MAXNUM];
int diffsolution=0;

char c='\"';
const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();//time(0);

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
        for (int j=0;j<NUM;j++)
           outFile1 << "/*(" << rowcol[i][j]/100 << ',' << rowcol[i][j]%100 << "*/";
       outFile1 << endl;
   }

    ofstream outFile2("unique.txt");
   for ( i=0;i<diffsolution;i++ )
   {
       outFile2 << setw(3) << i+1 << ":" ;
        for (int j=0;j<NUM;j++)
           outFile2 << "/*(" << rowcol[i][j]/100 << ',' << rowcol[i][j]%100 << "*/)";
       outFile2 << endl;
   }

   cout << endl
        << "//Total number of solutions after eliminating solutions \n"
           "//that can be represented by rotating chessboard is "  
        << diffsolution
        << "// ." << endl;

   cout << endl << "Time Elasped : " 
        << 1000*(double)(endTime-startTime) / CLOCKS_PER_SEC 
        << " microseconds." << endl;

    {char ch; cout<<"press any key to exit" <<endl; cin.get(ch);cin.get(ch);}
    return 0;
}

void printBoard(const char board[][MAXNUM])
{
    int rrow[MAXNUM],rrow1[MAXNUM],rrow2[MAXNUM],rrow3[MAXNUM];
   for (int row=0; row<NUM; row++)
      for (int col=0; col<NUM; col++)
          if (board[row][col]>0) 
              rrow[row]=row*100+col;

// if (!canfound(rrow,rowcol,solution))
   {
       cout << "Solution " << setw(5) << solution+1 << ": ";
       for (int j=0;j<NUM;j++)
       {
           rowcol[solution][j]=rrow[j];
               cout << '(' << rrow[j]/100 <<','<<rrow[j]%100 << ')';
       }
       solution++;
       cout << endl;

           rotatematrix90(rrow,rrow1);
       if (canfound(rrow1,diffrowcol,diffsolution))
           return;
       rotatematrix90(rrow1,rrow2);
       if (canfound(rrow2,diffrowcol,diffsolution))
           return;
       rotatematrix90(rrow2,rrow3);
       if (canfound(rrow3,diffrowcol,diffsolution))
           return;

       for ( j=0;j<NUM;j++)
           diffrowcol[diffsolution][j]=rrow[j];
        diffsolution++;
   }
}

void place(char board[][MAXNUM], char r, char c)
{
   if (r+1==NUM) 
   {
       board[r][c] = r+1;
      printBoard(board);
      return;
    }

   for (char idx=0; idx<NUM; idx++)
   {
       board[r][idx] = -9;
       board[idx][c] = -9;
       int t=c+r-idx;
        if ( t>=0 && t<NUM )
           board[idx][t]=-9;
       t = c-r+idx;
        if ( t>=0 && t<NUM )
           board[idx][t]=-9;
   }   
   board[r][c] = r+1;

    for (char col=0; col<NUM; col++)
      if (!board[r+1][col]) 
          {   
              char bakboard[MAXNUM][MAXNUM];
              memcpy(bakboard,board,MAXNUM*MAXNUM*sizeof(char));
              place(bakboard,r+1,col);
          }
}

void rotatematrix90(int rrow[MAXNUM],int rrow1[MAXNUM])
{
       for (int i=0;i<NUM;i++)
       rrow1[i]=rrow[i]/100+100*(NUM-1-rrow[i]%100);
   for (    i=0;i<NUM;i++)
   {
       int min = rrow1[i];
       int minidx=i;
       for (int j=i+1;j<NUM;j++)
           if (rrow1[j]<min)
           {
               min=rrow1[j];
               minidx=j;
           }
       rrow1[minidx]=rrow1[i];
       rrow1[i]=min;
   }
}

bool canfound(int rrow[MAXNUM],int rowcol[][MAXNUM],int solution)
{
    bool found = false;
   for (int i=0; i<solution && !found; i++)
/* {
       int j=0;
       while (j<NUM && rrow[j]==rowcol[i][j]) 
           j++;
       if (j==NUM) 
           found=true;
    }
*/
       found = !memcmp(rrow,rowcol[i],NUM*sizeof(int)); 
   return found;
}

// End of Program. 
