/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: TokenTest.cpp                               */
/* Path: /tests/TokenTest.cpp                                                 */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Saturday, 1st June 2024 9:40:01 pm                           */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Saturday, 1st June 2024 9:45:36 pm                          */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include <gtest/gtest.h>

#include <Token.hpp>

TEST(TokenTest, getData)
{
	Token token(type, "void");
	Token token2(type, "int");
	Token token3(type, "char");

	EXPECT_EQ(token.getData(), "void");
	EXPECT_EQ(token2.getData(), "int");
	EXPECT_EQ(token3.getData(), "char");
}

TEST(TokenTest, getType)
{
	Token token(struct_type, "func");
	Token token2(type, "int");
	Token token3(str, "ouiouibaguettes");

	EXPECT_EQ(token.getType(), struct_type);
	EXPECT_EQ(token2.getType(), type);
	EXPECT_EQ(token3.getType(), str);
}

/*main for Unit test of FileManager Class*/

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
