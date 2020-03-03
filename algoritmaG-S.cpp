/*
    Nama    : Aithra Junia Bouty
    Kelas   : B
    NPM     : 140810180054
*/
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define N 5

bool chooseMen(int prioritas[2 * N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prioritas[w][i] == m1)
            return true;

        if (prioritas[w][i] == m)
            return false;
    }
}
void smp(int prioritas[2 * N][N]) //smp = stable matching problem
{
    int women[N];
    bool men[N];

    memset(women, -1, sizeof(women));
    memset(men, false, sizeof(men));
    int jumlahJomblo = N;

    while (jumlahJomblo > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (men[m] == false)
                break;

        for (int i = 0; i < N && men[m] == false; i++)
        {
            int w = prioritas[m][i];

            if (women[w - N] == -1)
            {
                women[w - N] = m;
                men[m] = true;
                jumlahJomblo--;
            }

            else
            {
                int m1 = women[w - N];

                if (chooseMen(prioritas, w, m, m1) == false)
                {
                    women[w - N] = m;
                    men[m] = true;
                    men[m1] = false;
                }
            }
        }
    }
    cout << "-----------------" << endl;
    cout << "  Men     Women  " << endl;
    cout << "-----------------" << endl;
    string man;
    string woman;
    for (int i = 0; i < N; i++)
    {
        if (i < N)
        {
            if (women[i] == 0)
                woman = "Amy";
            if (women[i] == 1)
                woman = "Bertha";
            if (women[i] == 2)
                woman = "Clare";
            if (women[i] == 3)
                woman = "Diane";
            if (women[i] == 4)
                woman = "Erika";

            if (i == 0)
                man = "Victor";
            if (i == 1)
                man = "Wyatt";
            if (i == 2)
                man = "Xavier";
            if (i == 3)
                man = "Yancey";
            if (i == 4)
                man = "Zeus";
        }
        cout << " " << man << "\t  " << woman << endl;
    }
    cout << "-----------------" << endl;
}

int main()
{
    int prioritas[2 * N][N] = {{6, 5, 8, 9, 7},
                            {8, 6, 5, 7, 9},
                            {6, 9, 7, 8, 5},
                            {5, 8, 7, 6, 9},
                            {6, 8, 5, 9, 7},
                            {4, 0, 1, 3, 2},
                            {2, 1, 3, 0, 4},
                            {1, 2, 3, 4, 0},
                            {0, 4, 3, 2, 1},
                            {3, 1, 4, 2, 0}};
    smp(prioritas);

    return 0;
}
