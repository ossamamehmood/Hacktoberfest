from tkinter import *
import tkinter.messagebox
import random
import time
import datetime
#========================== GUI CONFIGURATION ===========================#
root = Tk()
root.geometry("1350x750+0+0")
root.title("Restaurant Management System")
root.configure(background = "cadet blue")
root.resizable(0,0)
#============================ WORKING AREA ==============================#
Tops = Frame(root,bg="navy blue",bd=20,padx=20,relief=RIDGE)
Tops.pack(side=TOP)
lblTitle = Label(Tops,font = ("arial",60,"bold"),text="Restaurant Management System",bd=21,bg="navy blue",fg="white",justify=CENTER)
lblTitle.grid(row=0,column=0)

ReceiptCal_F = Frame(root,bg="cadet blue",bd=10,relief=RIDGE)
ReceiptCal_F.pack(side=RIGHT)
Buttons_F = Frame(ReceiptCal_F,bg="cadet blue",bd=3,relief=RIDGE)
Buttons_F.pack(side=BOTTOM)
Cal_F = Frame(ReceiptCal_F,bg="cadet blue",bd=6,relief=RIDGE)
Cal_F.pack(side=TOP)
Receipt_F = Frame(ReceiptCal_F,bg="cadet blue",bd=4,relief=RIDGE)
Receipt_F.pack(side=BOTTOM)

MenuFrame = Frame(root,bg="cadet blue",bd=10,relief=RIDGE)
MenuFrame.pack(side=LEFT)
Drinks_F = Frame(MenuFrame,bg="powder blue",bd=10)
Drinks_F.pack(side=TOP)
Name_F = Frame(MenuFrame,bg="black",bd=4)
Name_F.pack(side=BOTTOM)
Cost_F = Frame(MenuFrame,bg="powder blue",bd=4)
Cost_F.pack(side=BOTTOM)

Drinks_F = Frame(MenuFrame,bg="powder blue",bd=10,relief=RIDGE)
Drinks_F.pack(side=LEFT)
MainCourse_F = Frame(MenuFrame,bg="powder blue",bd=10,relief=RIDGE)
MainCourse_F.pack(side=RIGHT)
#============================== VARIABLES ==============================#
var1 = IntVar()
var2 = IntVar()
var3 = IntVar()
var4 = IntVar()
var5 = IntVar()
var6 = IntVar()
var7 = IntVar()
var8 = IntVar()
var9 = IntVar()
var10 = IntVar()
var11 = IntVar()
var12 = IntVar()
var13 = IntVar()
var14 = IntVar()
var15 = IntVar()
var16 = IntVar()
DateofOrder = StringVar()
DateofOrder.set(time.strftime("%d/%m/%Y"))
Receipt_Ref = StringVar()
PaidTax = StringVar()
SubTotal = StringVar()
TotalCost = StringVar()
CostofMainCourse = StringVar()
CostofDrinks = StringVar()
ServiceCharge = StringVar()
text_Input = StringVar()
Customer = StringVar()
Mobile = StringVar()
operator = ""

E_Fanta = StringVar()
E_Fanta.set("0")
E_Limca = StringVar()
E_Limca.set("0")
E_CocaCola = StringVar()
E_CocaCola.set("0")
E_Pepsi = StringVar()
E_Pepsi.set("0")
E_ThumbsUp = StringVar()
E_ThumbsUp.set("0")
E_Coffee = StringVar()
E_Coffee.set("0")
E_Tea = StringVar()
E_Tea.set("0")
E_Beer = StringVar()
E_Beer.set("0")

E_DalMakhani = StringVar()
E_DalMakhani.set("0")
E_ShahiPaneer = StringVar()
E_ShahiPaneer.set("0")
E_DumAloo = StringVar()
E_DumAloo.set("0")
E_IdliSambhar = StringVar()
E_IdliSambhar.set("0")
E_PavBhaji = StringVar()
E_PavBhaji.set("0")
E_ChholeBhature = StringVar()
E_ChholeBhature.set("0")
E_Naan = StringVar()
E_Naan.set("0")
E_TandooriRoti = StringVar()
E_TandooriRoti.set("0")

