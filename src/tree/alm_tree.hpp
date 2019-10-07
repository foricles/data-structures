#ifndef _ALM_TREE_HPP_
#define _ALM_TREE_HPP_

#include "alm_bintree.hpp"

#if _DEBUG
#include <iostream>
#endif // _DEBUG


template <class Data> using AlmTree = RBTree<Data>;



template <class Data>
class AlmTreeUniq : public RBTree<Data>
{
public:
	void Push(const Data &data) override
	{
		if (!this->Contain(data)) RBTree<Data>::Push(data);
	}
};



template <class Data>
struct HashStruct
{
	Data data;
	unsigned int hash;

	friend bool operator == (const HashStruct &lhv, const HashStruct &rhv) { return lhv.hash == rhv.hash; };
	friend bool operator != (const HashStruct &lhv, const HashStruct &rhv) { return lhv.hash != rhv.hash; };
	friend bool operator < (const HashStruct &lhv, const HashStruct &rhv) { return lhv.hash < rhv.hash; };
	friend bool operator > (const HashStruct &lhv, const HashStruct &rhv) { return lhv.hash > rhv.hash; };

	HashStruct()
	{
		RecalcHash();
	}

	HashStruct(const Data &pdata)
		: data(pdata)
		, hash(0)
	{
		RecalcHash();
	}

	void RecalcHash()
	{
		int count = sizeof(Data) / sizeof(char);
		char *p = static_cast<char*>(static_cast<void*>(&data));
		for (int i(0); i < count; ++i)
		{
			hash |= static_cast<unsigned int>(*p);
			++p;
		}
	}

#if _DEBUG
	friend std::ostream & operator << (std::ostream & out, HashStruct &t) { out << t.data; return out; };
#endif // _DEBUG
};

template <class Data> using AlmHashMap = AlmTreeUniq<HashStruct<Data>>;
#endif // !_ALM_TREE_HPP_