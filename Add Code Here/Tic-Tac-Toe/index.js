<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tic Tac Toe</title>
    <style>
        body {
            font-family: 'Barlow Semi Condensed', sans-serif;
            color: white;
            background-color: black;
        }

        h1 {
            text-align: center;
            font-size: 5rem;
            margin-top: 0;
            animation: fadeInDown;
            /* referring directly to the animation's @keyframe declaration */
            animation-duration: 1s;
            /* don't forget to set a duration! */
        }

        .container {
            animation: fadeIn;
            animation-duration: 2s;
        }

        h2 {
            text-align: center;
        }

        input,
        button {
            text-align: center;
        }

        input[type="text"],
        textarea {
            border: none;
            outline: none;
            border-bottom: 0.5px solid #00ff00;
            /* You can adjust the color and thickness of the outline */
            color: white;
            background-color: black;
            font-size: 1rem;
        }

        .container {
            display: flex;
            height: 55vh;
            width: 100%;
            justify-content: center;
            align-items: center;
        }

        .tic-tac-toe {
            display: grid;
            grid-template-columns: 1fr 1fr 1fr;
            grid-template-rows: 1fr 1fr 1fr;
            gap: 9px;
            background-color: white;
        }

        .tic-tac-toe>div {
            display: flex;
            pointer-events: auto;
            background-color: rgb(0, 0, 0);
            width: 125px;
            height: 125px;
            color: white;
            font-size: 5rem;
            justify-content: center;
            align-items: center;
        }

        .resets {
            display: flex;
            width: 100%;
            justify-content: center;
        }

        .players {
            display: flex;
            justify-content: center;
            align-items: center;
            gap: 10px;
            flex-wrap: wrap;
            font-size: 1.3rem;
        }

        .footer {
            width: 100%;
            margin-top: 3%;
            padding-top: 0.1%;
            height: 10vh;
            background-color: #333333;
            text-align: center;
        }

        /* CSS */
        .button-85 {
            font-family: 'Barlow Semi Condensed', sans-serif;
            padding: 0.6em 2em;
            border: none;
            outline: none;
            color: rgb(255, 255, 255);
            background: #111;
            cursor: pointer;
            position: relative;
            z-index: 0;
            border-radius: 10px;
            user-select: none;
            -webkit-user-select: none;
            touch-action: manipulation;
        }

        .button-85:before {
            font-family: 'Barlow Semi Condensed', sans-serif;
            content: "";
            background: linear-gradient(45deg,
                    #ff0000,
                    #ff7300,
                    #fffb00,
                    #48ff00,
                    #00ffd5,
                    #002bff,
                    #7a00ff,
                    #ff00c8,
                    #ff0000);
            position: absolute;
            top: -2px;
            left: -2px;
            background-size: 400%;
            z-index: -1;
            filter: blur(5px);
            -webkit-filter: blur(5px);
            width: calc(100% + 4px);
            height: calc(100% + 4px);
            animation: glowing-button-85 20s linear infinite;
            transition: opacity 0.3s ease-in-out;
            border-radius: 10px;
        }

        @keyframes glowing-button-85 {
            0% {
                background-position: 0 0;
            }

            50% {
                background-position: 400% 0;
            }

            100% {
                background-position: 0 0;
            }
        }

        .button-85:after {
            font-family: 'Barlow Semi Condensed', sans-serif;
            z-index: -1;
            content: "";
            position: absolute;
            width: 100%;
            height: 100%;
            background: #222;
            left: 0;
            top: 0;
            border-radius: 10px;
        }

        @media (max-width:576px) {
            .container {
                height: 40vh;
            }

            h1 {
                font-size: 3.5rem;
            }

            .tic-tac-toe {
                gap: 5px;
            }

            .tic-tac-toe>div {
                display: flex;
                pointer-events: auto;
                background-color: rgb(0, 0, 0);
                width: 65px;
                height: 65px;
                color: white;
                font-size: 2rem;
                justify-content: center;
                align-items: center;
            }

            p {
                margin: 5px;
                text-align: center;
                width: 100%;
            }

            .button-85 {
                margin-top: 25px;
            }

            .footer {
                margin-top: 10%;
                height: 10vh;
                padding-top: 4%;
                width: 100%;
                align-items: center;
            }

            #top-button {
                margin-left: -6%;
            }
        }
    </style>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/animate.css/4.1.1/animate.min.css" />
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Barlow+Semi+Condensed&display=swap" rel="stylesheet">
    <link rel="icon" href="./Images/tic-tac-toe.png"">
