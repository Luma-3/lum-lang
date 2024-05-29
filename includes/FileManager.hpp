/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:57:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 20:41:01 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_HPP
# define ARG_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileManager
{
	
private:
	vector<string> _files;

public:
	FileManager();
	~FileManager();

	int			addFile(string filename);
	void		removeFile(size_t index);

	string		getExtension(string filename);
	ifstream	openFile(string filename);
	string		getFile(size_t index) const;
	size_t		getNbFiles() const;
};

#endif