class Solution {
public:


    // using stack to store the directories 
    // curr is there to store thr data between two //
    // Initially adding / to the end of the given path to ensure that the last curr is always considered
    // traverse through the path and maintain the current accordingly
    // whenever / is encountered  (/.. come out from the directory) - pop
    // (/nameOfDirectory going into directory) - push based upon curr
    // finally get the simplified path from the directories left in stack

    string simplifyPath(string path) 
    {
        string curr,simplifiedPath;
        stack<string> st;
        path.push_back('/');

        for(char c:path)
        {
            if(c == '/')
            {
                if(curr.empty())  continue;
                else if(curr == "..")
                {
                    if(!st.empty())  st.pop();

                }
                else if(curr!=".") st.push(curr);
                curr = "";
            }
            else
            curr.push_back(c);
        }
        while(!st.empty())
        {
            simplifiedPath = "/" + st.top() + simplifiedPath;
            st.pop();
        }
        return simplifiedPath.empty() ? "/":simplifiedPath;
    }
};
