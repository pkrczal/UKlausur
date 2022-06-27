//
// Created by Paul Krczal on 20.06.22.
//

#include "Logic.h"
#include "sstream"

int Logic::getValue(int zeile, int spalte) {
    if (zeile >= 0 && spalte >= 0 && zeile < this->zeilen && spalte < this->spalten) {
        int i = v[zeile][spalte];
        return i;
    }
    return 0;
}

void Logic::setValue(int zeile, int spalte, int vlaue) {
    if (zeile >= 0 && spalte >= 0 && zeile < this->zeilen && spalte < this->spalten) {
        v[zeile][spalte] = vlaue;
    }
}

std::string Logic::getValue(std::string key) {
    for (MetaData *mD: m) {
        if (mD->getKey() == key) {
            return mD->getValue();
        }
    }
    return "";
}

void Logic::addPair(std::string key, std::string value) {
    MetaData *mD = new MetaData(key, value);
    m.push_back(mD);
}

void Logic::deletePair(std::string key) {
    int index = 0;
    for (MetaData *mD: m) {
        if (mD->getKey() == key) {
            m.erase(m.begin() + index);
            return;
        }
        index++;
    }
}

int Logic::read(std::string filename) {
    std::ifstream in;
    in.open(filename);
    char buff[100] = "";
    std::string stringBuffer;
    in.getline(buff, sizeof(buff));
    in.getline(buff, sizeof(buff));
    in.getline(buff, sizeof(buff));
    std::stringstream ss(buff);
    std::getline(ss, stringBuffer, ' ');
    std::getline(ss, stringBuffer, '\n');
    name = stringBuffer;
    in.getline(buff, sizeof(buff));
    std::stringstream ss1(buff);
    std::getline(ss1, stringBuffer, ' ');
    std::getline(ss1, stringBuffer, '\n');
    int numberOfPairs = std::stoi(stringBuffer);
    for (int i = 0; i < numberOfPairs; i++) {
        std::string key, value;
        in.getline(buff, sizeof(buff));
        std::stringstream ssLoop(buff);
        std::getline(ssLoop, stringBuffer, ':');
        key = stringBuffer;
        std::getline(ssLoop, stringBuffer, ' ');
        std::getline(ssLoop, stringBuffer, '\n');
        value = stringBuffer;
        m.push_back(new MetaData(key, value));
    }
    int zeilenRead, spaltenRead;
    in.getline(buff, sizeof(buff));
    std::stringstream ss2(buff);
    std::getline(ss2, stringBuffer, ' ');
    std::getline(ss2, stringBuffer, '\n');
    zeilenRead = std::stoi(stringBuffer);
    zeilen = zeilenRead;
    in.getline(buff, sizeof(buff));
    std::stringstream ss3(buff);
    std::getline(ss3, stringBuffer, ' ');
    std::getline(ss3, stringBuffer, '\n');
    spaltenRead = std::stoi(stringBuffer);
    spalten = spaltenRead;
    in.getline(buff, sizeof(buff));
    std::stringstream ssValue(buff);
    for (int i = 0; i < zeilenRead; i++) {
        for (int u = 0; u < spaltenRead; u++) {
            std::getline(ssValue, stringBuffer, ' ');
            int value = std::stoi(stringBuffer);
            v[i][u] = value;
        }
    }
    return 0;
}

int Logic::write(std::string filename) {
    std::ofstream out;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    out.open(filename);
    out << "C++ Tut" << std::endl;
    out << "Erstellt am: " << std::put_time(&tm, "%d-%m-%Y") << std::endl;
    out << "Name: " << name << std::endl;
    out << "Anzahl Infos: " << m.size() << std::endl;
    for (MetaData *mD: m) {
        out << mD->getKey() << ": " << mD->getValue() << std::endl;
    }
    out << "Anzahl Zeilen: " << zeilen << std::endl;
    out << "Anzahl Spalten: " << spalten << std::endl;
    for (int i = 0; i < zeilen; i++) {
        for (int z = 0; z < spalten; z++) {
            out << v[i][z] << " ";
        }
    }
    return 0;
}
