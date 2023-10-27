#include <stdio.h>
#include <math.h>

#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j)
{
    return (0 <= i && i <= ROW_CAP - 1 && 0 <= j && j <= COL_CAP - 1);
}

IdxType getLastIdxRow(Matrix m)
{
    return ROW_EFF(m) - 1;
}

IdxType getLastIdxCol(Matrix m)
{
    return COL_EFF(m) - 1;
}

boolean isIdxEffMatrix(Matrix m, IdxType i, IdxType j)
{
    return (0 <= i && i <= ROW_EFF(m) - 1 && 0 <= j && j <= COL_EFF(m) - 1);
}

ElType getElmtDiagonal(Matrix m, IdxType i)
{
    return ELMTMatrix(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut)
{
    int i, j;
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            ELMTMatrix(*mOut, i, j) = ELMTMatrix(mIn, i, j);
        }
    }
}

void readMatrix(Matrix *m, int nRow, int nCol)
{
    int i, j, temp;
    createMatrix(nRow, nCol, m);
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &temp);
            ELMTMatrix(*m, i, j) = temp;
        }
    }
}

void displayMatrix(Matrix m)
{
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (j == COL_EFF(m) - 1)
            {
                printf("%d", ELMTMatrix(m, i, j));
            }
            else
            {
                printf("%d ", ELMTMatrix(m, i, j));
            }
        }
        printf("\n", ELMTMatrix(m, i, j));
    }
}
//ADISI UNTUK PRINT PROFIL
void displayMatrixChar(Matrix m)
{
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (j == COL_EFF(m) - 1)
            {
                printf("%c", ELMTMatrix(m, i, j));
            }
            else
            {
                printf("%c ", ELMTMatrix(m, i, j));
            }
        }
        printf("\n", ELMTMatrix(m, i, j));
    }
}

Matrix addMatrix(Matrix m1, Matrix m2)
{
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMTMatrix(m1, i, j) += ELMTMatrix(m2, i, j);
        }
    }
    return m1;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMTMatrix(m1, i, j) -= ELMTMatrix(m2, i, j);
        }
    }
    return m1;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix m;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m2); j++)
        {
            ELMTMatrix(m, i, j) = 0;
            for (k = 0; k < COL_EFF(m1); k++)
            {
                ELMTMatrix(m, i, j) += ELMTMatrix(m1, i, k) * ELMTMatrix(m2, k, j);
            }
        }
    }
    return m;
}

Matrix multiplyMatrixWithMod(Matrix m1, Matrix m2, int mod)
{
    Matrix m3;
    createMatrix(ROW_EFF(m2), COL_EFF(m1), &m3);
    m3 = multiplyMatrix(m1, m2);
    int i, j;
    for (i = 0; i < ROW_EFF(m3); i++)
    {
        for (j = 0; j < COL_EFF(m3); j++)
        {
            ELMTMatrix(m3, i, j) %= mod;
        }
    }
    return m3;
}

Matrix multiplyByConst(Matrix m, ElType x)
{
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            ELMTMatrix(m, i, j) *= x;
        }
    }
    return m;
}

void pMultiplyByConst(Matrix *m, ElType k)
{
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            ELMTMatrix(*m, i, j) *= k;
        }
    }
}

boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    if (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2))
    {
        int i, j;
        for (i = 0; i < ROW_EFF(m1); i++)
        {
            for (j = 0; j < COL_EFF(m1); j++)
            {
                if (ELMTMatrix(m1, i, j) != ELMTMatrix(m2, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return (!isMatrixEqual(m1, m2));
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m)
{
    return (COL_EFF(m) * ROW_EFF(m));
}

boolean isSquare(Matrix m)
{
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m)
{
    if (isSquare(m))
    {
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++)
        {
            for (j = 0; j < COL_EFF(m); j++)
            {
                if (ELMTMatrix(m, i, j) != ELMTMatrix(m, j, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

boolean isIdentity(Matrix m)
{
    if (isSquare(m))
    {
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++)
        {
            for (j = 0; j < COL_EFF(m); j++)
            {
                if (i != j)
                {
                    if (ELMTMatrix(m, i, j) != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

boolean isSparse(Matrix m)
{
    int i, j, count = 0;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMTMatrix(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return (count <= 0.05 * countElmt(m));
}

Matrix negation(Matrix m)
{
    return multiplyByConst(m, -1);
}

void pNegation(Matrix *m)
{
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m)
{
    int i, j, k, p, var = 1;
    Matrix mFac;
    float det;
    if (countElmt(m) == 1)
    {
        det = (float)ELMTMatrix(m, 0, 0);
    }
    else if (countElmt(m) == 4)
    {
        det = (ELMTMatrix(m, 0, 0) * ELMTMatrix(m, 1, 1)) - (ELMTMatrix(m, 1, 0) * ELMTMatrix(m, 0, 1));
        det = (float)(det);
    }
    else
    {
        // buat matrix lebih kecil untuk kofaktor
        createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mFac);
        det = 0;
        for (i = 0; i < ROW_EFF(m); i++)
        {
            for (j = 1; j < ROW_EFF(m); j++)
            {
                for (k = 0; k < COL_EFF(m); k++)
                {
                    // jika kolom =  baris yg digunakan sbg var det, maka diabaikan
                    if (k == i)
                    {
                        continue;
                    }
                    else if (k < i)
                    {
                        p = k;
                    }
                    else
                    {
                        // jika k lebih besar dari nilai baris det, maka posisi k di matrix cofactor berkurang1
                        p = k - 1;
                    }
                    ELMTMatrix(mFac, j - 1, p) = ELMTMatrix(m, j, k);
                }
            }
            det += var * ELMTMatrix(m, 0, i) * determinant(mFac);
            var *= -1; // untuk penanda minus atau plus
        }
    }
    return det;
}

Matrix transpose(Matrix m)
{
    Matrix m1;
    int i, j;
    createMatrix(COL_EFF(m), ROW_EFF(m), &m1);
    for (i = 0; i < COL_EFF(m); i++)
    {
        for (j = 0; j < ROW_EFF(m); j++)
        {
            ELMTMatrix(m1, i, j) = ELMTMatrix(m, j, i);
        }
    }
    return m1;
}

void pTranspose(Matrix *m)
{
    Matrix mc;
    mc = transpose(*m);
    copyMatrix(mc, m);
}