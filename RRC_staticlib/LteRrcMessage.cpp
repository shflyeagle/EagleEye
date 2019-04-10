#include "LteRrcMessage.h"
#include "tool.h"

LteRrcMessage::LteRrcMessage()
{
	/**
	* <b> High level design of the function is :</b>
	*/
	mp_msg_structure = nullptr;
	decoded_msg.clear();
}


LteRrcMessage::~LteRrcMessage()
{
	if (mp_msg_structure != nullptr)
	{
		delete mp_msg_structure;
	}
}

int LteRrcMessage::decode(const char * name,
	const char * per_bits,
	const int len,
	const bool to_txt)
{
	/**
	* <b> High level design of the function is :</b>
	*/

	int ret = -1;
	if ((len == 0) || (per_bits == NULL)) return ret;

	/**
	* decode it.
	*/
	asn_TYPE_descriptor_t *td = tool_t::get_td_by_name(name);
	if (td == NULL) return ret;

	asn_dec_rval_t rval;
	rval = uper_decode(0,   /** asn_codec_ctx_t *opt_codec_ctx */
		td,  /** asn_TYPE_descriptor_t *td */
		(void **)(&mp_msg_structure), /** void **sptr */
		per_bits,  /** const void *buffer */
		len,       /** size_t size */
		0,         /** int skip_bits */
		0          /** int unused_bits */);

	if (rval.code != RC_OK){
		//        std::cout << "create|uper_decode error ret = " << rval.code << std::endl;
		return ret;
	}

	/**
	* Print this message field text and value into mp_field->m_asn_text.
	*/
	if (to_txt)
	{
		tool_t::get_message_text(decoded_msg, (void *)mp_msg_structure, td);
	}
	else
	{
		tool_t::get_message_xml_text(decoded_msg, (void *)mp_msg_structure, td);
	}

	ret = 0;
	return ret;
}