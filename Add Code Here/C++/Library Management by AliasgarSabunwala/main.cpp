// Calling Files
header.h
write_book.cpp
modify_book.cpp
delete_student.cpp
display_alls.cpp
display_allb.cpp
book_issue.cpp
book_deposit.cpp
IntroSreen.cpp 
Options.cpp
    
// global declaration for stream object, object
fstream fp,fp1;
book bk;
student st;

int main()
{
    char ch;
    
    // Invoking IntroSreen.cpp 
    intro();
    
    do
        {
            clrscr();

            // Options.cpp
            cout<<"\n\n\n\t  Options";
            cout<<"\n\n\t    01. BOOK ISSUE";
            cout<<"\n\n\t    02. BOOK DEPOSIT";
              cout<<"\n\n\t  03. ADMINISTRATOR MENU";
              cout<<"\n\n\t  04. EXIT";
              cout<<"\n\n\tPlease Select Your Option (1-4) ";

              // getting Options
              ch=getche();

              // Using Switch Case
              switch(ch)
                  {
                    case '1':clrscr();
                         book_issue();
                            break;
                      case '2':book_deposit();
                             break;
                      case '3':admin_menu();
                         break;
                      case '4':exit(0);
                      default :cout<<"Wrong Option";
                  }
            }
        while(ch!='4');
}
