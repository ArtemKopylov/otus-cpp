#include "lib.h"
#include <gtest/gtest.h>

#include <algorithm>
#include <string>
using namespace std;

namespace GTEST
{
	bool argument_passed = false;
	int PATCH_VERSION = 0;
}

TEST(g_version_test, test_valid_version) {
	int v = version();
	EXPECT_GT(v, 0);
	if (GTEST::argument_passed)
		EXPECT_EQ(v, GTEST::PATCH_VERSION);
}

int main(int argc, char** argv) {
	int i = 1;
	while (i < argc && strstr(argv[i], "--gtest"))
	{
		i++;
	}
	if (i < argc)
	{
		GTEST::argument_passed = true;
		string s(argv[i]);
		s.erase(remove_if(s.begin(), s.end(), [](char x){return x < '0' || x > '9';}), s.end());
		GTEST::PATCH_VERSION = stoi(s);
	}

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
