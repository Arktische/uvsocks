#include "utils.h"

#include "config.h"

// Convert IPv4 or IPv6 sockaddr to string, need to free the buffer after use
// manually!
char *sockaddr_to_str(struct sockaddr *addr) {
    char *result;
    if (addr->sa_family == AF_INET) { // IPv4
        result = (char *)malloc(INET_ADDRSTRLEN);
        if (!result) FATAL("malloc() failed!");
        int n =
            uv_ip4_name((struct sockaddr_in *)addr, result, INET_ADDRSTRLEN);
        if (n) {
            free(result);
            result = NULL;
        }
    } else if (addr->sa_family == AF_INET6) { // IPv4
        result = (char *)malloc(INET6_ADDRSTRLEN);
        if (!result) FATAL("malloc() failed!");
        int n =
            uv_ip6_name((struct sockaddr_in6 *)addr, result, INET6_ADDRSTRLEN);
        if (n) {
            free(result);
            result = NULL;
        }
    } else {
        result = NULL;
    }
    return result;
}