#include "BusinessSystem.h"

// Implementations for EstateOwner
BusinessMediator* EstateOwner::SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator) {
    BusinessMediator* old = mediator_;
    mediator_ = mediator;
    return old;
}

// Implementations for GroceryStore
BusinessMediator* GroceryStore::SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator) {
    BusinessMediator* old = mediator_;
    mediator_ = mediator;
    return old;
}

// Implementations for Restaurant
BusinessMediator* Restaurant::SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator) {
    BusinessMediator* old = mediator_;
    mediator_ = mediator;
    return old;
}

void Restaurant::SetIsOpened(design::AccessKey<BusinessMediator>, bool isOpened) {
    isOpened_ = isOpened;
}

std::int32_t Restaurant::CookFood() {
    if (isOpened_) {
        if (mediator_) mediator_->FoodIsCooked();
        return price_;
    }
    return 0;
}

std::int32_t Restaurant::AlterPrice(std::int32_t priceChange) {
    price_ += priceChange;
    return price_;
}

// Implementations for BusinessMediator
BusinessMediator::BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant)
    : estateOwner_(estateOwner), groceryStore_(groceryStore), restaurant_(restaurant) {
    estateOwner_.SetBusinessMediator(design::AccessKey<BusinessMediator>(), this);
    groceryStore_.SetBusinessMediator(design::AccessKey<BusinessMediator>(), this);
    restaurant_.SetBusinessMediator(design::AccessKey<BusinessMediator>(), this);
}

void BusinessMediator::EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) {
    restaurant_.AlterPrice((newPrice - oldPrice) / 1000);
}

void BusinessMediator::GroceryStockChanged(std::int32_t newStock) {
    if (newStock > 0) {
        restaurant_.SetIsOpened(design::AccessKey<BusinessMediator>(), true);
    } else {
        restaurant_.SetIsOpened(design::AccessKey<BusinessMediator>(), false);
    }
}

void BusinessMediator::GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) {
    restaurant_.AlterPrice(newPrice - oldPrice);
}
