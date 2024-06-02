/* ************************************************************************** */
/*                                                                            */
/* Project: lum-lang    |   File: main.cpp                                    */
/* Path: /sources/main.cpp                                                    */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* File Created: Wednesday, 29th May 2024 5:33:11 pm                          */
/* Author: Jean-Baptiste Brousse (jb.brs@icloud.com)                          */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/*                                                                            */
/* Last Modified: Monday, 3rd June 2024 12:33:23 am                           */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */


#include <FileManager.hpp>

using std::string;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	string filename;
	FileManager fileManager;
	
	if (argc < 2)
	{
		cerr << "Error: no file provided" << endl;
		return (1);
	}
	filename = argv[1];
	try {
		fileManager.AddFile(filename);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	cout << "File added: " << fileManager.readFile(0) << endl;

	return (0);
}