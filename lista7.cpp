#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;
 
// AUma função que retorna o maior de 2 valores
int max(int a, int b) { return (a > b)? a : b; }
 
// Retorna o valor máximo que pode ser colocado na mochila com o peso limite determinado
int knapSack(int pesoLim, int pesos[], int valores[], int n)
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
           else if (pesos[i-1] <= w)
                 K[i][w] = max(valores[i-1] + K[i-1][w-pesos[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][pesoLim];
}
 
int main()
{
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

    int  pesoLim = 100;
    int n = sizeof(valores)/sizeof(valores[0]);
    printf("%d\n", knapSack(pesoLim, pesos, valores, n));
    return 0;
}