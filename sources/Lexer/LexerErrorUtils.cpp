/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: LexerErrorUtils.cpp                         */
/* Path: /sources/Lexer/LexerErrorUtils.cpp                                   */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Friday, 7th June 2024 8:27:23 pm                             */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Friday, 7th June 2024 8:38:59 pm                            */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Lexer.hpp"

#include <iostream>

using std::regex;
using std::smatch;


int	is_valid_number(char c)
{
	return (isalpha(c) || c == '_');
}

int		Lexer::invalidNumber(void)
{
	size_t start;
	size_t end;
	
	// find invalid identifier
	end = _file.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_", _position);
	if (end == string::npos)
		end = _file.length();
	start = _position - _currentMatch.length();
	string invalidIdentifier = _file.substr(start, end - start);
	_errors.push_back(Error(errLex_invNumFormat, invalidIdentifier, _lineNumber, _colNumber));
	_position = end - 1;
	updatePosition(invalidIdentifier);
	return (ERROR);
}