import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:velocity_x/velocity_x.dart';
class Contacts extends StatelessWidget {
  const Contacts({super.key});



  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: context.cardColor,
      appBar: AppBar(

        backgroundColor: Colors.transparent,
        title: "Contact Page".text.xl3.cyan50.center.make(),
      ),
       body: SafeArea(child:
          Center(

           child: Column(

             children: [
               Image.asset("assets/images/logo1.png",
                 fit: BoxFit.contain,
               ),

               "Welcome Contact Page of Vimal Store  ".text.xl3.center.orange300.extraBold.make(),
               const SizedBox(
                 height: 20,
               ),
               Row(
                 children: [
                   const Icon(CupertinoIcons.house_alt_fill, color: Color(0xffd7f1df),),
                   const  SizedBox(
                     width: 8,
                   ),

                   "Owner Name  :-".text.xl2.bold.blue200.make(),
                   const  SizedBox(
                     width: 10,
                   ),
                   "xxxxxx xxxxxx".text.xl.blue200.make(),
                 ],
               ),
               const SizedBox(height: 10,),
               Row(
                 children: [
                   const Icon(CupertinoIcons.phone_fill, color: Color(0xffd7f1df),),
                   const SizedBox(
                     width: 8,
                   ),
                  "Phone No   :-".text.xl2.bold.blue200.make(),
                   const  SizedBox(
                     width: 20,
                   ),
                   "+91 xxx xxx xxxx".text.xl.blue200.make(),
                ],
    ),
               const SizedBox(height: 10,),
               Row(
                 children: [
                   const Icon(CupertinoIcons.phone_circle, color: Color(0xffd7f1df),),
                   const SizedBox(
                     width: 8,
                   ),
                   "Whatsapp Phone No :-".text.xl.bold.blue200.make(),
                   const  SizedBox(
                     width: 8,
                   ),
                   "+91 xxx xxx xxxx".text.xl.blue200.make(),
                 ],
               ),
               const SizedBox(height: 10,),
               Row(
                 children: [
                   const Icon(CupertinoIcons.location_solid, color: Color(0xffd7f1df),),
                   const SizedBox(
                     width: 7,
                   ),
                   "Location  :-".text.xl3.bold.blue200.make(),
                   const SizedBox(
                     width: 10,
                   ),
                   "SHOP NO 101 \n NEAR JRG BANK \n GOVINDPUR"
                       "\n  PINCODE - 831015 \n JAMSHEDPUR \n"
                       " JHARKHAND".text.xl.blue200.make(),
                 ],
               ),
               const SizedBox(height: 10,),
               Row(
                 children: [
                   const Icon(CupertinoIcons.mail, color: Color(0xffd7f1df),),
                   const  SizedBox(
                     width: 13,
                   ),
                   "Email  :-".text.xl.bold.blue200.make(),
                   const    SizedBox(
                     width: 10,
                   ),
                   "job-xxx-00@gmail.com".text.xl.blue200.make(),
                 ],
               ),
               const  SizedBox(height: 10,),
               Row(
                 children: [
                   const Icon(CupertinoIcons.person_2, color: Color(0xffd7f1df),),
                   const SizedBox(
                     width: 13,
                   ),
                   "Partners  :-".text.xl.bold.blue200.make(),
                   const  SizedBox(
                     width: 10,
                   ),
                   "VIMAL SHARMA \n CHEETAN SHARMA \n HARSHIT SHARAMA  \n + MANY MORE".text.xl.blue200.make(),
                 ],
               ),

             ],
           ).px8()

          ),


    ),

    );
  }
}