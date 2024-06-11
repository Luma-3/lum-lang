/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: ErrorTest.cpp                               */
/* Path: /tests/ErrorTest.cpp                                                 */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Sunday, 2nd June 2024 5:59:15 pm                             */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Tuesday, 11th June 2024 7:37:00 pm                          */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include <gtest/gtest.h>

#include "Error.hpp"

TEST(ErrorTest, getter)
{
	Error error(errLex_illChar, "@", 1, 4);
	EXPECT_EQ(error.getColum(), "4");
	EXPECT_EQ(error.getLine(), "1");
	EXPECT_EQ(error.getContext(), "@");
	EXPECT_EQ(error.getValue("ctx"), "@");
	EXPECT_EQ(error.getValue("ln"), "1");
	EXPECT_EQ(error.getValue("col"), "4");
}

TEST(ErrorTest, FormatError)
{
	Error error(errLex_illChar, "@", 1, 4);
	EXPECT_EQ(Error::FormatError(error), "Illegal character '@' at line 1, column 4.");
	Error error2(errLex_undifineExp, "World", 2, 5);
	EXPECT_EQ(Error::FormatError(error2), "Undefined expression 'World' start at line 2, column 5. Expected a valid expression.");
	Error error3(errLex_invNumFormat, "1.2.3", 3, 6);
	EXPECT_EQ(Error::FormatError(error3), "Invalid number format '1.2.3' at line 3, column 6. Number must be followed by a whitespace or an operator.");
}

/*main for Unit test of FileManager Class*/

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}