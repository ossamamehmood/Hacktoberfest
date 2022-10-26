//function to find anagram sum or sum of Jumbled String


int findSumOfJumbledString(string s) {
    unordered_map<char,int> m;
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
        if(m.find('z')!=m.end()) //0
        {
            m['e']-=m['z'];
            m['r']-=m['z'];
            m['o']-=m['z'];
            m.erase('z');
        }
        if(m.find('x')!=m.end()) //6
        {
            sum = sum + 6*m['x'];
            m['s']-=m['x'];
            m['i']-=m['x'];
            m.erase('x');
        }
        if(m.find('g')!=m.end())  //8
        {
            sum = sum + 8*m['g'];
            m['e']-=m['g'];
            m['i']-=m['g'];
            m['h']-=m['g'];
            m['t']-=m['g'];
            m.erase('g');
        }
        if(m.find('w')!=m.end()) //2
        {
            sum = sum + 2*m['w'];
            m['t']-=m['w'];
            m['o']-=m['w'];
            m.erase('w');
        }
        if(m.find('u')!=m.end()) //4
        {
            sum = sum + 4*m['u'];
            m['f']-=m['u'];
            m['o']-=m['u'];
            m['r']-=m['u'];
            m.erase('u');
        }
        if((m.find('h')!=m.end())) //3
        {
            sum = sum + 3*m['h'];
            m['t']-=m['h'];
            m['r']-=m['h'];
            m['e']-=m['h'];
            m['e']-=m['h'];
            m.erase('h');
        }
        if((m.find('f')!=m.end())) //5
        {
            sum = sum + 5*m['f'];
            m['i']-=m['f'];
            m['v']-=m['f'];
            m['e']-=m['f'];
            m.erase('f');
        }
        if((m.find('s')!=m.end()))
        {
            sum = sum + 7*m['s'];
            m['e']-=m['s'];
            m['v']-=m['s'];
            m['e']-=m['s'];
            m['n']-=m['s'];
            m.erase('s');
        }
        if(m.find('o')!=m.end())
        {
            sum = sum + m['o'];
            m['n']-=m['o'];
            m['e']-=m['o'];
            m.erase('o');
        }
        if(m.find('i')!=m.end())
        {
            sum = sum + 9*m['i'];
            m['n']-=m['i'];
            m['n']-=m['i'];
            m['e']-=m['i'];
            m.erase('i');
        }
        return sum;
}