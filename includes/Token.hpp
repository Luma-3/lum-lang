/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: Token.hpp                                   */
/* Path: /includes/Token.hpp                                                  */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Saturday, 1st June 2024 8:58:31 pm                           */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Saturday, 8th June 2024 2:27:17 pm                          */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */


#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <string>
#include <map>

using std::string;
using std::map;

enum e_TokenType
{
	identifier,
	number,
	str,
	whitespace
};

const map<e_TokenType, string> TokenRegexes = {
	{identifier, "[a-zA-Z_][a-zA-Z0-9_]*"},
	{number, "[0-9]+(\\.[0-9]+)?"},
	{str, "\"[^\"]*\""},
	{whitespace, "[ \t\n]+"}
};

class Token
{
private:
	e_TokenType _type;
	string _data;
	
public:
	Token(e_TokenType type, string data);
	~Token() = default;

	string		getData();
	e_TokenType		getType();
};


#endif