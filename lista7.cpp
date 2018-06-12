#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

#define pesoMax 1000
#define valorMax 1000

bool taken[100][100];

// Função que retorna o maior de 2 valores
int max(int a, int b) { return (a > b)? a : b; }

// Retorna o valor máximo que pode ser colocado na mochila com o peso limite determinado
void knapSack(int pesoLim, int pesos[], int valores[], int n)
{
   int i, w;
   int K[n+1][pesoLim+1];

   // Construa a tabela K [] [] de maneira ascendente
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= pesoLim; w++)
       {
           if (i==0 || w==0)
                K[i][w] = 0;
           else if (pesos[i-1] <= w){
                K[i][w] = max(valores[i-1] + K[i-1][w-pesos[i-1]],  K[i-1][w]);
                if(K[i][w]== valores[i-1] + K[i-1][w-pesos[i-1]]){
                  taken[i][w] = true;
                  }
                }
           else{
                K[i][w] = K[i-1][w];
              }
       }
   }

   cout << "\nValor da mochila = " << K[n][pesoLim] << endl;
   cout << endl;
   int res = K[n][pesoLim];
   w = pesoLim;
   for (i = n; i > 0 && res > 0; i--) {
       if (res == K[i - 1][w])
           continue;
       else {
           printf("Valor do item = %d; Peso = %d\n", valores[i - 1], pesos[i - 1]);

           res = res - valores[i - 1];
           w = w - pesos[i - 1];
       }
   }
}

int main()
{
    memset(taken, false, sizeof taken);
    int size;
    cout << "Informe o tamanho dos vetores:" << '\n';
    cin >> size;

    int valores[size];
    int pesos[size];

    if (size < 1000000) {
        srand((unsigned)time(NULL));
        for (size_t i = 0; i < size; i++) {
            valores[i] = rand()%1000;
        }
    }

    if (size <= 20) {
        cout << "Valores = ";
        for (size_t i = 0; i < size; i++) {
            cout << valores[i] << " ";
        }
    }

    cout << endl;

    if (size < 1000000) {
        for (size_t i = 0; i < size; i++) {
            pesos[i] = rand()%100;
        }
    }

    if (size <= 20) {
        cout << "Pesos = ";
        for (size_t i = 0; i < size; i++) {
            cout << pesos[i] << " ";
        }
    }

    cout << endl;

    int  pesoLim;
    cout << "Insira o peso máximo da mochila: ";
    cin >> pesoLim;

    int n = sizeof(valores)/sizeof(valores[0]);
    knapSack(pesoLim, pesos, valores, n);
    return 0;
}
