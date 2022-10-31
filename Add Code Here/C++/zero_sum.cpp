#include <iostream>
#include <unordered_map>
using namespace std;
 
void printAllSubarrays(int nums[], int n)
{
    unordered_multimap<int, int> map;
 
    map.insert(pair<int, int>(0, -1));
 
    int sum = 0;
 
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
 
        if (map.find(sum) != map.end())
        {
            auto it = map.find(sum);
 
            while (it != map.end() && it->first == sum)
            {
                cout << "Subarray [" << it->second + 1 << "…" << i << "]\n";
                it++;
            }
        }
 
        map.insert(pair<int, int>(sum, i));
    }
}
 
int main()
{
    int nums[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int n = sizeof(nums)/sizeof(nums[0]);
 
    printAllSubarrays(nums, n);
 
    return 0;
}
