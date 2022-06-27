//
// Created by Paul Krczal on 20.06.22.
//

#ifndef UKLAUSUR_METADATA_H
#define UKLAUSUR_METADATA_H
#pragma once

#include "string"

class MetaData {

public:
    MetaData(std::string key, std::string value) : key(key), value(value) {}

    MetaData(MetaData &m) : key(m.key), value(m.value) {}

    MetaData() = default;

    ~MetaData() {}

    std::string getKey() { return key; }

    std::string getValue() { return value; }

private:
    std::string key;
    std::string value;
};


#endif //UKLAUSUR_METADATA_H
