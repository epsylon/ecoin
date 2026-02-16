// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)

#ifndef SERIALNUMBERPROOF_H_
#define SERIALNUMBERPROOF_H_

#include <list>
#include <vector>
#include <bitset>
#include "Params.h"
#include "Coin.h"
#include "Commitment.h"
#include "../bignum.h"
#include "../serialize.h"
#include "Accumulator.h"
#include "../util.h"

using namespace std;
namespace libzerocoin {

/**A Signature of knowledge on the hash of metadata attesting that the signer knows the values
 *  necessary to open a commitment which contains a coin(which it self is of course a commitment)
 * with a given serial number.
 */
class SerialNumberSignatureOfKnowledge {
public:
	SerialNumberSignatureOfKnowledge(const Params* p);
	/** Creates a Signature of knowledge object that a commitment to a coin contains a coin with serial number x
	 *
	 * @param p params
	 * @param coin the coin we are going to prove the serial number of.
	 * @param commitmentToCoin the commitment to the coin
	 * @param msghash hash of meta data to create a signature of knowledge on.
	 */
	SerialNumberSignatureOfKnowledge(const Params* p, const PrivateCoin& coin, const Commitment& commitmentToCoin, uint256 msghash);

	/** Verifies the Signature of knowledge.
	 *
	 * @param msghash hash of meta data to create a signature of knowledge on.
	 * @return
	 */
	bool Verify(const CBigNum& coinSerialNumber, const CBigNum& valueOfCommitmentToCoin,const uint256 msghash) const;

	IMPLEMENT_SERIALIZE
	(
	    READWRITE(s_notprime);
	    READWRITE(sprime);
	    READWRITE(hash);
	)
private:
	const Params* params;
	// challenge hash
	uint256 hash; //TODO For efficiency, should this be a bitset where Templates define params?

	// challenge response values
	// this is s_notprime instead of s
	// because the serialization macros
	// define something named s and it conflicts
	vector<CBigNum> s_notprime;
	vector<CBigNum> sprime;
	inline CBigNum challengeCalculation(const CBigNum& a_exp, const CBigNum& b_exp,
	                                   const CBigNum& h_exp) const;
};

} /* namespace libzerocoin */
#endif /* SERIALNUMBERPROOF_H_ */
