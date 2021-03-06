#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> graph;
    for (int i = 0; i != N; ++i)
    {
        vector<int> temp;
        for (int j = 0; j != N; ++j)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                temp.push_back(j);
            }
        }
        graph.push_back(temp);
    }

    for (int i = 0; i != N; ++i)
    {
        vector<unsigned long long> curr(N, 0);
        curr[i] = 1;
        vector<unsigned long long> net(N, 0);

        bool flag = true;

        while (flag)
        {
            flag = false;
            vector<unsigned long long> next(N, 0);
            for (int j = 0; j != N; ++j)
            {
                for (auto d: graph[j])
                {
                    next[d] += curr[j];
                    if (curr[j] != 0)
                    {
                        flag = true;
                    }
                    net[d] += curr[j];
                }
            }
            curr = next;
//            for (auto x: net)
//            {
//                cout << x << " ";
//            }
//            cout << "\n";
        }

//        cout << "out" << "\n";

        for (auto x: net)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}
