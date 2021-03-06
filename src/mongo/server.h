/** @file server.h

    This file contains includes commonly needed in the server files (mongod, mongos, test).  It is *NOT* included in the C++ client; i.e. 
    this is a very good place for global-ish things that you don't need to be in the client lib.

    Over time we should move more here, and more out of pch.h.  And get rid of pch.h at some point.
*/

#pragma once
#ifndef MONGO_SERVER_H
#define MONGO_SERVER_H

#if !defined(MONGO_EXPOSE_MACROS)
# error this file is for mongo server programs not client lib
#endif

#include <map>
#include <vector>
#include <set>

#include "bson/inline_decls.h"

//using namespace std;
//using namespace bson;

/* Note: do not clutter code with these -- ONLY use in hot spots / significant loops. */

// branch prediction.  indicate we expect to be true
#define likely MONGO_likely

// branch prediction.  indicate we expect to be false
#define unlikely MONGO_unlikely

// prefetch data from memory
//#define PREFETCH MONGOPREFETCH

// logs at most once per secs
#define LOGATMOST(secs) static time_t __last = 0; time_t __now=time(0); if(__last+secs>__now) {} else if ( ( __last = __now ) > 0 ) log() 

// log but not too fast.  this is rather simplistic we can do something fancier later
#define LOGSOME LOGATMOST(20)

#endif /* MONGO_SERVER_H */
