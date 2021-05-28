#ifndef LOGGER_H
#define LOGGER_H

#include "Definition.h"

#ifndef __FILENAME__
#define __FILENAME__ __FILE__
#endif

#define LOGGER(level)                          \
    if (level > nes::Logger::get().getLevel()) \
        ;                                      \
    else                                       \
        nes::Logger::get().getStream() << '[' << __FILENAME__ << ":" << std::dec << __LINE__ << "] "

#define Logger_CPU                                      \
    if (nes::CpuTrace != nes::Logger::get().getLevel()) \
        ;                                               \
    else                                                \
        nes::Logger::get().getCpuTraceStream()

namespace nes
{
    enum Level
    {
        None,
        Error,
        Info,
        InfoVerbose,
        CpuTrace
    };
    class Logger
    {
    public:
        ~Logger();
        void setLoggerStream(out &stream);
        void setCpuTraceStream(out &stream);
        Logger &setLevel(Level level);
        Level getLevel();

        out &getStream();
        out &getCpuTraceStream();

        static Logger &get();

    private:
        Level m_logLevel;
        out *m_logStream;
        out *m_cpuTrace;
    };
    class TeeBuf : public stbuff
    {
    public:
        TeeBuf(stbuff *sb1, stbuff *sb2);

    private:
        virtual int overflow(int c);
        virtual int sync();
        stbuff *m_sb1;
        stbuff *m_sb2;
    };
    class TeeStream : public out
    {
    public:
        TeeStream(out &o1, out &o2);

    private:
        TeeBuf m_tbuf;
    };
};
#endif