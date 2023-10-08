def __init__(self):
	# Create a window
	window = Tk() 
	window.title("Loan Calculator") # Set title

	# create the input boxes.
	Label(window, text = "Annual Interest Rate").grid(row = 1,
									column = 1, sticky = W)
	Label(window, text = "Number of Years").grid(row = 2,
								column = 1, sticky = W)
	Label(window, text = "Loan Amount").grid(row = 3,
							column = 1, sticky = W)
	Label(window, text = "Monthly Payment").grid(row = 4,
								column = 1, sticky = W)
	Label(window, text = "Total Payment").grid(row = 5,
								column = 1, sticky = W)

	# for taking inputs
	self.annualInterestRateVar = StringVar() 
	Entry(window, textvariable = self.annualInterestRateVar,
				justify = RIGHT).grid(row = 1, column = 2)

	self.numberOfYearsVar = StringVar()
	Entry(window, textvariable = self.numberOfYearsVar,
			justify = RIGHT).grid(row = 2, column = 2)

	self.loanAmountVar = StringVar()
	Entry(window, textvariable = self.loanAmountVar,
		justify = RIGHT).grid(row = 3, column = 2)

	self.monthlyPaymentVar = StringVar()
	lblMonthlyPayment = Label(window, textvariable =
				self.monthlyPaymentVar).grid(row = 4,
				column = 2, sticky = E)

	self.totalPaymentVar = StringVar()
	lblTotalPayment = Label(window, textvariable =
				self.totalPaymentVar).grid(row = 5,
				column = 2, sticky = E)
	
	# create the button
	btComputePayment = Button(window, text = "Compute Payment",
						command = self.computePayment).grid(
							row = 6, column = 2, sticky = E) 
	# Create an event loop
	window.mainloop() 
