import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:velocity_x/velocity_x.dart';

class MyTheme{
  static ThemeData  lightTheme(BuildContext context) => ThemeData(primarySwatch: Colors.deepPurple,
    brightness: Brightness.light,
    fontFamily: GoogleFonts.romanesco().fontFamily,
    cardColor: Color(0xff390975),
    canvasColor: Color(0xffaae5de),
    hintColor: Color(0xe5cff3f0),
    backgroundColor: Color(0xe5097a88),
    appBarTheme:  AppBarTheme(

      // backgroundColor: Color(0xff556ade),

      color: Color(0xff030c3f),
      elevation: 0.0,

      iconTheme: IconThemeData(color: Color(0xffa66da1)),
    ),
    textTheme: Theme.of(context).textTheme,
  );
  static ThemeData  darkTheme(BuildContext context) => ThemeData(primarySwatch: Colors.deepPurple,
    brightness: Brightness.dark,
    fontFamily: GoogleFonts.poppins().fontFamily,
   hintColor: Colors.white,
    cardColor: Colors.black,
    canvasColor: Color(0xff085e96),
    backgroundColor: Color(0xe50d3160),
    appBarTheme:  AppBarTheme(

      // backgroundColor: Color(0xff556ade),

      color: Color(0xff000000),
      elevation: 0.0,

      iconTheme: IconThemeData(color: Color(0xffffffff)),
    ),

    textTheme: Theme.of(context).textTheme,
  );
}