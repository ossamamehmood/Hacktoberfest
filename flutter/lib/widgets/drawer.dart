import 'package:app/pages/contact.dart';

import 'package:app/pages/home_page.dart';
import 'package:app/pages/shop.dart';
import 'package:app/utils/routes.dart';
import 'package:flutter/material.dart';

import 'package:velocity_x/velocity_x.dart';

class MyDrawer extends StatelessWidget {
  const MyDrawer({super.key});


  @override
  Widget build(BuildContext context) {
    const imageUrl = "https://avatars.githubusercontent.com/u/139707943?v=4";
    return  Drawer(
      child: Container(
        color: context.cardColor,
        child: ListView(
          padding: EdgeInsets.zero,
          children: [

            const DrawerHeader(
              padding: EdgeInsets.zero,
              child: UserAccountsDrawerHeader(
                margin: EdgeInsets.zero,
                decoration: BoxDecoration(
                  color: Color(0xff083452),
                ),
                accountName: Text("Ankit Kumar", style: TextStyle(
                  color: Color(0xffb4f3fa),
                  fontSize: 25,
                  fontWeight: FontWeight.bold,
                ),
                ),
                accountEmail: Text("kumarankit11458@gmail.com", style: TextStyle(
                  color: Color(0xffaae5de),
                  fontWeight: FontWeight.bold,
                ),
                ),
                currentAccountPicture: CircleAvatar(
                  backgroundImage: NetworkImage(imageUrl),
                ),
            ),
            ),
            ListTile(

              onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context)=> const HomePage(),
              ),
              ),

              leading: const Icon(Icons.home, color: Color(0xff94c2c4),
              ),
              title: const Text("Home", style: TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.w800,
                  color: Color(0xff94c2c4),
              ),),
            ),
            ListTile(
              onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context)=>const MyDrawer(),
              ),
              ),
              leading: const Icon(Icons.account_circle
                , color: Color(0xff94c2c4),
              ),
              title: const Text("Profile", style: TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.w800,
                  color: Color(0xff94c2c4),
              ),),
            ),
            ListTile(
              onTap:  () => Navigator.pushNamed(context, MyRoutes.cartRoute),
              leading: const Icon(Icons.shopping_cart, color:  Color(0xff94c2c4),
              ),
              title: const Text("Add to Cart", style: TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.w800,
                  color: Color(0xff94c2c4),
              ),),
            ),
            ListTile(
              onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context)=>Contacts(),
              ),
              ),
              leading: const Icon(Icons.contact_page, color: Color(0xff94c2c4),
              ),
              title: const Text("Contacts", style: TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.w800,
                  color: Color(0xff94c2c4),
              ),),
            ),
            ListTile(
              onTap: () => Navigator.push(context, MaterialPageRoute(builder: (context)=> shopPage(),
              ),
              ),
              leading: const Icon(Icons.shopify_rounded, color: Color(0xff94c2c4),
              ),
              title: const Text("Shop Now", style: TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.w800,
                color: Color(0xff94c2c4),
              ),),
            ),

          ],//children
        ),
      ),
    );
  }
}
