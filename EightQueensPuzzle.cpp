#include <iostream>
using namespace std;

// Global Var
bool ChessBoard[8][8];
int Counter = 1;

// return 0 = func work true
// return 1 = no more space to shift
// return 2 = no more solution
int Shifter(int line)
{
    for (int i = 0; i < 8; i++)
        if (ChessBoard[line][i])
        {
            if (i + 1 < 8)
            {
                ChessBoard[line][i] = 0;
                ChessBoard[line][i + 1] = 1;
                return 0;
            }
            else
            {
                if (!line)
                    return 2;
                return 1;
            }
        }
}
void Initialize(int line = 0)
{
    ChessBoard[line][0] = 1;
}

void print()
{
    cout << "__________________________\n"
         << Counter << ".\n\n";
    Counter++;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << ChessBoard[i][j] << "  ";
        }
        cout << endl;
    }
}
// return 0 = Not Hitted
// return 1 = Hitted
bool DiagonalHitResult_Comp(int line, int target)
{
    for (int i = line - 1, j = 1; i >= 0; i--, j++)
    {
        if (target - j >= 0)
        {
            if (ChessBoard[i][target - j])
            {
                return 1;
            }
        }
        if (target + j < 8)
        {
            if (ChessBoard[i][target + j])
            {
                return 1;
            }
        }
    }
    return 0;
}
// return 0 = Not Hitted
// return 1 = Hitted
bool LinearHitResult_Comp(int line, int target)
{
    for (int i = line - 1; i >= 0; i--)
        if (ChessBoard[i][target])
        {
            return 1;
        }
    return 0;
}
// return 0 = Not Hitted
// return 1 = Hitted
bool HitResult(int line)
{
    if (!line)
        return 0;
    int target = -1;
    for (int i = 0; i < 8; i++)
        if (ChessBoard[line][i])
        {
            target = i;
            break;
        }
    if (target != -1)
        return LinearHitResult_Comp(line, target) + DiagonalHitResult_Comp(line, target);
}
void ClearLine(int line)
{
    for (int i = 0; i < 8; i++)
    {
        ChessBoard[line][i] = 0;
    }
}
int main()
{
    int line = 1;
    Initialize();
    Initialize(line);

A:

    bool hitresult = HitResult(line);
    if (hitresult)
    {
    B:
        int shiftresult = Shifter(line);
        switch (shiftresult)
        {
        case 0:
            goto A;
            break;
        case 1:
            ClearLine(line);
            line--;
            goto B;
            break;
        case 2:
            cout << "\nDone !!!";
            break;
        }
    }
    else
    {
        if (line + 1 < 8)
        {
            line++;
            Initialize(line);
            goto A;
        }
        else
        {
            print();
            goto B;
        }
    }
    return 0;
}
