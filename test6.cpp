#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
int main()
{
    string s;
    vector<int> v;
    getline(cin, s);
    istringstream is(s);
    int inter;
    char ch;
    while (is >> inter)
    {
         v.push_back(inter);
         is >> ch;
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
