/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManagerTest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:09:54 by jbrousse          #+#    #+#             */
/*   Updated: 2024/06/01 00:12:40 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

#include <FileManager.hpp>

TEST(FileManagerTest, addFile)
{
	FileManager fileManager;

	EXPECT_EQ(fileManager.AddFile("test.lum"), 0);
	EXPECT_EQ(fileManager.AddFile("test.txt"), 1);
}

TEST(FileManagerTest, getFile)
{
	FileManager fileManager;

	fileManager.AddFile("test.lum");
	EXPECT_EQ(fileManager.getFile(0), "test.lum");
	EXPECT_EQ(fileManager.getFile(1), "");
}

TEST(FileManagerTest, removeFile)
{
	FileManager fileManager;

	fileManager.AddFile("test.lum");
	EXPECT_EQ(fileManager.getFile(0), "test.lum");
	fileManager.RemoveFile(0);
	EXPECT_EQ(fileManager.getFile(0), "");
}

TEST(FileManagerTest, getExtension)
{
	FileManager fileManager;

	EXPECT_EQ(fileManager.getExtension("test.lum"), ".lum");
	EXPECT_EQ(fileManager.getExtension("test.txt"), ".txt");
}

TEST(FileManagerTest, openFile)
{
	FileManager fileManager;
	ifstream file1;
	ifstream file2;

	EXPECT_EQ(fileManager.OpenFile("../../tests/test.lum", file1), true);
	EXPECT_EQ(fileManager.OpenFile("../../tests/test.txt", file2), false);
}

TEST(FileManagerTest, getNbFiles)
{
	FileManager fileManager;

	EXPECT_EQ(fileManager.getNbFiles(), 0);
	fileManager.AddFile("test.lum");
	EXPECT_EQ(fileManager.getNbFiles(), 1);
}

/*main for Unit test of FileManager Class*/

int main(int ac, char **av)
{
	::testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}

// Path: test/FileManagerTest.cpp