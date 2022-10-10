using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CMS.Properties;

namespace CMS.BL
{
    class ADMINBL
    {
        private string Name;
        private string Password;

        public string Name1 { get => Name; set => Name = value; }
        public string Password1 { get => Password; set => Password = value; }
        public ADMINBL(string Name,string Password)
        {
            this.Name = Name;
            this.Password = Password;
        }
        public  bool isAdmin()
        {
            if(this.Name == "Ali" && Password == "ali123@")
            {
                return true;
            }
            return false;
        }
    }
}
