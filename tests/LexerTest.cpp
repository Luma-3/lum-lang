/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: LexerTest.cpp                               */
/* Path: /tests/LexerTest.cpp                                                 */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Tuesday, 11th June 2024 12:53:46 pm                          */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Tuesday, 11th June 2024 4:43:58 pm                          */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Lexer.hpp"
#include <gtest/gtest.h>

TEST(LexerTest, LexerTest_NoErrorsToken_Test)
{
	Lexer lexer("test.lum");
	lexer.Tokenize();
	EXPECT_EQ(lexer.getErrors().size(), 0);
}

TEST(LexerTest, LexerTest_WithErrorsToken_Test)
{
	Lexer lexer("test_with_error.lum");
	lexer.Tokenize();
	EXPECT_EQ(lexer.getErrors().size(), 1);
}

Test(LexerTest, LexerTest_Tokenfound_Test)
{
	Lexer lexer("test.lum");
	lexer.Tokenize();
	EXPECT_EQ(lexer.getTokens().size(), 15);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
