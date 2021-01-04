#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "schwein.h"

using testing::StrEq;
using testing::Not;

namespace tiereTest {
	using namespace tiere;

class schweinTest : public ::testing::Test
{
	protected:
		schwein objUnderTest;
		void TearDown() override {
			// TODO test in TearDown: Good style?
			EXPECT_THAT(objUnderTest.get_name(), Not(StrEq("Elsa")));
		}
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
	} catch (...) {
		FAIL() << "unexpected exception";
	}
}

TEST_F(schweinTest, set_name__new_valid_name)
{
	objUnderTest.set_name("newname");
	EXPECT_THAT(objUnderTest.get_name(), StrEq("newname"));
}

}

