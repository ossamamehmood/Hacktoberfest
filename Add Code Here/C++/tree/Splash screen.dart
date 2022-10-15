import 'package:flutter/cupertino.dart';

import 'package:flutter/material.dart';

import 'package:google_fonts/google_fonts.dart';

class SplashScreen extends StatefulWidget {

  const SplashScreen({Key? key}) : super(key: key);

  @override

  _SplashScreenState createState() => _SplashScreenState();

}

class _SplashScreenState extends State<SplashScreen> {

  @override

  Widget build(BuildContext context) {

    return Scaffold(

      backgroundColor: Colors.black,

      body: Center(

        child: Container(

          width: MediaQuery.of(context).size.width,

          height: MediaQuery.of(context).size.height,

          alignment: Alignment.center,

          decoration: BoxDecoration(

              gradient: LinearGradient(

                  begin: Alignment.topCenter,

                  end: Alignment.bottomCenter,

                  stops: [0.5, 0.9],

                  colors: [Colors.black, Colors.yellow])),

          child: Column(

            mainAxisAlignment: MainAxisAlignment.center,

            crossAxisAlignment: CrossAxisAlignment.center,

            mainAxisSize: MainAxisSize.max,

            children: [

              RichText(

                text: TextSpan(

                    text: 'App',

                    style: TextStyle(

                      color: Colors.red,

                      fontWeight: FontWeight.bold,

                      fontSize: 30.0,

                    ),

                    children: <TextSpan>[

                      TextSpan(

                        text: 'Name',

                        style: TextStyle(

                          color: Colors.blueAccent,

                          fontWeight: FontWeight.bold,

                          //fontSize: 30.0,

                        ),

                      ),

                    ]),

              ),

              RichText(

                  text: TextSpan(

                      text: "by   ",

                      style: TextStyle(color: Colors.white, fontSize: 10),

                      children: [

                    TextSpan(

                      text: 'Kunal Jain',

                      style: TextStyle(

                        fontFamily: GoogleFonts.poppins().fontFamily,

                        color: Colors.lime[50],

                        fontWeight: FontWeight.bold,

                        fontSize: 15.0,

                      ),

                    ),

                  ]))

            ],

          ),

        ),

      ),

    );

  }

}
