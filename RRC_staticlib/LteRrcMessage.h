#pragma once

#include <string>
#include "LteRrcAsn.h"

/**
* \union message_union_t
* \brief This structure is usseful for memory management.
*
* With the structure, the message buffer can be allocated once and
* used many times.
*/
union message_union_t{
	BCCH_BCH_Message_t BCCH_BCH;
	BCCH_DL_SCH_Message_t BCCH_DL_SCH;
	BCCH_DL_SCH_Message_BR_t BCCH_DL_SCH_BR;
	MCCH_Message_t MCCH;
	PCCH_Message_t PCCH;
	DL_CCCH_Message_t DL_CCCH;
	DL_DCCH_Message_t DL_DCCH;
	UL_CCCH_Message_t UL_CCCH;
	UL_DCCH_Message_t UL_DCCH;
	SC_MCCH_Message_r13_t SC_MCCH_R13;
};

class LteRrcMessage
{
public:
	LteRrcMessage();
	~LteRrcMessage();

	/**
	* decode rrc into text or xml
	*/
	int decode(const char * name, const char * per_bits, const int len, const bool to_txt = true);

	/**
	* decoded msg in txt or xml
	*/
	std::string decoded_msg;

	/**
	* Message structure.
	*/
	message_union_t *mp_msg_structure;
};

