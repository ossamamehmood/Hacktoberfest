using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task_1.BL;
using Task_1.UI;

namespace Task_1.DL
{
    class COFFESHOP
    {
        string Name;
        public static List<string> Orders = new List<string>();
        public static List<MenuItems> Menu = new List<MenuItems>();
        public static void readData(string Path)
        {
            StreamReader CFile = new StreamReader(Path);
            string Record;
            if(File.Exists(Path))
            {
                while((Record = CFile.ReadLine())!=null)
                {
                    string[] SplitRecord = Record.Split(',');
                    string Name = SplitRecord[0];
                    string Type = SplitRecord[1];
                    float Price =float.Parse( SplitRecord[2]);
                    MenuItems Item = new MenuItems(Name, Type, Price);
                    AddItemsintoList(Item);
                }
                CFile.Close();
                Console.WriteLine("Data Loaded Successfully ");
            }
        }
        public static void storeData(string Path,MenuItems Item)
        {
            StreamWriter Writer = new StreamWriter(Path, true);
            Writer.WriteLine(Item.getName() + "," + Item.getType() + "," + Item.getPrice());
            Writer.Flush();
            Writer.Close();
        }
        public static void AddItemsintoList(MenuItems Item)
        {
            Menu.Add(Item);
        }
        public static string cheapestItem()
        {
            for(int i=0;i<Menu.Count;i++)
            {
                for(int y=0;y<Menu.Count-1;y++)
                {
                    if(Menu[y].getPrice() < Menu[y+1].getPrice())
                    {
                        MenuItems Temp = Menu[y + 1];
                        Menu[y + 1] = Menu[y];
                        Menu[y] = Temp;
                    }
                }
            }
            return Menu[0].getName();
        }
        public static List<string> drinkOnly()
        {
            List<string> Temp = new List<string>();
            for(int i=0;i<Menu.Count;i++)
            {
                if(Menu[i].getType() == "DRINK")
                {
                    Temp.Add(Menu[i].getName());
                }
            }
            return Temp;
        }
        public static List<string> foodOnly()
        {
            List<string> Temp = new List<string>();
            for (int i = 0; i < Menu.Count; i++)
            {
                if (Menu[i].getType() == "FOOD")
                {
                    Temp.Add(Menu[i].getName());
                }
            }
            return Temp;
        }
        public static void AddOrder(List<string> Temp)
        {
            Orders.AddRange(Temp);
        }
        public static void fulfillOrder()
        {
            for(int i=0;i<Orders.Count;i++)
            {
                Console.WriteLine("The {0} is Readdy", Orders[i]);
                Orders.RemoveAt(i);
            }
            if(Orders.Count == 0)
            {
                Console.WriteLine("All Order Are FullFilled");
            }
        }
        public static void viewOrderList()
        {
            for(int i=0;i<Orders.Count;i++)
            {
                Console.WriteLine("Order is " + Orders[i]);
            }
        }
        public static float totalPayableAmount()
        {
            float Result = 0F;
            for(int i=0;i<Orders.Count;i++)
            {
                for(int y=0;y<Menu.Count;y++)
                {
                    if(Orders[i] == Menu[y].getName())
                    {
                        Result = Result + Menu[y].getPrice();
                    }    
                }
            }
            return Result;
        }

    }
}
