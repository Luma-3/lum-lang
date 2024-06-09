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
/* Last Modified: Sunday, 9th June 2024 7:49:57 pm                            */
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
	char_,
	whitespace,
	keyword,
	operator_unary,
	operator_binary,
	operator_assignment,
	operator_comparison,
	operator_logical,
	operator_bitwise,
	lParen,
	rParen,
	lBrace,
	rBrace,
	lBracket,
	rBracket,
	semicolon,
	comma,
	arrow,
	colon,
	comment
};

const map<e_TokenType, string> TokenRegexes = {
	{identifier, "[a-zA-Z_][a-zA-Z0-9_]*"},
	{number, "[0-9]+(\\.[0-9]+)?"},
	{str, "\"[^\"]*\""},
	{char_, "'[^']'"},
	{whitespace, "[ \t\n]+"}
};

const map<string, bool> TokenKeywords = {
	{"func", true},
	{"if", true},
	{"else", true},
	{"while", true},
	{"for", true},
	{"return", true},
	{"break", true},
	{"continue", true},
	{"true", true},
	{"false", true},
	{"null", true},
	{"void", true},
	{"int", true},
	{"float", true},
	{"string", true},
	{"bool", true},
	{"char", true},
	{"struct", true},
	{"enum", true},
	{"typedef", true},
	{"extern", true},
	{"static", true},
	{"const", true},
	{"volatile", true}
	// {"register", true},
	// {"auto", true},
	// {"inline", true},
	// {"restrict", true},
	// {"sizeof", true}
};

const map<string, e_TokenType> TokenDelimiters = {
	{"(", lParen},
	{")", rParen},
	{"{", lBrace},
	{"}", rBrace},
	{"[", lBracket},
	{"]", rBracket},
	{";", semicolon},
	{",", comma},
	{"->", arrow},
	{":", colon}
};

const map<string, e_TokenType> TokenOperators = {
	// Arithmetic operators
	{"++", operator_unary},
	{"--", operator_unary},
	
	{"+", operator_binary},
	{"-", operator_binary},
	{"*", operator_binary},
	{"/", operator_binary},
	{"%", operator_binary},

	// Bitwise operators
	{"&", operator_bitwise},
	{"|", operator_bitwise},
	{"^", operator_bitwise},
	{"~", operator_bitwise},
	{"<<", operator_bitwise},
	{">>", operator_bitwise},
	
	// Logical operators
	{"&&", operator_logical},
	{"||", operator_logical},
	{"!", operator_logical},

	// Comparison operators
	{"==", operator_comparison},
	{"!=", operator_comparison},
	{"<", operator_comparison},
	{">", operator_comparison},
	{"<=", operator_comparison},
	{">=", operator_comparison},
	
	// Assignment operators
	{"=", operator_assignment},
	{"+=", operator_assignment},
	{"-=", operator_assignment},
	{"*=", operator_assignment},
	{"/=", operator_assignment},
	{"%=", operator_assignment},
	{"&=", operator_assignment},
	{"|=", operator_assignment},
	{"^=", operator_assignment},
	{"<<=", operator_assignment},
	{">>=", operator_assignment},
	{"~=", operator_assignment},

	// Other operators TODO (ternary, null-coalescing, etc.)
	// {".", },
	// {"...", },
	// {"?", },
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