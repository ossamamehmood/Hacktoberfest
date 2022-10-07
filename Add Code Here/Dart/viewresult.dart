import 'package:flutter/material.dart';

class VIEWRESULTS extends StatefulWidget {
  final String a;
  final String b;
  final String c;
  final String d;
  const VIEWRESULTS(this.a,this.b,this.c,this.d);

  @override
  State<VIEWRESULTS> createState() => _VIEWRESULTSState();
}

class _VIEWRESULTSState extends State<VIEWRESULTS> {
  @override

  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        title: Text("RESULTS"),
        centerTitle:true,
      ),
      body: Padding(
        padding:EdgeInsets.all(10),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceAround,
              children: [
                Container(
                  margin: EdgeInsets.fromLTRB(0, 50, 0, 0),
                  padding: EdgeInsets.fromLTRB(0, 15, 0, 0),
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.all(Radius.circular(20)),
                    color: Colors.red,
                  ),
                  height: 150,width: 150,
                  child:Column(
                    children: [
                       Text("A",style: TextStyle(color: Colors.white, fontSize: 30),),
                      SizedBox(height: 30,),
                      Text(widget.a, style: TextStyle(color: Colors.yellow,fontSize: 20))
                    ],
                  ),
                ),

                Container(
                  padding: EdgeInsets.fromLTRB(0, 15, 0, 0),
                  margin: EdgeInsets.fromLTRB(0, 50, 0, 0),
                  decoration: BoxDecoration(
                    borderRadius: BorderRadius.all(Radius.circular(20)),
                    color: Colors.green,
                  ),
                  height: 150,width: 150,
                  child:Column(
                    children: [
                      Text("B",style: TextStyle(color: Colors.white, fontSize: 30),),
                      SizedBox(height: 30,),
                      Text(widget.b, style: TextStyle(color: Colors.yellow,fontSize: 20))
                    ],
                  ),
                ),
                ]
            ),

            SizedBox(height: 30),

            Row(
                mainAxisAlignment: MainAxisAlignment.spaceAround,
                children: [
                  Container(
                    padding: EdgeInsets.fromLTRB(0, 15, 0, 0),
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.all(Radius.circular(20)),
                      color: Colors.blue,
                    ),
                    height: 150,width: 150,
                    child:Column(
                      children: [
                        Text("C",style: TextStyle(color: Colors.white, fontSize: 30),),
                        SizedBox(height: 30,),
                        Text(widget.c, style: TextStyle(color: Colors.yellow,fontSize: 20))
                      ],
                    ),
                  ),

                  Container(
                    padding: EdgeInsets.fromLTRB(0, 15, 0, 0),
                    decoration: BoxDecoration(
                      borderRadius: BorderRadius.all(Radius.circular(20)),
                      color: Colors.brown,
                    ),
                    height: 150,width: 150,
                    child:Column(
                      children: [
                        Text("D",style: TextStyle(color: Colors.white, fontSize: 30),),
                        SizedBox(height: 30,),
                        Text(widget.d, style: TextStyle(color: Colors.yellow,fontSize: 20))
                      ],
                    ),
                  ),
                ]
            ),

            Container(
              margin: EdgeInsets.fromLTRB(180, 200, 0, 0),
              child: Text("Made by-\nHarshJain(102103432)",style: TextStyle(fontSize: 15),),
            )

      ]
    ),
    ),
    );
  }
}