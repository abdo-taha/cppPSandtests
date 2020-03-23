#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(8);
    v.push_back(11);
    cout << lower_bound(v.begin(),v.end(), 0 )-v.begin();

    return 0;
}
