/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by brs@icloud.       #+#    #+#             */
/*   Updated: 2024/06/04 21:46:32 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Last Modified: Sunday, 2nd June 2024 11:58:08 pm                           */
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
using std::cout;
using std::endl;

// PUBLIC METHODS //

void	Lexer::Tokenize()
{
	while(_position < _file.length())
	{
		int result = tryMatch();
		if (result == FOUND) {
			continue ;
		} 
		else if (result == NOT_FOUND) {
			string ill_char(1, _file[_position]);
			_errors.push_back(Error(errLex_illChar, ill_char, _lineNumber, _colNumber));
			updatePosition(ill_char);
		}
		else {
			_position++;
		}
	}
}

vector<Error>	Lexer::getErrors() const
{
	return (_errors);
}

// PRIVATE METHODS //

int		Lexer::tryMatch()
{
	int result;
	
	if ((result = matchNumber()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchIdentifier()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchWhitespace()) != NOT_FOUND) {
		return (result);
	}
	return (NOT_FOUND);
}

void	Lexer::updatePosition(const string &matched)
{
	for (char c : matched)
	{
		if (c == '\n') {
			_lineNumber++;
			_colNumber = 1;
		}
		else {
			_colNumber++;
		}
	}
}

void	Lexer::addToken(e_TokenType type, string data)
{
	_tokens.push_back(Token(type, data));
}

// DEBUG METHODS //

void	Lexer::ReadToken()
{
	int	i = 0;
	for (Token token : _tokens)
	{
		i++;
		cout << "Token " + std::to_string(i) + " | Type: " 
			+ std::to_string(token.getType()) + " : " + token.getData() + "\n";
	}
}

void	Lexer::readError()
{
	for (Error error : _errors)
	{
		cout << Error::FormatError(error) + "\n";
	}
}