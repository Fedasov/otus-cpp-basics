#include "random.h"
#include "inter.h"
#include "slovar_resultatov.h"

#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main() {
    const std::string filename = "testFile.txt";

    std::string name;
    std::cout << "Hi! Enter your name, please: ";
    std::cin >> name;

    int max_value = choose_kommanda(filename);
    int our_value = random(max_value);

	std::fstream file{filename, std::ios_base::in | std::ios_base::out | std::fstream::app};
	if (!file.is_open())
	{
		std::cout << "Error! File was not opened!" << std::endl;
		return 1;
	}

    int value = 0, i = 0;
    do {
        std::cout << "Enter a namber: ";
        std::cin >> value; 
        if (value > our_value) {
            std::cout << "greater than" << std::endl;
        } else if (value < our_value) {
            std::cout << "less than" << std::endl;
        } else {
            std::cout << "you win!" << std::endl << std::endl;
        }
        i++;
    } while(value != our_value);

    file << name << " " << i << std::endl;
    file.seekg(0);
    
    std::map<std::string, int> resultat = slovar(&file);

    std::cout << "High scores table:" << std::endl;
    for (const auto& [ima, res] : resultat)
        std::cout << ima << "\t" << res << std::endl;

    return 0;
}


