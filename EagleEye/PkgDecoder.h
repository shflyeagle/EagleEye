#pragma once

#include "EeCommon.h"

class StrucTree;
class PkgVisitor;
class PkgDecoder
{
public:
	PkgDecoder() = default;

	PkgDecoder(unsigned pkgId)
	{
		this->pkgId = pkgId;
	}

	PkgDecoder* clone()
	{
		PkgDecoder* clone = createInstance();
		clone->pkgId = this->pkgId;		
		return clone;
	}

	StrucTree* detachStrucTree()
	{
		StrucTree* st = strucTree;
		strucTree = nullptr;
		return st;
	}

	virtual PkgDecoder* createInstance()
	{
		return new PkgDecoder;
	}

	//note :
	//1.	before destructor PkgDecoder, PLS explicitly call detachStrucTree to delete strucTree to avoid memory leak
	//2.	if not, assert w/ _BLOCK_TYPE_IS_INVALID will be triggered. currently, don't know why ???
	virtual ~PkgDecoder()
	{
		if (strucTree != nullptr)
		{	
			//delete strucTree;
			strucTree = nullptr;
		}
	}

	const StrucTree* getStrucTree() const;

	unsigned getStrucId() const
	{
		return pkgId;
	}

	virtual void decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter = false);	

protected:
	StrucTree* strucTree{ nullptr };

	unsigned pkgId{ 0xFFFFFFFF };
};

class PkgDecoderMng
{
public:
	~PkgDecoderMng()
	{
		for (auto it = pkgDecoders.begin(); it != pkgDecoders.end(); ++it)
		{
			delete it.value();
		}

		pkgDecoders.clear();
	}

	virtual PkgDecoder* getDecoder(unsigned pkgId) = 0;

protected:
	QMap<unsigned, PkgDecoder*> pkgDecoders;
};