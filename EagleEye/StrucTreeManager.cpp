#include "StrucTreeManager.h"
#include "StrucLUT.h"
#include "StrucTree.h"

StrucTreeManager* StrucTreeManager::inst = nullptr;
QMap<QString, qint8> StrucTreeManager::baseType2BytesMap;
QMap<QString, qint8> StrucTreeManager::baseType2IdxMap;

StrucTreeManager* StrucTreeManager::getInstance()
{
	if (nullptr == inst)
	{
		inst =  new StrucTreeManager;
	}

	return inst;
}

void StrucTreeManager::clrInstance()
{
	if (nullptr != inst)
	{
		delete inst;
		inst = nullptr;
	}
}

void StrucTreeManager::generate()
{
	quint16 strucTvIdxSeed = 0;
	quint16 strucTvIdxCur = 0;

	parseStrucFile();

	foreach(qint32 sid, stucId2StructProfileMap.keys())
	{
		quint16 strucTV = STRUC_TV(sid);
		quint16 strucN = STRUC_N(sid);
		strucTvIdxCur = strucTVArr[strucTV];
		if (INVALID_U16 == strucTvIdxCur)
		{
			strucTVArr[strucTV] = strucTvIdxSeed;
			strucTvIdxCur = strucTVArr[strucTV];
			++strucTvIdxSeed;

			EELOG_DEBUG("StrucTreeManager::generate|TV (" <<
				strucTV << 
				") Idx (" << 
				strucTvIdxCur << 
				")");
		}
		else
		{
			Q_ASSERT(strucTvIdxCur < EE_MAX_STRUC_TV);
		}

		FieldInfo *fi = new FieldInfo;
		fi->fd.type = stucId2StructProfileMap.value(sid)->sr.r0Name;
		StrucTree *st = new StrucTree(fi, 0);
		fi->fd.sizeInByte = generateStrucTree(fi->fd.type, st);
		st->setId(STRUC_N(sid));
		strucTreeArr[strucTvIdxCur][strucN] = *st;

		//EELOG_DEBUG("StrucTreeManager::generate\n" << QSTR2CSTR(st->dump()));
		//EELOG_DEBUG("" << QString(80, '=').toStdString().c_str());

		delete st;
	}
}

StrucTree *StrucTreeManager::getStrucTree(quint32 strucId)
{
	quint16 strucTV = STRUC_TV(strucId);
	quint16 strucN = STRUC_N(strucId);
	StrucTree *st = &(strucTreeArr[strucTVArr[strucTV]][strucN]);
	if (INVALID_U16 == st->getId())
	{
		EELOG_ERROR("StrucTreeManager::getStrucTree|failed to get struc tree (" 
			<< strucId 
			<< ")");
		Q_ASSERT(false);
		return nullptr;
	}
	return st;
}

quint16 StrucTreeManager::getStrucTreeVecIndex(quint32 strucId)
{
	quint16 strucTV = STRUC_TV(strucId);
	return strucTVArr[strucTV];
}

StrucTreeManager::StrucTreeManager():
strucFile(SLUT_GET_SF()), stucId2StructProfileMap(SLUT_GET_SP_MAP())
{
	strucName2FieldCxtVecMap.clear();	
	baseType2BytesMap.clear();
	baseType2IdxMap.clear();

	memset(strucTVArr, INVALID_U16, sizeof(quint16)* INVALID_U16);
	for (int i = 0; i < EE_MAX_STRUC_TV; ++i)
	{
		strucTreeArr[i] = new StrucTree[INVALID_U16];
	}

	baseType2BytesMap.insert("quint8", 1);
	baseType2BytesMap.insert("quint16", 2);
	baseType2BytesMap.insert("quint32", 4);
	baseType2BytesMap.insert("qint8", 1);
	baseType2BytesMap.insert("qint16", 2);
	baseType2BytesMap.insert("qint32", 4);

	baseType2IdxMap.insert("qint8", BASE_TYPE_IDX_QINT8);
	baseType2IdxMap.insert("qint16", BASE_TYPE_IDX_QINT16);
	baseType2IdxMap.insert("qint32", BASE_TYPE_IDX_QINT32);
	baseType2IdxMap.insert("quint8", BASE_TYPE_IDX_QUINT8);
	baseType2IdxMap.insert("quint16", BASE_TYPE_IDX_QUINT16);
	baseType2IdxMap.insert("quint32", BASE_TYPE_IDX_QUINT32);
}

