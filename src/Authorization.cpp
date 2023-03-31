//
// Created by andriy on 3/25/23.
//

#include "Authorization.h"


std::string Authorization::toHash(const std::string &value) {
    CryptoPP::byte digest[CryptoPP::MD5::DIGESTSIZE];
    std::string hash_result;
    CryptoPP::MD5 hash;

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