//#ifndef MAP_H
//#define MAP_H

//#include <map>
//#include <string>
//#include <iostream>
#include "map.h"

Map::Map() : currentLocation("Forest") {}

void Map::addLocation(const std::string& locationName, const std::map<std::string, std::string>& directions, const std::string& description, const std::string& narrative) {
        locations[locationName] = directions;
        descriptions[locationName] = description;
        narratives[locationName] = narrative;
}

bool Map::move(const std::string& direction) {
        auto it = locations[currentLocation].find(direction);
        if (it != locations[currentLocation].end()) {
                currentLocation = it->second;
                return true;
        }
        return false;
}

std::string Map::getCurrentLocationDescription() const {
        return descriptions.at(currentLocation); // Access the description using the current location
}

std::string Map::getCurrentNarrative() const {
        return narratives.at(currentLocation); // Return the narrative for the current location
}

std::string Map::describeCurrentLocation() const {
        return "You are currently at " + currentLocation + ".";
}

void Map::setCurrentLocation(const std::string& location) {
        if (locations.find(location) != locations.end()) {
                currentLocation = location;
        }
}

//std::string Map::describeCurrentLocation() const {
//      return "You are currently at " + currentLocation + ".";
//}
