/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: Token.cpp                                   */
/* Path: /sources/Token.cpp                                                   */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Saturday, 1st June 2024 9:27:17 pm                           */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Thursday, 6th June 2024 5:56:19 pm                          */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Token.hpp"

using std::string;

Token::Token(e_TokenType type, string data)
{
	_type = type;
	_data = data;
}

string	Token::getData()
{
	return (_data);
}

e_TokenType	Token::getType()
{
	return (_type);
}
