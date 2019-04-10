
#include "PkgDecoder.h"
#include "StrucLUT.h"
#include "StrucTree.h"
#include "PkgVisitor.h"

void PkgDecoder::decode(const QByteArray& b, PkgLoc* pkgLoc, bool is4Filter)
{
	if (strucTree != Q_NULLPTR)
	{
		delete strucTree;
		strucTree = Q_NULLPTR;
	}
}


const StrucTree* PkgDecoder::getStrucTree() const
{
	return strucTree;
}