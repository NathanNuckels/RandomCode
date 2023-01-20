#ifndef INET_HH_
#define INET_HH_

namespace inet{
    int connect(const char* domain, const char* protocol);
    int bind(const char* protocol);
};

#endif
