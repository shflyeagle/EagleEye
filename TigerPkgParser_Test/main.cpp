#include "TigerPkgParser_Test.h"
#include <QtWidgets/QApplication>

#include "DataManager.h"
#include "TigerDataManager.h"
#include "TigerPkgParser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TigerPkgParser_Test w;
    w.show();
	
	EELOG_INIT();

	//QString fileName = "E:/Troubleshooting/LR17.1/Legacy UL tput on load 166/0831/eNB930831ULtput.pcap";
	QString fileName = "E:/Troubleshooting/LR17.1/Legacy UL tput on load 166/0831/eNB147.pcap";
	{
		DataManager dm;
		TigerPkgParser parser(&dm);
		parser.parse();
	}

    return a.exec();
}
