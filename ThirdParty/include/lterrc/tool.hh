//$Id: tool.hh 491 2009-12-23 11:01:49Z Shoujie Li $ -*- c++ -*-

/**
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

#ifndef TOOL_HH
#define TOOL_HH

#include <cstdlib>
#include <string>

#include "LteRrcAsn.h"

class tool_t
{
public:
    /**
     * \brief It is the callback to write the buffer into a file.
     * 
     * The file is accessed by key.
     */
    static int write_out2file(const void *buffer, size_t size, void *key);
    
    /**
     * \brief It returns the asn_TYPE_descriptor_t associated structure size.
     */
    static int asn_struct_size(asn_TYPE_descriptor_t* _asn);

    /**
     * \brief It converts input string into per bit data.
     * 
     * \param inout
     * - Input and output string.
     * .
     * \param format
     * - 0: "01111 111"
     * - 1: "0xaef4 0xae34"
     * .
     */
    static void convert_string(std::string & inout, int format);

    /**
     * \brief It gets the asn_TYPE_descriptor_t by its name.
     *
     * Only the root asn_TYPE_descriptor_t can be gotten.
     */
    static asn_TYPE_descriptor_t * get_td_by_name(const std::string & td_name );

    /**
     * \brief It gets message normal text according to its structure.
     */
    static int  get_message_text(std::string & _text,  
                                 void * _start,   
                                 asn_TYPE_descriptor_t * td);

    /**
     * \brief It gets message xml text according to its structure.
     */
    static int  get_message_xml_text(std::string & _text,  
                                 void * _start,   
                                 asn_TYPE_descriptor_t * td);
};

#endif // TOOL_HH
