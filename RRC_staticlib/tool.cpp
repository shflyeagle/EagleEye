//$Id: tool.cc 491 2009-12-23 11:01:49Z Shoujie Li $ -*- c++ -*-

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "tool.h"

#include <cmath>
#include <iostream>
#include <bitset>
#include <map>
#include <set>

int 
tool_t::write_out2file
(const void *buffer, 
 size_t size, 
 void *key)
{
    /**
     * <b> High level design of the function is :</b>
     */

    FILE *fp = (FILE *)key;
    return (fwrite(buffer, 1, size, fp) == size) ? 0 : -1;
}

int 
tool_t::asn_struct_size
(asn_TYPE_descriptor_t * _asn)
{
    /**
     * <b> High level design of the function is :</b>
     */

    int ret_size = -1;

    ber_tlv_tag_t * tags = _asn->tags;
    if ( tags != NULL ){
        switch (tags[0]){
        case (ASN_TAG_CLASS_UNIVERSAL | (1 << 2)):
            /**
             * BOOLEAN
             */
        case (ASN_TAG_CLASS_UNIVERSAL | (5 << 2)):
            /**
             * asn_DEF_NULL
             */
            ret_size = sizeof(int);
        break;

        case (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)):
            {
                std::string type_name = _asn->name;
        
                if ( (_asn->uper_encoder == INTEGER_encode_uper) &&
                     (type_name == "INTEGER") ){
                    ret_size = sizeof(ENUMERATED_t);
                }
                else {
                    /**
                     * long: asn_DEF_NativeInteger.
                     */
                    ret_size = sizeof(long);
                }
            }
            break;

        case (ASN_TAG_CLASS_UNIVERSAL | (3 << 2)):
            /**
             * BIT_STRING_t
             */
            ret_size = sizeof(BIT_STRING_t);
            break;

        case (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)):
            /**
             * OCTET_STRING_t
             */
            ret_size = sizeof(OCTET_STRING_t);
            break;


        case (ASN_TAG_CLASS_UNIVERSAL | (10 << 2)):
            /**
             * ENUMERATED_t == INTEGER_t == ASN__PRIMITIVE_TYPE_t
             */
            ret_size = sizeof(ENUMERATED_t);
            break;

        case (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)):
            {
                /**
                 * asn_*_OF_specifics_t: * can be SET, CHOICE, SEQUENCE.
                 * Use a wildcast pointer.
                 */
                asn_SET_OF_specifics_t * specifics = 
                    (asn_SET_OF_specifics_t*)(_asn->specifics);
                if ( specifics != NULL ){
                    ret_size = specifics->struct_size;
                    return ret_size;
                }
            }
            break;

        case (ASN_TAG_CLASS_CONTEXT | (0 << 2)):
        case (ASN_TAG_CLASS_CONTEXT | (1 << 2)):
        case (ASN_TAG_CLASS_CONTEXT | (2 << 2)):
        case (ASN_TAG_CLASS_CONTEXT | (3 << 2)):
            if ( tags[1] == (ASN_TAG_CLASS_UNIVERSAL | (10 << 2)) ){
                ret_size = sizeof(long);
            }
            else if ( tags[1] == (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)) ){
                /**
                 * asn_*_OF_specifics_t: * can be SET, CHOICE, SEQUENCE.
                 * Use a wildcast pointer.
                 */
                asn_SEQUENCE_specifics_t * specifics =
                    (asn_SEQUENCE_specifics_t *)(_asn->specifics);
                ret_size = specifics->struct_size;
            }
        break;

        default:
            {
                /**
                 * asn_*_OF_specifics_t: * can be SET, CHOICE, SEQUENCE.
                 * Use a wildcast pointer.
                 */
                asn_SET_OF_specifics_t * specifics = 
                    (asn_SET_OF_specifics_t*)(_asn->specifics);
                if ( specifics != NULL ){
                    ret_size = specifics->struct_size;
                    if ( ret_size > 0 ) return ret_size;
                }
            }
            break;
        }
    }
    else{
        /**
         * asn_*_OF_specifics_t: * can be SET, CHOICE, SEQUENCE.
         * Use a wildcast pointer.
         */
        asn_SET_OF_specifics_t * specifics = 
            (asn_SET_OF_specifics_t*)(_asn->specifics);
        if ( specifics != NULL ){
            ret_size = specifics->struct_size;
            if ( ret_size > 0 ) return ret_size;
        }
    }

    return ret_size;
}

