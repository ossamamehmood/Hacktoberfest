using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode.Easy
{
    internal class ValidPalindrome
    {
        public static bool main(string s)
        {
            if (s == null)
            {
                return true;
            }
            s = s.ToLower();
            int start = 0;
            int end = s.Length - 1;
            bool flag = true;
            while (start < end)
            {
                if (Char.IsLetterOrDigit(s[start]) && Char.IsLetterOrDigit(s[end]))
                {
                    if (s[start] != s[end])
                    {
                        flag = false;
                        return flag;
                    }
                    start++;
                    end--;
                }
                if (!Char.IsLetterOrDigit(s[start])) start++;
                if (!Char.IsLetterOrDigit(s[end])) end--;
            }
            return flag;
        }
    }
}
