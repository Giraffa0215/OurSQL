#pragma once
#include <cstdio>
#include "Block.h"
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
** ---------------------------------------------------
** |First Data Block|First Free Block|Block Count|...|
** ---------------------------------------------------
** 0                4                8           12
** ����ÿ��Block�л������һ��Block��ָ��,���ֻ���¼��һ������/����Block��ָ�뼴�ɡ�
** ÿһ��Block����������,Ҳ����Ϊ����Block, Block����֤�������
** ��Block����,ָ��Block��ָ��ʵ����һ������ļ�ͷ��ƫ�ƿ���
** �й�Block����֯�ṹ����"Block.h"
*/
class File
{
public:
	File(const char*);
	~File();
	// ���ļ�ָ�붨�򵽵�offest��
	void filePtChangeTo(uint offest);
private:
	FILE *filePt;
	uint firstDataBlock;
	uint firstFreeBlock;
	uint blockCount;
};

