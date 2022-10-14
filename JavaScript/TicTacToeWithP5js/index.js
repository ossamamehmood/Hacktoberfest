var BOARD = null;
function setup() {
  createCanvas(400, 400);
  BOARD = new ttt(width-100,height-100);
  BOARD.drawGrid(undefined, undefined, force=true)
  BOARD.chooseSide();
}

function draw() {
  BOARD.drawGrid();
}
function mouseClicked(){
  //Update Move ---> Check Winning status --->Do resp task after winning or draw
  if (BOARD.gameState == 'stopped'){
    BOARD.gameState = 'turnChoosing';
    BOARD.drawGrid(undefined, undefined, force=true);
    BOARD.chooseSide();
  }else if (BOARD.gameState == 'running' && mouseX<400 && mouseY < 400){
    BOARD.updateMouseClick(mouseX, mouseY);
    if (BOARD.checkWin('playerOne')){
      BOARD.endGame('playerOne');
    }else if (BOARD.checkWin('playerTwo')){
      BOARD.endGame('playerTwo');
    }else if(BOARD.checkWin('playerOne') == null || BOARD.checkWin('playerTwo') == null){
      BOARD.endGame('\tNone');
    }
  }else if (BOARD.gameState == 'turnChoosing'){
    var yesCoords = [width*0.13, height*0.415, width*0.13+100, height*0.415+50];
    var noCoords = [width*0.625, height*0.415, width*0.625+100, height*0.415+50];
    if (mouseX > yesCoords[0] && mouseY > yesCoords[1] && mouseX < yesCoords[2] && mouseY < yesCoords[3]){
      BOARD.startGame('playerOne');
    } else if (mouseX > noCoords[0] && mouseY > noCoords[1] && mouseX < noCoords[2] && mouseY < noCoords[3]){
      BOARD.startGame('playerTwo');
    }
  }
}
class ttt{
  constructor(wdh,hgt){
    this.grid = [
      ['','',''],
      ['','',''],
      ['','','']
    ];
    this.symbol = {
      "playerOne": 'X',
      "playerTwo":'O'
    };
    this.currentPlayer = 'playerOne';
    this.gameState = 'turnChoosing';
    this.width = wdh;
    this.height = hgt;
  }
  putMove(player, spot){
    if (this.grid[spot.row][spot.column] == ''){
      this.grid[spot.row][spot.column] = this.symbol[player];
      this.currentPlayer = (this.currentPlayer == 'playerTwo') ? 'playerOne' : 'playerTwo';
      return true;
    }
    return false;
  }
  checkWin(player){
    //Returns true if player won else false. If out of moves, returns none
    var status = 0;
    //HorizontalCheck
    for (var i=0;i<3;i++){
      status = 0;
      for (var j=0;j<3;j++){
        if (this.grid[i][j] == this.symbol[player]){
          status++;
        }
      if (status == 3){
        return true;
      }
      }
    }
    //VerticalCheck
    for (var i=0;i<3;i++){
      status = 0;
      for (var j=0;j<3;j++){
        if (this.grid[j][i] == this.symbol[player]){
          status++;
        }
      if (status == 3){
        return true;
      }
      }
    }
    //DiagonalCheck
    if ((this.grid[0][0]+this.grid[1][1]+this.grid[2][2] == this.symbol[player]+this.symbol[player]+this.symbol[player]) || (this.grid[0][2]+this.grid[1][1]+this.grid[2][0] == this.symbol[player]+this.symbol[player]+this.symbol[player])){
    return true;
    }
    //Check for cell vacancy
    var vacant = null;
    for (var i=0;i<3;i++){
      for (var j=0;j<3;j++){
        if (this.grid[i][j] == ''){
          vacant = true;
        }
      }
    }
  return (vacant == true) ? false : vacant;
  }
  drawGrid(wdh=this.width, hgt=this.height, force=false){
    //Don't draw grids if game not running and not forced
    if ((this.gameState != 'running' && !force)){
      return 0;
    }
    background(50);
    //DrawingLines
    var gridOffset = 0.15*this.width;
    strokeWeight(10);
    stroke(0);
    for(var i=0;i<2;i++){
      for (var j=0;j<2;j++){
        var x1 = gridOffset+wdh/3*(i*(j+1));
        var y1 = gridOffset+hgt/3*(1-i)**(i+j)*2**j;
        var x2 = gridOffset+wdh/3*(3**(1-i)*2**(i*j));
        var y2 = gridOffset+hgt/3*3**i*2**(j*(1-i));
        line(x1,y1,x2,y2);
      }
    }
    
    //DrawingSymbols
    var offset=0.1*this.width;
    strokeWeight(5);
    for(var i=0;i<3;i++){
      for(var j=0;j<3;j++){
        if (this.grid[i][j] =='X'){
          //DrawCross
          stroke(255,0,0);
          line(wdh/3*j+offset+gridOffset,hgt/3*i+offset+gridOffset,wdh/3*(j+1)-offset+gridOffset,hgt/3*(i+1)-offset+gridOffset);
          line(wdh/3*(j+1)-offset+gridOffset,hgt/3*i+offset+gridOffset,wdh/3*j+offset+gridOffset,hgt/3*(i+1)-offset+gridOffset);
        }else if(this.grid[i][j] == 'O'){
          stroke(50,255,100);
          fill(50);
          ellipse(wdh/3*j+wdh/6+gridOffset,hgt/3*i+hgt/6+gridOffset,0.25*this.width-offset,0.25*this.width-offset);
        }
      }
    }
  }
  updateMouseClick(mX,mY){
    var gridOffset = 0.15*this.width;
    var col = null;
    var row = null;
    //Horizontal and Vertical Scan
    for (var i=0;i<3;i++){
      if (mX < this.width/3*(i+1)+gridOffset && col == null){
        col = i;
      }
      if (mY < this.height/3*(i+1)+gridOffset && row == null){
        row = i;
      }
    }
    if (col != null && row != null && this.gameState == 'running'){
      return this.putMove(this.currentPlayer, {'row':row, 'column':col});
    }
    return false;
  }
  startGame(player){
    this.gameState = 'running';
    this.currentPlayer = player;
    this.resetGrid();
  }
  resetGrid(){
    for (var i=0;i<3;i++){
      for (var j=0;j<3;j++){
        this.grid[i][j] = '';
      }
    }
  }
  endGame(won = undefined){
    //Disables mouse input and displayes winning status if game has ended
    this.gameState = 'stopped';

    fill(153,0,76);
    noStroke();
    rect(width*0.05,height*0.25,width*0.9,height*0.4,20,20,20,20);
    fill(153,255,153);
    text('Game Point goes to', width*0.24, height*0.4);
    fill(100,255,0);
    text(won,width*0.37,height*0.52);
    }
  chooseSide(){
    noStroke();
    textSize(35);
    fill(0,0,0,50);
    rect(width*0,height*0.2,width,height*0.5)
    fill(150,250,0);
    textSize(25);
    text('Do you want to start first?',width*0.15,height*0.25,width*0.8,height*0.25);
    rect(width*0.13,height*0.415,100,50,20,20,20,20);
    rect(width*0.625,height*0.415,100,50,20,20,20,20);
    fill(0);
    textSize(25);
    text('Yes',width*0.2,height*0.5);
    text('No',width*0.71,height*0.5);
  }
  
  
  ///
}