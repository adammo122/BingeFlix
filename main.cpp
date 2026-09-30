/*
 * Course: LDCW6123 - Fundamentals of Digital Competence for Programmer
 * Group Project: Netflix Binge-Watch Planner & Schedule Calculator
 * Description: An interactive companion tool inspired by Netflix. Calculates
 *              completion schedules and evaluates "Binge Risk Level".
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // Welcome Banner
    cout << "========================================================\n";
    cout << "       NETFLIX BINGE-WATCH PLANNER & SCHEDULE           \n";
    cout << "========================================================\n\n";

    int showChoice = 0;
    int totalEpisodes = 0;
    double episodeDurationMinutes = 0.0;
    double dailyWatchHours = 0.0;
    string showName = "";

    // Step 1: Select a Show or Enter Custom Details
    cout << "Select a Netflix Show to Plan:\n";
    cout << "1. Stranger Things (34 Episodes, ~60 mins each)\n";
    cout << "2. Squid Game (9 Episodes, ~55 mins each)\n";
    cout << "3. Wednesday (8 Episodes, ~45 mins each)\n";
    cout << "4. Custom Show Entry\n";
    cout << "Enter choice (1-4): ";
    cin >> showChoice;

    // Process menu selection using a switch statement
    switch (showChoice)
    {
    case 1:
        showName = "Stranger Things";
        totalEpisodes = 34;
        episodeDurationMinutes = 60.0;
        break;
    case 2:
        showName = "Squid Game";
        totalEpisodes = 9;
        episodeDurationMinutes = 55.0;
        break;
    case 3:
        showName = "Wednesday";
        totalEpisodes = 8;
        episodeDurationMinutes = 45.0;
        break;
    case 4:
        cout << "\nEnter Custom Show Name: ";
        cin.ignore(); // Clear buffer
        getline(cin, showName);
        cout << "Enter Total Number of Episodes: ";
        cin >> totalEpisodes;
        cout << "Enter Average Episode Duration (in minutes): ";
        cin >> episodeDurationMinutes;
        break;
    default:
        cout << "\n[Error] Invalid choice! Defaulting to Custom Show.\n";
        showName = "Custom Show";
        totalEpisodes = 10;
        episodeDurationMinutes = 45.0;
        break;
    }

    // Input Validation for Episodes & Duration
    if (totalEpisodes <= 0 || episodeDurationMinutes <= 0)
    {
        cout << "\n[Error] Episode count and duration must be greater than zero. Exiting program.\n";
        return 1;
    }

    // Step 2: Get Daily Watch Hours
    cout << "\nHow many hours can you dedicate to watching per day? ";
    cin >> dailyWatchHours;

    // Input Validation for Watch Hours
    if (dailyWatchHours <= 0.0)
    {
        cout << "\n[Error] Daily watch time must be greater than 0 hours. Exiting program.\n";
        return 1;
    }

    // Step 3: Calculations
    double totalRuntimeMinutes = totalEpisodes * episodeDurationMinutes;
    double totalRuntimeHours = totalRuntimeMinutes / 60.0;
    double daysToFinish = totalRuntimeHours / dailyWatchHours;
    double episodesPerDay = (dailyWatchHours * 60.0) / episodeDurationMinutes;

    // Step 4: Evaluate "Binge Risk Level" using if / else if logic
    string riskLevel = "";
    string healthAdvice = "";

    if (dailyWatchHours < 2.0)
    {
        riskLevel = "LOW (Casual Viewer)";
        healthAdvice = "Balanced schedule! Minimal impact on sleep and daily routine.";
    }
    else if (dailyWatchHours >= 2.0 && dailyWatchHours <= 4.0)
    {
        riskLevel = "MODERATE (Dedicated Binger)";
        healthAdvice = "Take 10-minute stretch breaks between episodes and stay hydrated.";
    }
    else
    {
        riskLevel = "HIGH / SEVERE (Marathon Binger)";
        healthAdvice = "Warning! Watching over 4 hours daily may cause eye strain and sleep disturbance.";
    }

    // Step 5: Output Summary
    cout << "\n========================================================\n";
    cout << "             BINGE PLAN SUMMARY FOR: " << showName << "\n";
    cout << "========================================================\n";
    cout << fixed << setprecision(1);
    cout << " Total Series Runtime  : " << totalRuntimeHours << " hours (" << totalRuntimeMinutes << " mins)\n";
    cout << " Days to Complete      : " << ceil(daysToFinish) << " day(s)\n";
    cout << " Recommended Pace      : ~" << setprecision(1) << episodesPerDay << " episode(s) per day\n";
    cout << " Binge Risk Level      : " << riskLevel << "\n";
    cout << " Health Recommendation : " << healthAdvice << "\n";
    cout << "========================================================\n";
    cout << "Thank you for using the Netflix Companion App!\n";

    return 0;
}