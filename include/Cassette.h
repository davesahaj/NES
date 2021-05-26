#ifndef CASSETTE_H
#define CASSETTE_H
#include "Definition.h"

namespace nes
{

    class Cassette
    {
    public:
        Cassette();
        bool loadCassette(std::string path);
        const vb &getROM();
        const vb &getVROM();
        Byte getMapper();
        Byte getNameTableMirroring();
        bool hasExtendedRAM();

    private:
        vb pROM;
        vb cROM;
        Byte mapNum;
        Byte nameTable;
        bool extendedRAM;
        bool cRAM;
    };
}

#endif