#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "stock_photo_webstore.hpp"
#include "photo.hpp"

int main() {
    StockPhotoWebstore webstore;

    webstore.addPhoto(Photo("music", "guitar", "res_low", 15))
            .addPhoto(Photo("music", "piano", "res_medium", 20))
            .addPhoto(Photo("music", "bass", "res_high", 25))
            .addPhoto(Photo("music", "drum", "res_low", 15))
            .addPhoto(Photo("music", "harp", "res_medium", 20))
            .addPhoto(Photo("food", "fish", "res_high", 20))
            .addPhoto(Photo("food", "chips", "res_low", 10))
            .addPhoto(Photo("food", "tacos", "res_medium", 15))
            .addPhoto(Photo("food", "nachos", "res_high", 20))
            .addPhoto(Photo("sports", "golf", "res_low", 30));

    webstore.updatePrice("music", "bass", 125)
            .printAllPhotos();

    return 0;
}