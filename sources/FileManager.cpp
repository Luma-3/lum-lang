/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: FileManager.cpp                             */
/* Path: /sources/FileManager.cpp                                             */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Wednesday, 29th May 2024 6:50:38 pm                          */
/* Author: Jean-Baptiste Brousse (luma3.brs@gmail.com)                        */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Saturday, 1st June 2024 4:43:53 pm                          */
/* Modified By: Jean-Baptiste Brousse (luma3.brs@gmail.com>)                  */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/*                                                                            */
/* ************************************************************************** */

#include <FileManager.hpp>

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;

string FileManager::getExtension(string const &filename)
{
	size_t pos = filename.find_last_of('.');
	if (pos == string::npos) {
		return ("");
	}
	return (filename.substr(pos));
}

int FileManager::AddFile(string const &filename)
{
	if (getExtension(filename) != ".lum")
	{
		cerr << "Error: file must be a .lum file" << endl;
		return (1);
	}
	_files.push_back(filename);
	return (0);
}

void FileManager::RemoveFile(size_t index)
{
	if (index >= _files.size())
	{
		cerr << "Error: index out of range" << endl;
		return ;
	}
	_files.erase(_files.begin() + static_cast<int64_t>(index));
}

bool FileManager::OpenFile(string const &filename, ifstream &file)
{	
	file.open(filename);
	try {
		if (!file.is_open())
		{
			throw "Error: could not open file";
		}
	} catch (const char *e) {
		cerr << e << endl;
		return (false);
	}
	return (true);
}

string FileManager::getFile(size_t index) const
{
	if (index >= _files.size())
	{
		cerr << "Error: index out of range" << endl;
		return ("");
	}
	return (_files[index]);
}

size_t FileManager::getNbFiles() const
{
	return (_files.size());
}
