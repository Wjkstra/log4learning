#include "Mylog.h"
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <iostream>

using namespace log4cpp;
using std::cout;
using std::endl;

namespace Wjkstra{

Mylog* Mylog::_pInstance = nullptr;
Mylog::Log Mylog::_log;

Mylog* Mylog::getInstance(){
    if(nullptr == _pInstance){
        _pInstance = new Mylog();
    }
    return _pInstance;
}

Mylog::Log::Log(){ cout<<"Log()"<<endl; }
Mylog::Log::~Log(){
    if(_pInstance){
        delete _pInstance;
        _pInstance = nullptr;
    }
    cout<<"~Log()"<<endl;
}

Mylog::Mylog()
:_mycat(Category::getRoot().getInstance("mycat"))
{
    auto ptnLayout1 = new PatternLayout();
    ptnLayout1->setConversionPattern("%d %c [%p] %m%n");

    auto ptnLayout2 = new PatternLayout();
    ptnLayout2->setConversionPattern("%d %c [%p] %m%n");
    auto posApp = new OstreamAppender("console",&cout);
    posApp->setLayout(ptnLayout1);
    
    //set address where save log file
    auto pfileApp = new FileAppender("pfileApp","log4cpp.log");
    pfileApp->setLayout(ptnLayout2);

    _mycat.setPriority(Priority::DEBUG);
    _mycat.addAppender(posApp);
    _mycat.addAppender(pfileApp);
    cout<<"Mylog()"<<endl;
}

Mylog::~Mylog(){
    Category::shutdown();
    cout<<"~Mylog()"<<endl;
}

void Mylog::error(const char* msg){
    _mycat.error(msg);
}
void Mylog::warning(const char* msg){
    _mycat.warn(msg);
}
void Mylog::info(const char* msg){
    _mycat.info(msg);
    }
void Mylog::debug(const char* msg){
    _mycat.debug(msg);
}

}//end of namespace Wjkstra


