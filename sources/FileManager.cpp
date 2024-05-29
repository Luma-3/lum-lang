/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:50:39 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 20:40:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include <FileManager.hpp>

using namespace std;

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}


string FileManager::getExtension(string filename)
{
	size_t pos = filename.find_last_of(".");
	if (pos == string::npos)
		return ("");
	return (filename.substr(pos));
}

int FileManager::addFile(string filename)
{
	if (getExtension(filename) != ".lum")
	{
		cerr << "Error: file must be a .lum file" << endl;
		return (1);
	}
	_files.push_back(filename);
	return (0);
}

void FileManager::removeFile(size_t index)
{
	if (index >= _files.size())
	{
		cerr << "Error: index out of range" << endl;
		return ;
	}
	_files.erase(_files.begin() + index);
}

ifstream FileManager::openFile(string filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Error: could not open file " << filename << endl;
		return (file);
	}
	return (file);
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
