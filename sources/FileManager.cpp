/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:50:39 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 23:07:46 by jbrousse         ###   ########.fr       */
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
