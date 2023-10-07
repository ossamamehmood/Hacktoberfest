int m=columnCount;
int n=rowCount;
int [][] temp=new int[m][n];
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
temp[i][j]=matrix[j][i];

return temp;
