/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: StaticMatcher.cpp                           */
/* Path: /sources/Lexer/StaticMatcher.cpp                                     */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Sunday, 9th June 2024 4:55:58 pm                             */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Sunday, 9th June 2024 7:59:39 pm                            */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Lexer.hpp"

bool	Lexer::matchKeyword(const string &str)
{
	return (TokenKeywords.find(str) != TokenKeywords.end());
}

bool	Lexer::matchDelimiter(void)
{
	for (int i = 2; i > 0; i--)
	{
		string str = _file.substr(_position, i);
		if (TokenDelimiters.find(str) != TokenDelimiters.end())
		{
			addToken(TokenDelimiters.at(str), str);
			_position += i;
			updatePosition(str);
			return (FOUND);
		}
	}
	return (NOT_FOUND);
}

bool	Lexer::matchOperator(void)
{
	for (int i = 2; i > 0; i--)
	{
		string str = _file.substr(_position, i);
		if (TokenOperators.find(str) != TokenOperators.end())
		{
			addToken(TokenOperators.at(str), str);
			_position += i;
			updatePosition(str);
			return (FOUND);
		}
	}
	return (NOT_FOUND);
}

bool	Lexer::matchComment(void)
{
	if (_file[_position] == '/' && _file[_position + 1] == '/')
	{
		size_t end = _file.find("\n", _position);
		if (end == string::npos)
			end = _file.length();
		addToken(comment, _file.substr(_position, end - _position));
		_position = end;
		updatePosition(_file.substr(_position, end - _position));
		return (FOUND);
	}
	else if (_file[_position] == '/' && _file[_position + 1] == '*')
	{
		size_t end = _file.find("*/", _position);
		if (end == string::npos)
		{
			_errors.push_back(Error(errLex_longCommentNotClosed, "/*", _lineNumber, _colNumber));
			_position = _file.length();
			return (ERROR);
		}
		addToken(comment, _file.substr(_position, end - _position + 2));
		_position = end + 2;
		updatePosition(_file.substr(_position, end - _position + 2));
		return (FOUND);
	}
	return (NOT_FOUND);
}