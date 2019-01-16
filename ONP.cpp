#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    //Valor de operacoes
    int v = 0;

    //Operacao
    string op;
    stack<char> pilha;

    //Pega o num de operacoes
    cin >> v;

    //Loop para pegar as operacoes
    while(v--)
    {
        cin >> op;
        int tam = op.size();

        for(int i = 0; i < tam; ++i)
        {
            if(isalpha(op[i]))
                cout << op[i];
            else if(op[i] == ')')
            {
                cout << pilha.top();
                pilha.pop();
            }
            else if(op[i] != '(')
            {
                pilha.push(op[i]);
            }
        }

        cout << endl;
    }

    return 0;
}
