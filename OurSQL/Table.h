#pragma once
#include <cstdio>
#include <vector>
#include "Column.h"

typedef char byte;
typedef unsigned short int ushort;
//enum CONDITION {GREAT,LESS,EQUAL};
/* Table���ļ��еĽṹ
** -------------------------------------------------------
** |                          TCB                        | 64 bytes
** -------------------------------------------------------
** |Conlum 1 data type|Conlum 1 data length|Conlum 1 name| 64 bytes
** -------------------------------------------------------
** |Conlum 2 data type|Conlum 2 data length|Conlum 2 name| 64 bytes
** -------------------------------------------------------
** |Conlum 3 data type|Conlum 3 data length|Conlum 3 name| 64 bytes
** -------------------------------------------------------
** |Conlum n data type|Conlum n data length|Conlum n name| 64 bytes
** -------------------------------------------------------
** 0                  1                    3             63
** --------------
** |Conlum Count|
** --------------
** 0            2
** data typeΪһ��byte���ͣ�data lengthΪһ��ushort����
** ����һ���С4K��Ϊ��ʹ�����ܹ�����һ����¼�����data length�ĺͲ��ܳ���4k(4084 bytes)
** �й�Block����֯�ṹ����"Block.h"
**
** Record�Ľṹ
** -------------------------------------------------------------------------------------------------------------------------------
** |Variable-Data 1 pointer|Variable-Data 1 length|VarData 2 pt|VarData 2 len|...|FixData 1|FixData 2|...|VarData 1|VarData 2|...|
** -------------------------------------------------------------------------------------------------------------------------------
** һ���ɱ䳤�ȵ�����ָ��ռ2�ֽ�,����ռ2�ֽ�
** ָ����record�ڵ�ƫ����
*/
class Table
{
public:
	Table(const char *);
	static void initTable(const char *, std::vector<Column>);
	~Table();
	static bool structTable(std::vector<Column> _tableStructure, FILE*);
	void showTableStructure();
	byte* parseRecord(byte* record, ushort index);
	byte* formRecord(std::vector<byte*>&, int&);
	byte* getColumnData(ushort index);
	int getColumnSize();
	int compareRecord(byte* record, byte* conditionData, int dataPostion);
	void printTitle();
	void printRecord(byte* record);
	static int condition(int, char ch);
private:
	FILE *fileName;
	std::vector<ushort> variableAttributePosition;
	int fixedLength;
	std::vector<Column*> tableStructure;
};

