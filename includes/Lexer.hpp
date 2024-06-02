/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: Lexer.hpp                                   */
/* Path: /includes/Lexer.hpp                                                  */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Saturday, 1st June 2024 11:18:38 pm                          */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Sunday, 2nd June 2024 11:56:31 pm                           */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include "Token.hpp"
#include "Error.hpp"

using std::vector;
using std::string;
using std::ifstream;

#define Tregex_number "[0-9]+(\\.[0-9]+)?"
#define Tregex_str "[0-9]*[a-z]*[A-Z]*"

class Lexer
{
private:
	ifstream file;
	size_t	_position;
	size_t	_colNumber;
	size_t	_lineNumber;
	vector<Token> _tokens;
	vector<Error> _errors;

public:
	Lexer() : _position(0), _colNumber(0), _lineNumber(0) {};
	~Lexer() = default;

	void			Tokenize(string file);
	string			ReadToken();
	
	vector<string>	getErrors();
};



#endif