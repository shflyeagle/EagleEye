#include "PkgVisitor.h"
#include "StrucTree.h"
#include "PkgDecoder.h"
#include "StrucLUT.h"


PkgVisitor::PkgVisitor()
{
}


PkgVisitor::~PkgVisitor()
{
}

QString PkgVisitor::show(const PkgDecoder* decoder)
{
	const StrucTree* st = decoder->getStrucTree();
	if (Q_NULLPTR == st)
	{
		return QString();
	}

	QString dsp;
	const FpVec& fpv = SLUT_GET_FPVEC(decoder->getStrucId());
	foreach(auto item, fpv)
	{
		auto pItem = item.get();

		if (!st->getKvMap()->contains(pItem->name))
		{
			continue;
		}

		if (SHOW_MASK_KV_VALUE_YES == pItem->showMask &&
			st->getKvMap()->value(pItem->name).toString() != "1")
		{
			continue;
		}

		QString value = "NA";
		if (pItem->kvMap.isEmpty())
		{
			value = st->getKvMap()->value(pItem->name).toString();
		}
		else
		{
			if (pItem->kvMap.contains(
				st->getKvMap()->value(pItem->name).toString()))
			{
				value = pItem->kvMap.value(
					st->getKvMap()->value(pItem->name).toString());
			}
			else if (pItem->kvMap.contains("OTHER"))
			{
				value = pItem->kvMap.value("OTHER");
			}

			if(SHOW_MASK_KV_PREFIX == pItem->showMask)
			{
				dsp.append(value).append("  ");
				value = st->getKvMap()->value(
					pItem->name).toString();
			}
		}

		if (SHOW_MASK_KV_VALUE_ONLY == pItem->showMask || 
			SHOW_MASK_VALUE_ONLY == pItem->showMask)
		{
			dsp.append(value)
				.append("  ");
		}
		else
		{
			dsp.append(pItem->alias.isEmpty() ? 
				pItem->name : pItem->alias)
				.append("=")
				.append(value)
				.append("  ");
		}			
	}

	return dsp;
}

