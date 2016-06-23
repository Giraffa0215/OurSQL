#pragma once
#include <cstdio>
#include <string>
#include <set>
#include <map>
#define CATGORY_NAME "OurSQL.cat"
/*
ourSQL.cat�ļ��Ľṹ
��һ����һ������n ��ʾһ����n�����ݿ�
��������n��
ÿ������һ��string,��ʾ���ݿ���
������һ������m����ʾ������ݿ���m����
��������m��string���ֱ��ʾ��m���������
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

