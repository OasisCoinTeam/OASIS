// Copyright (c) 2020 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PIVX_CONSENSUS_ZEROCOIN_VERIFY_H
#define PIVX_CONSENSUS_ZEROCOIN_VERIFY_H

#include "consensus/consensus.h"
#include "main.h"
#include "script/interpreter.h"
#include "zpivchain.h"

// Public coin spend
bool RecalculateZNZSupply(int nHeightStart, bool fSkipZC = true);
bool UpdateZZNZSupply(const CBlock& block, CBlockIndex* pindex);

#endif //PIVX_CONSENSUS_ZEROCOIN_VERIFY_H
