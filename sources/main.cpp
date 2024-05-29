/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:33:13 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 20:44:04 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include <FileManager.hpp>

using namespace std;

int main(int ac, char **av)
{
	string filename;
	FileManager fileManager;
	
	if (ac < 2)
	{
		cerr << "Error: no file provided" << endl;
		return (1);
	}
	filename = av[1];
	fileManager.addFile(filename);
	cout << "File added: " << fileManager.getFile(0) << endl;

	return (0);
}