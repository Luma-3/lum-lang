/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManager.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:57:55 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 23:07:57 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSER_HPP
# define ARG_PARSER_HPP

#include <vector>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;

class FileManager
{
	
private:
	vector<string> _files;

public:
	FileManager() = default;
    ~FileManager() = default;

	int			AddFile(string const &filename);
	void		RemoveFile(size_t index);
	bool 		OpenFile(string const &filename, ifstream &file);

	string		getFile(size_t index) const;
	string		getExtension(string const &filename);
	size_t		getNbFiles() const;
};

#endif