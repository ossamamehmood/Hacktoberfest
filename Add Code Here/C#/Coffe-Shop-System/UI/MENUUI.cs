using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Task_1.BL;
using Task_1.DL;

namespace Task_1.UI
{
    class MENUUI
    {
        public static char menu()
        {
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("1. Add MenuItems");
            Console.WriteLine("2. View The Cheapest Item In The Menu");
            Console.WriteLine("3. View The Drink Menu");
            Console.WriteLine("4. View The Food Item");
            Console.WriteLine("5. Add Order");
            Console.WriteLine("6. Fulfill Order");
            Console.WriteLine("7. View The Order List");
            Console.WriteLine("8. Total Payable Amount");
            Console.WriteLine("9. Exit");
            Console.WriteLine();
            char Option;
            Option = char.Parse(Console.ReadLine());
            return Option;
        }
        public static MenuItems AddMenu(string Path)
        {
            Console.WriteLine("Enter Name of Item");
            string name = Console.ReadLine();
            Console.WriteLine("Enter Type of Items");
            string type = Console.ReadLine();
            type = type.ToUpper();
            Console.WriteLine("Enter price of items");
            int price = int.Parse(Console.ReadLine());
            MenuItems Item = new MenuItems(name,type,price);
            COFFESHOP.storeData(Path, Item);
            return Item;
        }
        public static void clearScreen()
        {
            Console.WriteLine();
            Console.WriteLine("Press Any Key To Continue ");
            Console.Clear();
        }
        public static List<string> addOrder()
        {
            string Item;
            bool flag = false;
            List<string> Order = new List<string>();
            Console.WriteLine("How many order you want to place ");
            int count = int.Parse(Console.ReadLine());
            for (int i = 0; i < count; i++)
            {
                Console.WriteLine("Enter Item Name");
                Item = Console.ReadLine();
                for (int y=0;y<COFFESHOP.Menu.Count;y++)
                {
                    if(Item == COFFESHOP.Menu[i].getName())
                    {
                        Order.Add(Item);
                        flag = true;
                        Console.WriteLine("Order Added ");
                    }
                }
                if(flag == false)
                {
                    Console.WriteLine("This Product is Currently Unavailable ");
                    i--;
                }
            }
            return Order;
        }
    }
}
