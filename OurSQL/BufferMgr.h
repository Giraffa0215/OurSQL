#pragma once
#include <vector>
#include <map>
#include <list>
#include "Block.h"
#include "bufferId.h"
#define MAX_BLOCK_SIZE 4

class BufferMgr
{
public:
	BufferMgr();
	~BufferMgr();
	void addBlock(const char*, Block *);
	void removeBlock(uint);
	Block* getBlock(const char*, uint);
	int getAndReleaseLruBlock();
	void clear();
	void showBlock();
	bool switchLog();
private:
	Block *block[MAX_BLOCK_SIZE];
	bufferId *blockInfo[MAX_BLOCK_SIZE];
	int curSize;
	bool logRecord;
	// �����BufferMgr�ڲ���ŵĶ�Ӧ��ϵ
	std::map<bufferId, int>numMap;

	// LRU�б�
	std::list<int>leastList;

	// block��LRU�б��еĶ�Ӧָ��
	std::map<int, std::list<int>::iterator>leastAddr;
};

