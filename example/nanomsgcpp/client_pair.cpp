#include "nn.hpp"

#include <nanomsg/pair.h>
#include <cassert>
#include <iostream>
#include <unistd.h>
using namespace std;

#define ADDRESS1 "inproc://test"
#define ADDRESS2 "tcp://127.0.0.1:8000"
#define ADDRESS3 "ipc:///tmp/reqrep.ipc"

int main ()
{
    nn::socket s2 (AF_SP, NN_PAIR);
    s2.connect(ADDRESS3)
    char buf[25];

    s2.send ("...CCC,client send\n", 19, 0);
    int rc = s2.recv (buf, sizeof (buf), 0);
    cout<<"...buf,client recv: " << buf << endl;

    while(1)
    {
        sleep(1);
    };
    return 0;
}