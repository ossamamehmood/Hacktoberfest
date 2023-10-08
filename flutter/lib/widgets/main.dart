
import 'package:app/pages/cart_page.dart';
import 'package:app/pages/home_page.dart';
import 'package:app/pages/login_page.dart';
import 'package:app/utils/routes.dart';
import 'package:app/widgets/themes.dart';
import 'package:flutter/material.dart';


void main() {
  runApp(const MyApp());
}
 
class MyApp extends StatelessWidget {
  const MyApp({super.key});




  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      // home: HomePage(),
      themeMode: ThemeMode.system,
      theme: MyTheme.lightTheme(context),
      debugShowCheckedModeBanner: false,
      darkTheme: MyTheme.darkTheme(context),
      initialRoute: MyRoutes.loginRoute,
      routes: {
        "/": (context) =>  const HomePage(),
        MyRoutes.homeRoute: (context) =>const HomePage(),
        MyRoutes.loginRoute: (context) =>const LoginPage(),
        MyRoutes.cartRoute : (context) =>const CartPage(),

       },

    );
  }
}
