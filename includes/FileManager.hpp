/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: FileManager.hpp                             */
/* Path: /includes/FileManager.hpp                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Wednesday, 29th May 2024 6:57:54 pm                          */
/* Author: Jean-Baptiste Brousse (luma3.brs@gmail.com)                        */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Saturday, 1st June 2024 4:44:43 pm                          */
/* Modified By: Jean-Baptiste Brousse (luma3.brs@gmail.com>)                  */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_HPP
# define ARG_PARSER_HPP

#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;

class FileManager
{
	
private:
	vector<string> _files;

public:
	FileManager() = default;
    ~FileManager() = default;

	int			AddFile(string const &filename);
	void		RemoveFile(size_t index);
	bool 		OpenFile(string const &filename, ifstream &file);

	string		getFile(size_t index) const;
	string		getExtension(string const &filename);
	size_t		getNbFiles() const;
};

#endif