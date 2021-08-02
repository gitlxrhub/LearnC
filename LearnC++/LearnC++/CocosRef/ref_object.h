#ifndef __REF_OBJECT_H__
#define __REF_OBJECT_H__

// 1:针对的在堆上的内存管理，所以，凡是继承了ref_object的对象
// 只能通过堆来实例化。

class ref_object {
public:
	ref_object();
	virtual ~ref_object(); // 因为需要通过基类的指针来释放子类的实力，所以我们需要将基类的析构函数定义成虚函数
private:
	int ref_count;
public:
	void retain();
	void release();
	void autorelaese(); // 将这个节点，放入到自动释放池里面
};

// 全局只有一个。
#include <vector>

class autorelease_pool {
public:
	autorelease_pool();
	~autorelease_pool();
public:
	static autorelease_pool* get_instance();
	std::vector<ref_object*> object_set;
public:
	void release_all_ref_object();
	void push_ref_object(ref_object* obj);
};

#endif

