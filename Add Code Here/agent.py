import torch
import random
import numpy as np
from collections import deque #ds for store our memory
from game import SnakeGameAI, Direction , Point
from model import DQN ,QTrainer
from helper import plot 
MAX_MEMORY =100_000
BATCH_SIZE =1000
LR =0.001
class Agent:#need to store game ,model in agent
    def __init__(self):
        self.n_games =0#randomness
        self.epsilon=0
        self.gamma=0.9 #discount rate
        self.memory=deque(maxlen=MAX_MEMORY)#popleft()
        self.model=DQN(11,256,3)
        self.trainer=QTrainer(self.model,lr=LR,gamma=self.gamma)

    
    def get_state(self, game):
        head = game.snake[0]  #list ,points in all direction
        point_l = Point(head.x - 20, head.y)
        point_r = Point(head.x + 20, head.y)#four points around head
        point_u = Point(head.x, head.y - 20)
        point_d = Point(head.x, head.y + 20)
        
        dir_l = game.direction == Direction.LEFT
        dir_r = game.direction == Direction.RIGHT
        dir_u = game.direction == Direction.UP
        dir_d = game.direction == Direction.DOWN

        state = [  #11 states if danger is straight or ahead
            # Danger straight
            (dir_r and game.is_collision(point_r)) or #if go right we get collison also have danger here
            (dir_l and game.is_collision(point_l)) or 
            (dir_u and game.is_collision(point_u)) or 
            (dir_d and game.is_collision(point_d)),

            # Danger right
            (dir_u and game.is_collision(point_r)) or 
            (dir_d and game.is_collision(point_l)) or 
            (dir_l and game.is_collision(point_u)) or 
            (dir_r and game.is_collision(point_d)),

            # Danger left
            (dir_d and game.is_collision(point_r)) or 
            (dir_u and game.is_collision(point_l)) or 
            (dir_r and game.is_collision(point_u)) or 
            (dir_l and game.is_collision(point_d)),
            
            # Move direction
            dir_l,# one of them is true other is false
            dir_r,
            dir_u,
            dir_d,
            
            # Food location 
            game.food.x < game.head.x,  # food left cherck whether food is left of us
            game.food.x > game.head.x,  # food right
            game.food.y < game.head.y,  # food up
            game.food.y > game.head.y  # food down
            ]

        return np.array(state, dtype=int)
    
    def remember(self,state,action,reward,next_state,done):
        self.memory.append(state,action,reward,next_state,done)#popleft
    def train_long_memory(self):
        if len(self.memory)<BATCH_SIZE:
            mini_sample=random.sample(self.memory,BATCH_SIZE) #list of tuples
        else:
            mini_sample=self.memory
        states,actions,rewards,new_states,dones=zip(*mini_sample) #how zip fun work
        self.trainer.train_step(states,actions,rewards,new_states,dones)
        #for state,action,reward,next_state,done in mini_sample:
                    #self.trainer.train_step(state,action,reward,next_state,done)
    def train_short_memory(self,state,action,reward,next_state,done):
        self.trainer.train_step(state,action,reward,next_state,done)

    def get_action(self,state):
        #random moves :tradeoff exploration 
        self.epsilon=80-self.n_games
        final_move=[0,0,0]
        if random.randint(0,200)<self.epsilon:
            move=random.randint(0,2)
            final_move[move]=1
            #more gamewe have small epsilon we get
            #small epsilon  we dont get random move
        else:
            state0=torch.tensor(state,dtype=torch.float)
            prediction=self.model(state0)
            #raw value 
            move=torch.argmax(prediction).item()#convert into 1 no
            final_move=[move]=1
        return final_move





def train():
    plot_scores=[] #scores for ploting later
    plot_mean_scores=[]
    total_score=0
    record=0
    agent=Agent()
    game=SnakeGameAI()
    while True:
        state_old=agent.get_state(game)


        final_move=agent.get_action(state_old)
        reward,done,score=game.play_step(final_move)

        state_new=agent.get_state(game)
        agent.train_short_memory(state_old,final_move,reward,state_new,done)
        if done:
            #train long memory ,plot
            game.reset()
            agent.n_games +=1
            agent.train_long_memory()
            if score > record:
                record=score
                agent.model.save()
            print('Game',agent.n_games,'Score',score,'Record:',record)
            plot_scores.append(score)
            total_score +=score
            mean_score=total_score/agent.n_games
            plot_mean_scores.append(mean_score)
            plot(plot_scores,plot_mean_scores)

#we need model and trainer

if __name__=='__main__':
    train()
