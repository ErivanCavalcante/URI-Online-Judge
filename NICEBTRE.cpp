#include <iostream>

using namespace std;

//Vetor de caracteres a serem pegos
char str[10001];
//Usado para varrer toda a string
int i;

//
int maximo(int a, int b)
{
    return (a > b)? a : b;
}

//Calcula o tamanho da arvore
int tamanho()
{
    //Condicao de parada
    if(str[i++] == 'l')
        return 1;
    else
        return maximo(tamanho() , tamanho()) + 1;
}

int main()
{
    int cont;
    //Pega o numero do contador
    cin >> cont;

    //Loop para pegar todas as strings e fazer a contagem
    while(cont--)
    {
        //Pega a string
        cin >> str;

        //Zera o i para fazer o loop na string
        i = 0;

        //Conta recursivamente
        cout << tamanho() - 1 << endl;
    }

    return 0;
}
