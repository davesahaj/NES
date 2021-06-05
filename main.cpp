#include "Emulator.h"
#include "Logger.h"
#include "Definition.h"

namespace nes
{
}

int main(int c, char **v)
{

    fout logFile("NES.log"), cpuTraceFile;

    nes::TeeStream logTee(logFile, std::cout);

    if (logFile.is_open() && logFile.good())
        nes::Logger::get().setLoggerStream(logTee);
    else
        nes::Logger::get().setLoggerStream(std::cout);

    nes::Logger::get().setLevel(nes::Info);

    std::string path;
}