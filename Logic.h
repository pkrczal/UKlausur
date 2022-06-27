//
// Created by Paul Krczal on 20.06.22.
//

#ifndef UKLAUSUR_LOGIC_H
#define UKLAUSUR_LOGIC_H

#include "vector"
#include "string"
#include "MetaData.h"
#include "ReadSaveInterface.h"
#include "iostream"
#include "fstream"

#pragma once

class Logic : ReadSaveInterface {

public:
    Logic(std::string name, int zeilen, int spalten) : name(name),
                                                       zeilen(zeilen),
                                                       spalten(spalten),
                                                       v(zeilen, std::vector<int>(spalten, 0)) {

    }

    Logic(Logic &l) : name(l.name), zeilen(l.zeilen), spalten(l.spalten), v(l.v) {

    }

    ~Logic() {
        for (MetaData *mD : m) {
            delete mD;
        }
    }

    Logic() = default;

    int getValue(int zeile, int spalte);

    void setValue(int zeile, int spalte, int value);

    std::string getValue(std::string key);

    void addPair(std::string key, std::string value);

    void deletePair(std::string key);

    int read(std::string filename) override;

    int write(std::string filename) override;

private:
    std::vector<std::vector<int>> v;
    std::vector<MetaData*> m;
    std::string name;
    int zeilen;
    int spalten;

};


#endif //UKLAUSUR_LOGIC_H