#========================= FUNCTIONS (DRINKS) ==========================#
def chkFanta():
    if(var1.get()==1):
        txtFanta.configure(state=NORMAL)
        txtFanta.focus()
        txtFanta.delete("0",END)
        E_Fanta.set("")
    elif(var1.get() == 0):
        txtFanta.configure(state=DISABLED)
        E_Fanta.set("0")
def chkLimca():
    if(var2.get()==1):
        txtLimca.configure(state=NORMAL)
        txtLimca.focus()
        txtLimca.delete("0",END)
        E_Limca.set("")
    elif(var2.get() == 0):
        txtLimca.configure(state=DISABLED)
        E_Limca.set("0")
def chkCocaCola():
    if(var3.get()==1):
        txtCocaCola.configure(state=NORMAL)
        txtCocaCola.focus()
        txtCocaCola.delete("0",END)
        E_CocaCola.set("")
    elif(var3.get() == 0):
        txtCocaCola.configure(state=DISABLED)
        E_CocaCola.set("0")
def chkPepsi():
    if(var4.get()==1):
        txtPepsi.configure(state=NORMAL)
        txtPepsi.focus()
        txtPepsi.delete("0",END)
        E_Pepsi.set("")
    elif(var4.get() == 0):
        txtPepsi.configure(state=DISABLED)
        E_Pepsi.set("0")
def chkThumbsUp():
    if(var5.get()==1):
        txtThumbsUp.configure(state=NORMAL)
        txtThumbsUp.focus()
        txtThumbsUp.delete("0",END)
        E_ThumbsUp.set("")
    elif(var5.get() == 0):
        txtThumbsUp.configure(state=DISABLED)
        E_ThumbsUp.set("0")
def chkCoffee():
    if(var6.get()==1):
        txtCoffee.configure(state=NORMAL)
        txtCoffee.focus()
        txtCoffee.delete("0",END)
        E_Coffee.set("")
    elif(var6.get() == 0):
        txtCoffee.configure(state=DISABLED)
        E_Coffee.set("0")
def chkTea():
    if(var7.get()==1):
        txtTea.configure(state=NORMAL)
        txtTea.focus()
        txtTea.delete("0",END)
        E_Tea.set("")
    elif(var7.get() == 0):
        txtTea.configure(state=DISABLED)
        E_Tea.set("0")
def chkBeer():
    if(var8.get()==1):
        txtBeer.configure(state=NORMAL)
        txtBeer.focus()
        txtBeer.delete("0",END)
        E_Beer.set("")
    elif(var8.get() == 0):
        txtBeer.configure(state=DISABLED)
        E_Beer.set("0")
#============================== PATENT =================================#
lblName = Label(Name_F,text="\t\t\tMADE BY AAKAR GUPTA\t\t\t\t\t",justify=CENTER,fg="white",bd=2,bg="black",font=("arial",16,"bold"))
lblName.grid()
#============================== DRINKS =================================#
Fanta = Checkbutton(Drinks_F,text="Fanta  ",variable=var1,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkFanta).grid(row=0,sticky=W)
Limca = Checkbutton(Drinks_F,text="Limca  ",variable=var2,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkLimca).grid(row=1,sticky=W)
CocaCola = Checkbutton(Drinks_F,text="Coca~Cola  ",variable=var3,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkCocaCola).grid(row=2,sticky=W)
Pepsi = Checkbutton(Drinks_F,text="Pepsi  ",variable=var4,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkPepsi).grid(row=3,sticky=W)
ThumbsUp = Checkbutton(Drinks_F,text="Thumbs Up  ",variable=var5,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkThumbsUp).grid(row=4,sticky=W)
Coffee = Checkbutton(Drinks_F,text="Coffee  ",variable=var6,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkCoffee).grid(row=5,sticky=W)
Tea = Checkbutton(Drinks_F,text="Tea  ",variable=var7,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkTea).grid(row=6,sticky=W)
Beer = Checkbutton(Drinks_F,text="Beer  ",variable=var8,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkBeer).grid(row=7,sticky=W)
#======================== ENTRY BOX FOR DRINKS =========================#
txtFanta = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Fanta)
txtFanta.grid(row=0,column=1)
txtLimca = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Limca)
txtLimca.grid(row=1,column=1)
txtCocaCola = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_CocaCola)
txtCocaCola.grid(row=2,column=1)
txtPepsi = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Pepsi)
txtPepsi.grid(row=3,column=1)
txtThumbsUp = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_ThumbsUp)
txtThumbsUp.grid(row=4,column=1)
txtCoffee = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Coffee)
txtCoffee.grid(row=5,column=1)
txtTea = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Tea)
txtTea.grid(row=6,column=1)
txtBeer = Entry(Drinks_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Beer)
txtBeer.grid(row=7,column=1)
#========================= FUNCTIONS (MAIN COURSE) =====================#
def chkDalMakhani():
    if(var9.get()==1):
        txtDalMakhani.configure(state=NORMAL)
        txtDalMakhani.focus()
        txtDalMakhani.delete("0",END)
        E_DalMakhani.set("")
    elif(var9.get() == 0):
        txtDalMakhani.configure(state=DISABLED)
        E_DalMakhani.set("0")
