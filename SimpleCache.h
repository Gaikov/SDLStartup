//
// Created by Roman on 30/07/2019.
//

#ifndef SDLTEST_SIMPLECACHE_H
#define SDLTEST_SIMPLECACHE_H

#include "headers.h"

template<class TItem>
class SimpleCache
{
public:
	typedef std::function<TItem*(const char *id)> FactoryFunction;

	SimpleCache(FactoryFunction ff);
	TItem* GetEntry(const char *id);
	bool ReleaseEntry(TItem *item, bool force); //returns true if it needs to be released

private:
	struct Entry
	{
		TItem *item;
		int refCount;
	};

	typedef std::map<std::string, Entry> CacheMap;

	FactoryFunction _factoryFunc;
	CacheMap _cache;

};

template<class TEntry>
SimpleCache<TEntry>::SimpleCache(SimpleCache::FactoryFunction ff) :
		_factoryFunc(ff)
{

}

template<class TEntry>
TEntry* SimpleCache<TEntry>::GetEntry(const char *id)
{
	auto it = _cache.find(id);
	if (it != _cache.end())
	{
		Entry &e = it->second;
		e.refCount ++;
		return e.item;
	}

	Entry newEntry;
	newEntry.refCount = 1;
	newEntry.item = _factoryFunc(id);
	if (newEntry.item)
	{
		_cache.insert(std::make_pair(id, newEntry));
		return newEntry.item;
	}

	return nullptr;
}

template<class TItem>
bool SimpleCache<TItem>::ReleaseEntry(TItem *item, bool force)
{
	for (auto it : _cache)
	{
		Entry &entry = it.second;
		if (entry.item == item)
		{
			entry.refCount --;
			if (entry.refCount <= 0 || force)
			{
				_cache.erase(it.first);
				return true;
			}
		}
	}
	return false;
}


#endif //SDLTEST_SIMPLECACHE_H
