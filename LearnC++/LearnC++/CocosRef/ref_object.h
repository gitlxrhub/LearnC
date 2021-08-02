#ifndef __REF_OBJECT_H__
#define __REF_OBJECT_H__

// 1:��Ե��ڶ��ϵ��ڴ�������ԣ����Ǽ̳���ref_object�Ķ���
// ֻ��ͨ������ʵ������

class ref_object {
public:
	ref_object();
	virtual ~ref_object(); // ��Ϊ��Ҫͨ�������ָ�����ͷ������ʵ��������������Ҫ���������������������麯��
private:
	int ref_count;
public:
	void retain();
	void release();
	void autorelaese(); // ������ڵ㣬���뵽�Զ��ͷų�����
};

// ȫ��ֻ��һ����
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

