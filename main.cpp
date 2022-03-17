#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> H;
    int m;
    int n;
    int diag = 0;
    int del = 0;
    int ins = 0;
    int valorMaximo = 0;
    int valorMaximoI = 0;
    int valorMaximoJ = 0;
    string seqA;
    string seqB;

    // recebendo as sequencias a e b e seus respectivos tamanhos
    cin >> m;
    cin >> n;
    cin >> seqA;
    cin >> seqB;

    // inicializando matriz H
    H.resize(n);
    for (int i = 0; i < n; i++)
    {
        H[i].resize(m);
    }

    // criando a matriz H
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (seqA[i] == seqB[j])
            {
                diag = H[i - 1][j - 1] + 2;
            }
            else
            {
                diag = H[i - 1][j - 1] - 1;
            }

            ins = H[i][j - 1] - 1;

            del = H[i - 1][j] - 1;

            H[i][j] = max(diag, max(ins, max(del, 0)));

            // calculando o valor maximo da matriz H
            if (H[i][j] > valorMaximo)
            {
                valorMaximo = H[i][j];
                valorMaximoI = i;
                valorMaximoJ = j;
            }
        }
    }

    // print das sequencias A e B e seus respectivos tamanhos assim como o valor Maximo da matriz H
    cout << "tamanho de a (m) = " << m << endl;
    cout << "a = " << seqA << endl;
    cout << "tamanho de b (n) = " << n << endl;
    cout << "b = " << seqB << endl;
    cout << "Valor Máximo: " << valorMaximo << endl;

    return valorMaximo;
}

// g++ -Wall -O3 main.cpp -o entrega1
// ./entrega1 < dna.seq