#pragma once
#ifndef MONGO_CLIENT_CLIENTONLY_PRIVATE_H
#define MONGO_CLIENT_CLIENTONLY_PRIVATE_H
namespace mongo {
    namespace shell_utils {
        extern mongo::mutex &mongoProgramOutputMutex;
    }
}

#endif /* MONGO_CLIENT_CLIENTONLY_PRIVATE_H */
