import 'package:flutter/material.dart';
import 'package:qcuiz/qcuiz_page.dart';

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.stretch,
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      // ignore: prefer_const_literals_to_create_immutables
      children: [
        Expanded(
          flex: 6,
          child: Padding(
            padding: EdgeInsets.all(8.0),
            child: Center(
              child: Text(
                'printf("Welcome to QCuiz");',
                style: TextStyle(
                  fontSize: 25,
                  fontWeight: FontWeight.bold,
                  color: Colors.white,
                ),
                textAlign: TextAlign.center,
              ),
            ),
          ),
        ),
        Expanded(
          child: Padding(
            padding: EdgeInsets.all(15.0),
            child: FlatButton(
              shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(10.0)),
              color: Colors.blueGrey[800],
              child: Text(
                "Start",
                style: TextStyle(
                    fontSize: 20.0,
                    color: Colors.white,
                    fontWeight: FontWeight.bold),
              ),
              onPressed: () {
                Navigator.push(context,
                    MaterialPageRoute(builder: (Context) => QCuiz_Page()));
              },
            ),
          ),
        ),
      ],
    );
  }
}

FlatButton(
    {required RoundedRectangleBorder shape,
    Color? color,
    required Text child,
    required Null Function() onPressed}) {}
