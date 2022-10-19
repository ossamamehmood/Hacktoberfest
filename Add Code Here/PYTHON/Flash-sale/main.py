import tkinter as tk

NUMBER_OF_DATA = -1
NUMBER_OF_ORDER = -1


def readData():
    global NUMBER_OF_DATA
    DATA = {"Name": [], "Price": []}
    try:
        file = open("MOCK_DATA.txt", "r", encoding="utf8")
        # print(file.read())
        temp = file.read().split("\n")
        NUMBER_OF_DATA = len(temp)
        for i in range(NUMBER_OF_DATA):
            filed = temp[i].split("|")
            DATA['Name'].append(filed[0])
            DATA['Price'].append(filed[1])
        print("readFile success have", NUMBER_OF_DATA, "items")
        file.close()

    except:
        print("Error can't read Data from MOCK_DATA.txt")
    return DATA


def showWithPage():

    global NUMBER_OF_DATA, frame, pageAtt, key
    middleFrame = frame['middle']
    paginateFrame = frame['page']
    clearFrame(middleFrame)
    clearFrame(paginateFrame)
    print("SHOW ITEM")

    DATA = readData()
    ignoreIndex = []
    count = 0

    searchInit("item")

    startNumberOfItem = (pageAtt['page']-1) * pageAtt['itemPerPage']
    endNumberOfItem = (pageAtt['page'] * pageAtt['itemPerPage'])

    if endNumberOfItem > NUMBER_OF_DATA:
        endNumberOfItem = NUMBER_OF_DATA

    for i in range(NUMBER_OF_DATA):
        if key in DATA['Name'][i].lower() or key == str(i+1):
            if startNumberOfItem <= count < endNumberOfItem:
                tk.Label(middleFrame, text=str(i+1)).grid(
                    row=i, column=0, sticky='NSEW', ipadx=10)
                tk.Label(middleFrame, text=DATA['Name'][i], anchor="w").grid(
                    row=i, column=1, sticky='NSEW', ipadx=10)
                tk.Label(middleFrame, text=DATA['Price'][i], anchor="e").grid(
                    row=i, column=2, sticky='NSEW', ipadx=10)

            count += 1
            if count >= endNumberOfItem:
                break

    minusBtn = tk.Button(paginateFrame, text='<', bg="red",
                         command=lambda: changePageNumber(False)).pack(side=tk.LEFT)
    pageLabel = tk.Label(
        paginateFrame, text=pageAtt['page']).pack(side=tk.LEFT)
    pulsBtn = tk.Button(paginateFrame, text='>', bg="green",
                        command=lambda: changePageNumber(True)).pack(side=tk.LEFT)

    middleFrame.pack(pady=10)
    paginateFrame.pack()


def clearFrame(frame):
    # destroy all widgets from frame
    for widget in frame.winfo_children():
        widget.destroy()

    # this will clear frame and frame will be empty
    # if you want to hide the empty panel then
    # frame.pack_forget()


def changePageNumber(isPlus=True):
    global NUMBER_OF_DATA, frame, pageAtt
    if isPlus and pageAtt['page']*pageAtt['itemPerPage'] < NUMBER_OF_DATA:
        pageAtt['page'] = pageAtt['page'] + 1
    elif not isPlus and pageAtt['page'] > 1:
        pageAtt['page'] = pageAtt['page'] - 1
    showWithPage()
    print("now page ", pageAtt['page'])


def insertItem(var):
    clearFrame(frame['error'])
    name = var[0].get()
    price = var[1].get()
    var[0].set("")
    var[1].set("")
    # print(name, price)

    if name != '' and price != '' and price.isnumeric():
        try:
            file = open("MOCK_DATA.txt", "a", encoding="utf8")
            file.write('\n' + name+"|"+price)
            file.close()
            selectFunction("Item")
        except:
            print("Error can't read Data from MOCK_DATA.txt")
    else:
        error = tk.Label(
            frame['error'], text="Please fill all input block", fg="red", pady=5).pack()
        frame['error'].pack()


