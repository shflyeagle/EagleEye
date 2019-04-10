#include "PkgPageCommand.h"
#include "PkgPageThread.h"

void LoadPkgPageCommand::execute()
{
	pageThread->loadPage(getPageReq());
}

void CancelPkgPageCommand::execute()
{
	pageThread->cancelPage(getPageReq());
}