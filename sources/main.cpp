/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:33:13 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 23:01:53 by jbrousse         ###   ########.fr       */
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