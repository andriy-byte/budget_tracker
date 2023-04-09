

#include "Authorization.h"


std::string Authorization::toHash(const std::string &value) {

#if BOOST_OS_WINDOWS
    CryptoPP::byte digest[CryptoPP::Weak::MD5::DIGESTSIZE];
    CryptoPP::Weak::MD5 hash;
#else
    CryptoPP::byte digest[CryptoPP::MD5::DIGESTSIZE];
    CryptoPP::MD5 hash;
#endif
    std::string hash_result;

    hash.Update(reinterpret_cast<const CryptoPP::byte *>(value.data()), value.size());
    hash.Final(reinterpret_cast<CryptoPP::byte *>(&digest[0]));

    CryptoPP::HexEncoder encoder;
    encoder.Attach(new CryptoPP::StringSink(hash_result));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();
    return hash_result;

}


std::string Authorization::encrypt(const std::string &password) {
    return toHash(password);

}

bool Authorization::isCorrect(const std::string &password, const std::string hash) {
    return toHash(password) == hash;
}