#include "CommandList.h"
#include <cstdio>

// �ڴ�ע������
void(*_commandFunctionList[])(char*, void*)
= {
	notFindException,
	exitCommand,
	newBlock,
	useBlock,
	showBuffer,
	showBlock,
	addRecord,
	removeRecord
};

char * _commandNameList[]
= {
	"",
	"exit",
	"newblock",
	"useblock",
	"showbuffer",
	"showblock",
	"addrecord",
	"removerecord"
};

int _commandList_length = 7;


void notFindException(char* cmd, void* par)
{
	printf("%s is not a correct command.\n", cmd);
}

void exitCommand(char* cmd, void *par)
{
	printf("Close the window to exit.\n");
}

void newBlock(char*cmd, void *par)
{
	buffer.addBlock(new Block(atoi((char *)par)));
}

void useBlock(char*cmd, void *par)
{
	if (buffer.getBlock(atoi((char *)par)) == nullptr)
		printf("Block not exist!\n");
}

void showBuffer(char*cmd, void *par)
{
	buffer.showBlock();
}

void showBlock(char*cmd, void *par)
{
	int bno = atoi((char *)par);
	buffer.getBlock(bno)->showBlock();
}

void addRecord(char*cmd, void *par)
{
	char *str = (char*)par;
	int bno;
	char record[100];
	sscanf(str, "%d %s", &bno, record);
	Record *rec = new Record(record);
	buffer.getBlock(bno)->addRecord(rec);
	delete rec;
}

void removeRecord(char*cmd, void *par)
{
	char *str = (char*)par;
	int bno, rindex;
	sscanf(str, "%d %d", &bno, &rindex);
	buffer.getBlock(bno)->removeRecord(rindex);
}