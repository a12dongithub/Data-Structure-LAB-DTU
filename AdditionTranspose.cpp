#include <iostream>
#include <stdio.h>
#define sz 11
struct Sparse
{
    int nrow, ncol, nz, row[sz], col[sz], value[sz];
};
Sparse addition(struct Sparse s1, struct Sparse s2)
{
    int i = 0, j = 0, k = 0;
    Sparse s3;
    s3.nrow = s1.nrow;
    s3.ncol = s1.ncol;

    for (i = 0; i < s1.nz && j < s2.nz;)
    {
        if (s1.row[i] < s2.row[j] || s1.row[i] == s2.row[j] && s1.col[i] < s2.col[j])
        {
            s3.row[k] = s1.row[i];
            s3.col[k] = s1.col[i];
            s3.value[k] = s1.value[i];
            i++;
            k++;
        }
        else if (s1.col[i] == s2.col[j] && s1.row[i] == s2.row[j])
        {
            if (s1.value[i] + s2.value[j] != 0)
            {

                s3.value[k] = s1.value[i] + s2.value[j];
                s3.col[k] = s1.col[i];
                s3.row[k] = s1.row[i];
                k++;
            }
            i++;
            j++;
        }
        else
        {
            s3.row[k] = s2.row[j];
            s3.col[k] = s2.col[j];
            s3.value[k] = s2.value[j];
            j++;
            k++;
        }
    }
    for (; i < s1.nz; i++, k++)
    {
        s3.row[k] = s1.row[i];
        s3.col[k] = s1.col[i];
        s3.value[k] = s1.value[i];
    }
    for (; j < s2.nz; j++, k++)
    {
        s3.row[k] = s2.row[j];
        s3.col[k] = s2.col[j];
        s3.value[k] = s2.value[j];
    }
    s3.nz = k;
    return s3;
}
void readMatrix(struct Sparse *S)
{
    scanf("%d%d%d", &S->nrow, &S->ncol, &S->nz);
    int i = 0;
    printf("Enter row column no. order respctively\n");
    for (; i < S->nz;)
    {
        scanf("%d%d%d", &S->row[i], &S->col[i], &S->value[i]);
        if (S->row[i] > S->nrow || S->col[i] > S->ncol)
        {
            printf("Enter Coreectly \n");
            scanf("%d%d%d", &S->row[i], &S->col[i], &S->value[i]);
        }
        i++;
    }
}
void printMatrix(struct Sparse S)
{

    for (int i = 0; i < S.nz; i++)
    {
        printf(" %d %d %d \n", S.row[i], S.col[i], S.value[i]);
    }
}
struct Sparse Transpose(struct Sparse A)
{
    struct Sparse extre;
    int t[sz] = {}, f[sz] = {};
    int i;
    for (i = 0; i < A.nz; i++)
    {
        f[A.col[i]]++;
    }

    for (i = 0; i < A.ncol; i++)
    {
        t[i + 1] = t[i] + f[i];
    }

    for (i = 0; i < A.nz; i++)
    {
        extre.row[t[A.col[i]]] = A.col[i];
        extre.col[t[A.col[i]]] = A.row[i];
        extre.value[t[A.col[i]]] = A.value[i];
        t[A.col[i]]++;
    }

    extre.nrow = A.ncol;
    extre.ncol = A.nrow;
    extre.nz = A.nz;
    return extre;
}

void multiply(struct Sparse A, struct Sparse B)
{
    struct Sparse matrix2 = Transpose(B);
    int res[sz][sz] = {};
    int i, j;
    for (i = 0; i < A.nz; i++)
    {
        for (j = 0; j < matrix2.nz; j++)
        {
            if (A.col[i] == matrix2.col[j])
                res[A.row[i]][matrix2.row[j]] += A.value[i] * matrix2.value[j];
        }
    }

    for (i = 0; i < A.nrow; i++)
    {

        for (j = 0; j < B.ncol; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    struct Sparse s, extre, w;
    printf(" no. of rows,col and num of 1 m.\n");
    readMatrix(&s);
    printf(" no. of rows,col and num of 2 m.\n");
    readMatrix(&extre);
    w = Transpose(s);
    printf(" transpose 1 matrix is : \n");
    printMatrix(w);
    w = Transpose(extre);
    printf("transpose  2 matrix is : \n");
    printMatrix(w);
    Sparse s3 = addition(s, extre);
    printf("\naddition m1+m2 non zero elements will be in order(row,col,value):\n");
    printMatrix(s3);
    printf("answer (m1 X m2) is : \n");
    multiply(s, extre);
}