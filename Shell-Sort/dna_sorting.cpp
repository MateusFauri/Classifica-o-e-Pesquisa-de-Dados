#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int count_inversions(const string &sequence)
{
    int inversions = 0;
    int n = sequence.length();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sequence[i] > sequence[j])
            {
                inversions++;
            }
        }
    }

    return inversions;
}

bool compare_sequences(const pair<int, string> &a, const pair<int, string> &b)
{
    int inv_a = count_inversions(a.second);
    int inv_b = count_inversions(b.second);

    if (inv_a == inv_b)
    {
        // Se o numero de inversões é o mesmo, compara com os índices originais
        return a.first < b.first;
    }

    return inv_a < inv_b;
}

int main()
{
    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, string>> sequences(m);
        cin.ignore(); // Ignora a linha em branco

        for (int j = 0; j < m; j++)
        {
            getline(cin, sequences[j].second);
            sequences[j].first = j; // Guarda o índice original
        }

        // stable_sort usa merge sort para ordenar na ordem de que a comparação de sequencias retorna
        stable_sort(sequences.begin(), sequences.end(), compare_sequences);

        for (int j = 0; j < m; j++)
        {
            cout << sequences[j].second << endl;
        }

        // coloca linha em branco ao final de cada dataset menos se for o último
        if (i < M - 1)
            cout << endl;
    }

    return 0;
}
