import 'package:flutter/material.dart';
import 'votenow.dart';


class Home extends StatefulWidget {
  const Home({Key? key}) : super(key: key);

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
      ),
      body: Column(
        children: [
          Container(
            margin: EdgeInsets.fromLTRB(0, 70, 0, 0),
            child: Text(
                "POLLING FOR <EVENT NAME>",
                  style: TextStyle(
                    fontSize: 20,
                    fontWeight: FontWeight.bold,
                    letterSpacing: 2,
                  ),
            ),
          ),

          Container(
            margin: EdgeInsets.fromLTRB(0, 100, 0, 0),
            child: Center(
              child: ElevatedButton(
                style: ButtonStyle(
                  shape: MaterialStateProperty.all<RoundedRectangleBorder>(
                  RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(18.0),
                ),
                  ),
                  ),
                onPressed: (){
                  Navigator.of(context).push(MaterialPageRoute(builder: (context)=>VOTER()));
                },
                child: Text("VOTE !",style: TextStyle(
                  fontSize: 30,
                ),),
              ),
            ),
          ),

          Container(
            margin: EdgeInsets.fromLTRB(180, 380, 0, 0),
            child: Text("Made by-\nHarshJain(102103432)",style: TextStyle(fontSize: 15),),
          )
        ],
      ),


    );
  }
}