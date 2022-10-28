import 'package:flutter/material.dart';
import 'package:rflutter_alert/rflutter_alert.dart';
import 'qcuiz_work.dart';

QCuizWork ob = new QCuizWork();

class QCuiz_Page extends StatefulWidget {
  const QCuiz_Page({Key? key}) : super(key: key);

  @override
  State<QCuiz_Page> createState() => _QCuiz_PageState();
}

class _QCuiz_PageState extends State<QCuiz_Page> {
  get child => null;

  List<Widget> scoreKeeper = [];
  int track = 1;

  void checkAnswer(bool userAns) {
    bool givenAnswer = ob.getans();
    if (givenAnswer == userAns && track < 10) {
      track++;
      scoreKeeper.add(Icon(
        Icons.check,
        color: Colors.green,
      ));
    } else {
      if (track >= 10) {
        Alert(
          context: context,
          // type: AlertType.error,
          title: "QCuiz",
          desc: "You've have reached the end of the quiz.",

          buttons: [
            DialogButton(
              color: Colors.blueGrey[900],
              child: Text(
                "CANCEL",
                style: TextStyle(color: Colors.white, fontSize: 20),
              ),
              onPressed: () {
                setState(() {
                  ob.restart();
                  scoreKeeper.clear();
                  track = 1;
                  Navigator.pop(context);
                });
              },
              width: 120,
            )
          ],
        ).show();
      } else
        track++;
      scoreKeeper.add(Icon(
        Icons.close,
        color: Colors.red,
      ));
    }
    setState(() {
      ob.getno();
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        backgroundColor: Colors.blueGrey[900],
        body: SafeArea(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            // ignore: prefer_const_literals_to_create_immutables
            children: [
              //Question here
              Expanded(
                flex: 6,
                child: Padding(
                  padding: EdgeInsets.all(8.0),
                  child: Center(
                    child: Text(
                      ob.getQue(),
                      style: TextStyle(
                        fontSize: 20,
                        fontWeight: FontWeight.bold,
                        color: Colors.white,
                      ),
                      textAlign: TextAlign.center,
                    ),
                  ),
                ),
              ),
              //true option here
              Expanded(
                child: Padding(
                  padding: EdgeInsets.all(15.0),
                  child: FlatButton(
                    shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(10.0)),
                    color: Colors.green[600],
                    child: Text(
                      "True",
                      style: TextStyle(
                          fontSize: 20.0,
                          color: Colors.black,
                          fontWeight: FontWeight.bold),
                    ),
                    onPressed: () {
                      checkAnswer(true);
                    },
                  ),
                ),
              ),
              //false option here
              Expanded(
                child: Padding(
                  padding: EdgeInsets.all(15.0),
                  child: FlatButton(
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(10.0),
                    ),
                    color: Colors.red[600],
                    child: const Text(
                      "False",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.black,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    onPressed: () {
                      checkAnswer(false);
                    },
                  ),
                ),
              ),
              //Row here as a score keeper
              Padding(
                padding:
                    const EdgeInsets.only(left: 8.0, right: 8.0, bottom: 8.0),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: scoreKeeper,
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

FlatButton(
    {required RoundedRectangleBorder shape,
    Color? color,
    required Text child,
    required Null Function() onPressed}) {}
