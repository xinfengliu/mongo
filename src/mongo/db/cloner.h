// cloner.h - copy a database (export/import basically)

/**
 *    Copyright (C) 2011 10gen Inc.
 *
 *    This program is free software: you can redistribute it and/or  modify
 *    it under the terms of the GNU Affero General Public License, version 3,
 *    as published by the Free Software Foundation.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef MONGO_DB_CLONER_H
#define MONGO_DB_CLONER_H

#include "jsobj.h"

namespace mongo {

    struct CloneOptions {

        CloneOptions() {
            logForRepl = true;
            slaveOk = false;
            useReplAuth = false;
            snapshot = true;
            mayYield = true;
            mayBeInterrupted = false;

            syncData = true;
            syncIndexes = true;
        }
            
        string fromDB;
        set<string> collsToIgnore;

        bool logForRepl;
        bool slaveOk;
        bool useReplAuth;
        bool snapshot;
        bool mayYield;
        bool mayBeInterrupted;

        bool syncData;
        bool syncIndexes;
    };

    bool cloneFrom( const string& masterHost , 
                    const CloneOptions& options , 
                    string& errmsg /* out */ , 
                    int* errCode = 0 /* out */ , 
                    set<string>* clonedCollections = 0 /* out */ );
    
    /**
     * @param slaveOk     - if true it is ok if the source of the data is !ismaster.
     * @param useReplAuth - use the credentials we normally use as a replication slave for the cloning
     * @param snapshot    - use $snapshot mode for copying collections.  note this should not be used when it isn't required, as it will be slower.
     *                      for example repairDatabase need not use it.
     * @param errCode     - If provided, this will be set on error to the server's error code.  Currently
     *                      this will only be set if there is an error in the initial system.namespaces query.
     */
    bool cloneFrom(const char *masterHost, string& errmsg, const string& fromdb, bool logForReplication,
                   bool slaveOk, bool useReplAuth, bool snapshot, bool mayYield,
                   bool mayBeInterrupted, int *errCode = 0);

    bool copyCollectionFromRemote(const string& host, const string& ns, string& errmsg);

} // namespace mongo

#endif /* MONGO_DB_CLONER_H */
