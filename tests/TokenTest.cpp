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
/* Last Modified: Tuesday, 11th June 2024 7:27:07 pm                          */
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
	Token token(keyword, "void");
	Token token2(keyword, "int");
	Token token3(keyword, "char");

	EXPECT_EQ(token.getData(), "void");
	EXPECT_EQ(token2.getData(), "int");
	EXPECT_EQ(token3.getData(), "char");
}

TEST(TokenTest, getType)
{
	Token token(keyword, "func");
	Token token2(keyword, "int");
	Token token3(str, "ouiouibaguettes");

	EXPECT_EQ(token.getType(), keyword);
	EXPECT_EQ(token2.getType(), keyword);
	EXPECT_EQ(token3.getType(), str);
}

/*main for Unit test of FileManager Class*/

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
