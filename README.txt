This repository will be used to learning how to use log4cpp that is a third-part library.
The log4cpp address : https://sourceforge.net/projects/log4cpp/files/

How to install log4cpp?
1. tar xzvf log4cpp-1.1.4rc3.tar.gz
2. cd log4cpp
3. ./configure
4. make
5. sudo make install

How to compile cpp file that was used log4cpp?

    g++ yourcpp.cc -llog4cpp -lpthread

An error may be reported: The dynamic library cannot be found.

Write the default lib library path and reload it:
    
    sudo vim /etc/ld.so.conf

Add some detail:

    include /etc/ld.so.conf.d/*.conf
    /usr/local/lib

Reload:

    sudo ldconfig
