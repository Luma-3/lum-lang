/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: Lexer.cpp                                   */
/* Path: /sources/Lexer.cpp                                                   */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Saturday, 1st June 2024 11:18:20 pm                          */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Sunday, 2nd June 2024 11:58:08 pm                           */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Lexer.hpp"

using std::regex;
using std::smatch;


void	Lexer::Tokenize(string file)
{
	(void)file;
	throw std::runtime_error("Not implemented");
}

string	Lexer::ReadToken()
{
	throw std::runtime_error("Not implemented");
}

vector<string>	Lexer::getErrors()
{
	throw std::runtime_error("Not implemented");
}