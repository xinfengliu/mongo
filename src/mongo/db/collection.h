// @file collection.h

#pragma once
#ifndef MONGO_DB_COLLECTION_H
#define MONGO_DB_COLLECTION_H

#include "namespace.h"

namespace mongo { 

    class Collection { 
    public:
        NamespaceDetails * const d;
        NamespaceDetailsTransient * const nsd;
    };

}

#endif /* MONGO_DB_COLLECTION_H */
