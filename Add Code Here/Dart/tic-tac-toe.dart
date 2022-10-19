import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
@override
Widget build(BuildContext context) {
	return MaterialApp(
	home: HomePage(),
	);
}
}

class HomePage extends StatefulWidget {
@override
_HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {

// declarations
bool oTurn = true;

// 1st player is O
List<String> displayElement = ['', '', '', '', '', '', '', '', ''];
int oScore = 0;
int xScore = 0;
int filledBoxes = 0;

@override
Widget build(BuildContext context) {
	return Scaffold(
	backgroundColor: Colors.indigo[900],
	body: Column(
		children: <Widget>[
		Expanded(
			
			// creating the ScoreBoard
			child: Container(
			child: Row(
				mainAxisAlignment: MainAxisAlignment.center,
				children: <Widget>[
				Padding(
					padding: const EdgeInsets.all(30.0),
					child: Column(
					mainAxisAlignment: MainAxisAlignment.center,
					children: <Widget>[
						Text(
						'Player X',
						style: TextStyle(fontSize: 20,
										fontWeight: FontWeight.bold,
										color: Colors.white),
						),
						Text(
						xScore.toString(),
						style: TextStyle(fontSize: 20,color: Colors.white),
						),
					],
					),
				),
				Padding(
					padding: const EdgeInsets.all(30.0),
					child: Column(
					mainAxisAlignment: MainAxisAlignment.center,
					children: <Widget>[
						Text('Player O', style: TextStyle(fontSize: 20,
														fontWeight: FontWeight.bold,
														color: Colors.white)
						),
						Text(
						oScore.toString(),
						style: TextStyle(fontSize: 20,color: Colors.white),
						),
					],
					),
				),
				],
			),
			),
		),
		Expanded(
			
			// Creating the Board for Tic tac toe
			flex: 4,
			child: GridView.builder(
				itemCount: 9,
				gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
					crossAxisCount: 3),
				itemBuilder: (BuildContext context, int index) {
				return GestureDetector(
					onTap: () {
					_tapped(index);
					},
					child: Container(
					decoration: BoxDecoration(
						border: Border.all(color: Colors.white)),
					child: Center(
						child: Text(
						displayElement[index],
						style: TextStyle(color: Colors.white, fontSize: 35),
						),
					),
					),
				);
				}),
		),
		Expanded(
			
			// Button for Clearing the Enter board
			// as well as Scoreboard to start allover again
			child: Container(
			child: Row(
			mainAxisAlignment: MainAxisAlignment.center,
			children: <Widget>[
				RaisedButton(
				color: Colors.indigo[50],
				textColor: Colors.black,
				onPressed: _clearScoreBoard,
				child: Text("Clear Score Board"),
				),
			],
			),
		))
		],
	),
	);
}

// filling the boxes when tapped with X
// or O respectively and then checking the winner function
void _tapped(int index) {
	setState(() {
	if (oTurn && displayElement[index] == '') {
		displayElement[index] = 'O';
		filledBoxes++;
	} else if (!oTurn && displayElement[index] == '') {
		displayElement[index] = 'X';
		filledBoxes++;
	}

	oTurn = !oTurn;
	_checkWinner();
	});
}

}
