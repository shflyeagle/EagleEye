#pragma once

#include "EeMacro.h"

#pragma pack(1)

typedef struct
{
    quint32 magic;
    quint16 verMajor;
    quint16 verMinor;
    quint32 thisZone;     /* gmt to local correction */
    quint32 sigfigs;      /* accuracy of timestamps */
    quint32 snapLen;      /* max length saved portion of each pkt */
    quint32 linkType;     /* data link type (LINKTYPE_*) */
}PcapFileHeader;

//4 + 2 + 2 + 4 + 4 + 4 + 4
#define EE_SIZE_PCAP_FILE_HEADER	sizeof(PcapFileHeader)
inline quint32 EE_BE_GetMagicFromPcapFileHeader(char* buf)
{
	return EE_BE_GetQUINT32(buf + 0);
}

inline quint32 EE_LE_GetMagicFromPcapFileHeader(char* buf)
{
	return EE_LE_GetQUINT32(buf + 0);
}

typedef struct
{
    quint32 tv_sec;       /* seconds (XXX should be time_t) */
    quint32 tv_usec;      /* and microseconds */
}TimeVal;
//4 + 4

#define EE_SIZE_TIME_VAL	sizeof(TimeVal)


typedef struct
{
    TimeVal ts;          /* time stamp */
    quint32 capLen;      /* length of portion present */
    quint32 len;         /* length this packet (off wire) */
}PcapPktHdr;

//4 + 4 + 4 + 4
#define EE_SIZE_PCAP_PKT_HEADER sizeof(PcapPktHdr)

inline quint32 EE_BE_GetCapLenFromPcapPktHdr(char* buf)
{
	return EE_BE_GetQUINT32(buf + EE_SIZE_TIME_VAL);
}

inline quint32 EE_LE_GetCapLenFromPcapPktHdr(char* buf)
{
	return EE_LE_GetQUINT32(buf + EE_SIZE_TIME_VAL);
}

typedef struct
{
  quint8 Eth_target_addr[6];   /**= use arpResolve( ) <br> Destination address from Ethernet header (6 bytes). */
  quint8 Eth_source_addr[6];   /**= use arpResolve( ) <br> Source address from Ethernet header (6 bytes). */
  quint16 Eth_protocol;   /**= 0x0800: Type field of Ethernet header (0800 for IP datagram)*/
  quint8 IP_Version_Length;   /**= 0x45: Version + IHL fields from IP header */
  quint8 IP_TypeOfService;   /**= 0x00: Type of service field from IP header */
  quint16 IP_TotalLength;   /**= total length of the datagram including IP hdr*/
  quint16 IP_Identification;   /** 0x0000: Identification field from IP header. */
  quint16 IP_IPFlag_FragementOffset; /**= 0x0000: Flags + Fragment offset fields from IP header. */
  quint8 IP_TimeToLive;   /** 0x02: Time to live field from IP header. */
  quint8 IP_Protocol;   /** Protocol field from IP header (0x11 for UDP).*/
  quint16 IP_HeaderChecksum;   /**= 0x0000 : Header checksum field from IP header. */
  quint32 IPSrc;   /**= 0xC0A80001 : Source address from IP header.*/
  quint32 IPDst;   /**= 0xC0A80002 : Destination address from IP header.*/
  quint16 UDPPortSrc;   /**= 0x0000: Source port number from UDP header.*/
  quint16 UDPPortDst;   /**= 0xC000: Destination port number from UDP header.*/
  quint16 UDP_Length;   /**= 0x01C1: Length (UDP header + data) from UDP header. */
  quint16 UDP_Checksum;   /**= 0x0000: UDP checksum field from UDP header.*/
}EthIPUDPHdr;

//6 + 6 + 2 + 1 + 1 + 2 + 2 + 2 + 1 + 1 + 2 + 4 + 4 + 2 + 2 + 2 + 2
#define EE_SIZE_ETH_IP_UDP_HEADER_V4 sizeof(EthIPUDPHdr)

