// @file d_globals.h
//
// these are global variables used in mongod ("d").  also used in test binary as that is effectively a variation on mongod code.
// that is, these are not in mongos.
//

#pragma once
#ifndef MONGO_DB_D_GLOBALS_H
#define MONGO_DB_D_GLOBALS_H

namespace mongo { 

    class RWLockRecursive;
    class ClientCursorMonitor;

    struct DGlobals : boost::noncopyable { 
        DGlobals();

        // these are intentionally never deleted:
        ClientCursorMonitor& clientCursorMonitor;

    };

    extern DGlobals d;

};

#endif /* MONGO_DB_D_GLOBALS_H */
