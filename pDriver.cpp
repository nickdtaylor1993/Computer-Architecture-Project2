#include <iostream>
#include <fstream>
#include <string>
#include "Cache.h"

using namespace std;

int main(int argc, const char * argv[])
{
    ifstream myfile (argv[1]);
    
    string capacity;
    string blockSize;
    string assoc;
    
    if (myfile.is_open())
    {
        string line;
        int i = 0;
        while (getline(myfile, line))
        {
            if(i == 0)
                capacity = line;
            if(i == 1)
                blockSize = line;
            if(i==2)
                assoc = line;
            i++;
        }
    }
    
    Cache cache = Cache();
    
    cache.initialize(atoi(capacity.c_str()), atoi(blockSize.c_str()), atoi(assoc.c_str()));
    
    
    ifstream accessFile (argv[2]);
    
    if (accessFile.is_open())
    {
        string line;
        while (getline(accessFile, line))
        {
            long long addr = atoll(line.c_str());
            cout << "Addr: " << addr << endl; 
	    cache.addAccess(addr, 1, 1);
            cache.printContents();
        }

    }
    cache.printStatistics();
    return 0;
}


