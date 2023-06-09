#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main() {
    const std::string filename = "testFile.txt";

    std::string name;
    std::cout << "Hi! Enter your name, please: ";
    std::cin >> name;

    int komanda = 0;
    std::cout << "0 - Play" << std::endl << "1 - select the maximum number. By default = 100"<< std::endl << "2 - You can choose the difficulty level"<< std::endl << "3 - Table of players and results" << std::endl;
    std::cin >> komanda;

    std::srand(std::time(nullptr));
    int max_value = 100;
    switch (komanda) {

        case 0:
            break;

        case 1:
            std::cout << " guess_the_number max_value = ";
            std::cin >> max_value;
            if (max_value > 32767) {
                std::cout << " guess_the_number max_value = 100" << std::endl;
                max_value = 100;
            }
		break;

        case 2:
            int lavel;
            std::cout << "1 - lavel 1" << std::endl << "2 - lavel 2" << std::endl << "3 - lavel 3"<< std::endl;
            std::cin >> lavel;
            switch(lavel) {
                case 1:
                    max_value = 10;
                case 2:
                    max_value = 50;
                case 3:
                    max_value = 100;
            }
            break;

        case 3:
            std::ifstream file(filename);
            file.seekg(0);
            std::cout << "High scores table:" << std::endl;
            std::string dline;
            while (std::getline(file, dline))
            {
                std::cout << dline << std::endl;
            }; 
            file.close();

        return 0;   
    }

    int our_value = rand() % max_value;
    std::cout << "our_value = " << our_value << std::endl;

	std::fstream file{filename, std::ios_base::in | std::ios_base::out | std::fstream::app};
	if (!file.is_open())
	{
		std::cout << "Error! File was not opened!" << std::endl;
		return false;
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

    std::string s_value;
    std::string line;
    int i_value = 0, j = 0;
    std::map<std::string, int> resultat;
    while (std::getline(file, line))
    {
        j++;
        if (j == 1){
            file.seekg(0);
        }

        file >> s_value;
        file >> i_value;

        if (resultat.count(s_value) == 1) {
            if (resultat[s_value] > i_value) {
                resultat[s_value] = i_value;
            }
        } else {
            resultat[s_value] = i_value;
        }

    };

    std::cout << "High scores table:" << std::endl;
    
    for (const auto& [ima, res] : resultat)
        std::cout << ima << "\t" << res << std::endl;

    return 1;
}