def insertItemInputBlock():
    global frame
    clearFrame(frame['error'])
    clearFrame(frame['bottomBTN'])

    var = [tk.StringVar(), tk.StringVar()]

    labelName = tk.Label(frame['bottomBTN'], text="Name").grid(
        row=0, column=0, sticky='NSEW', padx=1)
    InputName = tk.Entry(frame['bottomBTN'], textvariable=var[0]).grid(
        row=0, column=1, sticky='NSEW', padx=1)
    labelPrice = tk.Label(frame['bottomBTN'], text="Price").grid(
        row=0, column=2, sticky='NSEW', padx=1)
    InputPrice = tk.Entry(frame['bottomBTN'], textvariable=var[1]).grid(
        row=0, column=3, sticky='NSEW', padx=1)

    okButton = tk.Button(frame['bottomBTN'], text="submit", command=lambda: insertItem(var)).grid(
        row=1, column=0, columnspan=4, sticky='N', padx=1, pady=5)

    frame['bottomBTN'].pack(pady=10)


def deleteItem(var):
    clearFrame(frame['error'])
    No = var[0].get()
    var[0].set("")

    if No != '' and No.isnumeric() and int(No) <= NUMBER_OF_DATA:
        No = int(No)
        try:
            file = open("MOCK_DATA.txt", "r", encoding="utf8")
            temp = file.read().split("\n")
            file.close()

            temp.pop(No-1)
            strToWrite = "\n".join(temp)

            file = open("MOCK_DATA.txt", "w", encoding="utf8")
            file.write(strToWrite)
            file.close()

            selectFunction("Item")
        except:
            print("Error can't read Data from MOCK_DATA.txt")
    else:
        error = tk.Label(
            frame['error'], text="Plase input in range", fg="red", pady=5).pack()
        frame['error'].pack()


def deleteItemInputBlock():
    global frame
    clearFrame(frame['error'])
    clearFrame(frame['bottomBTN'])
    No = [tk.StringVar()]

    labelIndex = tk.Label(frame['bottomBTN'], text="No.").grid(
        row=0, column=0, sticky='NSEW', padx=1)
    InputName = tk.Entry(frame['bottomBTN'], textvariable=No[0]).grid(
        row=0, column=1, sticky='NSEW', padx=1)

    okButton = tk.Button(frame['bottomBTN'], text="submit", command=lambda: deleteItem(No)).grid(
        row=1, column=0, columnspan=4, sticky='N', padx=1, pady=5)

    frame['bottomBTN'].pack(pady=10)


def editItem(var):
    clearFrame(frame['error'])
    no = var[0].get()
    name = var[1].get()
    price = var[2].get()
    var[0].set("")
    var[1].set("")
    var[2].set("")

    if no != '' and name != '' and price != '' and no.isnumeric() and price.isnumeric() and int(no) <= NUMBER_OF_DATA:
        no = int(no)
        try:
            file = open("MOCK_DATA.txt", "r", encoding="utf8")
            temp = file.read().split("\n")
            file.close()

            temp[no-1] = name+"|"+price
            strToWrite = "\n".join(temp)

            file = open("MOCK_DATA.txt", "w", encoding="utf8")
            file.write(strToWrite)
            file.close()

            selectFunction("Item")
        except:
            print("Error can't read Data from MOCK_DATA.txt")
    else:
        error = tk.Label(
            frame['error'], text="Plase input in range and fill all input block", fg="red", pady=5).pack()
        frame['error'].pack()


