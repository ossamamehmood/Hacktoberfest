import 'dart:math';
import 'package:flutter/material.dart';

void main() {
  return runApp(
    MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.red,
        appBar: AppBar(
          title: Text('Dicee'),
          backgroundColor: Colors.red,
        ),
        body: DicePage(),
      ),
    ),
  );
}

class DicePage extends StatefulWidget {
  //const DicePage({Key? key}) : super(key: key);
  @override
  State<DicePage> createState() => _DicePageState();
}

class _DicePageState extends State<DicePage> {
  int leftDice = 1;
  int rightDice = 1;
  void changeDiceFace(){
    leftDice = Random().nextInt(6) + 1;
    rightDice = Random().nextInt(6) + 1;
  }
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Row(
        children: [
          Expanded(
              child: TextButton(
                  onPressed: () {
                    setState(() {
                      changeDiceFace();
                    });
                  },
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Image.asset('images/dice$leftDice.png'),
                  ))),
          Expanded(
              child: TextButton(
                  onPressed: () {
                    setState(() {
                      changeDiceFace();
                    });
                  },
                  child: Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Image.asset('images/dice$rightDice.png'),
                  ))),
        ],
      ),
    );
  }
}