def chkShahiPaneer():
    if(var10.get()==1):
        txtShahiPaneer.configure(state=NORMAL)
        txtShahiPaneer.focus()
        txtShahiPaneer.delete("0",END)
        E_ShahiPaneer.set("")
    elif(var10.get() == 0):
        txtShahiPaneer.configure(state=DISABLED)
        E_ShahiPaneer.set("0")
def chkDumAloo():
    if(var11.get()==1):
        txtDumAloo.configure(state=NORMAL)
        txtDumAloo.focus()
        txtDumAloo.delete("0",END)
        E_DumAloo.set("")
    elif(var11.get() == 0):
        txtDumAloo.configure(state=DISABLED)
        E_DumAloo.set("0")
def chkIdliSambhar():
    if(var12.get()==1):
        txtIdliSambhar.configure(state=NORMAL)
        txtIdliSambhar.focus()
        txtIdliSambhar.delete("0",END)
        E_IdliSambhar.set("")
    elif(var12.get() == 0):
        txtIdliSambhar.configure(state=DISABLED)
        E_IdliSambhar.set("0")
def chkPavBhaji():
    if(var13.get()==1):
        txtPavBhaji.configure(state=NORMAL)
        txtPavBhaji.focus()
        txtPavBhaji.delete("0",END)
        E_PavBhaji.set("")
    elif(var13.get() == 0):
        txtPavBhaji.configure(state=DISABLED)
        E_PavBhaji.set("0")
def chkChholeBhature():
    if(var14.get()==1):
        txtChholeBhature.configure(state=NORMAL)
        txtChholeBhature.focus()
        txtChholeBhature.delete("0",END)
        E_ChholeBhature.set("")
    elif(var14.get() == 0):
        txtChholeBhature.configure(state=DISABLED)
        E_ChholeBhature.set("0")
def chkNaan():
    if(var15.get()==1):
        txtNaan.configure(state=NORMAL)
        txtNaan.focus()
        txtNaan.delete("0",END)
        E_Naan.set("")
    elif(var15.get() == 0):
        txtNaan.configure(state=DISABLED)
        E_Naan.set("0")
def chkTandooriRoti():
    if(var16.get()==1):
        txtTandooriRoti.configure(state=NORMAL)
        txtTandooriRoti.focus()
        txtTandooriRoti.delete("0",END)
        E_TandooriRoti.set("")
    elif(var16.get() == 0):
        txtTandooriRoti.configure(state=DISABLED)
        E_TandooriRoti.set("0")
