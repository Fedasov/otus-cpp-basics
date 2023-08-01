#include "inter.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int choose_kommanda(string filename) {

    int komanda = 0;
    int max_value = 100;
    bool znachenie;
    do {
        cout << "0 - Play" << endl 
              << "1 - select the maximum number. By default = 100"<< endl 
              << "2 - You can choose the difficulty level"<< endl 
              << "3 - Table of players and results" << endl;

        cin >> komanda;
        znachenie = false;
        
        switch (komanda) {
        case 0:
            break;

        case 1: {
            cout << "Select the max_value not exceeding 32761. max_value = ";
            cin >> max_value;
            if (max_value > 32767) {
                cout << " Your number is too big --> max_value = 100" << endl;
                max_value = 100;
            }
            break;
            }

        case 2: {
            int lavel;
            cout << "1 - lavel 1" << endl << "2 - lavel 2" << endl << "3 - lavel 3"<< endl;
            cin >> lavel;
            switch(lavel) {
                case 1:
                    max_value = 10;
                    break;
                case 2:
                    max_value = 50;
                    break;
                case 3:
                    max_value = 100;
                    break;
                default:
                    cout << "lavel != 1 or 2 or 3. Because lavel = 3 --> max_value = 100" << endl;
                    max_value = 100;
                    break;
                }
                break;
            }

        case 3: {
            ifstream file(filename);
            file.seekg(0);
            cout << "High scores table:" << endl;
            string dline;
            while (getline(file, dline))
            {
                cout << dline << endl;
            }; 
            file.close();
            break;
            }

        default: {
            znachenie = true;
            break;
            }
        }
        if (komanda == 3) {
            znachenie = true;
            continue;
        }
    } while (znachenie);

    return max_value;
}