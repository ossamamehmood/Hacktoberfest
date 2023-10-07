// code by - Rishabh705

#include <iostream>
#include <vector>
using namespace std;
#define grid_row 50
#define grid_col 50
vector<vector<int>> grid(grid_row, vector<int>(grid_col));
class NeighbourCell
{
public:
    int countLive(int r, int c, vector<vector<int>> arr, int row, int col) // Will return number of live neighbours.
    {
        int i, j, count = 0;
        for (i = r - 1; i <= r + 1; i++)
        {
            for (j = c - 1; j <= c + 1; j++)
            {
                if ((i == r && j == c) || (i < 0 || j < 0) || (i >= row || j >= col))
                {
                    continue;
                }
                if (arr[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

class Updater
{
protected:
    void updateGrid()
    {
        NeighbourCell obj;
        vector<vector<int>> arr1; // new array for storing updated grid.
        for (int i = 0; i < grid_row; i++)
            arr1.push_back(vector<int>(grid_col));
        int alive = 0;
        for (int i = 0; i < grid_row; i++)
        {
            for (int j = 0; j < grid_col; j++)
            {
                alive = obj.countLive(i, j, grid, grid_row, grid_col);
                if (grid[i][j] == 1 && (alive == 2 || alive == 3))
                {
                    arr1[i][j] = 1;
                }
                else if (grid[i][j] == 0 && alive == 3)
                {
                    arr1[i][j] = 1;
                }
                else
                {
                    arr1[i][j] = 0;
                }
            }
        }
        grid = arr1; // make initial grid as updated grid
    }
};
class LifePlacer
{
public:
    void placeLife(vector<vector<int>> life)
    {
        int row_loc, col_loc;
        cout << "Enter the location to place on grid (x y) : ";
        cin >> row_loc >> col_loc;
        int x = 0, y = 0;
        for (size_t i = 0; i < life.size(); i++, x++)
        {
            x = life[i][0];
            y = life[i][1];
            grid[x - 1 + row_loc - 1][y - 1 + col_loc - 1] = 1;
        }
    }
};
class GenerationFinder : public Updater
{
public:
    GenerationFinder()
    {
        for (int i = 0; i < grid_row; i++)
        {
            for (int j = 0; j < grid_col; j++)
            {
                if (grid[i][j] == 1)
                    cout << " 0 ";
                else
                    cout << "   ";
            }
            cout << "\n";
        }
        updateGrid();
    }
};
int main()
{
    vector<vector<int>> block{{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    vector<vector<int>> boat{{1, 1}, {1, 2}, {2, 1}, {2, 3}, {3, 2}};
    vector<vector<int>> tub{{1, 2}, {2, 1}, {2, 3}, {3, 2}};
    vector<vector<int>> blinker{{1, 2}, {2, 2}, {3, 2}};
    vector<vector<int>> toad{{2, 2}, {2, 3}, {2, 4}, {3, 1}, {3, 2}, {3, 3}};
    vector<vector<int>> glider{{1, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}};
    vector<vector<int>> LWSS{{1, 1}, {1, 4}, {2, 5}, {3, 1}, {3, 5}, {4, 2}, {4, 3}, {4, 4}, {4, 5}};
    vector<vector<int>> gun{{1, 25}, {2, 23}, {2, 25}, {3, 13}, {3, 14}, {3, 21}, {3, 22}, {3, 35}, {3, 36}, {4, 12}, {4, 16}, {4, 21}, {4, 22}, {4, 35}, {4, 36}, {5, 1}, {5, 2}, {5, 11}, {5, 17}, {5, 21}, {5, 22}, {6, 1}, {6, 2}, {6, 11}, {6, 15}, {6, 17}, {6, 18}, {6, 23}, {6, 25}, {7, 11}, {7, 17}, {7, 25}, {8, 12}, {8, 16}, {9, 13}, {9, 14}};
    cout << "\n\t\t...Welcome to the Game of Life...\n";
    char res;
    int ctr = 0;
    LifePlacer obj;
    cout << "Want to add boat to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(boat);
        ctr++;
    }
    cout << "Want to add glider gun to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(gun);
        ctr++;
    }
    cout << "Want to add glider to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(glider);
        ctr++;
    }
    cout << "Want to add blinker to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(blinker);
        ctr++;
    }
    cout << "Want to add toad to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(toad);
        ctr++;
    }
    cout << "Want to add tub to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(tub);
        ctr++;
    }
    cout << "Want to add light spaceship to grid(y/n) ? ";
    cin >> res;
    if (res == 'y')
    {
        obj.placeLife(LWSS);
        ctr++;
    }
    if (ctr == 0)
        cout << "\nNo Life Added!\n";
    else
    {
        int n;
        cout << "Enter the number of generations you want to display : ";
        cin >> n;
        while(n--)
            GenerationFinder ob;
    }
    return 0;
}