// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract HelloWorld {
    // A variable of string data type 
    string word;
    //function to set data in variable
    function setWord(string memory _word) public {
        word = _word;
    }
    //function to get variable data
    function getWord() public view returns(string memory){
        return word;
    }
}