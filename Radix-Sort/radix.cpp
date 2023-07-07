#include "radix.h"

void print_vetor(std::vector<std::string>& vetor)
{
    for(auto &string : vetor)
        std::cout << string << " " ;
    
    std::cout << std::endl;
}

const int MSD::BITS_PER_BYTE = 8;
const int MSD::BITS_PER_INT = 32;
const int MSD::R = 256;
const int MSD::CUTOFF = 15;

int MSD::charAt(const std::string& s, int d) {
    if (d == s.length()) return -1;
    return s[d];
}

void MSD::sort(std::vector<std::string>& a, int lo, int hi, int d, std::vector<std::string>& aux)
{
    if (hi <= lo + CUTOFF) {
        insertion(a, lo, hi, d);
        return;
    }

    std::vector<int> count(R + 2, 0);
    for (int i = lo; i <= hi; i++) {
        int c = charAt(a[i], d);
        count[c + 2]++;
    }

    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];

    for (int i = lo; i <= hi; i++) {
        int c = charAt(a[i], d);
        aux[count[c + 1]++] = a[i];
    }

    for (int i = lo; i <= hi; i++)
        a[i] = aux[i - lo];

    for (int r = 0; r < R; r++)
        sort(a, lo + count[r], lo + count[r + 1] - 1, d + 1, aux);
}

void MSD::insertion(std::vector<std::string>& a, int lo, int hi, int d) 
{
    for (int i = lo; i <= hi; i++)
        for (int j = i; j > lo && less(a[j], a[j - 1], d); j--)
            std::swap(a[j], a[j - 1]);
}

bool MSD::less(const std::string& v, const std::string& w, int d) 
{
    for (int i = d; i < std::min(v.length(), w.length()); i++) {
        if (v[i] < w[i]) return true;
        if (v[i] > w[i]) return false;
    }
    return v.length() < w.length();
}

void MSD::sort(std::vector<std::string>& a) {
    int n = a.size();
    std::vector<std::string> aux(n);
    sort(a, 0, n - 1, 0, aux);
}

