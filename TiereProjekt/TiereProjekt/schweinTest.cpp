#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "schwein.h"

using testing::StrEq;
using testing::Not;
using testing::Gt;
using testing::Throw;

namespace tiereTest {
	using namespace tiere;

class schweinTest : public ::testing::Test
{
	protected:
		schwein objUnderTest;
		const std::string invalid_name = "Elsa";
};

TEST_F(schweinTest, ctor__default_name)
{
	EXPECT_THAT(objUnderTest.get_name(), StrEq("nobody"));
}

TEST_F(schweinTest, ctor__create_with_valid_name)
{
	try {
		schwein objUnderTest{ "someone" };
		EXPECT_THAT(objUnderTest.get_name(), StrEq("someone"));
	}
	catch (...) {
		FAIL() << "unexpected exception";
	}
}

TEST_F(schweinTest, ctor__create_with_invalid_name)
{
	try {
		schwein objUnderTest{ invalid_name };
		FAIL() << "expected exception";
	}
	catch (...) {
	}
}

TEST_F(schweinTest, set_name__new_valid_name)
{
	objUnderTest.set_name("newname");
	EXPECT_THAT(objUnderTest.get_name(), StrEq("newname"));
}

TEST_F(schweinTest, set_name__same_valid_name)
{
	const std::string old_name{ objUnderTest.get_name() };
	objUnderTest.set_name(old_name);
	EXPECT_THAT(objUnderTest.get_name(), StrEq(old_name));
}

TEST_F(schweinTest, set_name__deny_invalid_name)
{
	EXPECT_THROW(objUnderTest.set_name(invalid_name), std::exception);
}

TEST_F(schweinTest, ctor__default_weight)
{
	EXPECT_THAT(objUnderTest.get_gewicht(), Gt(0));
}

TEST_F(schweinTest, fressen__increase_weight)
{
	const int old_gewicht = objUnderTest.get_gewicht();
	objUnderTest.fressen();
	EXPECT_THAT(objUnderTest.get_gewicht(), Gt(old_gewicht));
}
}

