// @file rs_exception.h

#pragma once
#ifndef MONGO_DB_REPL_RS_EXCEPTION_H
#define MONGO_DB_REPL_RS_EXCEPTION_H

namespace mongo {

    class VoteException : public std::exception {
    public:
        const char * what() const throw () { return "VoteException"; }
    };

    class RetryAfterSleepException : public std::exception {
    public:
        const char * what() const throw () { return "RetryAfterSleepException"; }
    };

}

#endif /* MONGO_DB_REPL_RS_EXCEPTION_H */
