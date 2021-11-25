#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** R, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    R[i][j] = Low + rand() % (High-Low+1);
    if (j<colCount-1)
        Create(R, rowCount, colCount, Low, High, i, j+1);
        if (i<rowCount-1)
           Create(R, rowCount, colCount, Low, High, i+1, 0);
}

void PrintRow(int** R, const int i, const int colCount, int j)
{
    cout << setw(4) << R[i][j];
    if ( j < colCount-1 )
        PrintRow(R, i, colCount, j+1);
    else
        cout << endl;
}
void PrintArr(int** R, const int rowCount, const int colCount, int i)
{
    PrintRow(R, i, colCount, 0);
    if ( i < rowCount-1 )
        PrintArr(R, rowCount, colCount, i+1);
    else
        cout << endl;
}

void Sum(int** R, const int rowCount, const int colCount, int i, int j, int& S, int& k)
{
    if(!( R[i][j] % 2 != 0 ))
    {
        if(!( i % 3 == 0 && j % 3 == 0 ))
        
            S += R[i][j];
            k++;
            R[i][j] = 0;
    }
    if (j<colCount-1)
        Sum(R, rowCount, colCount, i, j+1, S, k);
    else
    if (i<rowCount-1)
        Sum(R, rowCount, colCount, i+1, 0, S, k);
}

int main()
{
    srand((unsigned)time(NULL));
    int Low = 4;
    int High = 51;
    int rowCount = 8;
    int colCount = 5;
    int **R = new int*[rowCount];
    for (int i=0; i<rowCount; i++)
        R[i] = new int[colCount];
    
    Create(R, rowCount, colCount, Low, High, 0, 0);
    PrintArr(R, rowCount, colCount, 0);
   
    
    int S=0;
    int k=0;
    Sum(R, rowCount, colCount, 0, 0, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    PrintArr(R, rowCount, colCount, 0);
    
    for (int i=0; i<rowCount; i++)
        delete [] R[i];
    delete [] R;
    
    
    return 0;
}
