#include <gtest/gtest.h>
#include "BusinessSystem.cpp"

// Test case for EstateOwner class
TEST(EstateOwnerTest, SetEstateRentPriceTest) {
    EstateOwner owner;
    BusinessMediator mediator(owner, GroceryStore(), Restaurant());

    owner.SetEstateRentPrice(1000);
    ASSERT_EQ(owner.GetRentPrice(), 1000);
}

// Test case for GroceryStore class
TEST(GroceryStoreTest, SupplyTest) {
    GroceryStore store;
    BusinessMediator mediator(EstateOwner(), store, Restaurant());

    store.Supply(100);
    ASSERT_EQ(store.GetStock(), 100);
}

// Test case for Restaurant class
TEST(RestaurantTest, CookFoodTest) {
    Restaurant restaurant;
    BusinessMediator mediator(EstateOwner(), GroceryStore(), restaurant);

    restaurant.SetIsOpened(true);
    ASSERT_GT(restaurant.CookFood(), 0);
}
