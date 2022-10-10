import 'package:flutter/material.dart';
import 'viewresult.dart';

class VOTER extends StatefulWidget {
  const VOTER({Key? key}) : super(key: key);

  @override
  State<VOTER> createState() => _VOTERState();
}

class _VOTERState extends State<VOTER> {

  static int ctra=0;
  static int ctrb=0;
  static int ctrc=0;
  static int ctrd=0;

  late String Sctra;
  late String Sctrb;
  late String Sctrc;
  late String Sctrd;



  var _firstPressa = true ;
  var _firstPressb = true ;
  var _firstPressc = true ;
  var _firstPressd = true ;


  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        title: Text("VOTES"),
        centerTitle: true,
      ),

      body: Padding(
        padding: EdgeInsets.all(20),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [

            Container(
              margin: EdgeInsets.fromLTRB(0, 20, 0, 0),
              child: Text(
                "CHOOSE :",
                style: TextStyle(
                  fontSize: 17,
                  fontWeight: FontWeight.bold,
                ),
              ),
            ),
            
            Container(
              margin: EdgeInsets.fromLTRB(0, 50,0, 0),
              child: ElevatedButton(
                style: ElevatedButton.styleFrom(
                  primary: Colors.red,
                ),
                onPressed: (){
                  setState((){
                    if(_firstPressa) {
                      _firstPressa = false;
                      ctra += 1;
                      showDialog(
                        context: context,
                        builder: (ctx) => AlertDialog(
                          title: const Text("VOTE SUBMITTED"),
                          content: const Text("You voted for A!"),
                          actions: <Widget>[
                            TextButton(
                              onPressed: () {
                                Navigator.of(ctx).pop();
                              },
                              child: Text("OK"),
                            ),
                          ],
                        ),
                      );
                    }
                  }
                  );
                },
                child: Text("A"),
              ),
            ),

            SizedBox(height: 10),

            ElevatedButton(
              style: ElevatedButton.styleFrom(
                primary: Colors.green,
              ),
              onPressed: (){
                setState((){
                  if(_firstPressb) {
                    _firstPressb = false;
                    ctrb += 1;
                    showDialog(
                      context: context,
                      builder: (ctx) => AlertDialog(
                        title: const Text("VOTE SUBMITTED"),
                        content: const Text("You voted for B!"),
                        actions: <Widget>[
                          TextButton(
                            onPressed: () {
                              Navigator.of(ctx).pop();
                            },
                            child: Text("OK"),
                          ),
                        ],
                      ),
                    );
                  }
                }
                );
              },
              child: Text("B"),
            ),

            SizedBox(height: 10),


            ElevatedButton(
              onPressed: () {
                setState(() {
                  if (_firstPressc) {
                    _firstPressc = false;
                    ctrc += 1;
                    showDialog(
                      context: context,
                      builder: (ctx) => AlertDialog(
                        title: const Text("VOTE SUBMITTED"),
                        content: const Text("You voted for C!"),
                        actions: <Widget>[
                          TextButton(
                            onPressed: () {
                              Navigator.of(ctx).pop();
                            },
                            child: Text("OK"),
                          ),
                        ],
                      ),
                    );
                  }
                }
                );
              },
              child: Text("C"),
            ),

            SizedBox(height: 10),


            ElevatedButton(
              style: ElevatedButton.styleFrom(
                primary: Colors.brown,
              ),
              onPressed: (){
                setState((){
                  if(_firstPressd) {
                    _firstPressd = false;
                    ctrd += 1;
                    showDialog(
                      context: context,
                      builder: (ctx) => AlertDialog(
                        title: const Text("VOTE SUBMITTED"),
                        content: const Text("You voted for D!"),
                        actions: <Widget>[
                          TextButton(
                            onPressed: () {
                              Navigator.of(ctx).pop();
                            },
                            child: Text("OK"),
                          ),
                        ],
                      ),
                    );
                  }
                }
                );
              },
              child: Text("D"),
            ),

            SizedBox(height: 10),


            Container(
              alignment: Alignment.centerRight,
              child: ElevatedButton(
                style: ElevatedButton.styleFrom(
                  primary: Colors.black,
                ),
                onPressed: (){
                  Sctra=ctra.toString();
                  Sctrb=ctrb.toString();
                  Sctrc=ctrc.toString();
                  Sctrd=ctrd.toString();
                  Navigator.of(context).push(MaterialPageRoute(builder: (context)=>VIEWRESULTS(Sctra,Sctrb,Sctrc,Sctrd)));
                },
                child:Text("VIEW VOTES"),
              ),
            ),

            Container(
              margin: EdgeInsets.fromLTRB(170, 200, 0, 0),
              child: Text("Made by-\nHarshJain(102103432)",style: TextStyle(fontSize: 15),),
            )
          ],
        ),
      ),
    );
  }
}