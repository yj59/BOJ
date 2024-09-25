#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;
    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }

        if (p[i] == p[j])
        {
            pi[i] = ++j;
        }
           
    }
    return pi;
}

int main()
{
    string s, temp;
    int final = 0;

    cin >> s;
    temp = s;

    for (int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(i, s.size());
        auto matched = getPi(temp);

        for (int j = 0; j < matched.size(); j++)
        {
            final = max(final, matched[j]);
        }
    }

    cout << final << "\n";
    return 0;
}
