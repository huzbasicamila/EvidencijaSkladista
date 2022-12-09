//
// Created by aidah on 12/8/2022.
//

#include "Stvar.h"
#include "Stvar.h"
#include <cstring>

int Stvar::brStvari=0;

Stvar::Stvar(){
    strcpy(this->naziv, "Nova stvar");
    this->kolicina=0;
}
void Stvar::setNaziv() {
    std::cout<<"Unesite naziv stvari: ";
    std::cin.getline(this->naziv, 50);
}
void Stvar::setKolicina(){
    std::cout<<"Unesite kolicinu: ";
    std::cin>>kolicina;
    std::cin.ignore();
}
char *Stvar::getNaziv() {
    return this->naziv;
}
int Stvar::getKolicina(){
    return this->kolicina;
}
void Stvar::unesiStvar(){
    std::cout<<"**** UNOS STVARI ****\n";
    this->setNaziv();
    this->setKolicina();
}
void Stvar::povecajKolicinu(int a){
    this->kolicina+=a;
}
void Stvar::smanjiKolicinu(int a) {
    this->kolicina-=a;
}
void Stvar::trenutnoBrStvari() {
    std::cout<<"Na stanju je trentuno " << Stvar::brStvari << " stvari. ";
}