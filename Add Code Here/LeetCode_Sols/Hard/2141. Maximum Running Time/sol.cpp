#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long total = 0;
        for(int battery : batteries) {
            total += battery;
        }
        
        long long start = 0, end = total;
        long long maxTime = 0;
        
        while(start <= end) {
            
            long long mid = start + (end - start) / 2;
            
            if(isFeasible(n, batteries, mid)) {
                maxTime = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return maxTime;
    }
    
private:
    bool isFeasible(int n, vector<int>& batteries, long long time) {
        
        long long totalRunTime = 0;
        
        for(int battery : batteries) {
            if(battery <= time) {
                totalRunTime += battery; 
            }
            else {
                totalRunTime += time;
            }
        }
        
        return totalRunTime >= time * n;
    }
};


int main() {

// call the fn here
  
  return 0;
}