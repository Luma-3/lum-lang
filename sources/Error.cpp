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
/* Last Modified: Sunday, 2nd June 2024 6:36:34 pm                            */
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

const map<e_errType, string> Error::errorMessage = {
	{errLex_illChar, "Illegal character '{ctx}' at line {ln}, column {col}."},
	{errLex_undifineExp, "Undefined expression '{ctx}' start at line {ln}, column {col}."},
	{errLex_invNumFormat, "Invalid number format '{ctx}' at line {ln}, column {col}."}
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

	string msg = errorMessage.at(error._type);
	
	while (std::regex_search(msg, match, pattern)) {
		
		string placeholder = match.str();
		string key = placeholder.substr(1,placeholder.size() - 2);
		string value = error.getValue(key);
		
		msg.replace(match.position(), match.length(), value);
	}
	
	return (msg);
}
