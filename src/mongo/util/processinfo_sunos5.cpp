// processinfo_none.cpp

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include "pch.h"
#include "processinfo.h"

#include <iostream>
using namespace std;

namespace mongo {

    ProcessInfo::ProcessInfo( pid_t pid ) {
    }

    ProcessInfo::~ProcessInfo() {
    }

    bool ProcessInfo::supported() {
        return false;
    }

    int ProcessInfo::getVirtualMemorySize() {
        return -1;
    }

    int ProcessInfo::getResidentSize() {
        return -1;
    }

    bool ProcessInfo::checkNumaEnabled() { 
        return false;
    }

    bool ProcessInfo::blockCheckSupported() {
        return true;
    }

    void ProcessInfo::SystemInfo::collectSystemInfo() {

    }

    void ProcessInfo::getExtraInfo( BSONObjBuilder& info ) {
        
    }

    bool ProcessInfo::blockInMemory( char * start ) {
        static long pageSize = 0;
        if ( pageSize == 0 ) {
            pageSize = sysconf( _SC_PAGESIZE );
        }
        start = start - ( (unsigned long long)start % pageSize );
        //unsigned char x = 0;
        char x = 0;
        if ( mincore(start , 128 , &x ) ) {
            log() << "mincore failed: " << errnoWithDescription() << endl;
            return 1;
        }
        return x & 0x1;

    }

}