def editItemInputBlock():
    global frame
    clearFrame(frame['error'])
    clearFrame(frame['bottomBTN'])

    var = [tk.StringVar(), tk.StringVar(), tk.StringVar()]

    labelName = tk.Label(frame['bottomBTN'], text="No").grid(
        row=0, column=0, sticky='NSEW', padx=1)
    InputName = tk.Entry(frame['bottomBTN'], textvariable=var[0]).grid(
        row=0, column=1, sticky='NSEW', padx=1)
    labelName = tk.Label(frame['bottomBTN'], text="Name").grid(
        row=1, column=0, sticky='NSEW', padx=1)
    InputName = tk.Entry(frame['bottomBTN'], textvariable=var[1]).grid(
        row=1, column=1, sticky='NSEW', padx=1)
    labelPrice = tk.Label(frame['bottomBTN'], text="Price").grid(
        row=1, column=2, sticky='NSEW', padx=1)
    InputPrice = tk.Entry(frame['bottomBTN'], textvariable=var[2]).grid(
        row=1, column=3, sticky='NSEW', padx=1)

    okButton = tk.Button(frame['bottomBTN'], text="submit", command=lambda: editItem(var)).grid(
        row=2, column=0, columnspan=4, sticky='N', padx=1, pady=5)

    frame['bottomBTN'].pack(pady=10)


def ItemManage():
    global frame
    clearFrame(frame['bottom'])

    showWithPage()

    btn1 = tk.Button(frame['bottom'], text='Insert new item',
                     command=lambda: insertItemInputBlock()).grid(
        row=0, column=0, sticky='NSEW', padx=5)
    btn2 = tk.Button(frame['bottom'], text='Delete item',
                     command=lambda: deleteItemInputBlock()).grid(
        row=0, column=1, sticky='NSEW', padx=5)
    btn3 = tk.Button(frame['bottom'], text='Edit item',
                     command=lambda: editItemInputBlock()).grid(
        row=0, column=2, sticky='NSEW', padx=5)
    btn4 = tk.Button(frame['bottom'], text='Add new order',
                     command=lambda: newOrderSetup()).grid(
        row=0, column=3, sticky='NSEW', padx=5)

    frame['bottom'].pack(pady=10)


def changeOrderPageNumber(isPlus=True):
    global NUMBER_OF_ORDER, pageOrderAtt
    if isPlus and pageOrderAtt['page']*pageOrderAtt['itemPerPage'] < NUMBER_OF_ORDER:
        pageOrderAtt['page'] = pageOrderAtt['page'] + 1
    elif not isPlus and pageOrderAtt['page'] > 1:
        pageOrderAtt['page'] = pageOrderAtt['page'] - 1
    showOrder()
    print("now order page ", pageOrderAtt['page'])


def readOrder():
    # * order schematic
    # order = [
    #     {
    #     items:[
    #        {
    #          Name:Salad,
    #          Price:234,
    #          Quantity:2
    #        },
    #        {
    #          Name:milk,
    #          Price:134,
    #          Quantity:3
    #        }
    #     ],
    #     summaryQuantity: 5,
    #     summaryPrice: 4252,
    #     CName: username,
    #     CAddress: 34 dishr sdjfo,
    #     CPhone: 0999999999
    #     },
    #     ...
    # ]
    # ? Sachet:1937:2#Milk - Homo:378:1|3|4252|
    # ? USERNAME|ADDRESS|0999999999
    global NUMBER_OF_ORDER
    orders = []
    try:
        file = open("ORDER.txt", "r", encoding="utf8")
        # print(file.read())
        temp = file.read().split("\n")
        NUMBER_OF_ORDER = len(temp)
        for i in range(NUMBER_OF_ORDER):
            order = {}
            listOfItem = []

            filed = temp[i].split("|")
            items = filed[0].split("#")
            for item in items:

                detail = item.split(":")

                obj = {}
                obj['Name'] = detail[0]
                obj['Price'] = int(detail[1])
                obj['Quantity'] = int(detail[2])
                listOfItem.append(obj)

            order['items'] = listOfItem
            order['summaryQuantity'] = filed[1]
            order['summaryPrice'] = filed[2]
            order['CName'] = filed[3]
            order['CAddress'] = filed[4]
            order['CPhone'] = filed[5]

            orders.append(order)
        print("readFile success have", NUMBER_OF_ORDER, "orders")
        file.close()

    except:
        print("Error can't read Data from ORDER.txt")
    return orders


