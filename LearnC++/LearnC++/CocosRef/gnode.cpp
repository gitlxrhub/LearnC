#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "gnode.h"

gnode::gnode() {
	printf("gnode::gnode called\n");
}

gnode::~gnode() {
	printf("gnode::~gnode called\n");
}

gnode* gnode::create() {
	gnode* node = new gnode();
	node->autorelaese(); // ϵͳͳһ�ĵط��ͷ�,ͳһ��ʱ���ͷ� 
	return node;
}