StrucTreeManager::~StrucTreeManager()
{
	for (int i = 0; i < EE_MAX_STRUC_TV; ++i)
	{
		if (strucTreeArr[i] != nullptr)
		{
			delete[] strucTreeArr[i];
			strucTreeArr[i] = nullptr;
		}
	}
}

void StrucTreeManager::parseStrucFile()
{
	QFile qFile(strucFile);
	if (!qFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		EELOG_WARN("StrucTreeManager::parseStrucFile|failed to open file (" << QSTR2CSTR(strucFile) << ")");
		return;
	}

	bool isStrucDefined = false;
	bool isEnclosedComment = false;
	QStringList strucFieldsList;

	QRegularExpression reStrucStart("typedef\\s+struct");
	QRegularExpression reStrucEnd("\\}\\s*\\S+\\s*;");
	QRegularExpression reStrucType("\\}\\s*(\\S+)\\s*;");
	QRegularExpressionMatch match;

	QTextStream ts(&qFile);
	while (!ts.atEnd())
	{
		QString line = ts.readLine();

		line.replace(QRegularExpression("\\/\\/.*(\\*\\/)$"), "\1");
		line.replace(QRegularExpression("\\/\\*.*\\*\\/"), "");
		line.replace(QRegularExpression("\\/\\/.*"), "");

		if (reStrucStart.match(line, 0).hasMatch())
		{
			isStrucDefined = true;
		}
		else if (reStrucEnd.match(line, 0).hasMatch())
		{
			if (isStrucDefined)
			{
				match = reStrucType.match(line, 0);
				if (match.hasMatch())
				{
					analyzeStruc(match.captured(1), strucFieldsList);
				}

				isStrucDefined = false;
				strucFieldsList.clear();
			}
		}
		else
		{
			if (isStrucDefined)
			{
				QRegularExpression re("\\/\\*.*\\*\\/");
				line.replace(re, "");
				if (isEnclosedComment)
				{
					re.setPattern("\\*\\/");
					if (re.match(line, 0).hasMatch())
					{
						isEnclosedComment = 0;
						re.setPattern(".*\\*\\/");
						line.replace(re, "");

						strucFieldsList.append(line);
					}
				}
				else
				{
					re.setPattern("\\/\\*");
					if (re.match(line, 0).hasMatch())
					{
						isEnclosedComment = 1;
						re.setPattern("\\/\\*.*");
						line.replace(re, "");
					}
					strucFieldsList.append(line);
				}
			}
		}
	}
	qFile.close();
}

