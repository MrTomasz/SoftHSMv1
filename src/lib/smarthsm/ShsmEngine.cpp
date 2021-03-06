//
// Created by Dusan Klinec on 16.04.16.
//

#include <src/lib/log.h>
#include "ShsmEngine.h"
#include "ShsmPrivateKey.h"
#include "ShsmPrivateOperation.h"

using namespace Botan;

PK_Ops::Signature*
ShsmEngine::get_signature_op(const Private_Key& key) const
{
#if defined(BOTAN_HAS_RSA)
    if(const ShsmPrivateKey* s = dynamic_cast<const ShsmPrivateKey*>(&key))
        return new ShsmPrivateOperation(*s);
#endif

    return 0;
}

PK_Ops::Decryption*
ShsmEngine::get_decryption_op(const Private_Key& key) const
{
#if defined(BOTAN_HAS_RSA)
    if(const ShsmPrivateKey* s = dynamic_cast<const ShsmPrivateKey*>(&key))
        return new ShsmPrivateOperation(*s);
#endif
    return 0;
}

Botan::PK_Ops::Verification *ShsmEngine::get_verify_op(const Botan::Public_Key &key) const {
#if defined(BOTAN_HAS_RSA)
    if(const RSA_PublicKey* s = dynamic_cast<const RSA_PublicKey*>(&key))
        return new RSA_Public_Operation(*s);
#endif
    return 0;
}

Botan::PK_Ops::Encryption *ShsmEngine::get_encryption_op(const Botan::Public_Key &key) const {
#if defined(BOTAN_HAS_RSA)
    if(const RSA_PublicKey* s = dynamic_cast<const RSA_PublicKey*>(&key))
        return new RSA_Public_Operation(*s);
#endif
    return 0;
}

