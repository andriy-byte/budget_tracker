

#ifndef BUDGET_TRACKER_AUTHORIZATION_H
#define BUDGET_TRACKER_AUTHORIZATION_H


#include<string>
#include<boost/predef.h>

#if BOOST_OS_WINDOWS
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#endif

#include<cryptopp/md5.h>
#include<cryptopp/hex.h>

class Authorization final {
public:
    static std::string encrypt(const std::string &password);

    static bool isCorrect(const std::string &password, const std::string hash);

private:
    static std::string toHash(const std::string &value);


};


#endif //BUDGET_TRACKER_AUTHORIZATION_H
