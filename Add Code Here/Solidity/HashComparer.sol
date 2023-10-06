//SPDX-License-Identifier: UNLICENSED
pragma solidity >=0.5.0 <0.9.0;

import "hardhat/console.sol";

contract Token {
    string public name = "HashComparer";

    // IPFS Hash: To be fetched from ipfs
    string public ipfsHash = "";

    // generatedHash will be sent by user
    // Doing it in tests for now
    string public generatedHash = "";

    // Owner address
    address public owner;

    constructor() {
        owner = msg.sender;
    }

    // Get Hash from interacting program/user
    function setGeneratedHash(string memory hash) external{
        generatedHash = hash;
    }

    // Get Hash from IPFS 
    function setIPFSHash(string memory hash) external{
        ipfsHash = hash;
    }

    // Bard :)
    function checkStringEquality(string memory str1, string memory str2) public pure returns (bool) {
      return keccak256(abi.encodePacked(str1)) == keccak256(abi.encodePacked(str2));
    }

    function compare() external view returns (int){
        //console.log("Generated Hash: ", genHash);
        //console.log("IPFS", ipfsHash);

        if(checkStringEquality(ipfsHash, generatedHash)){
            return 0;
        } else {
            return -1;
        }
    }
}
