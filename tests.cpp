#include <gtest/gtest.h>
#include "BusinessSystem.cpp"

TEST(BusinessTest, EstateRentPriceChangeTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    estateOwner.SetEstateRentPrice(20000);
    EXPECT_EQ(groceryStore.AlterPrice(0), 101); // Expected grocery price change
    EXPECT_EQ(restaurant.AlterPrice(0), 510); // Expected restaurant price change
}

TEST(BusinessTest, GroceryStockChangeTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    groceryStore.Supply(10);
    EXPECT_NO_THROW(restaurant.CookFood()); // Restaurant should be open

    groceryStore.Supply(-10);
    EXPECT_EQ(restaurant.CookFood(), -1); // Restaurant should be closed
}

TEST(BusinessTest, FoodIsCookedTest) {
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;
    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    groceryStore.Supply(1);
    EXPECT_NO_THROW(restaurant.CookFood()); // Should not throw, as grocery is available

    EXPECT_THROW(groceryStore.Sell(), std::logic_error); // Out of stock
}
