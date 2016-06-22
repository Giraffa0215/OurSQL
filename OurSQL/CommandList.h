#pragma once
#include "BufferMgr.h"
#include "File.h"
#include "Table.h"
extern BufferMgr buffer;
void notFindException(char* cmd, void* par);

void exitCommand(char* cmd, void *par);

/* newblock filename
** ��filename���һ�����ļ���
*/
void newBlock(char*cmd, void *par);

void showBuffer(char*cmd, void *par);

// �ݲ���ʹ��
void useBlock(char*cmd, void *par);

// �ݲ���ʹ��
void showBlock(char*cmd, void *par);

/* addrecord filename blocknum record
** ��filename�ĵ�blocknum�����һ����¼
*/
void addRecord(char*cmd, void *par);

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

void print(char *cmd, void *par);

/*����һ��table*/
void createTable(char *cmd, void *par);

/*��ӡ��ṹ*/
void showTableStructure(char *cmd, void *par);