void
tool_t::convert_string
(std::string & inout, 
 int format)
{
    /**
     * <b> High level design of the function is :</b>
     */

    switch (format) {
    case 0: {
        /**
         * Pop up context menu.
         */
        
        std::string tmp;
        for ( int i = 0; i < inout.size(); ++i ){
            if ( (inout[i] == '0') || (inout[i] == '1') ){
                tmp.append(1, inout[i]);
            }
        }
        
        int left_size = ((tmp.size()) % 8);
        if ( left_size > 0 ) tmp.append( 8-left_size, '0' );

        inout = "";
        int byte_size = ((tmp.size()) >> 3);
        for ( int i = 0; i < byte_size; ++i ){
            std::string tmp2 = tmp.substr( (i<<3), ((i+1)<<3) );
            std::bitset<8 > bits(tmp2);
            char tmp1 = (char)(bits.to_ulong());
            inout.append(1, tmp1);
        }

        break;
    }

    default:
        break;
    }
}

asn_TYPE_descriptor_t *
tool_t::get_td_by_name
(const std::string & td_name )
{
    /**
     * <b> High level design of the function is :</b>
     */

    asn_TYPE_descriptor_t * td = NULL;
    
    extern asn_TYPE_descriptor_s *asn_pdu_collection[];

	asn_TYPE_descriptor_t **asn = asn_pdu_collection;
    for(; *asn; ++asn) {
        
        if ( td_name == (*asn)->name ){
            td = *asn;
        }
    }
    
    return td;
}

int 
tool_t::get_message_text
(std::string & _text,
 void * _start, 
 asn_TYPE_descriptor_t * td)
{
    /**
     * <b> High level design of the function is :</b>
     */
    int ret = 0;
    _text = "";

    /**
     * Get message structure fields.
     */
    FILE * tmp_file = tmpfile();
    if ( tmp_file == NULL ) return -2;
    asn_fprint(tmp_file, td, _start);

    long file_size = 0;
    char * buffer = NULL;
    size_t result;

    fseek (tmp_file , 0 , SEEK_END);
    file_size = ftell (tmp_file);
    rewind (tmp_file);

    buffer = (char*) malloc (sizeof(char)*(file_size + 1));
    if (buffer == NULL) {
        ret = -3;
        return ret;
    }
    memset(buffer, '\0', (file_size+1));

    result = fread (buffer,1,file_size, tmp_file);
    assert (result == file_size);

    _text = buffer;

    free(buffer);
    fclose(tmp_file);

    return ret;
}

int 
tool_t::get_message_xml_text
(std::string & _text,
 void * _start, 
 asn_TYPE_descriptor_t * td)
{
    /**
     * <b> High level design of the function is :</b>
     */
    int ret = 0;
    _text = "";

    /**
     * Get message structure fields.
     */
    FILE * tmp_file = tmpfile();
    if ( tmp_file == NULL ) return -2;

    xer_fprint(tmp_file, td, _start);

    long file_size = 0;
    char * buffer = NULL;
    size_t result;

    fseek (tmp_file , 0 , SEEK_END);
    file_size = ftell (tmp_file);
    rewind (tmp_file);

    buffer = (char*) malloc (sizeof(char)*(file_size + 1));
    if (buffer == NULL) {
        ret = -3;
        return ret;
    }
    memset(buffer, '\0', (file_size+1));

    result = fread (buffer,1,file_size, tmp_file);
    assert (result == file_size);

    _text = buffer;

    free(buffer);
    fclose(tmp_file);

    return ret;
}
