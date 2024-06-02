/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: FileManager.cpp                             */
/* Path: /sources/FileManager.cpp                                             */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Wednesday, 29th May 2024 6:50:38 pm                          */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Monday, 3rd June 2024 12:31:13 am                           */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */


#include "FileManager.hpp"

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

void FileManager::AddFile(string const &filename)
{
	if (getExtension(filename) != ".lum")
	{
		throw std::invalid_argument("file " + getExtension(filename) + " is not support");
	}
	_filePaths.push_back(filename);
}

void FileManager::RemoveFile(size_t index)
{
	if (index >= _filePaths.size())
	{
		throw std::out_of_range("Invalid index");
	}
	_filePaths.erase(_filePaths.begin() + static_cast<int64_t>(index));
	
}

string FileManager::getFilePath(size_t index) const
{
	if (index >= _filePaths.size())
	{
		throw std::out_of_range("Invalid index " + std::to_string(index) + " >= " + std::to_string(_filePaths.size()));
	}
	return (_filePaths[index]);
}

string FileManager::readFile(size_t index) const
{
	string file_path;
	
	try {
		file_path = getFilePath(index);
	} catch (const std::out_of_range& e) {
		throw std::runtime_error("Read file index: " + std::string(e.what()));
	}
	ifstream file(file_path, std::ios::binary | std::ios::ate);
	if (!file.is_open()) {
		throw std::runtime_error("Unable to open file");
	}
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);
	
	string buffer(size, '\0');
	file.read(&buffer[0], size);
	file.close();

	return (buffer);
}

size_t FileManager::getNbFiles() const
{
	return (_filePaths.size());
}
