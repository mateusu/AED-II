/*Matheus de Oliveira Lêu - 8802621
EP2.1 - KMP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void falha(char* p, int* f)
{
    f[0] = 0;
    int i = 1;
    int j = 0;

    int m = strlen(p);

    while (i < m)
    {
        if (p[i] == p[j])
        {
            f[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = f[j - 1];
        }
        else
        {
            f[i] = 0;
            i += 1;
        }
    }
}

int kmp(char* t, char* p, int i)
{
    int m = strlen(p);
    int n = strlen(t);
    int* f = malloc(m*sizeof(int));
    int k;
    for(k = 0; k < m; k++)
        f[k] = 0;
    falha(p, f);
    int j = 0;

    while (i < n)
    {
        if (t[i] == p[j])
        {
            if (j == m - 1)
            {
                return i - j;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if (j > 0)
            {
                j = f[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return -1;
}

void shiftRight(char* padrao){
   int k;
   for (k = strlen(padrao); k >0; k--){
    padrao[k]=padrao[k-1];
}
    padrao[0] = ' ';
}

//main parte 1
int main()
{
    char texto[100000];
    char padrao[200];
    int valor, iteracao;
    scanf("%[^\n]s\n", &texto);
    scanf("%d", &valor);
    int j, i, terminou, match;
    shiftRight(texto);
    texto[strlen(texto)] = ' ';
    for(j = 0; j < valor; j++)
    {
        iteracao = 0;
        terminou = 0;
        scanf("%s", &padrao);
        padrao[strlen(padrao)] = ' ';
        shiftRight(padrao);
        i = 0;
        while(terminou == 0)
        {
            match = kmp(texto, padrao, i);
            if(match == -1)
            {
                terminou = 1;
            }
            i = match+1;

            if(match != -1){
                if(iteracao > 0)printf(" %d", match);
                else printf("%d", match);


            }
            if(match ==-1 && iteracao == 0) printf("%d", -1);
            iteracao++;

        }
       // if(j < valor-1)
       printf("\n");

        memset(&padrao[0], 0, sizeof(padrao));
    }

    return 0;
}
