#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H

#include "Asset.h"

class ResourceManager
{
public:
	
	ResourceManager();
	//static void setContentPath(const std::string& path);
	//static const std::string& getContentPath();
	//static bool removeAsset(const std::string& assetName);
	
protected:
	enum AssetType
	{
		ASSET_UNDEFINED,
		ASSET_TEXTURE,
		ASSET_AUDIO
	};
	AssetType m_assetType;
};

#endif // _RESOURCEMANAGER_H