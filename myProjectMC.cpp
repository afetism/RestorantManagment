// myProjectMC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include<regex>
#include<fstream>
#include<Windows.h>
#include<conio.h>

enum direction {
	UP=72,
	DOWN=80
};
using namespace std;
const int Red = FOREGROUND_RED | FOREGROUND_INTENSITY;
const int White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
const int Yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int BlueBackground = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
const int RedBackground = BACKGROUND_RED | BACKGROUND_INTENSITY;
const int YellowBackground = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;


void setConsoleColor(int textAttributes, int backgroundColor) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, textAttributes | backgroundColor);
}

#include"baseClasies.h"
#include"drivedClasies.h"
#include"prototypes.h"
#include"menu.h"
#include"userPanel.h"
string CompanyLogo = R"(


                                               :----.             .----:          
                                            -==-::-==:         :==-::-==-        
                                          .-==.    -==-       -==-    .==-.      
                                         .===:      -==-     -==-      :===.     
                                         ===-       .===-   -===.       -===     
                                        -===.        -===: :===-        .===-    
                                       :===-         .====:====.         -===:   
                                       ====:          -=======-          :====   
                                      :====.          :=======:          .====:  
                                      -====           .=======.           -===-  
                                     .====-            =======            -====. 
                                     :====:            -=====-            :====: 
                                     -====.            -=====:            .====- 
                                     =====             :=====:             ===== 
                                    .=====             :=====.             =====.
                                    :=====             .=====.             -====:
                                    :====-             .=====.             -====:
                                    :====-             .=====.             -====-
                                    -====-              .....              -====-

                           

)";


int main()
{
	system("color 4E");
    system("color 4E");
    cout << "\t\t";
    for (int i = 0; i <= 100; i += 10)
    {
        setConsoleColor(Red, YellowBackground);
        cout << "       ";
        setConsoleColor(White, 0);

        Sleep(500);
    }
    system("cls");


	menu();
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
