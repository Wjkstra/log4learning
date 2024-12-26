#include <iostream>
#include "Mylog.h"

using namespace std;

void test0(){
    LogError("This is an error message");
    LogWarning("This is a warning message");
    LogInfo("This is an info message");
    LogDebug("This is a debug message");
}

int main(int argc,char* argv[])
{
    test0();
    return 0;
}

