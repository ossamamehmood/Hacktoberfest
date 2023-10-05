#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>

using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {

        map<string, priority_queue<string>> graph;

        for (auto ticket : tickets)
        {
            graph[ticket[0]].push(ticket[1]);
        }

        list<string> itinerary;
        dfs("JFK", graph, itinerary);

        return vector<string>(itinerary.begin(), itinerary.end());
    }

private:
    void dfs(string airport, map<string, priority_queue<string>> &graph, list<string> &itinerary)
    {

        priority_queue<string> &nextAirports = graph[airport];

        while (!nextAirports.empty())
        {
            dfs(nextAirports.top(), graph, itinerary);
            nextAirports.pop();
        }

        itinerary.push_front(airport);
    }
};

int main()
{

    // call the fn here

    return 0;
}