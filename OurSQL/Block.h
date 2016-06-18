#pragma once
#include <cstdio>
#include "Record.h"
#define BLOCK_SIZE 4096
#define UINT_SIZE sizeof(uint)
#define USHORT_SIZE sizeof(ushort)
typedef char byte;
typedef unsigned int uint;
typedef unsigned short int ushort;

/*
** Block �Ľṹ
** -----------------------------------------------------------------------------------------------------------
** |Next|Count|Free|Record1.Length|Record1.Pointer|Record2...|..Free Space..|Record n|Record n-1|...|Record 1|
** -----------------------------------------------------------------------------------------------------------
** 0    4     6    8              10              12
** 4�ֽڴ�С��Ϊuint, 2�ֽڴ�С��Ϊushort
** һ����ԣ��ⲿ��ָ��ռ4�ֽڣ����ڲ�ָ��/�ڲ���Сռ2�ֽ�
** �ڲ�ָ��ʵ����һ������ڿ�ͷ��ƫ����
*/
class Block
{
public:
	Block(uint);
	Block(uint, byte*);
	~Block();
	uint getBlockNum();

	// ���е���Ϣ
	const byte* getBlockAddr();
	uint getNextBlockOffset();
	ushort getRecordCount();

	// Record����
	bool canAddRecord(Record*);
	bool addRecord(Record*);
	byte* getRecordData(ushort index);
	ushort getRecordLength(ushort index);
	bool removeRecord(ushort index);

	ushort& setNext();
	void clear();
	bool isModified();
	void modify();
	byte* getHead();

	void showBlock();
private:
	uint blockNum;
	byte *head;
	bool modified;

	ushort getFree();
	ushort getRecordPointer(ushort index);
	ushort& setFree();
	ushort& setRecordCount();
	ushort& setRecordLength(ushort index);
	ushort& setRecordPointer(ushort index);

};