void StrucTreeManager::analyzeStruc(const QString& strucType, const QStringList& strucFields)
{
	QStringList remainFields;
	foreach(auto field, strucFields)
	{
		QRegularExpression reDefine("#define");
		QRegularExpression reIf("#if");
		QRegularExpression reElse("#else");
		QRegularExpression reEndif("#endif");
		if (!reDefine.match(field, 0).hasMatch() &&
			!reIf.match(field, 0).hasMatch() &&
			!reElse.match(field, 0).hasMatch() &&
			!reEndif.match(field, 0).hasMatch())
		{
			remainFields.append(field);
		}

		//EELOG_DEBUG("StrucTreeManager::analyzeStruc|field( " << QSTR2CSTR(field) << " )");
	}

	QString fields = remainFields.join("");
	fields.replace(QRegularExpression("\\/\\/.*$"), "");
	fields.replace(QRegularExpression("\\/\\*.*?\\*\\/"), "");
	fields.replace(QRegularExpression("\\s+"), " ");
	fields.replace(QRegularExpression("\\{"), "");
	fields.replace(QRegularExpression("\\}"), "");
	fields.replace(QRegularExpression("\\n"), "");
	remainFields = fields.split(";");

	//EELOG_DEBUG("StrucTreeManager::analyzeStruc|fields( " 
	//	<< QSTR2CSTR(fields) << " )" << ", size (" << remainFields.size() << " )");

	FieldCxtVec fieldCxtVec;
	foreach(auto field, remainFields)
	{
		if (!field.isEmpty())
		{
			FieldCxt fieldCxt;

			QRegularExpression re("\\s*(\\S+)\\s+(.*)");
			QRegularExpressionMatch match = re.match(field, 0);
			QString nm;
			QString cards;
			if (match.hasMatch())
			{
				fieldCxt.type = match.captured(1);
				nm = match.captured(2);
			}

			re.setPattern("\\[.*\\]");
			if (re.match(nm, 0).hasMatch())
			{
				re.setPattern("\\s*(\\S+)\\s*(\\[.*\\])");
				match = re.match(nm, 0);
				if (match.hasMatch())
				{
					fieldCxt.name = match.captured(1);
					cards = match.captured(2);
					re.setPattern("\\[(.*?)\\]");
					match = re.match(cards, 0);
					if (match.hasMatch())
					{
						fieldCxt.cards = match.captured(1).toInt();
					}
				}
			}
			else
			{
				fieldCxt.name = nm;
				fieldCxt.cards = 1;
			}

			//EELOG_DEBUG("StrucTreeManager::analyzeStruc|type (" 
			//	<< QSTR2CSTR(fieldCxt.type) 
			//	<< "), name = (" 
			//	<< QSTR2CSTR(fieldCxt.name) 
			//	<< "), cards (" 
			//	<< fieldCxt.cards 
			//	<< ")");

			fieldCxtVec.append(fieldCxt);
		}
	}

	strucName2FieldCxtVecMap.insert(strucType, fieldCxtVec);

}

