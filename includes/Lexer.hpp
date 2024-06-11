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
/* Last Modified: Tuesday, 11th June 2024 7:29:33 pm                          */
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
using std::regex;

#define ERROR -1
#define FOUND 1
#define NOT_FOUND 0

class Lexer
{
private:
	// File to tokenize
	string	_file;
	
	// Position in the file
	size_t	_position;
	size_t	_colNumber;
	size_t	_lineNumber;

	// Token and Error vectors
	vector<Token> _tokens;
	vector<Error> _errors;

	// Cache for regex matches
	std::smatch _currentMatch;

	// Generic regex matcher
	bool	matchRegex(const regex &regex);
	
	// Regex matchers
	int		matchNumber(void);
	int		matchIdentifier(void);
	int		matchWhitespace(void);
	int		matchString(void);
	int		matchChar(void);

	// Static matchers
	bool	matchKeyword(const string &str);
	bool	matchDelimiter(void);
	bool	matchOperator(void);
	bool	matchComment(void);
	
	
	void	updatePosition(const string &matched);
	void 	addToken(e_TokenType type, string data);
	int		tryMatch();

	// Error handlers

	int		invalidNumber(void);

public:
	Lexer(string file) : _file(file), _position(0), _colNumber(1), _lineNumber(1) {};
	~Lexer() = default;

	void			Tokenize(void);
	vector<Error>	getErrors() const;
	vector<Token>	getTokens() const;
	
	// DEBUG METHODS //
	void			ReadToken();
	void			readError();
};

int		is_valid_number(char c);

#endif