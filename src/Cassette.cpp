#include "Cassette.h"
#include "Definition.h"

namespace nes
{
    Cassette::Cassette()
    {
        nameTable = 0, mapNum = 0, extendedRAM = false;
    }

    bool Cassette::loadCassette(std::string path)
    {
    }
    const vb &Cassette::getROM() { return pROM; }
    const vb &Cassette::getVROM() { return cROM; }
    Byte Cassette::getMapper() { return mapNum; }
    Byte Cassette::getNameTableMirroring() { return nameTable }
    bool Cassette::hasExtendedRAM() { return extendedRAM; }
}