def changeKey(var, menu):
    global key, pageAtt, pageOrderAtt
    key = var.get().lower()
    # print("in", menu, "find", key)
    if menu == "order":
        pageOrderAtt['page'] = 1
        showOrder()
    elif menu == "item":
        pageAtt['page'] = 1
        showWithPage()


def searchInit(menu):
    global frame
    var = tk.StringVar()
    labelSearch = tk.Label(frame['search'], text="search").grid(
        row=0, column=0, sticky='W', padx=1)
    inputSearch = tk.Entry(frame['search'], textvariable=var).grid(
        row=0, column=1, columnspan=2, sticky='W', padx=1)
    searchBtn = tk.Button(frame['search'], text='Q',
                          command=lambda: changeKey(var, menu)).grid(
        row=0, column=3, sticky='W', padx=3)

    frame['search'].pack(pady=5)


def showOrder():

    global NUMBER_OF_ORDER, frame, pageOrderAtt, key
    middleFrame = frame['middle']
    paginateFrame = frame['page']
    clearFrame(middleFrame)
    clearFrame(paginateFrame)
    clearFrame(frame['bottom'])
    clearFrame(frame['bottomBTN'])

    orders = readOrder()
    ignoreIndex = []
    count = 0

    searchInit("order")

    for i in range(NUMBER_OF_ORDER):
        inOrder = False
        for j in range(len(orders[i]['items'])):
            if key in orders[i]['items'][j]['Name'].lower():
                inOrder = True
                break
        if not(key == str(i+1) or key in orders[i]['CName'].lower() or key in orders[i]['CAddress'].lower() or key in orders[i]['CPhone'] or inOrder):
            ignoreIndex.append(i)

    # print(ignoreIndex)
    if NUMBER_OF_ORDER > 0:
        # ต้องแสดง order ที่เท่าไรถึงเท่าไร
        startNumberOfItem = (
            pageOrderAtt['page']-1) * pageOrderAtt['itemPerPage']
        endNumberOfItem = (pageOrderAtt['page'] * pageOrderAtt['itemPerPage'])

        if endNumberOfItem > NUMBER_OF_ORDER-len(ignoreIndex):
            endNumberOfItem = NUMBER_OF_ORDER-len(ignoreIndex)

        rowCounter = 0
        for i in range(NUMBER_OF_ORDER):

            if not(i in ignoreIndex):

                if startNumberOfItem <= count < endNumberOfItem:

                    tk.Label(middleFrame, text="ORDERED: "+str(i+1)).grid(
                        row=rowCounter, column=0, sticky='W', ipadx=10)
                    rowCounter += 1

                    for j in range(len(orders[i]['items'])):
                        tk.Label(middleFrame, text=str(j+1)+" "+orders[i]['items'][j]['Name']).grid(
                            row=rowCounter, column=0, columnspan=3, sticky='W', ipadx=10)
                        tk.Label(middleFrame, text=orders[i]['items'][j]['Price']).grid(
                            row=rowCounter, column=3, sticky='W', ipadx=10)
                        tk.Label(middleFrame, text=" X " + str(orders[i]['items'][j]['Quantity'])).grid(
                            row=rowCounter, column=4, sticky='W', ipadx=10)
                        rowCounter += 1

                    tk.Label(middleFrame, text="QUANTITY: "+orders[i]['summaryQuantity']).grid(
                        row=rowCounter, column=0, sticky='W', ipadx=10)
                    rowCounter += 1
                    tk.Label(middleFrame, text="PRICE: "+orders[i]['summaryPrice']).grid(
                        row=rowCounter, column=0, sticky='W', ipadx=10)
                    rowCounter += 1
                    tk.Label(middleFrame, text="CUSTOMER NAME: "+orders[i]['CName']).grid(
                        row=rowCounter, column=0, sticky='W', ipadx=10)
                    rowCounter += 1
                    tk.Label(middleFrame, text="ADDRESS: "+orders[i]['CAddress']).grid(
                        row=rowCounter, column=0, sticky='W', ipadx=10)
                    rowCounter += 1
                    tk.Label(middleFrame, text="TEL: "+orders[i]['CPhone']).grid(
                        row=rowCounter, column=0, sticky='W', ipadx=10)
                    rowCounter += 1

                    tk.Label(middleFrame, text="-"*30).grid(
                        row=rowCounter, column=0, sticky='NSEW', ipadx=10)
                    rowCounter += 1

                count += 1
                if count >= endNumberOfItem:
                    break

        minusBtn = tk.Button(paginateFrame, text='<', bg="red",
                             command=lambda: changeOrderPageNumber(False)).pack(side=tk.LEFT)
        pageLabel = tk.Label(
            paginateFrame, text=pageOrderAtt['page']).pack(side=tk.LEFT)
        pulsBtn = tk.Button(paginateFrame, text='>', bg="green",
                            command=lambda: changeOrderPageNumber(True)).pack(side=tk.LEFT)

        middleFrame.pack(pady=10)
        paginateFrame.pack()