#============================ MAIN COURSE ==============================#
DalMakhani = Checkbutton(MainCourse_F,text="Dal Makhani / Dal Bhukhara   ",variable=var9,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkDalMakhani).grid(row=0,column=2,sticky=W)
ShahiPaneer = Checkbutton(MainCourse_F,text="Shahi Paneer / Paneer Butter Masala   ",variable=var10,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkShahiPaneer).grid(row=1,column=2,sticky=W)
DumAloo = Checkbutton(MainCourse_F,text="Dum Aloo / Masala Aloo   ",variable=var11,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkDumAloo).grid(row=2,column=2,sticky=W)
IdliSambhar = Checkbutton(MainCourse_F,text="Idli Sambhar / Vada Sambhar   ",variable=var12,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkIdliSambhar).grid(row=3,column=2,sticky=W)
PavBhaji = Checkbutton(MainCourse_F,text="Pav Bhaji / Puri Bhaji   ",variable=var13,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkPavBhaji).grid(row=4,column=2,sticky=W)
ChholeBhature = Checkbutton(MainCourse_F,text="Chhole Bhature / Chhole Kulchhe   ",variable=var14,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkChholeBhature).grid(row=5,column=2,sticky=W)
Naan = Checkbutton(MainCourse_F,text="Naan / Butter Naan / Garlic Naan   ",variable=var15,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkNaan).grid(row=6,column=2,sticky=W)
TandooriRoti = Checkbutton(MainCourse_F,text="Tandoori Roti / Tandoori Paratha   ",variable=var16,onvalue=1,offvalue=0,font = ("arial",18,"bold"),bg="powder blue",command=chkTandooriRoti).grid(row=7,column=2,sticky=W)
#====================== ENTRY BOX FOR MAIN COURSE ======================#
txtDalMakhani = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_DalMakhani)
txtDalMakhani.grid(row=0,column=3)
txtShahiPaneer = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_ShahiPaneer)
txtShahiPaneer.grid(row=1,column=3)
txtDumAloo = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_DumAloo)
txtDumAloo.grid(row=2,column=3)
txtIdliSambhar = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_IdliSambhar)
txtIdliSambhar.grid(row=3,column=3)
txtPavBhaji = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_PavBhaji)
txtPavBhaji.grid(row=4,column=3)
txtChholeBhature = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_ChholeBhature)
txtChholeBhature.grid(row=5,column=3)
txtNaan = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_Naan)
txtNaan.grid(row=6,column=3)
txtTandooriRoti = Entry(MainCourse_F,font = ("arial",16,"bold"),bd=8,width=6,justify=LEFT,state=DISABLED,textvariable=E_TandooriRoti)
txtTandooriRoti.grid(row=7,column=3)
#========================= BUTTONS FOR ITEMS ===========================#
"""======================= ORDER INFORMATION ========================="""
lblCustomer = Label(Cost_F,font = ("arial",14,"bold"),text="Customer name ",bg="powder blue",fg="black")
lblCustomer.grid(row=0,column=0,sticky=W)
txtCustomer = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=LEFT,fg="black",textvariable=Customer)
txtCustomer.grid(row=0,column=1)

lblMobile = Label(Cost_F,font = ("arial",14,"bold"),text="\tMobile ",bg="powder blue",fg="black")
lblMobile.grid(row=0,column=2,sticky=W)
txtMobile = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=LEFT,fg="black",textvariable=Mobile)
txtMobile.grid(row=0,column=3)
"""======================= COST INFORMATION =========================="""
lblCostofDrinks = Label(Cost_F,font = ("arial",14,"bold"),text="Cost of Drinks ",bg="powder blue",fg="black")
lblCostofDrinks.grid(row=1,column=0,sticky=W)
txtCostofDrinks = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=RIGHT,fg="black",textvariable=CostofDrinks)
txtCostofDrinks.grid(row=1,column=1)

lblCostofMainCourse = Label(Cost_F,font = ("arial",14,"bold"),text="Cost of Main Course ",bg="powder blue",fg="black")
lblCostofMainCourse.grid(row=2,column=0,sticky=W)
txtCostofMainCourse = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=RIGHT,fg="black",textvariable=CostofMainCourse)
txtCostofMainCourse.grid(row=2,column=1)

lblServiceCharge = Label(Cost_F,font = ("arial",14,"bold"),text="Service Charge ",bg="powder blue",fg="black")
lblServiceCharge.grid(row=3,column=0,sticky=W)
txtServiceCharge = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=RIGHT,fg="black",textvariable=ServiceCharge)
txtServiceCharge.grid(row=3,column=1)
"""====================== PAYMENT INFORMATION ========================"""
lblPaidTax = Label(Cost_F,font = ("arial",14,"bold"),text="\tPaid Tax\t",bg="powder blue",fg="black")
lblPaidTax.grid(row=1,column=2,sticky=W)
txtPaidTax = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=RIGHT,fg="black",textvariable=PaidTax)
txtPaidTax.grid(row=1,column=3)

