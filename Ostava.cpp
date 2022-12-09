//
// Created by aidah on 12/8/2022.
//

#include "Ostava.h"
#include <iostream>
#include <memory>
#include <cstring>

Ostava::Ostava() {
    std::cout<<"Unesi kapacitet ostave: ";
    std::cin>>this->maxBrStvari;
    std::cin.ignore();
    std::cout<<"Ostava kreirana \n";
}
void Ostava::setMaxBrStvari() {
    std::unique_ptr<int> broj=std::make_unique<int>(0);
    std::cout<<"Unesite za koliko zelite prosiriti ostavu: ";
    std::cin>>*broj;
    std::cin.ignore();
    this->maxBrStvari+=*broj;
}
int Ostava::getMaxBrStvari() {
    return this->maxBrStvari;
}
std::vector<Stvar> &Ostava::getStvari() {
    if (this->getMaxBrStvari() == Stvar::brStvari) {
        std::cout << "Ostava je puna. ";
    } else {
        Stvar temp;
        temp.unesiStvar();
        bool ima = false;
        for (auto &i: this->stvari) {
            if (_strcmpi(i.getNaziv(), temp.getNaziv()) == 0) {
                std::cout << "Nije moguce spremiti " << temp.getKolicina() << " "
                          << temp.getNaziv() << " u ostavu!\n";
                int slobodno = this->getMaxBrStvari() - Stvar::brStvari;
                i.povecajKolicinu(slobodno);
                std::cout << "Spremljeno je smao " << slobodno << " "
                          << temp.getNaziv() << " u ostavu!\n";
                Stvar::brStvari = this->getMaxBrStvari();
            } else {
                i.povecajKolicinu(temp.getKolicina());
                std::cout << "Spremljeno je " << temp.getKolicina() << " "
                          << temp.getNaziv() << " u ostavu! \n";
                Stvar::brStvari += temp.getKolicina();
            }
            break;
        }
        if (!ima) {
            if (temp.getKolicina() + Stvar::brStvari > this->getMaxBrStvari()) {
                std::cout << "Nije moguce spremiti  " << temp.getKolicina() << " "
                          << temp.getNaziv() << " u ostavu!\n";
                int viska = Stvar::brStvari + temp.getKolicina() - this->getMaxBrStvari();
                temp.smanjiKolicinu(viska);
                std::cout << "Spremljeno je samo " << viska << " "
                          << temp.getNaziv() << " u ostavu!\n";
                this->getStvari().push_back(temp);
                Stvar::brStvari = this->getMaxBrStvari();
            } else {
                this->getStvari().push_back(temp);
                std::cout << "Spremljeno je " << temp.getKolicina() << " "
                          << temp.getNaziv() << " u ostavu!\n";
                Stvar::brStvari += temp.getKolicina();
            }
        }
    }
}
void Ostava::uzmiStvar(){
    if(this->stvari.size()==0) {
        std::cout<<"Ostava je prazna \n";
    } else {
        this->ispisOstave();
        char stvar[50];
        bool ima=false;
        for(int i =0; i<this->stvari.size(); i++) {
            if(_strcmpi(this->stvari[i].getNaziv(), stvar)==0) {
                ima =true;
                int kol;
                do {
                    std::cout<<"Unesite kolicinu za uzeti: ";
                    std::cin>>kol;
                } while (kol<1 || kol>this->stvari[i].getKolicina());
                this->stvari[i].smanjiKolicinu(kol);
                Stvar::brStvari-=kol;
                if(this->stvari[i].getKolicina()==0)  {
                    this->stvari.erase(this->stvari.begin()+i);
                }
                break;
            }
        }
        if(!ima) {
            std::cout<<stvar << " ne postoji u ostavi\n";
        }
    }
}
void Ostava::ispisOstave() {
    if(this->stvari.size()==0) {
        std::cout<<" Ostava je prazna \n";
    } else {
        std::cout<<"Stvar \t\tKolicina\n";
        std::cout<<"--------------------------\n";
        for(auto& i:this->stvari) {
            std::cout<<i.getNaziv() << "\t\t" <<i.getKolicina() << "\n";
        }
        std::cout<<"--------------------------\n";
        std::cout<<"Ukupno: \t\t" << Stvar::brStvari << "\\" << this->getMaxBrStvari() << std::endl;
    }
}
void Ostava::pretragaOstave() {
    if(this->stvari.size()==0) {
        std::cout<< "Ostava je prazna!\n";
    } else {
        this->ispisOstave();
        char stvar[50];
        std::cout<<"Unesite stvar za pretragu: ";
        std::cin.getline(stvar, 50);
        bool ima=false;
        for(int i =0;i<this->stvari.size();i++) {
            if(_strcmpi(this->stvari[i].getNaziv(), stvar)==0) {
                ima=true;
                std::cout<<"U ostavi ima " << this->stvari[i].getKolicina() << " " << stvar << std::endl;
                break;
            }
        }
        if(!ima) {
            std::cout<<"Nije pronadjena " << stvar << " u ostavi! \n";
        }
    }
}