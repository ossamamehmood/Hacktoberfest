class CafeQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, customer):
        self.queue.append(customer)
        print(f"{customer} entered the queue.")

    def dequeue(self):
        if not self.is_empty():
            customer = self.queue.pop(0)
            print(f"{customer} left the queue.")
        else:
            print("The queue is empty.")

    def is_empty(self):
        return len(self.queue) == 0

    def view_queue(self):
        print("Current queue:", self.queue)

# Creating a cafe queue object
cafe_queue = CafeQueue()

# Adding customers to the queue
cafe_queue.enqueue("Customer 1")
cafe_queue.enqueue("Customer 2")
cafe_queue.enqueue("Customer 3")

# Viewing the queue
cafe_queue.view_queue()

# Removing a customer from the queue (the server calls the customer's name)
cafe_queue.dequeue()

# Viewing the queue after removing some customers
cafe_queue.view_queue()
