//
// Created by aidah on 12/8/2022.
//

#ifndef UNTITLED_OSTAVA_H
#define UNTITLED_OSTAVA_H

#include "Stvar.h"
#include <vector>

class Ostava {
private:
    std::vector<Stvar>stvari;
    int maxBrStvari;
public:
    Ostava();
    void setMaxBrStvari();
    int getMaxBrStvari();
    std::vector<Stvar>& getStvari();
    void spremiStvari();
    void uzmiStvar();
    void ispisOstave();
    void pretragaOstave();

    ~Ostava()=default;

};


#endif //UNTITLED_OSTAVA_H
