using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CMS.BL
{
    class AttendanceClass
    {
        private string name;
        private float percentage;
        public AttendanceClass(string name,float percentage)
        {
            this.Name = name;
            this.Percentage = percentage;
        }

        public string Name { get => name; set => name = value; }
        public float Percentage { get => percentage; set => percentage = value; }

        public static float calculatePercentage(float month,float days)
        {
            float percentage = 0;
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                percentage = (100 * days) / 31;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                percentage = (100 * days) / 30;
            }
            else if (month == 2)
            {
                percentage = (100 * days) / 28;
            }
            
            return percentage;
        }
    }
}
