#include "CreativeTab.h"

#include "com/mojang/minecraftpe/world/item/Item.h"
#include "com/mojang/minecraftpe/world/level/block/Block.h"
#include "../client/screens/InventoryTransitions.h"

CreativeTab::CreativeTab()
{
	InventoryTransitions::creativeTabs.emplace_back(this);
}

void CreativeTab::addItemInstance(const ItemInstance& item)
{
	itemsInTab.emplace_back(item);
}

void CreativeTab::addItem(Item* item, int data)
{
	addItemInstance(ItemInstance(item, data));
}

void CreativeTab::addItem(int itemId, int data)
{
	addItem(Item::mItems[itemId], data);
}

void CreativeTab::addBlock(Block* block, int data)
{
	addItemInstance(ItemInstance(block, data));
}

void CreativeTab::setTabIcon(const ItemInstance& item)
{
	tabIcon = item;
}

void CreativeTab::setTabIcon(Item* item, int data)
{
	setTabIcon(ItemInstance(item, data));
}

void CreativeTab::setTabIcon(Block* block, int data)
{
	setTabIcon(ItemInstance(block, data));
}

void CreativeTab::setTabIcon(int itemId, int data)
{
	setTabIcon(Item::mItems[itemId], data);
}

void CreativeTab::setTabIcon(const std::string& texturePath)
{
	imageIcon = texturePath;
}

CreativeTab* myTab1 = new CreativeTab();
CreativeTab* myTab2 = new CreativeTab();
CreativeTab* myTab3 = new CreativeTab();
CreativeTab* myTab4 = new CreativeTab();
CreativeTab* myTab5 = new CreativeTab();
CreativeTab* myTab6 = new CreativeTab();
CreativeTab* myTab7 = new CreativeTab();
CreativeTab* myTab8 = new CreativeTab();
CreativeTab* myTab9 = new CreativeTab();