#pragma once
#include "Block.h"
#include <vector>
#include <map>
#include <list>
#define MAX_BLOCK_SIZE 4

class BufferMgr
{
public:
	BufferMgr();
	~BufferMgr();
	void addBlock(Block *);
	void removeBlock(int);
	Block* getBlock(int);
	int getAndReleaseLruBlock();

	void showBlock();
private:
	Block *block[MAX_BLOCK_SIZE];
	int curSize;

	// ��ſ��п��������е����
	std::vector<int> freeList;

	// �����BufferMgr�ڲ���ŵĶ�Ӧ��ϵ
	std::map<int, int>numMap;

	// LRU�б�
	std::list<int>leastList;

	// block��LRU�б��еĶ�Ӧָ��
	std::map<int, std::list<int>::iterator>leastAddr;
};
