#pragma once

#include <log4cplus/layout.h> 
#include <log4cplus/loggingmacros.h> 
#include <log4cplus/helpers/stringhelper.h> 
#include <log4cplus/configurator.h>

using namespace log4cplus;
using namespace log4cplus::helpers;

#define eeLogger Logger::getRoot()
#define EELOG_TRACE(logEvent)		LOG4CPLUS_TRACE(eeLogger, logEvent)
#define EELOG_TRACE_STR(logEvent)	LOG4CPLUS_TRACE_STR(eeLogger, logEvent)
#define EELOG_DEBUG(logEvent)		LOG4CPLUS_DEBUG(eeLogger, logEvent)
#define EELOG_DEBUG_STR(logEvent)	LOG4CPLUS_DEBUG_STR(eeLogger, logEvent)
#define EELOG_INFO(logEvent)		LOG4CPLUS_INFO(eeLogger, logEvent)
#define EELOG_INFO_STR(logEvent)	LOG4CPLUS_INFO_STR(eeLogger, logEvent)
#define EELOG_WARN(logEvent)		LOG4CPLUS_WARN(eeLogger, logEvent)
#define EELOG_WARN_STR(logEvent)	LOG4CPLUS_WARN_STR(eeLogger, logEvent)
#define EELOG_ERROR(logEvent)		LOG4CPLUS_ERROR(eeLogger, logEvent)
#define EELOG_ERROR_STR(logEvent)	LOG4CPLUS_ERROR_STR(eeLogger, logEvent)
#define EELOG_FATAL(logEvent)		LOG4CPLUS_FATAL(eeLogger, logEvent)
#define EELOG_FATAL_STR(logEvent)	LOG4CPLUS_FATAL_STR(eeLogger, logEvent)

#define MY_LOG_FILE_PATH "D:/vs2013/sln/EagleEye/Cfg/logconfig.properites"

#define EELOG_INIT()\
do{\
	log4cplus::initialize(); \
	PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(MY_LOG_FILE_PATH)); \
} while (0);
