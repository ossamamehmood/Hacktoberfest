#include <bits/stdc++.h>
using namespace std;
int main()
{

    map<string, string> m;
    // map<string,string> m2;
    int count = 0, nvc = 0;
    vector<string> op;
    string line;
    string s1;
    string s2;
    int k;
    ifstream fin;
    fin.open("ref_con.txt");
    while (getline(fin, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                k = i;
                break;
            }
        }
        for (int i = 0; i < k; i++)
        {
            s1 += line[i];
        }
        for (int i = k; i < line.size(); i++)
        {
            s2 += line[i];
        }
        m.insert({s1, s2});
        s1.clear();
        s2.clear();
    }
    for (auto &vk : m) // refernce and not the copy.
    {
        //  cout << vk.first <<" "<<vk.first.size()<< endl << vk.second << endl;
        count++;
    }
    fin.close();
    ifstream fin2;
    fin2.open("test_con.txt");
    map<string, string> m2;
    string line2;
    while (getline(fin2, line2))
    {
        auto it = m.find(line2);
        if (it == m.end())
        {
            m2.insert(pair<string, string>(line2, "NO value found"));
            op.push_back("NO value found");
            nvc++;
        }
        else
        {
            auto &fs = (*it).first;
            // cout<<fs<<endl;
            auto &ss = (*it).second;
            op.push_back(ss);
            // cout<<ss<<endl;
            m2.insert(pair<string, string>(line2, ss));
        }

        // cout<<line2<<endl;
        // cout<<line2.size()<<endl;

        // ofstream fout;
        // fout.open("maviOP-DIS.txt");
        // fout<<line2<<" "<<"output"<<endl;
        // fout.close();
        // cout<<line2<<" ";
    }
    // cout << "Total values in map function are: " << count << endl;
    // cout << "Here is the required output:----------------------------------------------------\n";
    // for (auto &vk : m2) // refernce and not the copy.
    // {
    //     cout << vk.first << "-----------" << vk.second << endl;
    // }
    fin2.close();

    // cout << "Here are only outputs in order of values inserted:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // for (int i = 0; i < op.size(); i++)
    // {
    //     cout << op[i] << endl;
    // }
    ofstream fout;
    fout.open("output_con.con");
    for (int i = 0; i < op.size(); i++)
    {
        fout << op[i] << endl;
    }
    fout.close();
    cout << "Check output in output_con.con file\n";
    cout << "Number of values not found : " << nvc << endl;
    cout << "Programmed by Harsh Mavi" << endl;
}