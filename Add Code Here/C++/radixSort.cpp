/*-----------------CODED BY ROCKHOPPER130-----------------*/
#include <bits/stdc++.h>
#include <numeric>
#include <chrono>
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define int long long int
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j, k) FOR(i, j, k, 1)
#define RREP(i, j, k) RFOR(i, k, j, 1)
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
typedef std::vector<std::string> VS;
typedef std::vector<PII> VII;
typedef std::vector<VI> VVI;
typedef std::map<int,int> MPII;
typedef std::set<int> SETI;
typedef std::multiset<int> MSETI;
using namespace std;
using namespace std::chrono;

///*------------------------FUNCTIONS-----------------------*///

int max_element(VI &v, int l) {
    int max = v[0];
    REP(i,1,l){
        if (v[i] > max)
            max = v[i];
    }
    return max;
}

void countSort(VI &v, int l, int exp) {

    int otpt[l];
    int i;
    VI count(10,0);

    REP(i,0,l){
        count[(v[i] / exp) % 10]++;
    }
    REP(i,1,10){
        count[i] += count[i - 1];
    }
    for (i = l - 1; i >= 0; i--){
        otpt[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }
    REP(i,0,l){
        v[i] = otpt[i];
    }

}

void radixSort(VI &v, int l) {
    int m = max_element(v, l);
    for (int exp = 1; m / exp > 0; exp *= 10){
        countSort(v, l, exp);
    }
}


///*--------------------CODE BEGINS HERE--------------------*///

int32_t main() {
ios::sync_with_stdio(0);
cin.tie(0);

VI v;

REP(i,0,100){
    v.push_back(rand()%100);
}

int l=v.size();
REP(i,0,l){
    cout << v[i] << " ";
}
cout<<"\n";

auto start = steady_clock::now();
radixSort(v,l);
auto end = steady_clock::now();
auto elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
cout << "TIME FOR SORTING USING OUR RADIX SORT FUNCTION: " << elapsed_time << " nanoseconds" << "\n";

start = steady_clock::now();
sort(v.begin(),v.end());
end = steady_clock::now();
elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
cout << "TIME FOR SORTING USING OUR STL SORT FUNCTION: " << elapsed_time << " nanoseconds" << "\n";

REP(i,0,l){
    cout << v[i] << " ";
}
cout<<"\n";

return 0;
}