typedef struct
{
  quint8 Eth_target_addr[6];   /**= use arpResolve( ) <br> Destination address from Ethernet header (6 bytes). */
  quint8 Eth_source_addr[6];   /**= use arpResolve( ) <br> Source address from Ethernet header (6 bytes). */
  quint16 Eth_protocol;   /**= 0x86DD: Type field of Ethernet header (0x86DD for IPv6 datagram)*/
  quint32 IP_Version : 4;
  quint32 Traffic_Class : 8;
  quint32 Flow_Label : 20;
  quint16 Payload_Length;
  quint8 Next_Header;
  quint8 Hop_Limit;
  quint16 IPSrc[8];
  quint16 IPDst[8];
  quint16 UDPPortSrc;   /**= 0x0000: Source port number from UDP header.*/
  quint16 UDPPortDst;   /**= 0xC000: Destination port number from UDP header.*/
  quint16 UDP_Length;   /**= 0x01C1: Length (UDP header + data) from UDP header. */
  quint16 UDP_Checksum;   /**= 0x0000: UDP checksum field from UDP header.*/
}EthIPUDPHdr_V6;
//6 + 6 + 2 + 4 + 4 + 4 + 2 + 1 + 1 + 2 * 8 + 2 * 8 + 2 + 2 + 2 + 2
#define EE_SIZE_ETH_IP_UDP_HEADER_V6 sizeof(EthIPUDPHdr_V6)

#define EE_POS_PCAP_ETH_PROC			(EE_SIZE_PCAP_FILE_HEADER + EE_SIZE_PCAP_PKT_HEADER + 12)
#define EE_POS_PCAP_ETH_PROC_IP_VER		(EE_POS_PCAP_ETH_PROC + 1)

inline quint16 EE_BE_GetEthProFromEthIPUDPHdr(char* buf)
{
	return EE_BE_GetQUINT16(buf + EE_POS_PCAP_ETH_PROC);
}

inline quint16 EE_LE_GetEthProFromEthIPUDPHdr(char* buf)
{
	return EE_LE_GetQUINT16(buf + EE_POS_PCAP_ETH_PROC);
}

#pragma pack()

#define EE_SIZE_ETH_IP_UDP_HEADER_NULL			0
#define EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V4		(EE_SIZE_PCAP_FILE_HEADER + EE_SIZE_PCAP_PKT_HEADER + EE_SIZE_ETH_IP_UDP_HEADER_V4)
#define EE_POS_PCAP_DATA_W_ETHIPUDP_HDR_V6      (EE_SIZE_PCAP_FILE_HEADER + EE_SIZE_PCAP_PKT_HEADER + EE_SIZE_ETH_IP_UDP_HEADER_V6)
#define EE_POS_PCAP_DATA_WO_ETHIPUDP_HDR		(EE_SIZE_PCAP_FILE_HEADER + EE_SIZE_PCAP_PKT_HEADER)

#define EE_VAL_ETH_PROC_IP_V4				0x0800
#define EE_VAL_ETH_PROC_IP_V6				0x86DD
#define EE_VAL_ETH_IP_VER_V4				0x04
#define EE_VAL_ETH_IP_VER_V6				0x06
#define EE_VAL_ETH_IP_VER_NULL				0x00

#define PCAP_FILE_MAGIC						0xa1b2c3d4



//EE_ALIGN_4BYTE = lambda x : ((x + 3) & ~(0x03))

#define EE_MAX_SIZE_PCAP_PACKET_PAYLOAD			5000

#define QT_TABMODEL_MAX_COUNT					3000000
#define QT_TABMODEL_MAX_COUNT_MINUS_1			((QT_TABMODEL_MAX_COUNT)-(1))

////////////////////////////////Begin Tiger Trace
#define EE_SIZE_TIGER_PAYLOAD_HEADER			(1 + 1 + 1 + 1 + 1 + 1 + 2 + 1)
#define EE_SIZE_TIGER_PACKAGE_HEADER			(2 + 1)
#define TIGER_UL_ID			0x1E
#define TIGER_DL_ID         0x2B

inline bool isValidTigerPkg(quint8 uldlId)
{
	return TIGER_UL_ID == uldlId || TIGER_DL_ID == uldlId;
}

inline quint8 EE_BE_GetULDLIdFromTTPayloadHeader(char* buf)
{
	return EE_BE_GetQUINT8(buf + 0);
}

inline quint8 EE_BE_GetPkgNumFromTTPayloadHeader(char* buf)
{
	return EE_BE_GetQUINT8(buf + 5);
}

inline quint8 EE_BE_GetPkgLenFromTTPackageHeader(char* buf)
{
	return EE_BE_GetQUINT8(buf + 2);
}
////////////////////////////////End Tiger Trace