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
	node->autorelaese(); // 系统统一的地方释放,统一的时期释放 
	return node;
}