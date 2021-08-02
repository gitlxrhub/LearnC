#ifndef __G_NODE_H__
#define __G_NODE_H__

#include "ref_object.h"

class gnode : public ref_object {
public:
	gnode();
	~gnode();
public:
	static gnode* create(); // 构造创建函数
};
#endif

