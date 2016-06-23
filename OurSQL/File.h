#pragma once
#include <cstdio>
#include <set>
#include "Block.h"
#define MAX_FILENAME_LENGTH 64

/* �ļ��ṹ
** ------------
** |   FCB    | 4k
** ------------
** | Block #1 | 4k
** ------------
** | Block #2 | 4k
** ------------
** | Block #3 | 4k
** ------------
** | Block #4 | 4k
** ------------
** | Block ...| 4k
** ------------
** FCB�ṹ
** ---------------------------------------------------------------------------------------------------------
** |First Data Block|Last Data Block|First Free Block|Last Free Block|Data Block Count|Total Block Count|...
** ---------------------------------------------------------------------------------------------------------
** 0                4               8                12              16               20                24
** ����ÿ��Block�л������һ��Block��ָ��,���ֻ���¼��һ������/����Block��ָ�뼴�ɡ�
** ÿһ��Block����������,Ҳ����Ϊ����Block, Block����֤�������
** ��Block����,ָ��Block��ָ��ʵ����һ������ļ�ͷ��ƫ�ƿ���
** �й�Block����֯�ṹ����"Block.h"
*/
class File
{
public:
	File(const char*);
	static void initFile(const char*);
	~File();
	// ���ļ�ָ�붨�򵽵�offest��
	void filePtChangeTo(uint offest);
	Block* addNewBlock();
	void removeBlock(Block *, uint front);
	Block* readBlock(uint offest);
	void writeToFile(Block *);
	void showFile();
	const char* getFileName();
	void addRecord(byte* head, uint length);
	void removeRecord(uint bno, uint index);
	uint getHead();
private:
	FILE *filePt;
	uint firstDataBlock;
	uint firstFreeBlock;
	uint lastDataBlock;
	uint lastFreeBlock;
	uint dataBlockCount;
	uint totalBlockCount;

	const char *fileName;
	// �޸�Block��nextָ��
	void setNextOffest(Block *, uint offest);
	// ���ܹ����record�����ݿ�
	std::set<uint>hasFreeBlock;
};

