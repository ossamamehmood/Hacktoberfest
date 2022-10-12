'''q1
def perfectnum(num):
      my_sum=0;
      for i in range(1, num):
            if(num % i == 0):
                  my_sum+=i
      if(my_sum == num):
            print("The entered number is a perfect number !!!")
      else:
            print("The entered number is not a perfect number !!!")
ch='y'
while (ch=='y'):
      num=int(input("Enter the number : "))
      perfectnum(num)
      ch=input("Do you want to continue?(y/n): ")
'''
'''Q2
while True:
      print("Menu :")
      print("1.Check if all the elements in the list are numbers or not")
      print("2.Display the Reverse Form")
      print("3.Find a specified element in list")
      print("4.Remove a specified element from list")
      print("5.Sort the list in descending order")
      print("6.Accept 2 list and Find common element")
      ch=int(input("Enter your Choice :-"))
      if ch==1:
            lst1 = []
            n = int(input("Enter number of elements :- "))
            print("Enter Elements in list :- ")
            for i in range(0, n):
                  ele1 = input()
                  lst1.append(ele1)
            print("Entered List :- ")
            print(lst1)
            for ele in lst1:
                  res =(ele.isdigit())
            print("Are all Elements in list are digit ?? "+str(res))
            if(res):
                  res = [int(i) for i in lst1]
                  odd_count = len(list(filter(lambda x: (x%2 != 0) , res)))
                  print("Number of Odd elements in the list :- ", odd_count)
                  print()
            else:
                  max_string = max(lst1, key=len)
                  print("The largest string is :- ", max_string)
                  print()
      elif ch==2:
            lst1 = []
            n = int(input("Enter number of elements :- "))
            print("Enter Elements in list :- ")
            for i in range(0, n):
                  ele1 = input()
                  lst1.append(ele1)
            print("Entered List :- ")
            print(lst1)
            lst1.reverse()
            print("Reversed List :-")
            print(lst1)
            print()
      elif ch==3:
            lst=[]
            n = int(input("Enter number of elements :- "))
            for i in range(0, n):
                  ele = int(input())
                  lst.append(ele)
            print("Entered List is :-")
            print(lst)
            no=int(input("Enter the number to be find :- "))
            if no in lst:
                  print("Number Found!")
                  print()
            else:
                  print("Not Found in the list!!")
                  print()
      elif ch==4:
            lst1 = []
            n = int(input("Enter number of elements :- "))
            print("Enter Elements in list :- ")
            for i in range(0, n):
                  ele1 = input()
                  lst1.append(ele1)
            print("Entered List :- ")
            print(lst1)
            rem=input("Enter the no. to be removed :- ")
            lst1.remove(rem)
            print(lst1)
      elif ch==5:
            lst1 = []
            n = int(input("Enter number of elements :- "))
            print("Enter Elements in list :- ")
            for i in range(0, n):
                  ele1 = input()
                  lst1.append(ele1)
            print("Entered List :- ")
            print(lst1)
            print("List After sorting :- ")
            lst1.sort(reverse=True)
            print(lst1)
      elif ch==6:
            lst1 = []
            lst2=[]
            n = int(input("Enter number of elements for 1st list :- "))
            print("Enter Elements in list 1 :- ")
            for i in range(0, n):
                  ele1 = input()
                  lst1.append(ele1)
            print("Entered List 1 is :- ")
            print(lst1)
            n1 = int(input("Enter number of elements for 2nd list :- "))
            print("Enter Elements in List 2 :-")
            for i in range(0, n1):
                  ele1 = input()
                  lst2.append(ele1)
            print("Entered List 2 is :- ")
            print(lst2)
            common=[value for value in lst1 if value in lst2]
            print("Common Value :- ")
            print(common)
      else:
            break
'''
'''Q3
class Student:
      def __init__(self):
            self.name= input("Enter Student Name : ")
            self.roll= input("Enter Student Roll No. : ")
      def display_Student(self):
            print("-> Student Name : ", self.name)
            print("-> Roll No. : ", self.roll)
class Marks:
      def __init__(self):
            self.m1 = int(input("Enter marks in subject 1 : "))
            self.m2 = int(input("Enter marks in subject 2 : "))
            self.m3 = int(input("Enter marks in subject 3 : "))
      def display_Marks(self):
            print("-> Marks in subject 1 : ", self.m1)
            print("-> Marks in subject 2 : ", self.m2)
            print("-> Marks in subject 3 : ", self.m3)
class Result(Marks):
      total=0
      avg=0
      def __init__(self):
            super().__init__()
            self.total = self.m1 + self.m2 + self.m3
            self.avg = self.total/3
      def display_Result(self):
            super().display_Marks()
            print("-> Total Marks : ", self.total)
            print("-> Average Marks : ", self.avg)
class Grade(Student,Result):
      def __init__(self):
            Student.__init__(self)
            Result.__init__(self)
            if self.avg > 90:
                  self.grade = "A"
            elif self.avg > 80 or self.avg < 90 :
                  self.grade = "B"
            elif self.avg >70 or self.avg<80 :
                  self.grade = "C"
            else:
                  self.grade = "D"
      def display_Grade(self):
            Student.display_Student(self)
            Result.display_Result(self)
            print("-> Grade : ", self.grade)

#Driver code
print("\t STUDENT DETAILS ")
g1=Grade()
g1.display_Grade()
'''



