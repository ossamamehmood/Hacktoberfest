import java.util.*;
public class Hotel_Management
{
    Scanner sc = new Scanner(System.in);
    int days, room;
    boolean Type[];
    String date, name, gen, occp, add, pur, rname;
    int adults, child, no;
    double bill;
    boolean breakfast;
    public static void main()
    {
        System.out.println("  o    o         o         8  .oPYo.             8   .oPYo.   o                 ");
        System.out.println("  8    8         8         8  8   `8             8    8       8                 ");
        System.out.println(" o8oooo8 .oPYo. o8P .oPYo. 8 o8YooP' .oPYo. .oPYo8   `Yooo.  o8P  .oPYo. oPYo.  ");
        System.out.println("  8    8 8    8  8  8oooo8 8  8  `b  8oooo8 8    8      `8    8   .oooo8 8  `' ");
        System.out.println("  8    8 8    8  8  8.        8   8  8.     8    8       8    8   8    8 8");
        System.out.println("  8    8 `YooP'  8  `Yooo' 8  8   8  `Yooo' `YooP'   `YooP'   8   `YooP8 8");
        System.out.println(":..:::..:.....:::..::.....:..:::..:::..:.....::.....::::.....:::..::.....:..::::");
        System.out.println("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        System.out.println("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        System.out.println(" ");
        Hotel_Management ob = new Hotel_Management();
        ob.input();
        ob.roomBook();
        ob.registration();
        ob.billCalc();
    }
    public void input()
    {
        System.out.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        System.out.println("              165, General Kim Jong il Road, Pyongyang: 10010876               ");
        System.out.println();
        System.out.println("Dear Customer,");
        System.out.println("A warm welcome to our online booking site, for the greatest hotel in Pyongyang,");
        System.out.println("built in the year 1967, dedicted to our Great Leader, Marshall Kim il Sung.   ");
        System.out.println("At Hotel Red Star, we bring to you absolutely modern living in utmost comfort, ");
        System.out.println("amidst the fragrance of our glorious heritage.");
        System.out.println();
        System.out.println("Be you a native weekend tourist, or be you an international tourist coming ");
        System.out.println("to witness the wonders of North Korea, be assured that we will take up the ");
        System.out.println("responsibility of making your stay a memorable one.");
        System.out.println();
        System.out.println("Do you want to book a room in our grand hotel?");
        System.out.println("Please reply in yes or no: ");
        if ((sc.nextLine()).equalsIgnoreCase("yes"))
        {
            System.out.println();
            System.out.println("Please state your date of visit, and the number of days you intend to stay");
            System.out.println("Date: ");
            date = sc.nextLine();
            System.out.println("Number of days: ");
            days = sc.nextInt();
        }
        else
        {
            System.exit(0);
        }
    }
    public void roomBook()
    {
        boolean King[] = new boolean[5];
        boolean Queen[] = new boolean[5];
        boolean AC[] = new boolean[15];
        boolean Non[] = new boolean[15];
        King = randomFiller(King);
        Queen = randomFiller(Queen);
        AC = randomFiller(AC);
        Non = randomFiller(Non);
        int fl = 0;
        while(fl != 1)
        {
            System.out.println("Please select the type of room you prefer.");
            System.out.println("1. King Suite");
            System.out.println("2. Queen Suite");
            System.out.println("3. AC Deluxe");
            System.out.println("4. Non-AC Deluxe");
            System.out.print("Enter your choice to view: ");
            int ch = sc.nextInt();
            boolean tmp;
            switch(ch)
            {
                case 1 : tmp = RoomDescript.King();
                               if(tmp)
                               {
                                   Type = King;
                                   rname = "King Suite";
                                   fl =1;
                               }
                               break;
                case 2 : tmp = RoomDescript.Queen();
                                if(tmp)
                                {
                                    Type = Queen;
                                    rname = "Queen Suite";
                                    fl = 1;
                                }
                                break;
                case 3 : tmp = RoomDescript.AC();
                                if(tmp)
                                {
                                    Type = AC;
                                    rname = "AC Deluxe";
                                    fl = 1;
                                }
                                break;
                case 4 : tmp = RoomDescript.Non();
                                if(tmp)
                                {
                                    Type = Non;
                                    rname = "Non-AC Deluxe";
                                    fl = 1;
                                }
                                break;
                default : System.out.println("INPUT IS INVALID!!! PLEASE RE-ENTER YOUR CHOICE. ");
                    roomBook();
                }
            }
            String bed = "double";
            if (rname.equals("AC Deluxe") || rname.equals("Non-AC Deluxe"))
            {
                System.out.println("Single bed or double bed? ");
                sc.nextLine();
                bed = sc.nextLine();
            }
            System.out.println("Checking for room availability...........");
            for (long i = 0; i < 15; i++)       //Time consuming loop
            System.out.println("DONE!");
            int cn;
            System.out.println("Rooms available = ");
            for (int i = 0; i < Type.length; i++)
            {
                if (bed.equalsIgnoreCase("single") || bed.equalsIgnoreCase("single bed"))
                {
                    if (Type[i] == true && i <= (Type.length/2))
                    {
                        System.out.println("Room " + (i + 1));
                        room = i;
                    }
                }
                else if (bed.equalsIgnoreCase("double") || bed.equalsIgnoreCase("double bed"))
                {
                    if (Type[i] == true && i > (Type.length/2))
                    {
                        System.out.println("Room " + (i + 1));
                        room = i;
                    }
                }
            }
            System.out.println("We have assigned room " + (room + 1) + " for you");
            System.out.println("Let us now proceed to the registration");
        }
        public boolean[] randomFiller(boolean A[])
        {
            for (int i = 0; i < A.length; i++)
            {
                int rand = (int)(Math.random() + 0.5);
                if (rand == 1)
                A[i] = true;
                else if (rand == 0)
                A[i] = false;
            }
            return A;
        }
        void registration()
        {
            System.out.println();
            System.out.println(" ___________________________________________________");
            System.out.println("  REGISTRATION ");
            System.out.println(" ''''''''''''''");
            System.out.println(" ___________________________________________________");
            System.out.println("            ");
            System.out.print("Name : ");
            name = sc.nextLine();
            System.out.print("Gender : ");
            gen = sc.nextLine();
            System.out.print("Residential Address : ");
            add = sc.nextLine();
            System.out.print("Occupation : ");
            occp = sc.nextLine();
            System.out.print("Purpose of visit : ");
            pur = sc.nextLine();
            System.out.print("Number of rooms booked : ");
            no = sc.nextInt();
            System.out.print("Total number of adults : ");
            adults = sc.nextInt();
            System.out.print("Total number of children(below 18) : ");
            child = sc.nextInt();
            System.out.println("THANK YOU!!! ");
            System.out.println("Do you wish to complementary breakfast (yes/no)? ");
            sc.nextLine();
            String bk = sc.nextLine();
            breakfast = bk.equalsIgnoreCase("yes");
        }
        public void billCalc()
        {
            int rate = 0;
            if(rname.equals("King Suite"))
            rate = 8000;
            else if(rname.equals("Queen Suite"))
            rate = 5000;
            else if(rname.equals("AC Deluxe"))
            rate = 3000;
            else if(rname.equals("Non-Ac Deluxe"))
            rate = 2500;
            int add = 0, rent = rate * days;
            if(adults > (no*2))
            add = 200 * days;
            if(child > (no))
            add += 100 * days;
            if(breakfast)
            {
                add += days * (adults + child) * 200;
            }
            int gross = rent + add;
            display(gross);
        }
        void display(int n)
        {
            System.out.println();
            System.out.println("        ___         ");
            System.out.println("        |__) * |  |");
            System.out.println("        |__) | |_ |_");
            System.out.println();
            System.out.println("        HOTEL RED STAR                         ");
            System.out.println("        ^^^^^^^^^^^^^^^^^^^                       ");
            System.out.println();
            System.out.println("Room type: " + rname);
            System.out.println("Room number= " + room);
            System.out.println("Customer name: " + name);
            System.out.println("Total number of people= " + (adults+child));
            System.out.println("Date of check-in: " + date);
            System.out.println("Days stayed= " + days);
            System.out.println();
            System.out.println("Gross amount= " + n);
            double servtax = (5.0/100)*n;
            double vat = (14.5/100)*(servtax+n);
            bill = servtax + vat + n;
            System.out.println("Taxes= " + vat);
            System.out.println("Net amount= " + bill);
            System.out.println();
            System.out.println("Please enter mode of payment: ");
            String mode = sc.nextLine();
            System.out.println("THANK YOU!!");
        }
}

class RoomDescript
{
    /**
     * Will contain the descriptions of the rooms. When the user inputs his choice, a description will be available,
     * which will be accessible through this class.
     */
      static Scanner sc = new Scanner(System.in);
      static boolean King()
      {
          boolean a = false;
          System.out.println("KING SUITE");
          System.out.println(" ");
          System.out.println("The King Suite is for the very best of our guests. With world class ");
          System.out.println("features, and excellent room dedor, this room is nothing short of ");
          System.out.println("perfection, which is desired by many. The room is spacy, and the ");
          System.out.println("cosiness of it makes one feel at home, albeit a more comfortable and ");
          System.out.println("more exqi=uisite one. We assure you, if this shall be your choice, you ");
          System.out.println("shall regret the day of your departure.");
          System.out.println(" ");
          System.out.println("Features");
          System.out.println("^^^^^^^^^");
          System.out.println(" ");
          System.out.println("> 350X200 ft. room, large,spacy and comfortable");
          System.out.println("> A gigantic Double-bed, with Spektron-technology custom made ");
          System.out.println("mattress, for a good night's sleep.");
          System.out.println("> Air-conditioned, with two split A/Cs.");
          System.out.println("> A 42-inch LG Smart TV");
          System.out.println("> Two large sofas, a bedside table, and a coffee table");
          System.out.println("> A long balcony, with a stunning view of the Juche Tower, as well as the ");
          System.out.println("rest of Pyongyang.");
          System.out.println("> A mini-bar,with an assortment of the finest elixirs of Korea.");
          System.out.println("> A huge bathroom, fit for a king.");
          System.out.println(" ");
          System.out.println("The cost of this room(exclusive of taxes) is = Rs. 8000/day.");
          System.out.println(" ");
          System.out.println(" ");
          System.out.println(" ");
          System.out.println(" ");
          System.out.println("Do you want to choose this type?");
          System.out.println("Enter 'yes' to book, or 'no' to go back to the menu:");
          if(sc.nextLine().equalsIgnoreCase("yes"))
          a = true;
          System.out.println(" ");
          return a;
        }
        static boolean Queen()
        {
            boolean a = false;
            System.out.println("QUEEN SUITE");
            System.out.println(" ");
            System.out.println("The Queen Suite has an extra touch of comfort. The features available ");
            System.out.println("are generally associated with cosy lifestyle. The rooms are such made ");
            System.out.println("that we assure you that you shall have no problem in blending in with ");
            System.out.println("the feel of it. The atmosphere created by this room is a calm and ");
            System.out.println("peaceful one, in contrast to the loudness of the King Suite. If a quiet ");
            System.out.println("stay is what you desire, we take pleasure in welcoming you to the ");
            System.out.println("grandeur of this room.");
            System.out.println(" ");
            System.out.println("Features");
            System.out.println("^^^^^^^^^");
            System.out.println(" ");
            System.out.println("> 320X220 ft. room, cosy with a home made feel.");
            System.out.println("> A perfectly home-like double bed, with a plush Kamarov-protocol ");
            System.out.println("custom made matress.");
            System.out.println("> Air-conditioned, with a split A/C and a bedside A/C.");
            System.out.println("> A 42 inch LG Smart TV.");
            System.out.println("> Two large sofas, two bedside tables.");
            System.out.println("> A round balcony, with a spectacular view of Pyongyang.");
            System.out.println("> A wine counter, with vintage wines of Korea.");
            System.out.println("> A cosy, marble-and-graphite bathroom.");
            System.out.println(" ");
            System.out.println("The cost for this room(exclusive of taxes) is = Rs. 5000/day");
            System.out.println(" ");
            System.out.println(" ");
            System.out.println(" ");
            System.out.println("Do you want to choose this type?");
            System.out.println("Enter 'yes' to book, or 'no' to go back to the menu: ");
            if(sc.nextLine().equalsIgnoreCase("yes"))
            a = true;
            System.out.println(" ");
            return a;
        }
        static boolean AC()
        {
            boolean a = false;
            System.out.println("A/C DELUXE");
            System.out.println(" ");
            System.out.println("The A/C Deluxe is the standard room for our hotel. With an affordable ");
            System.out.println("price, and unbelievable comfort, the rooms will exceed your ");
            System.out.println("expectations. The ambience is a very tourist-friendly one, and the room ");
            System.out.println("will surely make your stay at Hotel Red Star, a very memorable one. ");
            System.out.println(" ");
            System.out.println("Features");
            System.out.println("^^^^^^^^^");
            System.out.println(" ");
            System.out.println("> 200X150 ft. room, fully air-conditioned.");
            System.out.println("> Choice of single or double bed, with a soft, comfortable mattress. ");
            System.out.println("> A 32 inch LG LED TV.");
            System.out.println("> A large sofa, centre table, bedside table.");
            System.out.println("> A balcony, with a spectacular view of Pyongyang.");
            System.out.println("> A well furnished bathroom.");
            System.out.println(" ");
            System.out.println("The cost for this room(exclusive of taxes) is = Rs. 3000/day");
            System.out.println(" ");
            System.out.println(" ");
            System.out.println(" ");
            System.out.println("Do you want to choose this type?");
            System.out.println("Enter 'yes' to book, or 'no' to go back to the menu: ");
            if(sc.nextLine().equalsIgnoreCase("yes"))
            a = true;
            System.out.println(" ");
            return a;
        }
        static boolean Non()
        {
            boolean a = false;
            System.out.println("NON A/C DELUXE");
            System.out.println(" ");
            System.out.println("Don't like canned air? Feeling natural? Don't worry! Hotel Red Star ");
            System.out.println("offers you a special Non A/C Deluxe Suite with open windows to enjoy ");
            System.out.println("the scenic beauty of Korea. The air here is as fresh as it can be, and the ");
            System.out.println("natural way of life will surely make you feel like a part of Korea. ");
            System.out.println(" ");
            System.out.println("Features");
            System.out.println("^^^^^^^^^");
            System.out.println(" ");
            System.out.println("> 150X150 ft. room.");
            System.out.println("> Four large openable windows. ");
            System.out.println("> Choice of single or double bed, with a soft, comfortable mattress.");
            System.out.println("> A 32 inch LG LED TV.");
            System.out.println("> A large sofa, centre table, bedside table.");
            System.out.println("> A balcony, with a spectacular view of Pyongyang.");
            System.out.println("> A well furnished bathroom.");
            System.out.println(" ");
            System.out.println("The cost for this room(exclusin=ve of taxes) is = Rs. 2500/day");
            System.out.println(" ");
            System.out.println(" ");
            System.out.println(" ");
            System.out.println("Do you want to choose this type?");
            System.out.println("Enter 'yes' to book, or 'no' to go back to the menu: ");
            if(sc.nextLine().equalsIgnoreCase("yes"))
            a = true;
            System.out.println(" ");
            return a;
        }
    }
