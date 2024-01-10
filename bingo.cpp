#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int LINHAS = 5;
const int COLUNAS = 5;

void gerarCartao(ofstream& arquivo) {
    vector<vector<int>> cartao(LINHAS, vector<int>(COLUNAS));
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            cartao[i][j] = rand() % 100 + 1;
        }
    }
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            arquivo << cartao[i][j] << " ";
        }
        arquivo << endl;
    }
    arquivo << endl;
}

void mostrarCartao(const vector<vector<int>>& cartao) {
    for (const auto& linha : cartao) {
        for (int num : linha) {
            cout << (num == 0 ? "x" : to_string(num)) << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    cout << "Escolha o modo de sorteio (automático/manual): ";
    string modoSorteio;
    cin >> modoSorteio;

    cout << "Escolha a quantidade de números (75, 90 ou 100): ";
    int quantidadeNumeros;
    cin >> quantidadeNumeros;

    cout << "Digite a quantidade de cartões a serem gerados: ";
    int quantidadeCartoes;
    cin >> quantidadeCartoes;

    ofstream arquivo("cartoes_bingo.txt");

    for (int i = 0; i < quantidadeCartoes; ++i) {
        gerarCartao(arquivo);
    }

    arquivo.close();

    vector<int> numerosSorteados;
    
    while (numerosSorteados.size() < quantidadeNumeros) {
        if (modoSorteio == "manual") {
            cout << "Pressione Enter para sortear o próximo número." << endl;
            cin.ignore(); // espera o Enter ser pressionado
        }

        int sorteio;
        do {
            sorteio = rand() % 100 + 1;
        } while (find(numerosSorteados.begin(), numerosSorteados.end(), sorteio) != numerosSorteados.end());

        numerosSorteados.push_back(sorteio);
        sort(numerosSorteados.begin(), numerosSorteados.end());

        // mostra o número sorteado e o imediatamente anterior
        if (numerosSorteados.size() > 1) {
            cout << "Número sorteado: " << sorteio << ", Anterior: " << numerosSorteados[numerosSorteados.size() - 2] << endl;
        } else {
            cout << "Número sorteado: " << sorteio << endl;
        }

        // Mostra o painel dos números sorteados
        cout << "Painel dos números sorteados: ";
        for (int num : numerosSorteados) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}