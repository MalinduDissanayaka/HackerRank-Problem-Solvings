#include <iostream>
#include <vector>
#include <unordered_map>

int migratoryBirds(const std::vector<int>& arr) {
    std::unordered_map<int, int> sightings;
    int maxSightings = 0;
    int mostFrequentBirdID = 0;

    for (int birdID : arr) {
        // Increment the count of sightings for the current bird ID
        sightings[birdID]++;

        // Check if the current bird ID has more sightings than the current maximum
        if (sightings[birdID] > maxSightings) {
            maxSightings = sightings[birdID];
            mostFrequentBirdID = birdID;
        }
        // If there is a tie, choose the smaller bird ID
        else if (sightings[birdID] == maxSightings) {
            if (birdID < mostFrequentBirdID) {
                mostFrequentBirdID = birdID;
            }
        }
    }

    return mostFrequentBirdID;
}

int main() {
    std::vector<int> arr = {1, 1, 2, 2, 3, 3, 3, 2, 2, 1, 1}; // Example input
    std::cout << "Most frequent bird ID: " << migratoryBirds(arr) << std::endl;
    return 0;
}
