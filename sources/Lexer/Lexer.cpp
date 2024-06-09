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
#include <iomanip>

using std::regex;
using std::smatch;
using std::cout;
using std::endl;
using std::setw;

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
			_position++;
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

	if ((result = matchComment()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchWhitespace()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchChar()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchString()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchNumber()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchIdentifier()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchDelimiter()) != NOT_FOUND) {
		return (result);
	}
	if ((result = matchOperator()) != NOT_FOUND) {
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
			if (c == '\t')
				_colNumber += 4;
			else if (c == '\r')
				_colNumber = 1;
			else
				_colNumber++;
		}
	}
}

void	Lexer::addToken(e_TokenType type, string data)
{
	_tokens.push_back(Token(type, data));
}

// DEBUG METHODS //

const map<e_TokenType, string> TokenName = {
	{e_TokenType::comment, "comment"},
	{e_TokenType::number, "number"},
	{e_TokenType::identifier, "identifier"},
	{e_TokenType::whitespace, "whitespace"},
	{e_TokenType::char_, "char"},
	{e_TokenType::str, "str"},
	{e_TokenType::operator_unary, "operator unary"},
	{e_TokenType::operator_binary, "operator binary"},
	{e_TokenType::operator_assignment, "operator assignment"},
	{e_TokenType::operator_comparison, "operator comparison"},
	{e_TokenType::operator_logical, "operator logical"},
	{e_TokenType::operator_bitwise, "operator bitwise"},
	{e_TokenType::keyword, "keyword"},
	{e_TokenType::lParen, "lParen"},
	{e_TokenType::rParen, "rParen"},
	{e_TokenType::lBrace, "lBrace"},
	{e_TokenType::rBrace, "rBrace"},
	{e_TokenType::lBracket, "lBracket"},
	{e_TokenType::rBracket, "rBracket"},
	{e_TokenType::semicolon, "semicolon"},
	{e_TokenType::comma, "comma"},
	{e_TokenType::arrow, "arrow"},
	{e_TokenType::colon, "colon"}
};


void Lexer::ReadToken()
{
	int i = 0;
	for (Token token : _tokens)
	{
		i++;
		std::cout << std::left << std::setw(10) << "Token " << setw(4) << i << " | " << std::left << setw(20) << TokenName.at(token.getType()) << " | " << setw(25) << (token.getData().length() >= 25 ? token.getData().substr(0, 24) + "." : token.getData()) << " | " << endl;
	}
}
void	Lexer::readError()
{
	for (Error error : _errors)
	{
		cout << Error::FormatError(error) + "\n";
	}
}