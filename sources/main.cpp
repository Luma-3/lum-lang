/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: main.cpp                                    */
/* Path: /sources/main.cpp                                                    */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Wednesday, 29th May 2024 5:33:11 pm                          */
/* Author: Jean-Baptiste Brousse (luma3.brs@gmail.com)                        */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Saturday, 1st June 2024 4:44:26 pm                          */
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

int main(int argc, char **argv)
{
	string filename = "";
	FileManager fileManager;
	
	if (argc < 2)
	{
		cerr << "Error: no file provided" << endl;
		return (1);
	}
	filename = argv[1];
	fileManager.AddFile(filename);
	cout << "File added: " << fileManager.getFile(0) << endl;

	return (0);
}