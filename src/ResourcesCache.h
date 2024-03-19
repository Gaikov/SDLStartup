//
// Created by Roman on 30/07/2019.
//

#ifndef SDLTEST_SIMPLECACHE_H
#define SDLTEST_SIMPLECACHE_H

#include "headers.h"

template<class TResource, class TParam>
class ResourcesCache
{
public:
	ResourcesCache() = default;
	void ReleaseAll();
	TResource* GetResource(const char *id, TParam param);
	void ReleaseResource(TResource *item, bool force = false); //returns true if it needs to be released

protected:
	virtual TResource* AllocateResource(const char *id, TParam param) = 0;
	virtual void FreeResource(TResource *item) = 0;

private:
	struct Entry
	{
		TResource *item;
		int refCount;
	};

	std::map<std::string, Entry> _cache;
};

template<class TItem, class TParam>
TItem* ResourcesCache<TItem, TParam>::GetResource(const char *id, TParam param)
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
	newEntry.item = AllocateResource(id, param);
	if (newEntry.item)
	{
		_cache.insert(std::make_pair(id, newEntry));
		return newEntry.item;
	}

	return nullptr;
}

template<class TItem, class TParam>
void ResourcesCache<TItem, TParam>::ReleaseResource(TItem *item, bool force)
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
				FreeResource(entry.item);
				return;
			}
		}
	}
}

template<class TItem, class TParam>
void ResourcesCache<TItem, TParam>::ReleaseAll()
{
	for (auto it : _cache)
	{
		Entry &entry = it.second;
		FreeResource(entry.item);
	}
	_cache.clear();
}


#endif //SDLTEST_SIMPLECACHE_H
