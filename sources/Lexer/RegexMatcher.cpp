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
/* Last Modified: Sunday, 9th June 2024 7:04:43 pm                            */
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
	regex number(TokenRegexes.at(e_TokenType::number));
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

int		Lexer::matchString(void)
{
	if (_file[_position] == '"')
	{
		regex str(TokenRegexes.at(e_TokenType::str));
		if (matchRegex(str))
		{
			addToken(e_TokenType::str, _currentMatch.str());
			updatePosition(_currentMatch.str());
			return (FOUND);
		}
		else
		{	string ill_char(1, _file[_position]);
			_errors.push_back(Error(errLex_stringNotClosed, ill_char, _lineNumber, _colNumber));
			return (ERROR);
		}
	}
	return (NOT_FOUND);
}

int		Lexer::matchIdentifier(void)
{
	regex identifier(TokenRegexes.at(e_TokenType::identifier));
	if (matchRegex(identifier))
	{
		if (matchKeyword(_currentMatch.str())) {
			addToken(e_TokenType::keyword, _currentMatch.str());
		}
		else
		{
			addToken(e_TokenType::identifier, _currentMatch.str());
		}
		updatePosition(_currentMatch.str());
		return (FOUND);
	}
	return (NOT_FOUND);
}

int		Lexer::matchWhitespace(void)
{
	regex whitespace(TokenRegexes.at(e_TokenType::whitespace));
	if (matchRegex(whitespace))
	{
		updatePosition(_currentMatch.str());
		return (FOUND);
	}
	return (NOT_FOUND);
}

int		Lexer::matchChar(void)
{
	if (_file[_position] == '\'')
	{
		regex char_(TokenRegexes.at(e_TokenType::char_));
		if (matchRegex(char_))
		{
			addToken(e_TokenType::char_, _currentMatch.str());
			updatePosition(_currentMatch.str());
			return (FOUND);
		}
		else
		{
			string ill_char(1, _file[_position]);
			_errors.push_back(Error(errLex_charNotClosed, ill_char, _lineNumber, _colNumber));
			return (ERROR);
		}
	}
	return (NOT_FOUND);
}

bool	Lexer::matchRegex(const regex &regex)
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