lblSubTotal = Label(Cost_F,font = ("arial",14,"bold"),text="\tSub Total",bg="powder blue",fg="black")
lblSubTotal.grid(row=2,column=2,sticky=W)
txtSubTotal = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=RIGHT,fg="black",textvariable=SubTotal)
txtSubTotal.grid(row=2,column=3)

lblTotalCost = Label(Cost_F,font = ("arial",14,"bold"),text="\tTotal Cost ",bg="powder blue",fg="black")
lblTotalCost.grid(row=3,column=2,sticky=W)
txtTotalCost = Entry(Cost_F,insertwidth=2,bg="white",bd=7,font = ("arial",14,"bold"),justify=RIGHT,fg="black",textvariable=TotalCost)
txtTotalCost.grid(row=3,column=3)


#======================== ENTRY BOX FOR RECEIPT ========================#
txtReceipt = Text(Receipt_F,width=46,height=15,bg="white",bd=4,font = ("arial",12,"bold"))
txtReceipt.grid(row=0,column=0)
#========================= FUNCTIONS (RECEIPT) =========================#
def iExit():
    iExit = tkinter.messagebox.askyesno("Exit Restaurant System","Are you sure you want to exit?")
    if(iExit > 0):
        root.destroy()
        return
def Reset():
    PaidTax.set("")
    SubTotal.set("")
    TotalCost.set("")
    CostofMainCourse.set("")
    CostofDrinks.set("")
    ServiceCharge.set("")
    txtReceipt.delete("1.0",END)
    
    E_Fanta.set("0")
    E_Limca.set("0")
    E_CocaCola.set("0")
    E_Pepsi.set("0")
    E_ThumbsUp.set("0")
    E_Coffee.set("0")
    E_Tea.set("0")
    E_Beer.set("0")
    
    E_DalMakhani.set("0")
    E_ShahiPaneer.set("0")
    E_DumAloo.set("0")
    E_IdliSambhar.set("0")
    E_PavBhaji.set("0")
    E_ChholeBhature.set("0")
    E_Naan.set("0")
    E_TandooriRoti.set("0")
    
    var1.set(0)
    var2.set(0)
    var3.set(0)
    var4.set(0)
    var5.set(0)
    var6.set(0)
    var7.set(0)
    var8.set(0)
    var9.set(0)
    var10.set(0)
    var11.set(0)
    var12.set(0)
    var13.set(0)
    var14.set(0)
    var15.set(0)
    var16.set(0)
    
    txtFanta.configure(state=DISABLED)
    txtLimca.configure(state=DISABLED)
    txtCocaCola.configure(state=DISABLED)
    txtPepsi.configure(state=DISABLED)
    txtThumbsUp.configure(state=DISABLED)
    txtCoffee.configure(state=DISABLED)
    txtTea.configure(state=DISABLED)
    txtBeer.configure(state=DISABLED)
    
    txtDalMakhani.configure(state=DISABLED)
    txtShahiPaneer.configure(state=DISABLED)
    txtDumAloo.configure(state=DISABLED)
    txtIdliSambhar.configure(state=DISABLED)
    txtPavBhaji.configure(state=DISABLED)
    txtChholeBhature.configure(state=DISABLED)
    txtNaan.configure(state=DISABLED)
    txtTandooriRoti.configure(state=DISABLED)

    txtCustomer.delete("0",END)
    txtMobile.delete("0",END)
