#pragma once

#include "EeCommon.h"

class StrucTree;

class LteRrcDecoder
{
public:
	LteRrcDecoder(quint8 signalingDirection, 
		quint8 channelType, 
		const QByteArray& rrcPayload);

	StrucTree* getStrucTree(StrucTree* root);

	~LteRrcDecoder();

private:
	void generate(const QDomNode& np, StrucTree* parent, StrucTree* root);
	
private:
	QString decodedRrc;
};

