using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task_1.BL;
using Task_1.UI;
using Task_1.DL;

namespace Task_1
{
    class Program
    {
        
        public static string Path = "Menu.txt";
        static void Main(string[] args)
        {
            COFFESHOP.readData(Path);
            while (true)
            {
                MenuItems Menu;
                char option = MENUUI.menu();
                MENUUI.clearScreen();
                if(option == '1')
                {
                    Menu=MENUUI.AddMenu(Path);
                    COFFESHOP.AddItemsintoList(Menu);
                }
                else if(option == '2')
                {
                    string Name=COFFESHOP.cheapestItem();
                    Console.WriteLine("Cheapest Item is " + Name);
                }
                else if(option == '3')
                {
                    List<string> Drink = COFFESHOP.drinkOnly();
                    for(int i=0;i<Drink.Count;i++)
                    {
                        Console.WriteLine("Drink Item is "+Drink[i] + " ");
                    }
                }
                else if(option == '4')
                {
                    List<string> Drink = COFFESHOP.foodOnly();
                    for (int i = 0; i < Drink.Count; i++)
                    {
                        Console.WriteLine("Food Item is "+Drink[i] + " ");
                    }
                }
                else if(option == '5')
                {
                    List<string> Order = MENUUI.addOrder();
                    COFFESHOP.AddOrder(Order);
                }
                else if(option == '6')
                {
                    COFFESHOP.fulfillOrder();
                }
                else if(option == '7')
                {
                    COFFESHOP.viewOrderList();
                }
                else if(option == '8')
                {
                    float Result = COFFESHOP.totalPayableAmount();
                    Console.WriteLine("Total Amount is " + Result);
                }
                else if(option == '9')
                {
                    break;
                }
                else
                {
                    continue;
                }
            }

        }
        
    }
}
