#include <iostream>  // std::cout
#include <algorithm> // std::reverse
#include <vector>    // std::vector

using namespace std;

struct termo
{
    string token;
    int linha;
    int coluna;
    int valor;
};

int maxVal(int diag, int del, int ins)
{
    if (diag >= del and diag >= ins and diag >= 0)
    {
        return diag;
    }
    else if (del >= ins and del >= 0)
    {
        return del;
    }
    else if (ins >= 0)
    {
        return ins;
    }
    else
    {
        return 0;
    }
}

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

    cin >> n;
    cin >> m;
    cin >> seqA;
    cin >> seqB;

    // print das sequencias A e B assim como seus respectivos tamanhos
    cout << "-------------------------------------" << endl;
    cout << "Tamanho de A (n) = " << n << endl;
    cout << "Sequencia A = " << seqA << endl;
    cout << "-------------------------------------" << endl;
    cout << "Tamanho de B (m) = " << m << endl;
    cout << "Sequencia B = " << seqB << endl;

    // inicializando matriz H com zeros
    H.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        H[i].resize(m + 1);
    }

    // criando a matriz H
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (seqA[i - 1] == seqB[j - 1])
            {
                diag = H[i - 1][j - 1] + 2;
            }
            else
            {
                diag = H[i - 1][j - 1] - 1;
            }

            ins = H[i][j - 1] - 1;

            del = H[i - 1][j] - 1;

            H[i][j] = maxVal(diag, del, ins);

            // calculando o valor maximo da matriz H
            if (H[i][j] > valorMaximo)
            {
                valorMaximo = H[i][j];
                valorMaximoI = i;
                valorMaximoJ = j;
            }
        }
    }

    // printando matriz H assim como o valor Maximo da matriz H
    cout << "-------------------------------------" << endl;
    cout << "Matriz H" << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << " " << endl;
        for (int j = 0; j <= m; j++)
        {
            cout << H[i][j] << " ";
        }
    }
    cout << "" << endl;
    cout << endl
         << "Valor Máximo da matriz H: " << valorMaximo << endl;
    cout << "Localizado em i = " << valorMaximoI << " e localizado em j = " << valorMaximoJ << endl;

    // obtenção do caminho com melhor valor
    termo termoAtual;
    vector<termo> vetorDeTermos;

    termoAtual.token = "MaxValue (EndPoint)";
    termoAtual.valor = valorMaximo;
    termoAtual.linha = valorMaximoI;
    termoAtual.coluna = valorMaximoJ;

    vetorDeTermos.push_back(termoAtual);

    while (termoAtual.valor != 0)
    {
        diag = H[termoAtual.linha - 1][termoAtual.coluna - 1];
        del = H[termoAtual.linha - 1][termoAtual.coluna];
        ins = H[termoAtual.linha][termoAtual.coluna - 1];

        if (diag >= del and diag >= ins)
        {
            termoAtual.token = "diagonal";
            termoAtual.valor = diag;
            termoAtual.linha = termoAtual.linha - 1;
            termoAtual.coluna = termoAtual.coluna - 1;
        }

        else if (del >= ins)
        {
            termoAtual.token = "delecao";
            termoAtual.valor = del;
            termoAtual.linha = termoAtual.linha - 1;
            termoAtual.coluna = termoAtual.coluna;
        }
        else
        {
            termoAtual.token = "insercao";
            termoAtual.valor = ins;
            termoAtual.linha = termoAtual.linha;
            termoAtual.coluna = termoAtual.coluna - 1;
        }

        vetorDeTermos.push_back(termoAtual);
    }
    cout << "-------------------------------------" << endl;
    cout << "caminho percorrido na matriz H (Do ultimo termo para primeiro) : " << endl
         << endl;

    for (int i = 0; i < int(vetorDeTermos.size()); i++)
    {
        cout << vetorDeTermos[i].token << endl;
    }

    // apos conseguir o caminho, com seus respectivos movimentos, agora vamos construir as sequencias alinhadas
    reverse(vetorDeTermos.begin(), vetorDeTermos.end());

    string seqA_alinhada = "";
    string seqB_alinhada = "";

    for (int i = 0; i < int(vetorDeTermos.size()); i++)
    {
        if (vetorDeTermos[i].token == "diagonal")
        {
            seqA_alinhada += seqA[vetorDeTermos[i].linha];
            seqB_alinhada += seqB[vetorDeTermos[i].coluna];
        }
        else if (vetorDeTermos[i].token == "insercao")
        {
            seqA_alinhada += "-";
            seqB_alinhada += seqB[vetorDeTermos[i].coluna];
        }
        else if (vetorDeTermos[i].token == "delecao")
        {
            seqA_alinhada += seqA[vetorDeTermos[i].linha];
            seqB_alinhada += "-";
        }
    }

    // print das sequencias A e B alinhadas
    cout << "-------------------------------------" << endl;
    cout << "Sequencia A alinhada: " << seqA_alinhada << endl;
    cout << "Sequencia B alinhada: " << seqB_alinhada << endl;
    cout << "-------------------------------------" << endl;

    return valorMaximo;
}

// g++ -Wall -O3 main.cpp -o entrega1
// ./entrega1 < dna.seq