</head>

<body>
    <h1><span>Tic</span> <span>Tac</span> <span>Toe</span></h1>
    <div class=" players">
    <p>Player1 :- <input type="text" name="" id="player1" placeholder="Enter player1's name" value=""></p>
    <!-- To create spacing -->
    &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
    <p>Player2 :- <input type="text" name="" id="player2" placeholder="Enter player2's name" value=""></p>
    <br />
    <!-- To create spacing -->
    &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
    <button type="button" id="top-button" class="button-85" onclick="players()">Submit</button>
    </div>
    <h2 id="result"></h2>
    <div class="container">
        <div class="tic-tac-toe">
            <div class="grid-item" id="1" value="0" onclick="initialize(0)"></div>
            <div class="grid-item" id="2" value="1" onclick="initialize(1)"></div>
            <div class="grid-item" id="3" value="2" onclick="initialize(2)"></div>
            <div class="grid-item" id="4" value="3" onclick="initialize(3)"></div>
            <div class="grid-item" id="5" value="4" onclick="initialize(4)"></div>
            <div class="grid-item" id="6" value="5" onclick="initialize(5)"></div>
            <div class="grid-item" id="7" value="6" onclick="initialize(6)"></div>
            <div class="grid-item" id="8" value="7" onclick="initialize(7)"></div>
            <div class="grid-item" id="9" value="8" onclick="initialize(8)"></div>
        </div>
    </div>
    <div class="resets">
        <button id="resets" class="button-85" type="button" onclick="reload()">Restart</button>
    </div>
    <div class="footer">
        <div>
            <p>© Tic-Tac-Toe</p>
            <p>-Ashish Kumar Sahoo</p>
        </div>
    </div>

    <script>
        var matrix = ["1", "2", "3", "4", "5", "6", "7", "8", "9"];
        var count = 0;
        var p1 = "Player1", p2 = "Player2";
        var prev;

        function players() {
            p1 = document.getElementById("player1").value;
            p2 = document.getElementById("player2").value;
        }

        function reload() {
            location.reload();
        }

        function initialize(select) {
            if (count % 2 != 0 && (matrix[select] != 'X' && matrix[select] != 'O')) {
                matrix[select] = 'O';
                count++;
                check(select);
            }
            else {
                if (matrix[select] != 'X' && matrix[select] != 'O') {
                    matrix[select] = 'X';
                    count++;
                }
                check(select);
            }

            if (select == 0) {
                document.getElementById("1").innerHTML = matrix[select];
            }
            else if (select == 1) {
                document.getElementById("2").innerHTML = matrix[select];
            }
            else if (select == 2) {
                document.getElementById("3").innerHTML = matrix[select];
            }
            else if (select == 3) {
                document.getElementById("4").innerHTML = matrix[select];
            }
            else if (select == 4) {
                document.getElementById("5").innerHTML = matrix[select];
            }
            else if (select == 5) {
                document.getElementById("6").innerHTML = matrix[select];
            }
            else if (select == 6) {
                document.getElementById("7").innerHTML = matrix[select];
            }
            else if (select == 7) {
                document.getElementById("8").innerHTML = matrix[select];
            }
            else {
                document.getElementById("9").innerHTML = matrix[select];
            }
        }

        function check(select) {
            if (count == 9) {
                document.getElementById("result").innerHTML = "DRAW";
                setTimeout(function () {
                    window.location.reload();
                }, 2000);
            }
            else {
                if ((matrix[0] == matrix[1] && matrix[1] == matrix[2]) || (matrix[3] == matrix[4] && matrix[4] == matrix[5]) || (matrix[6] == matrix[7] && matrix[7] == matrix[8]) || (matrix[0] == matrix[3] && matrix[3] == matrix[6]) || (matrix[1] == matrix[4] && matrix[4] == matrix[7]) || (matrix[2] == matrix[5] && matrix[5] == matrix[8]) || (matrix[0] == matrix[4] && matrix[4] == matrix[8]) || (matrix[2] == matrix[4] && matrix[4] == matrix[6])) {
                    if (matrix[select] == 'X') {
                        document.getElementById("result").innerHTML = p1 + " wins!!";
                    }
                    else {
                        document.getElementById("result").innerHTML = p2 + " wins!!";
                    }
                    setTimeout(function () {
                        window.location.reload();
                    }, 2000);
                }
            }
        }
    </script>

    </body>

</html>
