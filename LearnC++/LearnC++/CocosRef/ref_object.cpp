#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ref_object.h"

ref_object::ref_object() {
	this->ref_count = 1; // ��newһ�������ʱ�����ü���Ϊ1
}

ref_object::~ref_object() {
	printf("~ref_object");
}

void ref_object::retain() {
	this->ref_count++;
}

void ref_object::release() {
	this->ref_count--;
	if (this->ref_count == 0) { // �ͷ��������
		delete this;
	}
}

void ref_object::autorelaese() {
	autorelease_pool::get_instance()->push_ref_object(this);
}

autorelease_pool::autorelease_pool() {
	this->object_set.clear();
}

autorelease_pool::~autorelease_pool() {
	this->release_all_ref_object();
}

void autorelease_pool::release_all_ref_object() {
	for (int i = 0; i < this->object_set.size(); i++) {
		ref_object* obj = this->object_set[i];
		obj->release(); // �ͷ�
	}

	this->object_set.clear(); // ��������е�Ԫ��
}

void autorelease_pool::push_ref_object(ref_object* obj) {
	this->object_set.push_back(obj);
}

autorelease_pool sg_object_pool; // ȫ�ֶ���
autorelease_pool* autorelease_pool::get_instance() {
	return &sg_object_pool;
}