#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "photo.hpp"
#include "stock_photo_webstore.hpp"

void loadPhotosFromFile(StockPhotoWebstore &store, const std::string &filename) {
    std::ifstream file(filename.c_str());
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string category;
        std::string name;
        std::string resolution;
        std::string price;

        std::getline(iss, category, ';');
        std::getline(iss, name, ';');
        std::getline(iss, resolution, ';');
        std::getline(iss, price, ';');
        if (!category.empty()) {
            store.addPhoto(Photo(category, name, resolution, std::atoi(price.c_str())));
        }
    }
    file.close();
}

int main() {
    StockPhotoWebstore store;

    /*
     * Photo p1("sports", "football", "res_low", 90);
     * store.addPhoto(p1);
     */

    loadPhotosFromFile(store, "input.txt");

    store.printAllPhotos()
            .printAllPhotosInCategory("music")
            .printAllPhotosInCategory("sports")
            .printPhoto("music", "guitar")
            .printPhoto("sports", "golf")
            .removePhoto("sports", "golf")
            .removePhoto("music", "guitar")
            .printAllPhotos()
            .printAllPhotosInCategory("music")
            .printAllPhotosInCategory("sports")
            .printPhoto("music", "guitar")
            .printPhoto("sports", "golf");

    return 0;
}
