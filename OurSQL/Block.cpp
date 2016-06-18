#include "Block.h"
#include <cstring>

Block::Block(uint _blockNum) :blockNum(_blockNum)
{
	head = new byte[BLOCK_SIZE];
	memset(head, 0, sizeof(byte)*BLOCK_SIZE);
	setFree() = BLOCK_SIZE;
	modified = true;
}

Block::Block(uint bno, byte * _head) :blockNum(bno), head(_head)
{
	modified = false;
}


Block::~Block()
{
}

uint Block::getBlockNum()
{
	return blockNum;
}

bool Block::canAddRecord(Table *r)
{
	ushort top = UINT_SIZE + 2 * USHORT_SIZE + 2 * USHORT_SIZE * getRecordCount();
	return (top + 2 * USHORT_SIZE <= getFree() - r->getLength());
}

bool Block::addRecord(Table *r)
{
	if (!canAddRecord(r))	return false;
	modify();
	// ����head���ֵ�length
	setRecordLength(getRecordCount()) = r->getLength();
	// ������пռ�
	ushort pos = getFree() - r->getLength();
	// ����ָ��
	setRecordPointer(getRecordCount()) = pos;
	byte *p = head + pos;
	// ��������
	strncpy(p, r->getData(), r->getLength());
	// ����Freeָ��
	setFree() -= r->getLength();
	setRecordCount()++;
	return true;
}

byte * Block::getRecordData(ushort index)
{
	if (index >= getRecordCount())	return nullptr;
	return head + getRecordPointer(index);
}

ushort Block::getRecordLength(ushort index)
{
	return setRecordLength(index);
}

bool Block::removeRecord(ushort index)
{
	if (index >= getRecordCount())	return false;
	modify();
	int recordLength = getRecordLength(index);
	// ɾ�����һ�鲻��Ҫ�ƶ�
	if (index != getRecordCount() - 1) {
		//��index���������ָ��ռ�������,ָ���Records����������,����Freeָ��
		byte *last = head + getRecordPointer(index) + recordLength;
		for (int i = index + 1; i < getRecordCount(); i++) {
			int curRecordLength = getRecordLength(i);
			// ָ��λ������
			setRecordLength(i - 1) = curRecordLength;
			setRecordPointer(i - 1) = getRecordPointer(i) + recordLength;

			// Record����
			byte* buffer = new byte[curRecordLength];
			strncpy(buffer, getRecordData(i), curRecordLength);
			last -= curRecordLength;
			strncpy(last, buffer, curRecordLength);
			delete[] buffer;
		}
	}
	//����Freeָ��
	setFree() += recordLength;
	setRecordCount()--;
	return true;
}

ushort & Block::setNext()
{
	modify();
	return *(ushort *)head;
}

void Block::clear()
{
	setFree() = BLOCK_SIZE;
	setRecordCount() = 0;
	setNext() = 0;
}

bool Block::isModified()
{
	return modified;
}

const byte * Block::getBlockAddr()
{
	return (const byte*)head;
}

void Block::modify()
{
	modified = true;
}

byte * Block::getHead()
{
	return head;
}

void Block::showBlock()
{
	printf("BlockNum: #%d, count: %d\n", blockNum, getRecordCount());
	printf("%3s|%7s|%10s\n", "no", "length", "record");
	for (int i = 0; i < getRecordCount(); i++) {
		byte * s = new byte[getRecordLength(i) + 1];
		strncpy(s, getRecordData(i), getRecordLength(i));
		s[setRecordLength(i)] = 0;
		printf("%3d|%7d|%10s\n", i, getRecordLength(i), s);
		delete[] s;
	}
}

ushort& Block::setFree()
{
	return *(ushort *)(head + UINT_SIZE + USHORT_SIZE);
}

ushort Block::getFree()
{
	return setFree();
}

ushort Block::getRecordPointer(ushort index)
{
	return setRecordPointer(index);
}

ushort & Block::setRecordCount()
{
	return *(ushort *)(head + UINT_SIZE);
}

ushort & Block::setRecordLength(ushort index)
{
	return *(ushort *)(head + UINT_SIZE + 2 * USHORT_SIZE + index * 2 * USHORT_SIZE);
}

ushort & Block::setRecordPointer(ushort index)
{
	return *(ushort *)(head + UINT_SIZE + 3 * USHORT_SIZE + index * 2 * USHORT_SIZE);
}

uint Block::getNextBlockOffset()
{
	return *(uint *)(head);
}

ushort Block::getRecordCount()
{
	return setRecordCount();
}
