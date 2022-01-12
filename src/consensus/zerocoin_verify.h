// Copyright (c) 2020 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef OASIS_CONSENSUS_ZEROCOIN_VERIFY_H
#define OASIS_CONSENSUS_ZEROCOIN_VERIFY_H

#include "consensus/consensus.h"
#include "main.h"
#include "script/interpreter.h"
#include "zxoschain.h"

// Public coin spend
bool RecalculateXOSSupply(int nHeightStart, bool fSkipZC = true);
bool UpdateZXOSSupply(const CBlock& block, CBlockIndex* pindex);

#endif //OASIS_CONSENSUS_ZEROCOIN_VERIFY_H
