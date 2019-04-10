#pragma once

#include <EeLogging.h>
#include <tchar.h>
#include <gtest/gtest.h>

namespace EeGt
{
	class Environment : public testing::Environment
	{
	public:
		virtual void SetUp() override
		{
			EELOG_INIT();

			EELOG_DEBUG("EagleEye Google Test Environment SetUP");
		}
		virtual void TearDown() override
		{
			EELOG_DEBUG("EagleEye Google Test Environment TearDown");
		}
	};
}
