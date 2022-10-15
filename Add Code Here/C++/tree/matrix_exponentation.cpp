const int m = 2;
typedef long long ll;
#define forc(i, a, b) for(int i = (int)a; i < int(b); i++)
class Matrix{
    public:
        ll mat[m][m];
        void init(){
            mat[0][0] = k; mat[0][1] = 1;
            mat[1][0] = l; mat[1][1] = 0;
        }
        Matrix operator * (const Matrix &p){
            Matrix ans;
            forc(i, 0, m)
                forc(j, 0, m)
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + (mat[i][k]%MOD) * (p.mat[k][j]%MOD)) % MOD;
            return ans;
        }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    forc(i, 0, m)
        forc(j, 0, m)
        ans.mat[i][j] = (i == j);
    while(b){
        if(b&1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }
    return ans;
}
