#include <gtest/gtest.h>
#include "BusinessSystem.cpp"

TEST(BusinessTest, EstateRentPriceChangeTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    estateOwner.SetEstateRentPrice(20000);
    // Expected grocery price change is 20 (20000 - 0 / 1000)
    EXPECT_EQ(groceryStore.AlterPrice(0), 20);
    // Expected restaurant price change is 50 (20000 - 0 / 400)
    EXPECT_EQ(restaurant.AlterPrice(0), 50);
}

TEST(BusinessTest, GroceryStockChangeTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    groceryStore.Supply(10);
    EXPECT_NO_THROW(restaurant.CookFood()); // Restaurant should be open

    groceryStore.Supply(-10);
    EXPECT_EQ(restaurant.CookFood(), 0); // Restaurant should be closed
}

TEST(BusinessTest, FoodIsCookedTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    groceryStore.Supply(1);
    EXPECT_NO_THROW(restaurant.CookFood()); // Should not throw, as grocery is available

    groceryStore.Sell(); // Sell one item to make stock 0
    EXPECT_THROW(groceryStore.Sell(), std::logic_error); // Out of stock
}
