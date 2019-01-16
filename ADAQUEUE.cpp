#include <iostream>
#include <list>

using namespace std;

int main()
{
    int q, n;
    string operacao;

    list<int> fila;

    bool invertido = false;

    //Pega o numero de operacoes
    cin >> q;

    for (int z = 0; z < q; ++z)
    {
        operacao = "";

        while (operacao == "")
            cin >> operacao;

        if(operacao == "back")
        {
            if(fila.size() == 0)
                cout << "No job for Ada?\n";
            else
            {
                cout << ((invertido == false)? fila.back() : fila.front()) << "\n";
                (invertido == false)? fila.pop_back() : fila.pop_front();
            }
        }
        else if (operacao == "front")
        {
            if(fila.size() == 0)
                cout << "No job for Ada?\n";
            else
            {
                cout << ((invertido == false)? fila.front() : fila.back()) << "\n";
                (invertido == false)? fila.pop_front() : fila.pop_back();
            }
        }
        else if (operacao == "reverse")
        {
            invertido = !invertido;
        }
        else if (operacao == "push_back")
        {
            cin >> n;
            (invertido == false)? fila.push_back(n) : fila.push_front(n);
        }
        else if (operacao == "toFront")
        {
            cin >> n;
            (invertido == false)? fila.push_front(n) : fila.push_back(n);
        }
    }

    return 0;
}
