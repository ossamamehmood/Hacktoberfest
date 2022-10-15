//Program for sparse amtrix addition

#include<stdio.h>
void SparseAdd(int a[10][3], int b[10][3])
{
    int a_index,b_index,c_index,a_terms,b_terms,c_terms,c[20][3];
    if((a[0][0]!=b[0][0]) || (a[0][1]!=b[0][1]))
        printf("Incompatible matrix");
    else{
        c[0][0]=a[0][0];
        c[0][1]=a[0][1];
        a_terms=1; b_terms=1; c_terms=1;
        while((a_terms<=a[0][2]) &&(b_terms<=b[0][2]))
        {
            a_index = a[a_terms][0]*a[0][1]+a[a_terms][1];
            b_index = b[b_terms][0]*b[0][1]+b[b_terms][1];
            if(a_index < b_index)
            {
                c[c_terms][0] = a[a_terms][0];
                c[c_terms][1] = a[a_terms][1];
                c[c_terms][2] = a[a_terms][2];
                a_terms++;
            }
            else if(a_index > b_index)
            {
                c[c_terms][0] = b[b_terms][0];
                c[c_terms][1] = b[b_terms][1];
                c[c_terms][2] = b[b_terms][2];
                b_terms++;
            }
            else
            {
                c[c_terms][0] = a[a_terms][0];
                c[c_terms][1] = a[a_terms][1];
                c[c_terms][2] = a[a_terms][2] + b[b_terms][2];
                b_terms++; a_terms++;
            }
            c_terms++;
        }
        for(;a_terms <= a[0][2]; a_terms++, c_terms++)
        {
            c[c_terms][0] = a[a_terms][0];
            c[c_terms][1] = a[a_terms][1];
            c[c_terms][2] = a[a_terms][2];
        }
        for(;b_terms <= b[0][2]; b_terms++, c_terms++)
        {
            c[c_terms][0] = b[b_terms][0];
            c[c_terms][1] = b[b_terms][1];
            c[c_terms][2] = b[b_terms][2];
        }
    }
    c[0][2] = c_terms-1;
    display(c);
}
void Transpose(int a[10][3])
{
    int m,n,p,q,j,col,T[10][3];
    m=a[0][0]; n=a[0][1]; j=a[0][2];
    T[0][0]=n; T[0][1]=m; T[0][2]=j;
    if(j>0)
    {
        q=1;
        for(col=0; col < n; col++)
            for(p=1; p <= j; p++)
                if(a[p][1] == col)
                {
                    T[q][0] = a[p][1];
                    T[q][1] = a[p][0];
                    T[q][2] = a[p][2];
                    q++;
                }
    }
    display(T);
}
void display(int a[10][3])
{
    int i,j;
    int m = a[0][2];
    for(i=0; i<=m; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
}
void enter(int a[10][3],int m)
{
    int i,j;

    printf("Enter the elements of the sparse matrix : ");
    for(i=0; i<m; i++)
        for(j=0; j<3; j++)
            scanf("%d",&a[i][j]);
}
void main()
{
    int a[10][3],b[10][3],m,n,p,r[10][3],ch;
    char c;
    do
    {
        printf("\t\t\tMENU \n1)SPARSE ADDITION\n2)SPARSE TRANSPOSE");
        printf("\nEnter your option : ");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Enter the total number of rows of the first sparse matrix : ");
            scanf("%d",&m);
            enter(a,m);
            printf("Enter the total number of rows of the second sparse matrix : ");
            scanf("%d",&n);
            enter(b,n);
            printf("\nSparse addition : \n");
            SparseAdd(a,b);
        }
        else if(ch == 2)
        {
           printf("Enter the total number of rows of the sparse matrix : ");
            scanf("%d",&p);
            enter(r,p);
            printf("\nTranspose of sparse :\n");
            Transpose(r);
        }
        else
            printf("Enter valid choice");
        printf("\nDo you want to continue (y/n)");
        scanf("%s",&c);
    }while(c == 'y' || c == 'Y');

}
