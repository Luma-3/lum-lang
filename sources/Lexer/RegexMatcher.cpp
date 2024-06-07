/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: RegexMatcher.cpp                            */
/* Path: /sources/Lexer/RegexMatcher.cpp                                      */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Sunday, 2nd June 2024 7:50:56 pm                             */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Friday, 7th June 2024 8:39:23 pm                            */
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

int		Lexer::matchNumber(void)
{
	regex number(Tregex_number);
	if (matchRegex(number))
	{
		//check if number is not followed by an identifier
		if (is_valid_number(_file[_position]))
		{
			return (invalidNumber());
		}
		addToken(e_TokenType::number, _currentMatch.str());
		updatePosition(_currentMatch.str());
		return (FOUND);
	}
	return (NOT_FOUND);
}

int		Lexer::matchIdentifier(void)
{
	regex identifier(Tregex_identifier);
	if (matchRegex(identifier))
	{
		addToken(e_TokenType::struct_type, _currentMatch.str());
		updatePosition(_currentMatch.str());
		return (FOUND);
	}
	return (NOT_FOUND);
}

int		Lexer::matchWhitespace(void)
{
	regex whitespace(Tregex_whitespace);
	if (matchRegex(whitespace))
	{
		updatePosition(_currentMatch.str());
		return (FOUND);
	}
	return (NOT_FOUND);
}

bool	Lexer::matchRegex(regex &regex)
{
	if (std::regex_search(
		_file.cbegin() + _position,
		_file.cend(),
		_currentMatch,
		regex,
		std::regex_constants::match_continuous
	)) {
		
		_position += _currentMatch.length();
		return (FOUND);
	}
	return (NOT_FOUND);
}
