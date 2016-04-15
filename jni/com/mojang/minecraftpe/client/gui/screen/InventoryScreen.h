#pragma once

#include "Screen.h"

#include "../../../world/level/BlockPos.h"
#include "../../../world/item/ItemInstance.h"
#include "../InventoryPane.h"
#include "../CraftingType.h"


class Tessellator;
class ItemPack;
class ItemInstance;
class Recipe;
class ArmorSlot;
class ImageButton;
class CategoryButton;

class InventoryScreen : public Screen, public Touch::IInventoryPaneCallback {
public:
	struct TabButtonWithMeta;
	struct IngredientSlotStatus;
	
	enum class InventoryPaneType : unsigned int {
		INVENTORY,
		CRAFTING,
		ARMOR,
		BLOCKS,
		DECORATIONS,
		TOOLS,
		ITEMS
	};
	
	char is_vars[332 - 136]; // 136
	Touch::InventoryPane& inventory; // 332
	Touch::InventoryPane& armor; // 340
	Touch::InventoryPane& crafting; // 348
	Touch::InventoryPane& creative1; // 356
	Touch::InventoryPane& creative2; // 364
	Touch::InventoryPane& creative3; // 372
	Touch::InventoryPane& creative4; // 380
	char is_vars1[512 - 388]; // 388
	std::vector<InventoryScreen::TabButtonWithMeta> buttonTabs; // 512
	char is_vars2[616 - 516]; // 516
	InventoryScreen::InventoryPaneType selectedPaneType; // 616
	char is_vars3[656 - 620]; // 620
	ItemInstance item; // 656
	bool hasDumpedArmor; // 676
	char is_vars4[744 - 680]; // 680
	CraftingType craftingType; // 744
	char is_vars5[864 - 748]; // 748
	std::string cannotCreateString; // 864
	bool idk_b; // 868
	char is_vars6[8]; // 872
	BlockPos blockPos; // 880
	

	InventoryScreen(MinecraftClient&, CraftingType, const BlockPos&);
	virtual ~InventoryScreen();
	virtual void onInternetUpdate();
	virtual void handleButtonPress(short);
	virtual void handleButtonRelease(short);
	virtual void handleBackEvent(bool);
	virtual bool renderGameBehind() const;
	virtual bool closeOnPlayerHurt() const;
	virtual bool isModal() const;
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual void tick();
	virtual void handleScrollWheel(float);
	virtual void _updateTabButtonSelection();
	virtual void _buttonClicked(Button&);
	virtual void _pointerReleased(int, int);
	virtual void _controllerDirectionChanged(int, StickDirection);
	virtual void _controllerDirectionHeld(int, StickDirection);
	virtual bool addItem(Touch::InventoryPane&, int);
	virtual bool isAllowed(int);
	virtual std::vector<const ItemInstance*> getItems(const Touch::InventoryPane&);
	
	void _addItemArmorScreen(int);
	bool _addItemCraftingScreen(int);
	int _addItemCreativeScreen(ItemInstance&, bool, bool);
	int _addItemCreativeScreen(int, int, bool, bool);
	bool _addItemForInventoryPane(int&);
	void _closeWindow();
	void _drawSlotItemAt(Tessellator&, int, const ItemInstance*, int, int, bool);
	bool _entityCheck();
	int _getNumberOfIngredients(ItemInstance&, ItemPack&);
	ItemPack& _getPlayerInventoryItemPack();
	void _handleAddItem(Touch::InventoryPane&, int, bool);
	void _handleArmorInventoryNavigation(StickDirection);
	void _handleArmorJoyStickNavigation(StickDirection);
	void _handleArmorSlotNavigation(StickDirection);
	void _onBulkSelectCreativePane();
	void _populateFilteredItems();
	void _populateItem(const ItemInstance&);
	void _populateItems();
	void _putItemInToolbar(const ItemInstance*);
	void _refreshCraftingGrid(Recipe*);
	void _refreshCraftingItemList(const std::vector<Recipe*>&);
	void _renderArmorScreen(Tessellator&, int, int, float);
	void _renderCraftingScreen(Tessellator&, int, int, float);
	void _renderGridItem(ItemInstance*, InventoryScreen::IngredientSlotStatus, int, int);
	void _renderPlayer(float, float, float);
	void _selectInDirection(StickDirection);
	void _setCurrentRecipe(Recipe*);
	void _takeAndClearArmorSlot(ArmorSlot);
	void _updateArmorItems();
	void _updateCraftableItems(bool);
	void _updateCraftingButtonVisiblity();
	void _updateIngredientCountFromRecipe(Recipe*, bool, ItemPack&);
	void clearPopulatedItems();
	CategoryButton* createInventoryTabButton(int, bool);
	void drawIcon(InventoryScreen::InventoryPaneType, std::shared_ptr<ImageButton>, bool, bool);
	ItemInstance getItemFromType(InventoryScreen::InventoryPaneType);
};