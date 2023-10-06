#pip install deap
import random
from deap import base, creator, tools, algorithms

# Create a list of cities represented as (x, y) coordinates
cities = [
    (0, 0), (1, 2), (2, 4), (3, 1), (4, 3)
]

# Define the distance function between two cities
def distance(city1, city2):
    return ((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2) ** 0.5

# Create the optimization problem as minimizing a fitness function
creator.create("FitnessMin", base.Fitness, weights=(-1.0,))
creator.create("Individual", list, fitness=creator.FitnessMin)

# Create the genetic algorithm toolbox
toolbox = base.Toolbox()
toolbox.register("indices", random.sample, range(len(cities)), len(cities))
toolbox.register("individual", tools.initIterate, creator.Individual, toolbox.indices)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

# Define the evaluation function (fitness function)
def evaluate(individual):
    total_distance = sum(distance(cities[individual[i]], cities[individual[i+1]]) for i in range(len(cities) - 1))
    total_distance += distance(cities[individual[-1]], cities[individual[0]])  # Return to the starting city
    return total_distance,

toolbox.register("evaluate", evaluate)
toolbox.register("mate", tools.cxOrdered)
toolbox.register("mutate", tools.mutShuffleIndexes, indpb=0.2)
toolbox.register("select", tools.selTournament, tournsize=3)

# Create an initial population
population = toolbox.population(n=50)

# Run the genetic algorithm
ngen = 100  # Number of generations
cxpb = 0.7  # Crossover probability
mutpb = 0.2  # Mutation probability

for gen in range(ngen):
    offspring = algorithms.varAnd(population, toolbox, cxpb, mutpb)
    fits = toolbox.map(toolbox.evaluate, offspring)
    
    for fit, ind in zip(fits, offspring):
        ind.fitness.values = fit
    
    population = toolbox.select(offspring, len(population))

# Get the best individual in the final population
best_individual = tools.selBest(population, k=1)[0]
best_fitness = best_individual.fitness.values[0]
best_route = [cities[i] for i in best_individual]

print("Best individual:", best_individual)
print("Best fitness (total distance):", best_fitness)
print("Best route (order of cities):", best_route)

