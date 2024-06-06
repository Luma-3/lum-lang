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
/* Last Modified: Friday, 7th June 2024 12:11:22 am                           */
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

int		Lexer::matchNumber(void)
{
	regex number(Tregex_number);
	if (matchRegex(number))
	{
		//check if number is not followed by an identifier
		size_t affterMatch = _currentMatch.position() + _currentMatch.length();
		if (isalpha(_file[affterMatch]) || _file[affterMatch] == '_')
		{
			size_t start;
			size_t end;
			size_t size;
			
			// find invalid identifier
			end = _file.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_", affterMatch);
			printf("affterMatch: %zu\n", affterMatch);
			start = _position - _currentMatch.length();
			size = end - start;
			string invalidIdentifier = _file.substr(start, size);
			_errors.push_back(Error(errLex_invNumFormat, invalidIdentifier, _lineNumber, _colNumber - _currentMatch.length()));
			// _position = start + size;
			updatePosition(invalidIdentifier);
			printf("start: %zu\n", start);
			printf("end: %zu\n", end);
			printf("size: %zu\n", size);
			return (ERROR);
		}
		addToken(e_TokenType::number, _currentMatch.str());
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
		return (FOUND);
	}
	return (NOT_FOUND);
}

int		Lexer::matchWhitespace(void)
{
	regex whitespace(Tregex_whitespace);
	if (matchRegex(whitespace))
	{
		// addToken(e_TokenType::whitespace, _currentMatch);
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
		updatePosition(_currentMatch.str());
		return (FOUND);
	}
	return (NOT_FOUND);
}
