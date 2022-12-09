#include <iostream>
#include "Ostava.h"

int glavniMeni(){
    int izbor;
    std:: cout<<" 1. Unesi stvar\n";
    std::cout<<"  2.  Uzmi stvar\n";
    std::cout<<"  3.  Pretraga stvari \n";
    std::cout<<"  4.  Ispis ostave\n";
    std::cout<<"  5.  Kraj\n";
    do {
        std::cout<<"Izbor: ";
        std::cin>>izbor;
    } while(izbor<1 || izbor>5);
    std::cin.ignore();
    return izbor;
}

int main() {
    Ostava o;
    system("pause");
    system("cls");
    int izbor;
    do {
        izbor=glavniMeni();
        switch(izbor) {
            case 1:
                o.spremiStvari();
            case 2:
                o.uzmiStvar();
            case 3:
                o.pretragaOstave();
            case 4:
                o.ispisOstave();
            default:
                break;
        }
        system("pause");
        system ("cls");
    } while(izbor!=5);
    return 0;
}