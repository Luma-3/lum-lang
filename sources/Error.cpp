/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: Error.cpp                                   */
/* Path: /sources/Error.cpp                                                   */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Sunday, 2nd June 2024 4:34:10 pm                             */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Sunday, 9th June 2024 7:02:33 pm                            */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#include "Error.hpp"

#include <regex>

using std::regex;
using std::smatch;

const map<e_errType, string> Error::ErrorMsgMap = {
	{errLex_illChar, "Illegal character '{ctx}' at line {ln}, column {col}."},
	{errLex_undifineExp, "Undefined expression '{ctx}' start at line {ln}, column {col}. Expected a valid expression."},
	{errLex_invNumFormat, "Invalid number format '{ctx}' at line {ln}, column {col}. Number must be followed by a whitespace or an operator."},
	{errLex_invIdentifier, "Invalid identifier '{ctx}' at line {ln}, column {col}. Identifier must start with a letter or an underscore."},
	{errLex_stringNotClosed, "String not closed '{ctx}' at line {ln}, column {col}. String must be closed with a double quote."},
	{errLex_charNotClosed, "Character not closed '{ctx}' at line {ln}, column {col}. Character must be closed with a single quote."},
	{errLex_longCommentNotClosed, "Long comment not closed '{ctx}' at line {ln}, column {col}. Comment must be closed by '*/'."},
};

string	Error::getColum() const
{
	return (std::to_string(_col));
}

string	Error::getLine() const
{
	return (std::to_string(_ln));
}

string	Error::getContext() const
{
	return (_context);
}

string	Error::getValue(const string &key) const
{
	if (key == "ctx")	return getContext();
	if (key == "ln")	return getLine();
	if (key == "col")	return getColum();
	return ("");
}

string Error::FormatError(Error error)
{
	regex pattern("\\{\\w+\\}");
	smatch match;

	string msg = ErrorMsgMap.at(error._type);
	
	while (std::regex_search(msg, match, pattern)) {
		
		string placeholder = match.str();
		string key = placeholder.substr(1,placeholder.size() - 2);
		string value = error.getValue(key);
		
		msg.replace(match.position(), match.length(), value);
	}
	
	return (msg);
}
