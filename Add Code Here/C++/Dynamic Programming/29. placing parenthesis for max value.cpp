#include<bits/stdc++.h>
#define        ll        long long int
#define        ls        unsigned long long
#define         eps       1e-9
#define         M_E      2.718281828
#define         M_PI     3.1416
#define        MAX       500
#define        frin          for(ll i=0;i<n;i++)
#define        frjn          for(ll j=0;j<n;j++)
const int   mod=1e9+7;
using namespace std;

ll eval(ll a, ll b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}
ll get_maximum_value(const string &exp) {
    long n = exp.length()/2 + 1;
    vector< vector<long> > m(n, vector<long> (n, 0));
    vector< vector<long> > M(n, vector<long> (n, 0));
    vector<long >numbers;
    vector<char >op;

    for (int i = 0; i <  exp.size(); i++){
        if (i%2==0){numbers.push_back((long ) exp[i] - 48);}
        else{op.push_back(exp[i]);}
    }

    for(int i = 0; i < numbers.size(); i++){
        m[i][i] = numbers[i];
        M[i][i] = numbers[i];
    }
    for (int s=1; s < numbers.size(); s++){
        for (int i=0; i < numbers.size()-s; i++){
            int j = i + s;
            long max_value = numeric_limits<long>::min();
            long min_value = numeric_limits<long>::max();
            for (int k = i; k <=  j-1; k++){
                long a = eval(M[i][k], M[k+1][j], op[k]);
                long b = eval(M[i][k], m[k+1][j], op[k]);
                long c = eval(m[i][k], M[k+1][j], op[k]);
                long d = eval(m[i][k], m[k+1][j], op[k]);
                max_value = max(max_value,max(a, max(b, max(c, d))));
                min_value = min(min_value,min(a, min(b, min(c, d))));
            }
            pair<long, long>min_max;
            min_max.first = min_value;
            min_max.second = max_value;
            m[i][j] = min_max.first;
            M[i][j] = min_max.second;
        }
    }
    return M[0][numbers.size()-1];
}

int main() {
    string s;
    cin >> s;
    cout << get_maximum_value(s) <<endl;
    return 0;
}

