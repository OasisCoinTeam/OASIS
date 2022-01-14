// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2017-2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "amount.h"

#include "tinyformat.h"

/*
   The smallest denomination of a XOS is known as:
   mxos (or xos), ex: 56 xos-per-byte fee
*/

CFeeRate::CFeeRate(const CAmount& nFeePaid, size_t nSize)
{
    if (nSize > 0)
        nXosPerK = nFeePaid * 1000 / nSize;
    else
        nXosPerK = 0;
}

CAmount CFeeRate::GetFee(size_t nSize) const
{
    CAmount nFee = nXosPerK * nSize / 1000;

    if (nFee == 0 && nXosPerK > 0)
        nFee = nXosPerK;

    return nFee;
}

std::string CFeeRate::ToString() const
{
    return strprintf("%d.%08d xos/kB", nXosPerK / COIN, nXosPerK % COIN);
}
