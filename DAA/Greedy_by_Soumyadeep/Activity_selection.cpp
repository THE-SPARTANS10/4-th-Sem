#include <bits/stdc++.h>
using namespace std;

void vector_print(vector<pair<int, int>> v)
{
    cout << "Given activities are:"
         << "\n";
    cout << "(" << v[0].first << "," << v[0].second << ")";
    for (int i = 1; i < v.size(); i++)
    {
        cout << ",(" << v[i].first << "," << v[i].second << ")";
    }
    cout << "\n\n";
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int max_activities(vector<pair<int, int>> &v, int n)
{
    sort(v.begin(), v.end(), sortbysec);
    int prev = 0;
    int res = 1;
    cout << "Following activities are selected: "
         << "\n";
    cout << "(" << v[0].first << "," << v[0].second << ")";
    for (int curr = 1; curr < n; curr++)
    {
        // cout<<v[curr].first<<" & ";
        // cout<<v[curr].second<<"\n";
        if (v[curr].first >= v[prev].second)
        {
            cout << ",(" << v[curr].first << "," << v[curr].second << ")";
            res++;
            prev = curr;
        }
    }
    cout << "\n";
    return res;
}

int main()
{
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    cout << "Number of activities given: " << n << "\n";
    vector_print(v);
    cout << "\nMax_activities: " << max_activities(v, n) << "\n";
    return 0;
}