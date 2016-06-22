#pragma once
#include <cstdio>
#include <string>
#include <vector>
#include <map>

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
	bool removeDataBase(std::string dbName);
	bool removeTable(std::string dbName, std::string tableName);
private:
	std::map<std::string, std::vector<std::string>>database;
};

