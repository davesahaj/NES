#include "Logger.h"

namespace nes
{
    Logger::~Logger()
    {
    }
    Logger &Logger::get()
    {
        static Logger instance;
        return instance;
    }
    out &
    Logger::getCpuTraceStream()
    {
        return *m_cpuTrace;
    }
    out &
    Logger::getStream()
    {
        return *m_logStream;
    }

    void
    Logger::setLoggerStream(out &stream)
    {
        m_logStream = &stream;
    }

    void
    Logger::setCpuTraceStream(out &stream)
    {
        m_cpuTrace = &stream;
    }

    Logger &Logger::setLevel(Level level)
    {
        m_logLevel = level;
        return *this;
    }
    Level Logger::getLevel()
    {
        return m_logLevel;
    }

    TeeBuf::TeeBuf(stbuff *sb1, stbuff *sb2) : m_sb1(sb1), m_sb2(sb2) {}
    int TeeBuf::overflow(int c)
    {
        if (c == EOF)
        {
            return !EOF;
        }
        else
        {
            int const r1 = m_sb1->sputc(c);
            int const r2 = m_sb2->sputc(c);
            return r1 == EOF || r2 == EOF ? EOF : c;
        }
    }

    int TeeBuf::sync()
    {
        int const r1 = m_sb1->pubsync();
        int const r2 = m_sb2->pubsync();
        return r1 == 0 && r2 == 0 ? 0 : -1;
    }

    TeeStream::TeeStream(out &o1, out &o2) : out(&m_tbuf), m_tbuf(o1.rdbuf(), o2.rdbuf()) {}
}