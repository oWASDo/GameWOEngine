#pragma once
#include "Exporter.h"
#include <list>
#include <iostream>
#include <iterator>


#define CLEAR_LIST(list)	\
if (!list.empty())			\
{							\
	list.clear();			\
							\
}

#define GET_LIST_ELEMENTT(list_, type_, index_, el_)\
if (index_ >= 0 && list_.size() > index_)			\
{													\
	type_ el_ = nullptr;							\
	std::list<type>::iterator it = list_.begin();	\
	std::advance(it, index_);						\
	el_ = *it;										\
}

#define GET_LIST_ELEMENT2(list_, type_, index_, el_)\
if (index_ >= 0 && list_.size() > index_)			\
{													\
	std::list<type_>::iterator it = list_.begin();	\
	std::advance(it, index_);						\
	el_ = *it;										\
}

#define DELETE_ELEMENTS_IN_A_LIST(list_, type_)	\
for (size_t i = 0; i < list_.size(); i++)		\
{												\
	GET_LIST_ELEMENTT(list_, type_, i, p)		\
	if(p == nullptr){continue;}					\
	delete p;									\
}												\
CLEAR_LIST(list_)

#define DELETE_ELEMENTS_IN_A_LIST2(list_, type_)\
for (size_t i = 0; i < list_.size(); i++)		\
{												\
	type_ p = nullptr;							\
	GET_LIST_ELEMENT2(list_, type_, i, p)		\
	if(p == nullptr){continue;}					\
	delete p;									\
}												\
CLEAR_LIST(list_)
