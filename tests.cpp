#include "BusinessSystem.cpp"
#include "gtest/gtest.h"

// Test case for EstateOwner class
TEST(EstateOwnerTest, SetEstateRentPriceTest) {
    EstateOwner estateOwner;
    estateOwner.SetEstateRentPrice(20000);
    // Now we need to add a method to get the rent price
    EXPECT_EQ(estateOwner.GetEstateRentPrice(), 20000);
}

// Test case for GroceryStore class
TEST(GroceryStoreTest, SupplyTest) {
    GroceryStore groceryStore;
    groceryStore.Supply(10);
    // Now we need to add a method to get the stock
    EXPECT_EQ(groceryStore.GetStock(), 10);
}

// Since AlterPrice method already exists in GroceryStore, there is no need to fix it.

// Test case for Restaurant class
TEST(RestaurantTest, SetIsOpenedTest) {
    Restaurant restaurant;
    restaurant.SetIsOpened(true);
    // Now we need to add a method to check if the restaurant is opened
    EXPECT_TRUE(restaurant.IsOpened());
}

// Since CookFood method already exists in Restaurant, there is no need to fix it.

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
