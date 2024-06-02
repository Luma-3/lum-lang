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

	fileManager.AddFile("test.lum");
	ASSERT_EQ(fileManager.getFilePath(0), "test.lum");
	ASSERT_THROW(fileManager.AddFile("test.txt"), std::invalid_argument);
}

TEST(FileManagerTest, removeFile)
{
	FileManager fileManager;

	fileManager.AddFile("test.lum");
	EXPECT_EQ(fileManager.getFilePath(0), "test.lum");
	fileManager.RemoveFile(0);
	EXPECT_THROW(fileManager.getFilePath(0), std::out_of_range);
}

TEST(FileManagerTest, getExtension)
{
	FileManager fileManager;

	EXPECT_EQ(fileManager.getExtension("test.lum"), ".lum");
	EXPECT_EQ(fileManager.getExtension("test.txt"), ".txt");
}

TEST(FileManagerTest, readFile)
{
	FileManager fileManager;

	fileManager.AddFile("../../tests/test.lum");
	EXPECT_EQ(fileManager.readFile(0), "test.lum");
	EXPECT_THROW(fileManager.readFile(1), std::out_of_range);
	fileManager.AddFile("test.lum"); // Invalid file
	EXPECT_THROW(fileManager.readFile(1), std::runtime_error);
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