def addField(var):
    clearFrame(frame['error'])
    var['items'].append((tk.StringVar(), tk.StringVar()))
    var['maxField'] += 1
    newOrderBlock(var)


def deleteField(var):
    if var['maxField'] > 1:
        var['items'].pop()
        var['maxField'] -= 1
    else:
        error = tk.Label(
            frame['error'], text="Can't delete all of file", fg="red", pady=5).pack()
        frame['error'].pack()
    newOrderBlock(var)


def newOrderSetup():
    var = {'items': [(tk.StringVar(), tk.StringVar())], 'name': tk.StringVar(
    ), 'address': tk.StringVar(), 'phone': tk.StringVar(), 'maxField': 1}

    clearFrame(frame['error'])
    newOrderBlock(var)


def addNewOder(var):
    clearFrame(frame['error'])
    try:
        phone = var['phone'].get()
        name = var['name'].get()
        address = var['address'].get()
        if phone == '' or name == '' or address == '':
            error = tk.Label(
                frame['error'], text="Please fill all input block", fg="red", pady=5).pack()
            frame['error'].pack()
            return

        strToWrite = ["", "", "", name, address, phone]
        items = []
        sumQ = 0
        sumP = 0
        DATA = readData()

        for temp in var['items']:
            num = temp[0].get()
            q = temp[1].get()

            if num == '' or q == '':
                error = tk.Label(
                    frame['error'], text="Please fill all input block", fg="red", pady=5).pack()
                frame['error'].pack()
                return

            num = int(num)
            if num <= NUMBER_OF_DATA and num > 0 and q.isnumeric():
                items.append(DATA['Name'][num-1] +
                             ":" + DATA['Price'][num-1]+":"+q)
                sumQ += int(q)
                sumP += int(DATA['Price'][num-1])*int(q)
            else:
                error = tk.Label(
                    frame['error'], text="Please input in range", fg="red", pady=5).pack()
                frame['error'].pack()
                return

        strToWrite[0] = "#".join(items)
        strToWrite[1] = str(sumQ)
        strToWrite[2] = str(sumP)
        strToWrite = "|".join(strToWrite)

        file = open("ORDER.txt", "a", encoding="utf8")
        file.write('\n' + strToWrite)
        file.close()
        selectFunction("showOrder")
    except:
        error = tk.Label(
            frame['error'], text="Can't write this ORDER", fg="red", pady=5).pack()
        frame['error'].pack()


