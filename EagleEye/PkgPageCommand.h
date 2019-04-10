#pragma once

#include "EeCommon.h"

class PkgPageThread;

class PkgPageRequest
{
	friend class PkgPageCommand;

public:
	int no;
	unsigned pos;
	unsigned len;

public:
	PkgPageRequest(int no = 0, unsigned pos = 0, unsigned len = 0)
	{
		this->no = no;
		this->pos = pos;
		this->len = len;
	}

	QString dump() const
	{
		return QString("PkgPageRequest (No%1, Pos%2, Len%3")
			.arg(no)
			.arg(pos)
			.arg(len);
	}

};

class PkgPageCommand
{
public:
	PkgPageCommand(PkgPageThread * thread, const PkgPageRequest& req):
		pageThread(thread), pageReq(req)
	{
	}
	virtual ~PkgPageCommand()
	{
	}

	virtual void execute() = 0;

	const PkgPageRequest& getPageReq()
	{
		return pageReq;
	}

protected:
	PkgPageThread *pageThread;
	PkgPageRequest pageReq;
};

class LoadPkgPageCommand : public PkgPageCommand
{
public:
	LoadPkgPageCommand(PkgPageThread* thread, const PkgPageRequest& req) :PkgPageCommand(thread, req)
	{
	}

	void execute() override;
};

class CancelPkgPageCommand : public PkgPageCommand
{
public:
	CancelPkgPageCommand(PkgPageThread* thread, const PkgPageRequest& req) :PkgPageCommand(thread, req)
	{
	}

	void execute() override;
};