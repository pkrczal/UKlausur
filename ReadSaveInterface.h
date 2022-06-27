//
// Created by Paul Krczal on 20.06.22.
//

#ifndef UKLAUSUR_READSAVEINTERFACE_H
#define UKLAUSUR_READSAVEINTERFACE_H
#include "string"
#pragma once
#endif //UKLAUSUR_READSAVEINTERFACE_H

class ReadSaveInterface {

    virtual int read(std::string filename) = 0;
    virtual int write(std::string filename) = 0;

};
