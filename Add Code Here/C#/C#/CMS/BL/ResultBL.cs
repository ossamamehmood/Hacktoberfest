using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CMS.BL
{
    class ResultBL
    {
        private string name;
        private string password;
        private float urdu;
        private float math;
        private float english;
        private float computer;
        private float physics;
        private float total;
        public ResultBL(string Name,float urdu,float math,float english,float computer,float physics,string password)
        {
            this.Name = Name;
            this.Urdu = urdu;
            this.Math = math;
            this.Physics = physics;
            this.Computer = computer;
            this.English = english;
            this.password = password;
            this.Total = this.Urdu + this.Physics + this.Math + this.English + this.Computer;
        }
        public string Name { get => name; set => name = value; }
        public float Urdu { get => urdu; set => urdu = value; }
        public float Math { get => math; set => math = value; }
        public float English { get => english; set => english = value; }
        public float Computer { get => computer; set => computer = value; }
        public float Physics { get => physics; set => physics = value; }
        public float Total { get => total; set => total = value; }
        public string Password { get => password; set => password = value; }
    }
}
