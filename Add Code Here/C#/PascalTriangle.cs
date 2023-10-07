using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class PascalTriangle
    {
        public IList<IList<int>> Generate(int numRows)
        {
            IList<IList<int>> answer = new List<IList<int>>();
            for (int i = 1; i <= numRows; i++)
            {
                int addToList = 1;
                IList<int> row = new List<int>();
                for (int j = 1; j <= i; j++)
                {
                    row.Add(addToList);
                    addToList = addToList * (i - j) / j;
                }
                answer.Add(row);
            }
            return answer;
        }
        public IList<int> GetRow(int rowIndex)
        {
            long addToList = 1;
            IList<int> row = new List<int>();
            for (int j = 1; j <= rowIndex + 1; j++)
            {
                row.Add((int)addToList);
                addToList = addToList * (rowIndex - j + 1) / j;
            }
            return row;
        }
    }
}
