#pragma once
#include <cstdio>
#include <string>
#include <set>
#include <map>
#define CATGORY_NAME "OurSQL.cat"
/*
ourSQL.cat文件的结构
第一行是一个整数n 表示一共有n个数据库
接下来有n组
每组首先一个string,表示数据库名
接下来一个整数m，表示这个数据库有m个表
接下来有m个string，分别表示这m个表的名字
*/

class CategoryMgr
{
public:
	CategoryMgr();
	~CategoryMgr();
	bool addDataBase(std::string dbName);
	bool addTable(std::string dbName, std::string tableName);
	bool existDataBase(std::string dbName);
	bool existTable(std::string dbName, std::string tableName);
	bool removeDataBase(std::string dbName);
	bool removeTable(std::string dbName, std::string tableName);
	void showDatabase();
	bool showTable(std::string dbName);
	static std::string* makePath(const char*,const char*,const char*);
private:
	std::map<std::string, std::set<std::string>>database;
};

