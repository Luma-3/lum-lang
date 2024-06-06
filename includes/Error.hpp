/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: Error.hpp                                   */
/* Path: /includes/Error.hpp                                                  */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Sunday, 2nd June 2024 3:15:27 pm                             */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Thursday, 6th June 2024 11:25:44 pm                         */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

#include <map>
#include <string>

using std::map;
using std::string;

enum	e_errType
{
	errLex_illChar,
	errLex_undifineExp,
	errLex_invNumFormat,
	errLex_invIdentifier
};

class Error
{
public:

	Error(e_errType type, string ctx, size_t ln, size_t col)
		: _type(type), _context(ctx), _ln(ln), _col(col) {}
	~Error() = default;

	string			getColum() const;
	string			getLine() const;
	string			getContext() const;
	
	string			getValue(const string &key) const;

	static string	FormatError(Error error);

private:

	static const map<e_errType, string> errorMessage;
	const e_errType	_type;
	const string	_context;
	const size_t	_ln;
	const size_t	_col;
};

#endif