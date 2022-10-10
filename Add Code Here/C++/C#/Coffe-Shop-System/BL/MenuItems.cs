using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task_1.BL
{
    class MenuItems
    {
        string Name;
        string Type;
        float Price;
        public MenuItems(string Name,string Type,float Price)
        {
            this.Name = Name;
            this.Price = Price;
            this.Type = Type;
        }
        public string getName()
        {
            return Name;
        }
        public string getType()
        {
            return Type;
        }
        public float getPrice()
        {
            return Price;
        }

    }
}
