#pragma once
#include "BufferMgr.h"
#include "CategoryMgr.h"
#include "File.h"
#include "Table.h"
extern BufferMgr databaseBuffer;
extern CategoryMgr databaseCategory;
extern std::string curDatabase;
void notFindException(char* cmd, void* par);


/* newblock filename
** ��filename���һ�����ļ���
*/
void newBlock(char*cmd, void *par);

void showBuffer(char*cmd, void *par);

// �ݲ���ʹ��
void showBlock(char*cmd, void *par);

/* addrecord filename blocknum recordnum
** ��filename�ĵ�blocknum��ɾ����recordnum����¼
*/
void removeRecord(char*cmd, void *par);

/* newfile filename
** ��ʽ��һ�������ļ�filename
*/
void newFile(char*cmd, void *par);

/* showfile filename
** ��ӡ�����ļ�filename
*/
void showFile(char *cmd, void *par);

/* removeblock filename blocknum front
** ɾ�������ļ�filename�ĵ�blocknum�飬frontΪ��ɾ�����ǰһ��
*/
void removeBlock(char *cmd, void *par);

/*����һ��table*/
void createTable(char *cmd, void *par);

/*��ӡ��ṹ*/
void showTableStructure(char *cmd, void *par);

/*����record*/
void createRecord(char *cmd, void *par);

void createDatabase(char *cmd, void *par);

void removeDatabase(char *cmd, void *par);

void showDatabase(char*cmd, void *par);

void leaveDatabase(char *cmd, void *par);

void enterDatabase(char *cmd, void *par);

void removeTable(char *cmd, void *par);

void showAllTable(char *cmd, void *par);

void insertRecord(char *cmd, void *par);