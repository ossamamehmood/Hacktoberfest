import random
import tkinter as tk
import tkinter.ttk as ttk
from tkinter import PhotoImage
from tkinter import messagebox

class Application(tk.Frame):
	def __init__(self, master=None):
		super().__init__(master=master)
		self.master = master
		self.grid()

		self.username = tk.StringVar()
		self.main_frame()

		self.moves = ['rock', 'paper', 'scissor']
		self.userPoint = 0
		self.sysPoint = 0
		self.imIndex = 0
		self.imDelta = 1
		self.animateFrame = 0
		self.after_id = None
		self.imgDict = {'rock':rock_list, 'paper':paper_list,'scissor':scissor_list}

	def main_frame(self):
		self.main = tk.Frame(self, width=400, height=300, bg='white')
		self.main.grid(row=0, column=0)
		self.main.grid_propagate(False)

		self.game_lbl = tk.Label(self.main, image=rps_icon)
		self.game_lbl.grid(row=0, column=0, columnspan=3, padx=90, pady=10)

		self.name_lbl = tk.Label(self.main, text='Enter your name : ',
						font='verdana 10', bg='white')
		self.name_lbl.grid(row=1, column=0, pady=10)

		self.name_entry = ttk.Entry(self.main, textvariable=self.username)
		self.name_entry.grid(row=1, column=1, columnspan=2, pady=10)
		self.name_entry.focus_set()

		self.play = ttk.Button(self.main, text='Play Game', width=10,
					command=self.play_game)
		self.play.grid(row=2, column=0, pady=20)

		self.quit = ttk.Button(self.main, text='Quit Game', width=10,
					command=self.master.destroy)
		self.quit.grid(row=2, column=2, pady=20)

	def play_game(self):
		if self.username.get():
			self.main.destroy()
			self.draw_frames()
			self.draw_header_frame()
			self.draw_body_frame()
			self.draw_footer_frame()

			self.rock_user.bind('<Button-1>', lambda event, m='rock': self.move(m))
			self.paper_user.bind('<Button-1>', lambda event, m='paper': self.move(m))
			self.scissor_user.bind('<Button-1>', lambda event, m='scissor': self.move(m))
		else:
			messagebox.showinfo('Rock Paper Scissor', 'Player name is required')
			self.name_entry.focus_set()

	def draw_frames(self):
		self.header = tk.Frame(self, width=400, height=100)
		self.body = tk.Frame(self, width=400, height=170)
		self.footer = tk.Frame(self, width=400, height=30)

		self.header.grid(row=0, column=0)
		self.body.grid(row=1, column=0)
		self.footer.grid(row=2, column=0)

		self.header.grid_propagate(False)
		self.body.grid_propagate(False)
		self.footer.grid_propagate(False)

	def draw_header_frame(self):
		self.title = tk.Label(self.header, text='Rock Paper Scissor', fg='black',
						 font='Verdana 14')
		self.title.grid(row=0, column=1, columnspan=3, pady=(5,7))

		self.left = tk.LabelFrame(self.header, width=150, height=55, borderwidth=5)
		self.left.grid(row=1, column=0, columnspan=2, padx=(25,10))
		self.left.grid_propagate(False)

		self.vs = tk.Label(self.header, text='Vs', fg='red', font='Verdana 15 bold')
		self.vs.grid(row=1, column=2)

		self.right = tk.LabelFrame(self.header, width=150, height=55, borderwidth=5)
		self.right.grid(row=1, column=3, columnspan=2, padx=10)
		self.right.grid_propagate(False)

		self.username = tk.Label(self.left, text=f'{self.username.get()}', fg='dodgerblue3',
								font='verdana 10', padx=30)
		self.upoint = tk.Label(self.left, text=f'({self.userPoint})', fg='dodgerblue3',font='verdana 10')
		self.username.grid(row=0, column=0, sticky='news')
		self.upoint.grid(row=1, column=0, sticky='news')

		self.sysname = tk.Label(self.right, text=f'system', fg='dodgerblue3',
								font='verdana 10', padx=40)
		self.spoint = tk.Label(self.right, text=f'({self.userPoint})', fg='dodgerblue3',font='verdana 10')
		self.sysname.grid(row=0, column=0, sticky='news')
		self.spoint.grid(row=1, column=0, sticky='news')

	def draw_body_frame(self):
		self.rock_user = tk.Label(self.body, image=rock_small, cursor='hand2')
		self.rock_user.grid(row=0, column=0, pady=(5,0), padx=(45,10))

		self.paper_user = tk.Label(self.body, image=paper_small, cursor='hand2')
		self.paper_user.grid(row=1, column=0, pady=(5,0), padx=(50,10))

		self.scissor_user = tk.Label(self.body, image=scissor_small, cursor='hand2')
		self.scissor_user.grid(row=2, column=0, pady=(5,0), padx=(45,10))

		self.result_box = tk.Frame(self.body, width=180, height=100)
		self.result_box.grid(row=0, column=1, rowspan=2, columnspan=4)
		self.result_box.grid_propagate(False)

		self.lbox = tk.Frame(self.result_box, width=90, height=100)
		self.lbox.grid(row=0, column=0)
		self.lbox.grid_propagate(False)

		self.rbox = tk.Frame(self.result_box, width=90, height=100)
		self.rbox.grid(row=0, column=1)
		self.rbox.grid_propagate(False)

		self.rock_system = tk.Label(self.body, image=rock_small)
		self.rock_system.grid(row=0, column=5, pady=(5,0), padx=(10,10))

		self.paper_system = tk.Label(self.body, image=paper_small)
		self.paper_system.grid(row=1, column=5, pady=(5,0), padx=(15,10))

		self.scissor_system = tk.Label(self.body, image=scissor_small)
		self.scissor_system.grid(row=2, column=5, pady=(5,0), padx=(10,10))

		self.r1 = tk.Label(self.lbox, image='')
		self.r1.grid(row=0, column=0, pady=3, padx=1)

		self.r2 = tk.Label(self.rbox, image='')
		self.r2.grid(row=0, column=1, pady=3, padx=1)

		self.winner_msg = tk.Label(self.body, text='', fg='green',
						font='verdana 16 bold')
		self.winner_msg.grid(row=2, column=1, columnspan=4)

	def draw_footer_frame(self):
		self.reset_btn = ttk.Button(self.footer, text='Reset', command=self.reset_game)
		self.reset_btn.grid(row=0, column=0, padx=(120,20))

		self.home_btn = ttk.Button(self.footer, text='Home', command=self.go_home)
		self.home_btn.grid(row=0, column=1, padx=10, sticky='w')

	def move(self, user_move):
		self.imIndex = 0
		if self.after_id:
			self.after_cancel(self.after_id)

		sys_move = random.choice(self.moves)

		if user_move == 'rock':
				image1 = rock_large
		elif user_move == 'paper':
			image1 = paper_large
		elif user_move == 'scissor':
			image1 = scissor_large

		if sys_move == 'rock':
			image2 = rock_large
		elif sys_move == 'paper':
			image2 = paper_large
		elif sys_move == 'scissor':
			image2 = scissor_large

		winner = self.check_winner(user_move, sys_move)
		self.update_winner(winner)
		
		if winner == 'You Won!':
			self.animate = True
			list_ = self.imgDict[user_move]
			self.after_id = self.after(100, lambda : self.animate_winner('user', list_))
			self.r2['image'] = image2
		elif winner == 'You Lost!':
			self.animate = True
			list_ = self.imgDict[sys_move]
			self.after_id = self.after(100, lambda : self.animate_winner('sys', list_))
			self.r1['image'] = image1
		else:
			self.r1['image'] = image1
			self.r2['image'] = image2

	def check_winner(self, user_move, sys_move):
		res = None
		if user_move == 'rock':
			if sys_move == 'rock':
				res = 'Draw'
			elif sys_move == 'paper':
				res = 'You Lost!'
			elif sys_move == 'scissor':
				res = 'You Won!'
		elif user_move == 'paper':
			if sys_move == 'rock':
				res = 'You Won!'
			elif sys_move == 'paper':
				res = 'Draw'
			elif sys_move == 'scissor':
				res = 'You Lost!'
		elif user_move == 'scissor':
			if sys_move == 'rock':
				res = 'You Lost!'
			elif sys_move == 'paper':
				res = 'You Won!'
			elif sys_move == 'scissor':
				res = 'Draw'

		return res

	def update_winner(self, winner):
		if winner == 'You Won!':
			fg = 'green'
			self.userPoint += 1
			self.upoint['text'] = f'({self.userPoint})'
		elif winner == 'You Lost!':
			fg = 'red'
			self.sysPoint += 1
			self.spoint['text'] = f'({self.sysPoint})'
		elif winner == 'Draw':
			fg = 'gray'

		self.winner_msg['fg'] = fg
		self.winner_msg['text'] = winner

	def animate_winner(self, winner, img_list):
		img = img_list[self.imIndex]
		if self.imIndex == 0:
			self.imDelta = 1
		if self.imIndex == 10:
			self.imDelta = -1

		self.imIndex += self.imDelta

		if winner == 'user':
			self.r1.configure(image=img)
		elif winner == 'sys':
			self.r2.configure(image=img)

		self.after_id = self.after(70, lambda : self.animate_winner(winner, img_list))

	def reset_game(self):
		if self.after_id:
			self.after_cancel(self.after_id)

		self.r1['image'] = ''
		self.r2['image'] = ''
		self.userPoint = 0
		self.sysPoint = 0
		self.upoint['text'] = f'({self.userPoint})'
		self.spoint['text'] = f'({self.sysPoint})'
		self.winner_msg['text'] = ''

	def go_home(self):
		self.reset_game()
		self.header.destroy()
		self.body.destroy()
		self.footer.destroy()

		self.main_frame()

			


if __name__ == '__main__':
	root = tk.Tk()
	root.geometry('400x300+420+240')
	root.title('Rock Paper Scissor')

	rps_icon = PhotoImage(file='icons/rps.png')

	rock_small = PhotoImage(file='icons/rock_small.png')
	paper_small = PhotoImage(file='icons/paper_small.png')
	scissor_small = PhotoImage(file='icons/scissor_small.png')

	rock_large = PhotoImage(file='icons/rock_large.png')
	paper_large = PhotoImage(file='icons/paper_large.png')
	scissor_large = PhotoImage(file='icons/scissor_large.png')

	rock_list = [PhotoImage(file=f'animate/rock_large{i}.png') for i in range(11)]
	paper_list = [PhotoImage(file=f'animate/paper_large{i}.png') for i in range(11)]
	scissor_list = [PhotoImage(file=f'animate/scissor_large{i}.png') for i in range(11)]

	app = Application(master=root)
	app.mainloop()
