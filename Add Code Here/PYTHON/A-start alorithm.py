import math


class Node:
    def __init__(self, state, parent, actions, heuristic, totalCost):
        self.state = state
        self.parent = parent
        self.actions = actions
        self.totalCost = totalCost
        self.heuristic = heuristic


def findMin(frontier):
    minV = math.inf
    node = ''
    for i in frontier:
        if minV > frontier[i][1]:
            minV = frontier[i][1]
            node = i
    return node


def actionSequence(graph, goalState):
    global solution
    solution = [goalState]
    currentParent = graph[goalState].parent
    print(currentParent)
    while currentParent is not None:
        solution.append(currentParent)
        currentParent = graph[currentParent].parent
    solution.reverse()
    return solution


def Astar():
    initialState = 'C59'
    goalState = 'C5'
    graph = {'C1': Node('C1', None, [('C7', 1)], (1, 0), 0),
             'C2': Node('C2', None, [('C10', 1), ('C3', 1)], (5, 0), 0),
             'C3': Node('C3', None, [('C2', 1), ('C11', 1), ('C4', 1)], (6, 0), 0),
             'C4': Node('C4', None, [('C12', 1), ('C3', 1)], (7, 0), 0),
             'C5': Node('C5', None, [('C14', 1)], (9, 0), 0),

             'C6': Node('C6', None, [('C7', 1), ('C15', 1)], (0, 1), 0),
             'C7': Node('C7', None, [('C6', 1), ('C8', 1), ('C1', 1)], (1, 1), 0),
             'C8': Node('C8', None, [('C7', 1)], (2, 1), 0),
             'C9': Node('C9', None, [('C16', 1), ('C10', 1)], (4, 1), 0),
             'C10': Node('C10', None, [('C2', 1), ('C9', 1), ('C17', 1), ('C11', 1)], (5, 1), 0),
             'C11': Node('C11', None, [('C3', 1), ('C10', 1), ('C18', 1), ('C12', 1)], (6, 1), 0),
             'C12': Node('C12', None, [('C4', 1), ('C11', 1), ('C19', 1), ('C13', 1)], (7, 1), 0),
             'C13': Node('C13', None, [('C12', 1), ('C20', 1), ('C14', 1)], (8, 1), 0),
             'C14': Node('C14', None, [('C5', 1), ('C13', 1), ('C21', 1)], (9, 1), 0),

             'C15': Node('C15', None, [('C6', 1)], (0, 2), 0),
             'C16': Node('C16', None, [('C9', 1), ('C17', 1)], (4, 2), 0),
             'C17': Node('C17', None, [('C16', 1), ('C10', 1), ('C18', 1)], (5, 2), 0),
             'C18': Node('C18', None, [('C11', 1), ('C17', 1), ('C24', 1), ('C19', 1)], (6, 2), 0),
             'C19': Node('C19', None, [('C12', 1), ('C18', 1), ('C25', 1), ('C20', 1)], (7, 2), 0),
             'C20': Node('C20', None, [('C13', 1), ('C19', 1), ('C26', 1), ('C21', 1)], (8, 2), 0),
             'C21': Node('C21', None, [('C14', 1), ('C20', 1), ('C27', 1)], (9, 2), 0),

             'C22': Node('C22', None, [('C23', 1)], (1, 3), 0),
             'C23': Node('C23', None, [('C22', 1), ('C29', 1)], (2, 3), 0),
             'C24': Node('C24', None, [('C18', 1), ('C25', 1)], (6, 3), 0),
             'C25': Node('C25', None, [('C19', 1), ('C24', 1), ('C26', 1), ('C31', 1)], (7, 3), 0),
             'C26': Node('C26', None, [('C20', 1), ('C25', 1), ('C27', 1)], (8, 3), 0),
             'C27': Node('C27', None, [('C26', 1), ('C21', 1)], (9, 3), 0),

             'C28': Node('C28', None, [('C32', 1)], (0, 4), 0),
             'C29': Node('C29', None, [('C23', 1), ('C30', 1)], (2, 4), 0),
             'C30': Node('C30', None, [('C29', 1), ('C33', 1)], (3, 4), 0),
             'C31': Node('C31', None, [('C25', 1), ('C37', 1)], (7, 4), 0),

             'C32': Node('C32', None, [('C28', 1), ('C40', 1)], (1, 5), 0),
             'C33': Node('C33', None, [('C30', 1), ('C34', 1), ('C42', 1)], (3, 5), 0),
             'C34': Node('C34', None, [('C33', 1), ('C35', 1)], (4, 5), 0),
             'C35': Node('C35', None, [('C34', 1), ('C36', 1), ('C43', 1)], (5, 5), 0),
             'C36': Node('C36', None, [('C37', 1), ('C35', 1), ('C44', 1)], (6, 5), 0),
             'C37': Node('C37', None, [('C31', 1), ('C36', 1), ('C38', 1), ('C45', 1)], (7, 5), 0),
             'C38': Node('C38', None, [('C37', 1), ('C39', 1)], (8, 5), 0),
             'C39': Node('C39', None, [('C38', 1)], (9, 5), 0),

             'C40': Node('C40', None, [('C32', 1), ('C46', 1)], (0, 6), 0),
             'C41': Node('C41', None, [('C42', 1), ('C48', 1)], (2, 6), 0),
             'C42': Node('C42', None, [('C41', 1), ('C33', 1)], (3, 6), 0),
             'C43': Node('C43', None, [('C35', 1), ('C42', 1), ('C50', 1)], (5, 6), 0),
             'C44': Node('C44', None, [('C43', 1), ('C45', 1), ('C36', 1)], (6, 6), 0),
             'C45': Node('C45', None, [('C37', 1), ('C44', 1)], (7, 6), 0),

             'C46': Node('C46', None, [('C47', 1), ('C40', 1), ('C52', 1)], (0, 7), 0),
             'C47': Node('C47', None, [('C46', 1), ('C48', 1), ('C53', 1)], (1, 7), 0),
             'C48': Node('C48', None, [('C47', 1), ('C41', 1)], (2, 7), 0),
             'C49': Node('C49', None, [('C50', 1), ('C55', 1)], (4, 7), 0),
             'C50': Node('C50', None, [('C49', 1), ('C56', 1)], (5, 7), 0),
             'C51': Node('C51', None, [('C57', 1)], (8, 7), 0),

             'C52': Node('C52', None, [('C46', 1), ('C53', 1), ('C59', 1)], (0, 8), 0),
             'C53': Node('C53', None, [('C52', 1), ('C47', 1), ('C60', 1)], (1, 8), 0),
             'C54': Node('C54', None, [('C55', 1), ('C62', 1)], (3, 8), 0),
             'C55': Node('C55', None, [('C49', 1), ('C54', 1), ('C56', 1)], (4, 8), 0),
             'C56': Node('C56', None, [('C50', 1), ('C55', 1), ('C63', 1)], (5, 8), 0),
             'C57': Node('C57', None, [('C51', 1), ('C58', 1), ('C56', 1)], (8, 8), 0),
             'C58': Node('C58', None, [('C57', 1), ('C67', 1)], (9, 8), 0),

             'C59': Node('C59', None, [('C52', 1), ('C60', 1)], (0, 9), 0),
             'C60': Node('C60', None, [('C59', 1), ('C53', 1), ('C61', 1)], (1, 9), 0),
             'C61': Node('C61', None, [('C60', 1), ('C62', 1)], (2, 9), 0),
             'C62': Node('C62', None, [('C61', 1), ('C54', 1)], (3, 9), 0),
             'C63': Node('C63', None, [('C56', 1), ('C64', 1)], (5, 9), 0),
             'C64': Node('C64', None, [('C63', 1), ('C65', 1)], (6, 9), 0),
             'C65': Node('C65', None, [('C64', 1), ('C66', 1)], (7, 9), 0),
             'C66': Node('C66', None, [('C65', 1), ('C57', 1), ('C67', 1)], (8, 9), 0),
             'C67': Node('C67', None, [('C66', 1), ('C58', 1)], (9, 9), 0)}
    frontier = dict()
    heuristicCost = math.sqrt(((graph[goalState].heuristic[0] - graph[initialState].heuristic[0]) ** 2) + (
            (graph[goalState].heuristic[1] - graph[initialState].heuristic[1]) ** 2))
    frontier[initialState] = (None, heuristicCost)
    explored = dict()
    while len(frontier) != 0:
        currentNode = findMin(frontier)
        print(currentNode)
        del frontier[currentNode]
        if graph[currentNode].state == goalState:
            return actionSequence(graph, goalState)

        heuristicCost = math.sqrt(((graph[goalState].heuristic[0] - graph[currentNode].heuristic[0]) ** 2) + (
                (graph[goalState].heuristic[1] - graph[currentNode].heuristic[1]) ** 2))
        currentCost = graph[currentNode].totalCost
        explored[currentNode] = (graph[currentNode].parent, heuristicCost + currentCost)
        for child in graph[currentNode].actions:
            currentCost = child[1] + graph[currentNode].totalCost
            heuristicCost = math.sqrt(((graph[goalState].heuristic[0] - graph[child[0]].heuristic[0]) ** 2) + (
                    (graph[goalState].heuristic[1] - graph[child[0]].heuristic[1]) ** 2))
            if child[0] in explored:
                if graph[child[0]].parent == currentNode or child[0] == initialState or explored[child[0]][
                    1] <= currentCost + heuristicCost:
                    continue
            if child[0] not in frontier:
                graph[child[0]].parent = currentNode
                graph[child[0]].totalCost = currentCost
                frontier[child[0]] = (graph[child[0]].parent, currentCost + heuristicCost)
            else:
                if frontier[child[0]][1] < currentCost + heuristicCost:
                    graph[child[0]].parent = frontier[child[0]][0]
                    graph[child[0]].totalCost = frontier[child[0]][1] - heuristicCost
                else:
                    frontier[child[0]] = (currentNode, currentCost + heuristicCost)
                    graph[child[0]].parent = frontier[child[0]][0]
                    graph[child[0]].totalCost = currentCost


solution = Astar()
print('Path:', solution)