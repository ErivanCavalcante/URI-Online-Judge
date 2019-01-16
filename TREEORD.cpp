#include <iostream>

using namespace std;

int calcula(int *pre, int *pos, int *in, int n)
{
    int i, j;

    //Testa se o primeiro elemento do pre order eh igual ao ultimo elemento do pos order
    if(pre[0] != pos[n - 1])
        return 0;

    if(n == 1)
    {
        if(pre[0] == pos[0] && pos[0] == in[0])
            return 1;
        else
            return 0;
    }

    for(i = 0; i < n; ++i)
    {
        if(in[i] == pre[0])
            break;
    }

    if(i == n)
        return 0;

    int resultado = 1, post_r = pos[n - 2], leftn = 0;

    for(j = 0; j < n; ++j)
    {
        if(pre[j] == post_r)
        {
            if((resultado *= calcula(pre + j, pos + j - 1, in + i + 1, n - j)) == 0)
                return 0;

            leftn = j - 1;
            break;
        }
    }


    if(i != 0)
        resultado *= calcula(pre + 1, pos, in + 1, leftn);

    return resultado;
}

int main()
{
    int valor, i;

    cin >> valor;

    int pre[valor], pos[valor], in[valor];

    for(i = 0; i < valor; ++i)
        cin >> pre[i];

    for(i = 0; i < valor; ++i)
        cin >> pos[i];

    for(i = 0; i < valor; ++i)
        cin >> in[i];

    if(calcula(pre, pos, in, valor))
        cout << "yes" << endl;
    else
        cout << "no" << endl;


    return 0;
}
