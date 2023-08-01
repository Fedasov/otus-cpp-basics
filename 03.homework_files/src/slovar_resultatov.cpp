#include "slovar_resultatov.h"

#include <iostream>
#include <fstream>

std::map<std::string, int> slovar(std::fstream* file) {
    std::string s_value;
    std::string line;
    int i_value = 0, j = 0;
    std::map<std::string, int> resultat;
    while (std::getline(*file, line))
    {
        j++;
        if (j == 1){
            (*file).seekg(0);
        }

        (*file) >> s_value;
        (*file) >> i_value;

        if (resultat.count(s_value) == 1) {
            if (resultat[s_value] > i_value) {
                resultat[s_value] = i_value;
            }
        } else {
            resultat[s_value] = i_value;
        }
    }
    return resultat;
}