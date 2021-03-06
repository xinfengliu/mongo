// signal_handlers.h

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
#ifndef MONGO_UTIL_SIGNAL_HANDLERS_H
#define MONGO_UTIL_SIGNAL_HANDLERS_H

namespace mongo {

    /**
     * Obtains the log file handler and writes the current thread's stack trace to
     * it. This call issues an exit(). The function can safely be called from within a
     * signal handler.
     *
     * @param signal that this hadler is called for
     */
    void printStackAndExit( int signalNum );

} // namespace mongo

#endif /* MONGO_UTIL_SIGNAL_HANDLERS_H */