def CostofItem():
    Item1=float(E_Fanta.get())
    Item2=float(E_Limca.get())
    Item3=float(E_CocaCola.get())
    Item4=float(E_Pepsi.get())
    Item5=float(E_ThumbsUp.get())
    Item6=float(E_Coffee.get())
    Item7=float(E_Tea.get())
    Item8=float(E_Beer.get())
    Item9=float(E_DalMakhani.get())
    Item10=float(E_ShahiPaneer.get())
    Item11=float(E_DumAloo.get())
    Item12=float(E_IdliSambhar.get())
    Item13=float(E_PavBhaji.get())
    Item14=float(E_ChholeBhature.get())
    Item15=float(E_Naan.get())
    Item16=float(E_TandooriRoti.get())
    PriceofDrinks = (Item1 * 35)+(Item2 * 35)+(Item3 * 45)+(Item4 * 45)+(Item5 * 50)+(Item6 * 40)+(Item7 * 20)+(Item8 * 100)
    PriceofMainCourse = (Item9 * 120)+(Item10 * 100)+(Item11 * 95)+(Item12 * 105)+(Item13 * 75)+(Item14 * 50)+(Item15 * 10)+(Item16 * 8)
    DrinksPrice = "Rs.",str("%.2f"%(PriceofDrinks))
    MainCoursePrice = "Rs.",str("%.2f"%(PriceofMainCourse))
    CostofMainCourse.set(MainCoursePrice)
    CostofDrinks.set(DrinksPrice)
    SC = "Rs.",str("%.2f"%((PriceofDrinks + PriceofMainCourse)*0.05))
    ServiceCharge.set(SC)
    SubTotalofITEMS = "Rs.",str("%.2f"%(PriceofDrinks + PriceofMainCourse + (PriceofDrinks + PriceofMainCourse)*0.05))
    SubTotal.set(SubTotalofITEMS)
    Tax = "Rs.",str("%.2f"%((PriceofDrinks + PriceofMainCourse + (PriceofDrinks + PriceofMainCourse)*0.05)*0.15))
    PaidTax.set(Tax)
    TT = (PriceofDrinks + PriceofMainCourse + (PriceofDrinks + PriceofMainCourse)*0.05)*0.15
    TC = "Rs.",str("%.2f"%(PriceofDrinks + PriceofMainCourse + (PriceofDrinks + PriceofMainCourse)*0.05 + TT))
    TotalCost.set(TC)
def Receipt():
    txtReceipt.delete("1.0",END)
    x = random.randint(10000,100000)
    randomRef = str(x)
    Receipt_Ref.set("BILL " + randomRef)
    txtReceipt.insert(END,"\t\t     RECEIPT\n")
    txtReceipt.insert(END,"\n")
    txtReceipt.insert(END,"Receipt Ref:\t" + Receipt_Ref.get() + "\n")
    txtReceipt.insert(END,"Date of Order:\t" + DateofOrder.get() + "\n")
    txtReceipt.insert(END,"Customer's Name:\t" + Customer.get() + "\n")
    txtReceipt.insert(END,"Customer's Mobile no.:\t" + "+91 " + Mobile.get() + "\n")
    txtReceipt.insert(END,"\n")
    txtReceipt.insert(END,"Fanta:\t\t\t" + E_Fanta.get()+"\n")
    txtReceipt.insert(END,"Limca:\t\t\t" + E_Limca.get()+"\n")
    txtReceipt.insert(END,"Coca~Cola:\t\t\t" + E_CocaCola.get()+"\n")
    txtReceipt.insert(END,"Pepsi:\t\t\t" + E_Pepsi.get()+"\n")
    txtReceipt.insert(END,"Thumbs Up:\t\t\t" + E_ThumbsUp.get()+"\n")
    txtReceipt.insert(END,"Coffee:\t\t\t" + E_Coffee.get()+"\n")
    txtReceipt.insert(END,"Tea:\t\t\t" + E_Tea.get()+"\n")
    txtReceipt.insert(END,"Beer:\t\t\t" + E_Beer.get()+"\n")
    txtReceipt.insert(END,"\n")
    txtReceipt.insert(END,"Dal Makhani:\t\t\t" + E_DalMakhani.get()+"\n")
    txtReceipt.insert(END,"Shahi Paneer:\t\t\t" + E_ShahiPaneer.get()+"\n")
    txtReceipt.insert(END,"Dum Aloo:\t\t\t" + E_DumAloo.get()+"\n")
    txtReceipt.insert(END,"Idli Sambhar:\t\t\t" + E_IdliSambhar.get()+"\n")
    txtReceipt.insert(END,"Pav Bhaji:\t\t\t" + E_PavBhaji.get()+"\n")
    txtReceipt.insert(END,"Chhole Bhature:\t\t\t" + E_ChholeBhature.get()+"\n")
    txtReceipt.insert(END,"Naan:\t\t\t" + E_Naan.get()+"\n")
    txtReceipt.insert(END,"Tandoori Roti:\t\t\t" + E_TandooriRoti.get()+"\n")
    txtReceipt.insert(END,"\n")
    txtReceipt.insert(END,"Cost of Drinks:\t\t\t" + CostofDrinks.get()+"\n")
    txtReceipt.insert(END,"Paid Tax:\t\t\t" + PaidTax.get()+"\n")
    txtReceipt.insert(END,"Cost of Main Course:\t\t\t" + CostofMainCourse.get()+"\n")
    txtReceipt.insert(END,"Sub Total:\t\t\t" + SubTotal.get()+"\n")
    txtReceipt.insert(END,"Service Charge:\t\t\t" + ServiceCharge.get()+"\n")
    txtReceipt.insert(END,"Total:\t\t\t" + TotalCost.get()+"\n")
    txtReceipt.insert(END,"\n")
    txtReceipt.insert(END,"\n")
    txtReceipt.insert(END,"\n")
