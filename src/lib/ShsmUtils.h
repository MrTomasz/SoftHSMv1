//
// Created by Dusan Klinec on 21.06.15.
//

#ifndef SOFTHSMV1_SHSMUTILS_H
#define SOFTHSMV1_SHSMUTILS_H

#include "ShsmApiUtils.h"
#include "ShsmPrivateKey.h"
#include "SoftDatabase.h"
#include <string>

class ShsmUtils {
public:
    /**
     * Loads SHSM key handle of the object referenced by hKey. Under this value the object is referenced on the SHSM.
     */
    static SHSM_KEY_HANDLE getShsmKeyHandle(SoftDatabase * db, CK_OBJECT_HANDLE hKey);

    /**
     * Returns true if given key is stored in SHSM.
     */
    static CK_BBOOL isShsmKey(SoftDatabase * db, CK_OBJECT_HANDLE hKey);

    /**
     * Returns request string for decryption query.
     */
    static std::string getRequestDecrypt(ShsmPrivateKey * privKey, std::string key, std::string macKey, const Botan::byte byte[], size_t t);

    /**
     * Process ProcessData response, unprotects data, removes rubbish.
     */
    static Botan::SecureVector<Botan::byte> readProtectedData(Botan::byte * buff, size_t size, std::string key, std::string macKey, int * status);

    /**
     * Removes PKCS1.5 padding from the input buffer and places output to the output buffer.
     * Returns size of the unpadded data in the output buffer or negative in case of a padding failure.
     * Output buffer can be also the input buffer, so it is done in-place.
     */
    static ssize_t removePkcs15Padding(const Botan::byte * buff, size_t len, Botan::byte * out, size_t maxLen, int * status);

    /**
     * Demangles nonce in the processData response to the original one.
     */
    static void demangleNonce(Botan::byte *buff, size_t len);
};


#endif //SOFTHSMV1_SHSMUTILS_H
