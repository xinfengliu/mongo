// @file shard_version.h

/**
*    Copyright (C) 2010 10gen Inc.
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
#ifndef MONGO_S_SHARD_VERSION_H
#define MONGO_S_SHARD_VERSION_H

namespace mongo {

    /*
     * Install chunk shard vesion callbaks in shardconnection code. This activates
     * the chunk shard version control that mongos needs.
     *
     * MUST be called before accepting any connections.
     */
    void installChunkShardVersioning();


}  // namespace mongo

#endif /* MONGO_S_SHARD_VERSION_H */
