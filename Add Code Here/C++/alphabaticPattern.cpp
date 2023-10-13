#include<iostream>
using namespace std;
int main(){
    int col=1,row1,row2,row3=1,n,row4,k,x;
    char ch;
    cout<<"Enter the number:";
    cin>>n;
    while(col<=n){
        row1=1;
        while (row1<=n-col+1)
        { ch='A'+row1-1;
            cout<<" "<<ch;
            row1++;
        }
        row2=col-1;
        while (row2)    
        {
            cout<<"  ";
            row2--;
        }
        row3=col-1;
        while (row3)    
        {
            cout<<"  ";
            row3--;
        }
        row4=n;
        x=col-1;
        while (row4>=col)
        {ch='A'+n-x-1;
            cout<<" "<<ch;
            x++;
            row4--;
        }
        cout<<"\n";
        col++;
    }
}


//  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z Z Y X W V U T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S T U V W X Y     Y X W V U T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S T U V W X         X W V U T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S T U V W             W V U T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S T U V                 V U T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S T U                     U T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S T                         T S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R S                             S R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q R                                 R Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P Q                                     Q P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O P                                         P O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N O                                             O N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M N                                                 N M L K J I H G F E D C B A
//  A B C D E F G H I J K L M                                                     M L K J I H G F E D C B A
//  A B C D E F G H I J K L                                                         L K J I H G F E D C B A
//  A B C D E F G H I J K                                                             K J I H G F E D C B A
//  A B C D E F G H I J                                                                 J I H G F E D C B A
//  A B C D E F G H I                                                                     I H G F E D C B A
//  A B C D E F G H                                                                         H G F E D C B A
//  A B C D E F G                                                                             G F E D C B A
//  A B C D E F                                                                                 F E D C B A
//  A B C D E                                                                                     E D C B A
//  A B C D                                                                                         D C B A
//  A B C                                                                                             C B A
//  A B                                                                                                 B A
//  A    