#========================= BUTTONS FOR RECEIPT =========================#
btnTotal = Button(Buttons_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="Total",bg="powder blue",command=CostofItem).grid(row=0,column=0)
btnReceipt = Button(Buttons_F,padx=18,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=5,text="Receipt",bg="powder blue",command=Receipt).grid(row=0,column=1)
btnReset = Button(Buttons_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="Reset",bg="powder blue",command=Reset).grid(row=0,column=2)
btnExit = Button(Buttons_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="Exit",bg="powder blue",command=iExit).grid(row=0,column=3)
#======================= ENTRY BOX FOR CALCULATOR ======================#
txtDisplay = Entry(Cal_F,width=46,bg="white",bd=4,font = ("arial",12,"bold"),justify=RIGHT,fg="black",textvariable=text_Input)
txtDisplay.grid(row=0,column=0,columnspan=4,pady=1)
txtDisplay.insert(0,"0")
#======================== FUNCTIONS (CALCULATOR) =======================#
def clickbutton(num):
    global operator
    operator = operator + str(num)
    text_Input.set(operator)
def clearbutton():
    global operator
    operator = ""
    text_Input.set("")
def equalbutton():
    global operator
    if(text_Input.get() != ""):
        total = str(eval(operator))
        text_Input.set(total)
        operator = ""
    else:

        text_Input.set("0")
        operator = ""
#======================== BUTTONS FOR CALCULATOR =======================#
btn9 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="9",bg="powder blue",command=lambda: clickbutton(9)).grid(row=2,column=0)
btn8 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="8",bg="powder blue",command=lambda: clickbutton(8)).grid(row=2,column=1)
btn7 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="7",bg="powder blue",command=lambda: clickbutton(7)).grid(row=2,column=2)
btnAdd = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="+",bg="white",command=lambda: clickbutton("+")).grid(row=2,column=3)
btn6 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="6",bg="powder blue",command=lambda: clickbutton(6)).grid(row=3,column=0)
btn5 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="5",bg="powder blue",command=lambda: clickbutton(5)).grid(row=3,column=1)
btn4 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="4",bg="powder blue",command=lambda: clickbutton(4)).grid(row=3,column=2)
btnSubtract = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="-",bg="white",command=lambda: clickbutton("-")).grid(row=3,column=3)
btn3 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="3",bg="powder blue",command=lambda: clickbutton(3)).grid(row=4,column=0)
btn2 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="2",bg="powder blue",command=lambda: clickbutton(2)).grid(row=4,column=1)
btn1 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="1",bg="powder blue",command=lambda: clickbutton(1)).grid(row=4,column=2)
btnMultiply = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="*",bg="white",command=lambda: clickbutton("*")).grid(row=4,column=3)
btnClear = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="C",bg="powder blue",command=clearbutton).grid(row=5,column=0)
btn0 = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="0",bg="powder blue",command=lambda: clickbutton(0)).grid(row=5,column=1)
btnEqual = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="=",bg="powder blue",command=equalbutton).grid(row=5,column=2)
btnDivide = Button(Cal_F,padx=16,pady=1,bd=7,fg="black",font = ("arial",16,"bold"),width=4,text="/",bg="white",command=lambda: clickbutton("/")).grid(row=5,column=3)

root.mainloop()
