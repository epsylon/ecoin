// ECOin - Copyright (c) - 2014/2022 - GPLv3 - epsylon@riseup.net (https://03c8.net)

#ifndef SPENDMETADATA_H_
#define SPENDMETADATA_H_

#include "../uint256.h"
#include "../serialize.h"

using namespace std;
namespace libzerocoin {

/** Any meta data needed for actual ecoin integration.
 * Can extended provided the getHash() function is updated
 */
class SpendMetaData {
public:
	/**
	 * Creates meta data associated with a coin spend
	 * @param accumulatorId hash of block containing accumulator
	 * @param txHash hash of transaction
	 */
	SpendMetaData(uint256 accumulatorId, uint256 txHash);

	/**
	 * The hash of the block containing the accumulator CoinSpend
	 * proves membership in.
	 */
	uint256 accumulatorId; // The block the accumulator is in
	/**Contains the hash of the rest of transaction
	 * spending a zerocoin (excluding the coinspend proof)
	 */
	uint256 txHash; // The Hash of the rest of the transaction the spend proof is n.
	// Allows us to sign the transaction.
	IMPLEMENT_SERIALIZE
	(
	    READWRITE(accumulatorId);
	    READWRITE(txHash);
	)
};

} /* namespace libzerocoin */
#endif /* SPENDMETADATA_H_ */
