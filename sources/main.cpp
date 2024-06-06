/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by brs@icloud.       #+#    #+#             */
/*   Updated: 2024/06/04 21:41:30 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Last Modified: Monday, 3rd June 2024 12:33:23 am                           */
/* Modified By: Jean-Baptiste Brousse (jb.brs@icloud.com>)                    */
/* Aka: jbrousse | Luma-3                                                     */
/*                                                                            */
/* -------------------------------------------------------------------------- */
/* License: GNU General Public License v3.0 only                              */
/* License URL: https://www.gnu.org/licenses/gpl-3.0-standalone.html          */
/* ************************************************************************** */


#include <FileManager.hpp>
#include <Lexer.hpp>

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
	Lexer lexer(fileManager.readFile(0));
	lexer.Tokenize();
	lexer.ReadToken();
	lexer.readError();
	return (0);
}