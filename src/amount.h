// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2017-2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_AMOUNT_H
#define BITCOIN_AMOUNT_H

#include "serialize.h"

#include <stdlib.h>
#include <string>

/** Amount in xos (Can be negative) */
typedef int64_t CAmount;

static const CAmount COIN = 100000000;
static const CAmount CENT = 1000000;

/**
 * Fee rate in xos per kilobyte: CAmount / kB
 */
class CFeeRate
{
private:
    CAmount nXosPerK; // unit is xos-per-1,000-bytes
public:
    CFeeRate() : nXosPerK(0) {}
    explicit CFeeRate(const CAmount& _nXosPerK) : nXosPerK(_nXosPerK) {}
    CFeeRate(const CAmount& nFeePaid, size_t nSize);
    CFeeRate(const CFeeRate& other) { nXosPerK = other.nXosPerK; }

    CAmount GetFee(size_t size) const;                  // unit returned is xos
    CAmount GetFeePerK() const { return GetFee(1000); } // xos-per-1000-bytes

    friend bool operator<(const CFeeRate& a, const CFeeRate& b) { return a.nXosPerK < b.nXosPerK; }
    friend bool operator>(const CFeeRate& a, const CFeeRate& b) { return a.nXosPerK > b.nXosPerK; }
    friend bool operator==(const CFeeRate& a, const CFeeRate& b) { return a.nXosPerK == b.nXosPerK; }
    friend bool operator<=(const CFeeRate& a, const CFeeRate& b) { return a.nXosPerK <= b.nXosPerK; }
    friend bool operator>=(const CFeeRate& a, const CFeeRate& b) { return a.nXosPerK >= b.nXosPerK; }
    std::string ToString() const;

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
    {
        READWRITE(nXosPerK);
    }
};

#endif //  BITCOIN_AMOUNT_H
