#include <stdio.h>
#include <limits.h>
#define MAX 40
#define INF INT_MAX

// Station names
char* stations[] = {
    "Baiyappanahalli", "Swami Vivekananda Road", "Indiranagar", "MG Road",
    "Trinity", "Halasuru", "Cubbon Park", "Vidhana Soudha", "Sir M. Visveshwaraya",
    "City Railway Station", "Magadi Road", "Vijayanagar", "Attiguppe", 
    "Deepanjalinagar", "Mysore Road", "National College", "Jayanagar", 
    "Southend Circle", "Banashankari", "Rashtriya Vidyalaya Road", 
    "Puttenahalli", "Rajajinagar", "Kuvempu Road", "Srirampura", 
    "Mahalakshmi", "Peenya", "Yeshwantpur", "Dasarahalli", "Nagasandra", 
    "Sandal Soap Factory"
};

// Distance matrix (hypothetical distances in kilometers)
int distanceMatrix[MAX][MAX] = {
    {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58},
    {2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56},
    {4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54},
    {6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52},
    {8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50},
    {10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48},
    {12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46},
    {14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44},
    {16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42},
    {18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38},
    {22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36},
    {24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34},
    {26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32},
    {28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30},
    {30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28},
    {32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26},
    {34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24},
    {36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22},
    {38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20},
    {40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18},
    {42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14, 16},
    {44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14},
    {46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12},
    {48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10},
    {50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8},
    {52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6},
    {54, 52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2, 4},
    {56, 54, 52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0, 2},
    {58, 56, 54, 52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0}
};

// Function to calculate fare based on distance
int calculateFare(int distance) {
    if (distance <= 2) {
        return 10;  // ₹10 for up to 2 km
    } else if (distance <= 5) {
        return 20;  // ₹20 for up to 5 km
    } else if (distance <= 10) {
        return 30;  // ₹30 for up to 10 km
    } else {
        return 50;  // ₹50 for more than 10 km
    }
}

// Function to calculate travel time (assuming 30 km/h average speed)
double calculateTravelTime(int distance) {
    return (double) distance / 30.0;  // Time = Distance / Speed
}

int main() {
    int start, end, distance;
    double time;
    
    // Display list of stations
    printf("Available Metro Stations:\n");
    for (int i = 0; i < 30; i++) {
        printf("%d. %s\n", i+1, stations[i]);
    }

    // Get user input for start and end station
    printf("\nEnter the starting station number: ");
    scanf("%d", &start);
    printf("Enter the destination station number: ");
    scanf("%d", &end);

    // Adjust for array index (user input is 1-based, array index is 0-based)
    start--;
    end--;

    // Get the distance between the selected stations
    distance = distanceMatrix[start][end];

    // Calculate fare and travel time
    int fare = calculateFare(distance);
    time = calculateTravelTime(distance);

    // Display fare and travel time
    printf("\nMetro Ticket Fare Calculator\n");
    printf("----------------------------\n");
    printf("From: %s\n", stations[start]);
    printf("To: %s\n", stations[end]);
    printf("Distance: %d km\n", distance);
    printf("Fare: ₹%d\n", fare);
    printf("Estimated Travel Time: %.2f hours\n", time);

    return 0;
}
