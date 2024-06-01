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
/* Last Modified: Saturday, 1st June 2024 9:36:04 pm                          */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Token.hpp"

using std::string;

Token::Token(e_type type, string data)
{
	_type = type;
	_data = data;
}

string	Token::getData()
{
	return (_data);
}

e_type	Token::getType()
{
	return (_type);
}
