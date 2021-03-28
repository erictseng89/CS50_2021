# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000

    
def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    # Start with empty list
    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], 'r') as file:
        reader = csv.DictReader
        for row in reader(file):
            teams.append({'team': row['team'], 'rating': int(row['rating'])})

    # for row in teams:
    #     print(row)
    
    # result = (simulate_tournament(teams))
    # print(result)

    # print(teams[0]['team'])
    # print(teams[0]['rating'])


    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts.

    # Add a new key-value pair for each index(each team) in teams.
    for addToCount in range(len(teams)):
        counts[teams[addToCount]['team']] = 0

    # Simulate tournament N times, and add a count for the winner.
    for j in range(N):
        winner = (simulate_tournament(teams))
        counts[winner] += 1    

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    # I need to simulate a tournament.
    # Try recursion
    # If number of teams equals 1, then return index of winner
    # If number of teams equals 2, then run recursive function then simulate game and return the index of winner
    
    numberOfTeams = len(teams)
    winner = tournament_recursion(teams, 0, numberOfTeams)
    return teams[winner]['team']

# Run a recursive function to determine the winner
def tournament_recursion(teams, indexStart, number):
    # Base case
    if number < 2:
        return indexStart

    # Recursive case, this is assuming number of teams is a square power of 2. There are no checks for other numbers. 
    else:
        # Need to cast as int because otherwise the number becomes a float.
        newNumber = int(number / 2)
        topHalf = tournament_recursion(teams, indexStart, newNumber)
        bottomHalf = tournament_recursion(teams, (indexStart+newNumber), newNumber)

        gameResult = simulate_game(teams[topHalf], teams[bottomHalf])

        # I need to return a index integer
        if gameResult == True:
            return topHalf
        else:
            return bottomHalf


if __name__ == "__main__":
    main()
