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
/* Last Modified: Saturday, 1st June 2024 9:35:51 pm                          */
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

using std::string;

enum e_type
{
	struct_type,
	end_struct,
	option,
	delimiter,
	type,
	identifier,
	number,
	str,
	un_op,
	bin_op,
	assign
};

class Token
{
private:
	e_type _type;
	string _data;
	
public:
	Token(e_type type, string data);
	~Token() = default;

	string		getData();
	e_type		getType();
};


#endif