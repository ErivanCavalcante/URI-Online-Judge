#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> S;
    vector<int> Q;
    vector<int> res;

    //Pega os dados
    int n = 0;
    cin >> n;

    if(n < 2)
        n = 2;
    else if(n > 100)
        n = 100;

    while(n--)
    {
        int i;

        cin >> i;

        S.push_back(i);
    }

    cin >> n;

    if(n < 2)
        n = 2;
    else if(n > 100)
        n = 100;

    while(n--)
    {
        int i;

        cin >> i;

        Q.push_back(i);
    }

    for(int i = 0; i < S.size(); ++i)
    {
        for(int j = 0; j < Q.size(); ++j)
        {
            if(j == Q.size() - 1)
            {
                if(S[i] != Q[j])
                {
                    res.push_back(S[i]);
                    break;
                }
            }
            else
            {
                if(S[i] == Q[j])
                    break;
            }
        }
    }

    for(int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";

    }

    return 0;
}