qint16 StrucTreeManager::generateStrucTree(const QString& strucType, StrucTree *parent)
{
	auto it = strucName2FieldCxtVecMap.find(strucType);
	if (it == strucName2FieldCxtVecMap.end())
	{
		return 0;
	}
	const FieldCxtVec& fieldCxtVec = it.value();

	quint16 offset =
		parent->data(StrucTree::FI_IDX_OFFSET_IN_BYTE).toInt() +
		parent->data(StrucTree::FI_IDX_SIZE_IN_BYTE).toInt();
	quint16 baseOffset = offset;

	quint16 lastSize = 0;

	quint16 offsetBit = 0;

	//EELOG_DEBUG("StrucTreeManager::generateStrucTree|strucType (" 
	//	<< QSTR2CSTR(strucType) 
	//	<< "), size (" 
	//	<< fieldCxtVec.size() 
	//	<< ")");

	qint8 idx;
	for (idx = 0; idx < fieldCxtVec.size(); ++idx)
	{
		const FieldCxt& f = fieldCxtVec.at(idx);

		//EELOG_DEBUG("StrucTreeManager::generateStrucTree|type ("
		//	<< QSTR2CSTR(f.type)
		//	<< "), name ("
		//	<< QSTR2CSTR(f.name)
		//	<< "), cards (" 
		//	<< f.cards
		//	<< ")");
	
		if (1 == f.cards)
		{
			QRegularExpression re("(.*):(.*)");
			QRegularExpressionMatch match = re.match(f.name, 0);
			if (!match.hasMatch())
			{
				if (offsetBit)
				{
					offset += lastSize;
				}
				lastSize = 0;
				offsetBit = 0;

				FieldInfo *fi = new FieldInfo;
				fi->fd.type = f.type;
				fi->fd.name = f.name.trimmed();
				fi->fd.offsetInByte = offset;
				fi->fd.sizeInByte = 0;
				fi->fd.offsetInBit = 0;
				fi->fd.sizeInBit = 0;
				StrucTree *child = new StrucTree(fi, parent);
				parent->appendChild(child);

				if (!baseType2BytesMap.contains(f.type))
				{
					fi->fd.sizeInByte = generateStrucTree(f.type, child);
				}
				else
				{
					fi->fd.sizeInByte = baseType2BytesMap.value(fi->fd.type);
					fi->fd.baseTypeIdx = baseType2IdxMap.value(fi->fd.type);
					if (StrucLUT::fkLut.contains(fi->fd.name))
					{
						fi->fd.fkIdx = StrucLUT::fkLut.value(fi->fd.name);
					}
				}

				//dumpFieldInfo(*fi);				

				lastSize = fi->fd.sizeInByte;
			}
			else
			{
				if (offsetBit)
				{
					if (baseType2BytesMap.value(f.type) != lastSize ||
						offsetBit == 8 * lastSize)
					{
						offset += lastSize;
						offsetBit = 0;
						lastSize = 0;
					}
				}

				QString fnm = match.captured(1).trimmed();
				qint8 bitsize = match.captured(2).trimmed().toInt();

				FieldInfo *fi = new FieldInfo;
				fi->fd.type = f.type;
				fi->fd.name = fnm;
				fi->fd.offsetInByte = offset;
				fi->fd.sizeInByte = 0;
				fi->fd.offsetInBit = offsetBit;
				fi->fd.sizeInBit = bitsize;
				StrucTree *child = new StrucTree(fi, parent);
				parent->appendChild(child);

				fi->fd.sizeInByte = baseType2BytesMap.value(fi->fd.type);
				fi->fd.baseTypeIdx = baseType2IdxMap.value(fi->fd.type);
				if (StrucLUT::fkLut.contains(fi->fd.name))
				{
					fi->fd.fkIdx = StrucLUT::fkLut.value(fi->fd.name);
				}

				//dumpFieldInfo(*fi);

				lastSize = fi->fd.sizeInByte;

				offsetBit += bitsize;
			}
		}
		else
		{
			if (offsetBit)
			{
				offset += lastSize;
			}
			offsetBit = 0;
			lastSize = 0;

			quint16 lpOffset = offset;
			quint16 typeByteSize = 0;
			quint16 lp;
			for (lp = 0; lp < f.cards; ++lp)
			{
				FieldInfo *fi = new FieldInfo;
				fi->fd.type = f.type;
				fi->fd.name = QObject::tr("%1[%2]").arg(f.name.trimmed()).arg(lp);
				fi->fd.offsetInByte = lpOffset;
				fi->fd.sizeInByte = 0;
				fi->fd.offsetInBit = 0;
				fi->fd.sizeInBit = 0;
				StrucTree *child = new StrucTree(fi, parent);
				parent->appendChild(child);

				if (!baseType2BytesMap.contains(f.type))
				{
					typeByteSize = generateStrucTree(f.type, child);
				}
				else
				{
					typeByteSize = baseType2BytesMap.value(f.type);
					fi->fd.baseTypeIdx = baseType2IdxMap.value(f.type);
					if (StrucLUT::fkLut.contains(fi->fd.name))
					{
						fi->fd.fkIdx = StrucLUT::fkLut.value(fi->fd.name);
					}
				}

				fi->fd.sizeInByte = typeByteSize;

				lpOffset += typeByteSize;

				lastSize += typeByteSize;

				//dumpFieldInfo(*fi);				
			}
		}

		//EELOG_DEBUG("StrucTreeManager::generateStrucTree|offset (" 
		//	<< offset 
		//	<< "), offsetBit (" 
		//	<< offsetBit 
		//	<< "), lastSize (" 
		//	<< lastSize 
		//	<< ")");

		if (0 == offsetBit)
		{
			offset += lastSize;
		}
	}

	if (offsetBit)
	{
		offset += lastSize;
	}
	return offset - baseOffset;
}