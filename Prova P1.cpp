#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Inicio Programa
void Histograma() 
{
   cout << ">> Início: Prova P1\n" << endl;
}

// Função para receber os dados do usuário
vector<int> receberDados() 
{
    vector<int> valores;
    int valor;

    cout << "* Instruções *";
    cout << "\n * Os valores serão exibidos entre colchetes. \n";
    cout << "\n * Organize os valores entre espaços, eles serão exibidos da seguinte maneira [N1, N1, N3, N4].\n";
    cout << "\n * Os valores inseridos serão exibidos ao final do histograma. \n";
    
    cout << "\n Informe os dados: ";
    while (cin >> valor) 
    {
        valores.push_back(valor);  
        if (cin.peek() == '\n') break;  
    }

    return valores;
}

// Função para exibir os dados
void InserirDados(const vector<int>& valores) 
{
    cout << "\nDados: [";
    for (size_t i = 0; i < valores.size(); ++i) 
    {
       cout << valores[i];
       if (i != valores.size() - 1) 
       cout << ", ";
    }
    cout << "]\n";
}

// Função para exibir a configuração do histograma
void Configuracao(int totalLinhas, int totalColunas) 
{
   cout << "\n* Total de linhas: " << totalLinhas << endl;
   cout << "* Total de colunas: " << totalColunas << endl;
}

// Função para exibir o histograma horizontal
void ExibirHistograma(const vector<int>& valores, int totalColunas) 
{
   cout << "\n Histograma Horizontal\n";
   for (size_t i = 0; i < valores.size(); ++i) 
   {
      cout << i + 1 << "| ";  // Exibe o índice da linha
      for (int j = 0; j < valores[i]; ++j) 
      {
         cout << "* "; 
      }
        cout << endl;
    }

    // Exibe a linha inferior do gráfico e os números abaixo
    cout << " + ";
    for (int i = 0; i <= totalColunas; ++i) 
    {
       cout << "- ";
    }
    cout << endl;

    cout << "  ";
    for (int i = 0; i <= totalColunas; ++i)
    {
       cout << i << " ";
    }
    cout << endl;
}

// Exibir final do programa
void Final() 
{
   cout << "\n* Final do Programa\n";
}

int main() 
{
    Histograma();

    // Insercao dos dados dos usuarios
    vector<int> valores = receberDados();

    // Exibir os dados recebidos
    InserirDados(valores);

    // Calculo do total de linhas e colunas
    int totalLinhas = valores.size();
    int totalColunas = *max_element(valores.begin(), valores.end());

    // Exibe as informações de linhas e colunas
    Configuracao(totalLinhas, totalColunas);

    // Exibe o histograma horizontal
    ExibirHistograma(valores, totalColunas);

    // Exibe a mensagem de final do programa
    Final();

    return 0;
}
