#include "decoration.h"

#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

void decoration::bannerMontage() {
                    
    system("COLOR 09");
    cout << endl;
    cout << " ####### ####### #     # #    #                                                         " << endl;
    cout << " #          #    ##   ## #   #                                                          " << endl;
    cout << " #          #    # # # # #  #                                                           " << endl;
    cout << " #####      #    #  #  # ###                                                            " << endl;
    cout << " #          #    #     # #  #                                                           " << endl;
    cout << " #          #    #     # #   #                                                          " << endl;
    cout << " #          #    #     # #    #                                                         " << endl;
    cout << "" << endl;
    cout << " #     #    #    ### #     # ####### ####### #     #    #    #     #  #####  #######    " << endl;
    cout << " ##   ##   # #    #  ##    #    #    #       ##    #   # #   ##    # #     # #          " << endl;
    cout << " # # # #  #   #   #  # #   #    #    #       # #   #  #   #  # #   # #       #          " << endl;
    cout << " #  #  # #     #  #  #  #  #    #    #####   #  #  # #     # #  #  # #       #####      " << endl;
    cout << " #     # #######  #  #   # #    #    #       #   # # ####### #   # # #       #          " << endl;
    cout << " #     # #     #  #  #    ##    #    #       #    ## #     # #    ## #     # #          " << endl;
    cout << " #     # #     # ### #     #    #    ####### #     # #     # #     #  #####  #######    " << endl;
    cout << "" << endl;
    cout << "  #####  #     #  #####  ####### ####### #     #                                        " << endl;
    cout << " #     #  #   #  #     #    #    #       ##   ##                                        " << endl;
    cout << " #         # #   #          #    #       # # # #                                        " << endl;
    cout << "  #####     #     #####     #    #####   #  #  #                                        " << endl;
    cout << "       #    #          #    #    #       #     #                                        " << endl;
    cout << " #     #    #    #     #    #    #       #     #                                        " << endl;
    cout << "  #####     #     #####     #    ####### #     #                                        " << endl;
    cout << "" << endl;
    
    Sleep(3000);
    system("cls");
}

void decoration::select() {

    SetConsoleTextAttribute(color, 6);
}

void decoration::title(){

    SetConsoleTextAttribute(color,10);
}

void decoration::input() {

    SetConsoleTextAttribute(color, 9);
}

void decoration::info() {

    SetConsoleTextAttribute(color, 10);
}

void decoration::success() {

    SetConsoleTextAttribute(color, 10);
}

void decoration::danger() {

    SetConsoleTextAttribute(color, 4);
}

void decoration::defaultCOLOR() {

    SetConsoleTextAttribute(color, 15);
}

void decoration::adminCOLOR() {

    SetConsoleTextAttribute(color, 9);
}

void decoration::adminStatic() {

    SetConsoleTextAttribute(color, 15);
}

void decoration::adminTableHeader() {

    SetConsoleTextAttribute(color, 6);
}

void decoration::adminTableData() {

    SetConsoleTextAttribute(color, 15);
}

void decoration::adminInput() {

    SetConsoleTextAttribute(color, 7);
}