def newOrderBlock(var):

    global frame
    clearFrame(frame['bottomBTN'])

    for i in range(var['maxField']):
        labelName = tk.Label(frame['bottomBTN'], text="Item No*").grid(
            row=i, column=0, sticky='W', padx=1)
        InputName = tk.Entry(frame['bottomBTN'], textvariable=var['items'][i][0]).grid(
            row=i, column=1, sticky='W', padx=1)
        labelName = tk.Label(frame['bottomBTN'], text="Quantity*").grid(
            row=i, column=2, sticky='W', padx=1)
        InputName = tk.Entry(frame['bottomBTN'], textvariable=var['items'][i][1]).grid(
            row=i, column=3, sticky='W', padx=1)

    deleteButton = tk.Button(frame['bottomBTN'], text="- delete last item", bg="red", command=lambda: deleteField(var)).grid(
        row=var['maxField'], column=1,  sticky='N', padx=1, pady=5)
    addButton = tk.Button(frame['bottomBTN'], text="+ add another item", bg="green", command=lambda: addField(var)).grid(
        row=var['maxField'], column=2,  sticky='N', padx=1, pady=5)

    labelPrice = tk.Label(frame['bottomBTN'], text="Customer name*").grid(
        row=var['maxField']+2, column=0, sticky='W', padx=1)
    InputPrice = tk.Entry(frame['bottomBTN'], textvariable=var['name']).grid(
        row=var['maxField']+2, column=1, sticky='W', padx=1)
    labelPrice = tk.Label(frame['bottomBTN'], text="Phone number*").grid(
        row=var['maxField']+2, column=2, sticky='W', padx=1)
    InputPrice = tk.Entry(frame['bottomBTN'], textvariable=var['phone']).grid(
        row=var['maxField']+2, column=3, sticky='W', padx=1)
    labelPrice = tk.Label(frame['bottomBTN'], text="Customer Address*").grid(
        row=var['maxField']+3, column=0, sticky='W', padx=1)
    InputPrice = tk.Entry(frame['bottomBTN'], textvariable=var['address'], width=60).grid(
        row=var['maxField']+3, column=1, columnspan=4,  sticky='W', padx=1)

    okButton = tk.Button(frame['bottomBTN'], text="submit", command=lambda: addNewOder(var)).grid(
        row=var['maxField']+4, column=0, columnspan=4, sticky='N', padx=1, pady=5)

    frame['bottomBTN'].pack(pady=10)


def selectFunction(keyword):
    global frame, key

    keywordList = ["Item", "showOrder"]
    functionTuple = (ItemManage, showOrder)

    key = ""
    clearFrame(frame['error'])

    try:
        index = keywordList.index(keyword)

        if index >= 0:
            functionTuple[index]()
    except:
        error = tk.Label(
            frame['error'], text="Can't select this choice", fg="red", pady=5).pack()
        frame['error'].pack()


app = tk.Tk()
app.title('CONSTRUCTION FLASH SALE')

errorFrame = tk.Frame()
buttonFrame = tk.Frame()
middleFrame = tk.Frame()
paginateFrame = tk.Frame()
bottomFrame = tk.Frame()
bottomBTNFrame = tk.Frame()
searchFrame = tk.Frame()

frame = {"error": errorFrame, "button": buttonFrame,
         "middle": middleFrame, "page": paginateFrame,
         "bottom": bottomFrame, "bottomBTN": bottomBTNFrame,
         "search": searchFrame}
pageAtt = {"page": 1, "itemPerPage": 10}
pageOrderAtt = {"page": 1, "itemPerPage": 2}
key = ""

question = tk.Label(app, text='Please select a choice', pady=5).pack()

btn1 = tk.Button(frame['button'], text='Show or Manage items',
                 command=lambda: selectFunction("Item")).grid(
    row=0, column=0, sticky='NSEW', padx=5)
btn2 = tk.Button(frame['button'], text='show order',
                 command=lambda: selectFunction("showOrder")).grid(
    row=0, column=1, sticky='NSEW', padx=5)

frame['button'].pack()
frame['search'].pack()

app.geometry("500x710")
app.mainloop()
