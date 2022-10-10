using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CMS.BL;

namespace CMS.DL
{
    class AttendanceDL
    {
        private static List<AttendanceClass> AttendanceData = new List<AttendanceClass>();

        internal static List<AttendanceClass> AttendanceData1 { get => AttendanceData; set => AttendanceData = value; }

        public static void addAttendanceIntoList(AttendanceClass Temp)
        {
            AttendanceData1.Add(Temp);
        }

    }
}
