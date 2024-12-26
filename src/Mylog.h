#ifndef _Mylog_H_
#define _Mylog_H_

//this header file can set level of log
#include<log4cpp/Category.hh>

namespace Wjkstra{

class Mylog
{
public:
    static Mylog* getInstance();

    //set level of log
    void error(const char*);
    void warning(const char*);
    void info(const char*);
    void debug(const char*);

private:
    class Log{
    public:
        Log();
        ~Log();
    };
private:
    Mylog();
    ~Mylog();

private:
    log4cpp::Category& _mycat;
    static Mylog* _pInstance;
    static Log _log;
};

#define addprefix(msg) string("[]")\
    .append(__FILE__).append(":")\
    .append(__func__).append(":")\
    .append("]")\
    .append(":").append(msg).c_str()

#define LogError(msg) Wjkstra::Mylog::getInstance()->error(addprefix(msg))
#define LogWarning(msg) Wjkstra::Mylog::getInstance()->warning(addprefix(msg))
#define LogInfo(msg) Wjkstra::Mylog::getInstance()->info(addprefix(msg))
#define LogDebug(msg) Wjkstra::Mylog::getInstance()->debug(addprefix(msg))

} //end of Wjkstra
#endif

