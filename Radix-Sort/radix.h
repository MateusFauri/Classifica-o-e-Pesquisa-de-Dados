#ifndef MSD_SORT_H
#define MSD_SORT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

class MSD {
private:
    static const int BITS_PER_BYTE;
    static const int BITS_PER_INT;
    static const int R;
    static const int CUTOFF;

    static int charAt(const std::string& s, int d);
    static void sort(std::vector<std::string>& a, int lo, int hi, int d, std::vector<std::string>& aux);
    static void insertion(std::vector<std::string>& a, int lo, int hi, int d);
    static bool less(const std::string& v, const std::string& w, int d);

public:
    static std::map<std::string, int> countOccurrences(std::vector<std::string>& a);
    static std::map<std::string, int> top1000Occurrences(std::map<std::string, int>& ocorrencias);
    static void sort(std::vector<std::string>& a);
};

void print_vetor(std::vector<std::string>& vetor);

#endif  // MSD_SORT_H