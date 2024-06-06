#include "BusinessSystem.cpp"
#include "gtest/gtest.h"

// Test case for EstateOwner class
TEST(EstateOwnerTest, SetEstateRentPriceTest) {
    EstateOwner estateOwner;
    estateOwner.SetEstateRentPrice(20000);
    EXPECT_EQ(estateOwner.GetEstateRentPrice(), 20000);
}

// Test case for GroceryStore class
TEST(GroceryStoreTest, SupplyTest) {
    GroceryStore groceryStore;
    groceryStore.Supply(10);
    EXPECT_EQ(groceryStore.GetStock(), 10);
}

TEST(GroceryStoreTest, AlterPriceTest) {
    GroceryStore groceryStore;
    EXPECT_EQ(groceryStore.AlterPrice(10), 10);
}
